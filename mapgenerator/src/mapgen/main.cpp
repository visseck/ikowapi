#include "opensm/osmmap.h"
#include "tinyxml2/tinyxml2.h"
#include <string>
#include <stdio.h>

using namespace ikowapi;
using namespace tinyxml2;

void buildSVGFile(const char *filePath, const OSMMap &map)
{
    double minLat, minLon, maxLat, maxLon;
    map.getExtents(minLat, minLon, maxLat, maxLon);
    const int svgHeight = 10000;
    const int svgWidth = 10000;
    XMLDocument doc;
    XMLElement *svg = nullptr;
    {
        auto root = doc.NewElement("html");
        doc.InsertFirstChild(root);
        auto body = doc.NewElement("body");
        root->InsertFirstChild(body);
        svg = doc.NewElement("svg");
        body->InsertFirstChild(svg);
        svg->SetAttribute("width", svgWidth);
        svg->SetAttribute("height", svgHeight);
        svg->SetAttribute("id", "ikowapi_map");
        auto scriptElement = doc.NewElement("script");
        scriptElement->SetText("\nwindow.onload = function() {\n// Expose to window namespase for testing purposes\nwindow.zoomIkoWapi = svgPanZoom('#ikowapi_map', {\nzoomEnabled: true,\ncontrolIconsEnabled: true,fit: true,\ncenter: true,\n// viewportSelector: document.getElementById('demo-tiger').querySelector('#g4') // this option will make library to misbehave. Viewport should have no transform attribute\n});\n};");
        body->InsertEndChild(scriptElement);
    }

    char buffer[256];
    std::string fullPath;
    double maxX = 0;
    for (const auto &road : map.m_Roads)
    {
        fullPath.clear();
        for (const auto &node : road->m_Nodes)
        {
            double x = ((node->m_Position.m_Lat - minLat) / (maxLat - minLat)) * (double)svgWidth;
            if (x > maxX)
                maxX = x;
            double y = ((node->m_Position.m_Lon - minLon) / (maxLon - minLon)) * (double)svgHeight;
            sprintf(buffer, "%f,%f ", x, y);
            fullPath.append(buffer);
        }
        auto polyLine = doc.NewElement("polyline");
        polyLine->SetAttribute("points", fullPath.c_str());
        polyLine->SetAttribute("style", "fill:none;stroke:black;stroke-width:3");
        svg->InsertEndChild(polyLine);
    }

    doc.SaveFile(filePath);
}

int main()
{
    OSMMap map;
    map.loadMap("/home/akarim/Downloads/map");
    buildSVGFile("/home/akarim/ikowapi/index.html", map);
    return 0;
}
