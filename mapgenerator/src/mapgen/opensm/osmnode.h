#pragma once
#include <stdint.h>
#include "../core/lonlat.h"

namespace ikowapi
{
class OSMNode
{
  public:
    uint32_t m_NodeID;
    LonLat m_Position;
};
}