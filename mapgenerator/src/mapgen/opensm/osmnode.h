#pragma once
#include <stdint.h>
#include <vector>
#include "../core/lonlat.h"

namespace ikowapi
{
    class OSMRoad;
    class OSMNode
    {
    public:
        uint64_t m_NodeID;
        LonLat m_Position;
        std::vector<OSMRoad*> m_ReferencedRoads;
    };
}