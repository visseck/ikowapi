#pragma once
#include <string>
#include <vector>
#include <stdint.h>
#include <memory>

namespace ikowapi
{
class OSMMap;
struct Address;

class IkowapiMap
{
  public:
    std::vector<Address> m_Addresses;
    void BuildMap(const OSMMap &map, double addressSize);
};
}