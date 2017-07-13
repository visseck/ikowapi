#pragma once
#include <vector>
#include <string>
namespace ikowapi
{
class OSMNode;
class OSMRoad
{
public:
  std::string m_Name;
  std::vector<OSMNode *> m_Nodes;
};
}