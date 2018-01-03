#include "osmmap.h"
#include <stdio.h>
#include <string>
#include <memory>
#include "../tinyxml2/tinyxml2.h"
#include <unordered_map>
#include <limits>

namespace ikowapi
{

struct RoadAsIDs
{
    std::vector<uint64_t> m_NodeIDs;
    std::string m_RoadName;
};

bool OSMMap::loadMap(const char *mapName)
{
    tinyxml2::XMLDocument doc;
    auto error = doc.LoadFile(mapName);

    auto *rootNode = doc.FirstChildElement();
    auto *iterNode = rootNode->FirstChildElement();

    std::string nodeName;
    std::unordered_map<uint64_t, OSMNode *> idToNodeMap;
    std::vector<std::unique_ptr<RoadAsIDs>> tempRoadData;

    while (iterNode != nullptr)
    {
        nodeName = iterNode->Name();
        if (nodeName == "node")
        {
            std::unique_ptr<OSMNode> nodePtr = std::make_unique<OSMNode>();
            nodePtr->m_Position.m_Lat = iterNode->DoubleAttribute("lat");
            nodePtr->m_Position.m_Lon = iterNode->DoubleAttribute("lon");
            nodePtr->m_NodeID = iterNode->UInt64Attribute("id");
            if (nodePtr->m_NodeID == 4612020071)
            {
                int yees = 5;
            }
            idToNodeMap[nodePtr->m_NodeID] = nodePtr.get();
            m_Nodes.push_back(std::move(nodePtr));
        }
        else if (nodeName == "way")
        {
            auto wayPropIter = iterNode->FirstChildElement();
            auto roadPtr = std::make_unique<RoadAsIDs>();
            bool roadIsActualRoad = false;
            bool roadHasPoints = false;
            std::string wayPropName;
            while (wayPropIter != nullptr)
            {
                wayPropName = wayPropIter->Name();
                if (wayPropName == "nd")
                {
                    uint64_t ref = wayPropIter->UInt64Attribute("ref");
                    roadPtr->m_NodeIDs.push_back(ref);
                    roadHasPoints = true;
                }
                else if (wayPropName == "tag")
                {
                    if (strcmp(wayPropIter->Attribute("k"), "highway") == 0)
                    {
                        roadIsActualRoad = true;
                    }
                    else if (strcmp(wayPropIter->Attribute("k"), "name") == 0)
                    {
                        roadPtr->m_RoadName = wayPropIter->Attribute("v");
                    }
                }
                wayPropIter = wayPropIter->NextSiblingElement();
            }

            if (roadIsActualRoad && roadHasPoints)
            {
                tempRoadData.push_back(std::move(roadPtr));
            }
        }
        iterNode = iterNode->NextSiblingElement();
    }

    m_Roads.reserve(tempRoadData.size());
    for (const auto &tempRoad : tempRoadData)
    {
        std::unique_ptr<OSMRoad> road = std::make_unique<OSMRoad>();
        road->m_Name = tempRoad->m_RoadName;
        road->m_Nodes.reserve(tempRoad->m_NodeIDs.size());
        for (auto nodeID : tempRoad->m_NodeIDs)
        {
            auto iter = idToNodeMap.find(nodeID);
            if (iter == idToNodeMap.end())
            {
                int z = 2;
            }
            road->m_Nodes.push_back(iter->second);
            iter->second->m_ReferencedRoads.push_back(road.get());
        }
        m_Roads.push_back(std::move(road));
    }

	return true;
}

void OSMMap::getExtents(double &minLat, double &minLon, double &maxLat, double &maxLon) const
{

    minLat = std::numeric_limits<double>::max();
    maxLat = -std::numeric_limits<double>::max();
    minLon = std::numeric_limits<double>::max();
    maxLon = -std::numeric_limits<double>::max();

    for (const auto &road : m_Roads)
    {
        for (const auto &node : road->m_Nodes)
        {
            if (node->m_Position.m_Lat > maxLat)
            {
                maxLat = node->m_Position.m_Lat;
            }
            if (node->m_Position.m_Lat < minLat)
            {
                minLat = node->m_Position.m_Lat;
            }
            if (node->m_Position.m_Lon > maxLon)
            {
                maxLon = node->m_Position.m_Lon;
            }
            if (node->m_Position.m_Lon < minLon)
            {
                minLon = node->m_Position.m_Lon;
            }
        }
    }
}
}