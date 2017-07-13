#pragma once
#include <string>
#include <vector>
#include <stdint.h>
#include <memory>

namespace ikowapi
{
class OSMMap;
struct LonLat;
struct Address
{
    uint16_t m_RoadAddress;
    std::string m_RoadName;
    std::vector<LonLat> m_Points;
};

class IkowapiMap
{
  public:
    std::vector<std::unique_ptr<Address>> m_Addresses;
    void BuildMap(const OSMMap &map);
};
}