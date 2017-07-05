cmake_minimum_required(VERSION 3.0)

set( SOURCE
    main.cpp
    core/lonlat.h
    opensm/osmmap.cpp
    opensm/osmmap.h
    opensm/osmnode.h
    opensm/osmroad.h
    tinyxml2/tinyxml2.h
    tinyxml2/tinyxml2.cpp
)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

include(CMakeToolsHelpers OPTIONAL)

add_executable(mapgen ${SOURCE})
