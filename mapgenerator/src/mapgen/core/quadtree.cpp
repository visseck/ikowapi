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
    // 0 - TopLeft
    // 1 - TopRight
    // 2 - BottomRight
    // 3 - BottomLeft
    int32_t indicesPerQuad[4][2];
    for (const auto &roadEntry : m_Entries)
    {
        const OSMRoad &road = *roadEntry.m_Road;
        for (uint32_t i = 0; i < 4; ++i)
        {
            indicesPerQuad[i][0] = std::numeric_limits<int32_t>::min();
            indicesPerQuad[i][1] = std::numeric_limits<int32_t>::max();
        }

        for (uint32_t i = roadEntry.m_StartIndex; i < roadEntry.m_EndIndex; ++i)
        {
            auto lonLat = road.m_Nodes[i]->m_Position;
            if (lonLat.m_Lat < m_PosX + extentX / 2)
            {
                if (lonLat.m_Lon < m_PosY + extentY / 2)
                {
                    if (i < indicesPerQuad[3][0])
                        indicesPerQuad[3][0] = i;
                    if (i > indicesPerQuad[3][1])
                        indicesPerQuad[3][1] = i;
                }
                else
                {
                    if (i < indicesPerQuad[0][0])
                        indicesPerQuad[0][0] = i;
                    if (i > indicesPerQuad[0][0])
                        indicesPerQuad[0][0] = i;
                }
            }
            else
            {
                if (lonLat.m_Lon < m_PosY + extentY / 2)
                {
                    if (i < indicesPerQuad[2][0])
                        indicesPerQuad[2][0] = i;
                    if (i > indicesPerQuad[2][1])
                        indicesPerQuad[2][1] = i;
                }
                else
                {
                    if (i < indicesPerQuad[1][0])
                        indicesPerQuad[1][0] = i;
                    if (i > indicesPerQuad[1][1])
                        indicesPerQuad[1][1] = i;
                }
            }
        }
    }
}
}