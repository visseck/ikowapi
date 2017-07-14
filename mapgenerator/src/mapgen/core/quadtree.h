#pragma once
#include <stdint.h>
#include <vector>
#include <memory>

namespace ikowapi
{
class OSMMap;
class OSMRoad;
class RoadQuadTree
{
  public:
    RoadQuadTree(const OSMMap &map);

  private:
	  enum TreePos
	  {
		  TopLeft = 0,
		  TopRight = 1,
		  BottomRight = 2,
		  BottomLeft = 3
	  };

	  enum Index
	  {
		  Min = 0,
		  Max = 1
	  };

    struct RoadSectionEntry
    {
        OSMRoad *m_Road;
        int32_t m_StartIndex;
        int32_t m_EndIndex;
    };

    struct TreeNode
    {
        TreeNode(double posX, double posY);
        void RecurseDown(double extentX, double extentY);
        double m_PosX;
        double m_PosY;
        std::vector<RoadSectionEntry> m_Entries;
        std::unique_ptr<TreeNode> m_SubNodes[4];
    };

    double m_ExtentY;
    double m_ExtentX;
    std::unique_ptr<TreeNode> m_RootNode;
};
}