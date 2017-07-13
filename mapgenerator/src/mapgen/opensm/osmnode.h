#pragma once
#include <stdint.h>
#include "../core/lonlat.h"

namespace ikowapi
{
class OSMNode
{
public:
  uint64_t m_NodeID;
  LonLat m_Position;
};
}