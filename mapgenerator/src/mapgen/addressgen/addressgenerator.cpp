#include "addressgenerator.h"
#include "../core/lonlat.h"
#include "../opensm/osmmap.h"
#include <cmath>
#include "address.h"

namespace ikowapi
{


struct AddressFeeder
{
	AddressFeeder(const std::vector<OSMNode*>& nodes)
		: m_Nodes(nodes)
		, m_CurIndex(0)
		, m_CurRatio(0)
	{
	}

	bool isFinished() const
	{
		return m_CurIndex == m_Nodes.size() - 1;
	}

	double getNextPoint(double desiredDistance, LonLat& lonLatOut, Vector2& normalOut);
	{
		Vector2 toNextPoint = Vector2(m_Nodes[m_CurIndex]->m_Position, m_Nodes[m_CurIndex + 1]->m_Position);
		double distanceToNext = toNextPoint.length();
		if (distanceToNext*(1 - m_CurRatio) >= desiredDistance)
		{
			double ratioToAdd = desiredDistance / distanceToNext;
			lonLatOut = toNextPoint*(m_CurRatio + ratioToAdd);
		}
		return 0;

	}

	uint32_t m_CurIndex;
	double m_CurRatio;
	const std::vector<OSMNode*>& m_Nodes;
};

void IkowapiMap::BuildMap(const OSMMap &map, double addressSize)
{
	for (const auto & road : map.m_Roads)
	{
		Address curAddress;
		bool curAddressValid = false;

		const auto& nodes = road->m_Nodes;
		Vector2 normal;
		for (size_t i = 0; i < nodes.size(); ++i)
		{
			if (i > 0)
			{
				if (i < nodes.size() - 1)
				{
					Vector2 prevNormal = Vector2(nodes[i - 1]->m_Position, nodes[i]->m_Position).getPerpendicularLeft();
					prevNormal.normalize();
					Vector2 nextNormal = Vector2(nodes[i]->m_Position, nodes[i + 1]->m_Position).getPerpendicularLeft();
					nextNormal.normalize();
					normal = (prevNormal + nextNormal) / 2;
					normal.normalize();
				}
				else
				{
					normal = Vector2(nodes[i - 1]->m_Position, nodes[i]->m_Position).getPerpendicularLeft();
					normal.normalize();
				}
			}
			else
			{
				normal = Vector2(nodes[i]->m_Position, nodes[i + 1]->m_Position).getPerpendicularLeft();
				normal.normalize();
			}
		}
	}
}
}