#pragma once
#include <memory>
#include "osmnode.h"
#include "osmroad.h"
namespace ikowapi
{
class OSMMap
{
public:
  bool loadMap(const char *mapName);
  void getExtents(double &minLat, double &minLon, double &maxLat, double &maxLon) const;
  std::vector<std::unique_ptr<OSMNode>> m_Nodes;
  std::vector<std::unique_ptr<OSMRoad>> m_Roads;
};
}