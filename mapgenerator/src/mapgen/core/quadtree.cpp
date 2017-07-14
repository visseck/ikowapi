#include "quadtree.h"
#include "../opensm/osmmap.h"
#include <limits>

namespace ikowapi
{
RoadQuadTree::TreeNode::TreeNode(double posX, double posY)
    : m_PosX(posX), m_PosY(posY)
{
}

RoadQuadTree::RoadQuadTree(const OSMMap &map)
{
    double startX, startY, endX, endY;
    map.getExtents(startX, startY, endX, endY);

    m_ExtentX = endX - startX;
    m_ExtentY = endY - startY;
    m_RootNode = std::make_unique<TreeNode>(startX, startY);

    for (const auto &road : map.m_Roads)
    {
        m_RootNode->m_Entries.push_back(RoadSectionEntry{road.get(), 0, static_cast<uint16_t>(road->m_Nodes.size())});
    }
    m_RootNode->RecurseDown(m_ExtentX, m_ExtentY);
}

void RoadQuadTree::TreeNode::RecurseDown(double extentX, double extentY)
{
	if (m_Entries.size() < 20)
		return;
    // 0 - TopLeft
    // 1 - TopRight
    // 2 - BottomRight
    // 3 - BottomLeft
		
	m_SubNodes[TopLeft] = std::make_unique<TreeNode>(m_PosX, m_PosY + extentY / 2);
	m_SubNodes[TopRight] = std::make_unique<TreeNode>(m_PosX + extentX / 2, m_PosY + extentY / 2);
	m_SubNodes[BottomRight] = std::make_unique<TreeNode>(m_PosX + extentX / 2, m_PosY);
	m_SubNodes[BottomLeft] = std::make_unique<TreeNode>(m_PosX, m_PosY);

    int32_t indicesPerQuad[4][2];
    for (const auto &roadEntry : m_Entries)
    {
        const OSMRoad &road = *roadEntry.m_Road;
        for (uint32_t i = 0; i < 4; ++i)
        {
            indicesPerQuad[i][Min] = std::numeric_limits<int32_t>::max();
            indicesPerQuad[i][Max] = std::numeric_limits<int32_t>::min();
        }

        for (int32_t i = roadEntry.m_StartIndex; i < roadEntry.m_EndIndex; ++i)
        {
            auto lonLat = road.m_Nodes[i]->m_Position;
            if (lonLat.m_Lat < m_PosX + extentX / 2)
            {
                if (lonLat.m_Lon < m_PosY + extentY / 2)
                {
                    if (i < indicesPerQuad[BottomLeft][Min])
                        indicesPerQuad[BottomLeft][Min] = i;
                    if (i > indicesPerQuad[BottomLeft][Max])
                        indicesPerQuad[BottomLeft][Max] = i;
                }
                else
                {
                    if (i < indicesPerQuad[TopLeft][Min])
                        indicesPerQuad[TopLeft][Min] = i;
                    if (i > indicesPerQuad[TopLeft][Max])
                        indicesPerQuad[TopLeft][Max] = i;
                }
            }
            else
            {
                if (lonLat.m_Lon < m_PosY + extentY / 2)
                {
                    if (i < indicesPerQuad[BottomRight][Min])
                        indicesPerQuad[BottomRight][Min] = i;
                    if (i > indicesPerQuad[BottomRight][Max])
                        indicesPerQuad[BottomRight][Max] = i;
                }
                else
                {
                    if (i < indicesPerQuad[TopRight][Min])
                        indicesPerQuad[TopRight][Min] = i;
                    if (i > indicesPerQuad[TopRight][Max])
                        indicesPerQuad[TopRight][Max] = i;
                }
            }
        }

		for (int i = 0; i < 4; ++i)
		{
			if (indicesPerQuad[i][0] == std::numeric_limits<int32_t>::max())
				continue;
			m_SubNodes[i]->m_Entries.push_back(RoadSectionEntry{ roadEntry.m_Road, indicesPerQuad[i][Min], indicesPerQuad[i][Max] });
		}
    }

	for (int i = 0; i < 4; ++i)
	{
		m_SubNodes[i]->RecurseDown(extentX / 2, extentY / 2);
	}
}
}