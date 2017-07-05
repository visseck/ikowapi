#pragma once
#include <vector>

namespace ikowapi
{
class OSMNode;
class OSMRoad
{
  public:
    std::vector<OSMNode *> m_Nodes;
};
}