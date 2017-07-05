#include "osmmap.h"
#include <stdio.h>
#include "../tinyxml2/tinyxml2.h"

namespace ikowapi
{
bool OSMMap::loadMap(const char *mapName)
{
    tinyxml2::XMLDocument doc;
    auto error = doc.LoadFile(mapName);

    tinyxml2::XMLNode *rootNode = doc.FirstChild();
    tinyxml2::XMLNode *versionNode = rootNode->FirstChild();
    tinyxml2::XMLNode *iterNode = versionNode->FirstChild();

    std::string nodeName;
    while (iterNode != nullptr)
    {
        nodeName = iterNode->GetText();
        if (nodeName == "node")
        {
            std::unique_ptr<OSMNode> nodePtr = std::make_unique<OSMNode>();
            nodePtr->m_Position.m_Lat = iterNode->DoubleAttribute("lat");
            nodePtr->m_Position.m_Lon = iterNode->DoubleAttribute("lon");
            nodePtr->m_NodeID = iterNode->UInt64Attribute("id");
        }
        //else if ()
    }
}
}