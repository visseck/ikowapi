# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/akarim/ikowapi/mapgenerator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/akarim/ikowapi/mapgenerator/build

# Include any dependencies generated for this target.
include src/mapgen/CMakeFiles/mapgen.dir/depend.make

# Include the progress variables for this target.
include src/mapgen/CMakeFiles/mapgen.dir/progress.make

# Include the compile flags for this target's objects.
include src/mapgen/CMakeFiles/mapgen.dir/flags.make

src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o: src/mapgen/CMakeFiles/mapgen.dir/flags.make
src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o: ../src/mapgen/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akarim/ikowapi/mapgenerator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mapgen.dir/main.cpp.o -c /home/akarim/ikowapi/mapgenerator/src/mapgen/main.cpp

src/mapgen/CMakeFiles/mapgen.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mapgen.dir/main.cpp.i"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/akarim/ikowapi/mapgenerator/src/mapgen/main.cpp > CMakeFiles/mapgen.dir/main.cpp.i

src/mapgen/CMakeFiles/mapgen.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mapgen.dir/main.cpp.s"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/akarim/ikowapi/mapgenerator/src/mapgen/main.cpp -o CMakeFiles/mapgen.dir/main.cpp.s

src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.requires:

.PHONY : src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.requires

src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.provides: src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.requires
	$(MAKE) -f src/mapgen/CMakeFiles/mapgen.dir/build.make src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.provides.build
.PHONY : src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.provides

src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.provides.build: src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o


src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o: src/mapgen/CMakeFiles/mapgen.dir/flags.make
src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o: ../src/mapgen/opensm/osmmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akarim/ikowapi/mapgenerator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o -c /home/akarim/ikowapi/mapgenerator/src/mapgen/opensm/osmmap.cpp

src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mapgen.dir/opensm/osmmap.cpp.i"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/akarim/ikowapi/mapgenerator/src/mapgen/opensm/osmmap.cpp > CMakeFiles/mapgen.dir/opensm/osmmap.cpp.i

src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mapgen.dir/opensm/osmmap.cpp.s"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/akarim/ikowapi/mapgenerator/src/mapgen/opensm/osmmap.cpp -o CMakeFiles/mapgen.dir/opensm/osmmap.cpp.s

src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.requires:

.PHONY : src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.requires

src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.provides: src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.requires
	$(MAKE) -f src/mapgen/CMakeFiles/mapgen.dir/build.make src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.provides.build
.PHONY : src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.provides

src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.provides.build: src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o


src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o: src/mapgen/CMakeFiles/mapgen.dir/flags.make
src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o: ../src/mapgen/tinyxml2/tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akarim/ikowapi/mapgenerator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o -c /home/akarim/ikowapi/mapgenerator/src/mapgen/tinyxml2/tinyxml2.cpp

src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.i"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/akarim/ikowapi/mapgenerator/src/mapgen/tinyxml2/tinyxml2.cpp > CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.i

src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.s"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/akarim/ikowapi/mapgenerator/src/mapgen/tinyxml2/tinyxml2.cpp -o CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.s

src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.requires:

.PHONY : src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.requires

src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.provides: src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.requires
	$(MAKE) -f src/mapgen/CMakeFiles/mapgen.dir/build.make src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.provides.build
.PHONY : src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.provides

src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.provides.build: src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o


# Object files for target mapgen
mapgen_OBJECTS = \
"CMakeFiles/mapgen.dir/main.cpp.o" \
"CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o" \
"CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o"

# External object files for target mapgen
mapgen_EXTERNAL_OBJECTS =

src/mapgen/mapgen: src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o
src/mapgen/mapgen: src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o
src/mapgen/mapgen: src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o
src/mapgen/mapgen: src/mapgen/CMakeFiles/mapgen.dir/build.make
src/mapgen/mapgen: src/mapgen/CMakeFiles/mapgen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/akarim/ikowapi/mapgenerator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mapgen"
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mapgen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mapgen/CMakeFiles/mapgen.dir/build: src/mapgen/mapgen

.PHONY : src/mapgen/CMakeFiles/mapgen.dir/build

src/mapgen/CMakeFiles/mapgen.dir/requires: src/mapgen/CMakeFiles/mapgen.dir/main.cpp.o.requires
src/mapgen/CMakeFiles/mapgen.dir/requires: src/mapgen/CMakeFiles/mapgen.dir/opensm/osmmap.cpp.o.requires
src/mapgen/CMakeFiles/mapgen.dir/requires: src/mapgen/CMakeFiles/mapgen.dir/tinyxml2/tinyxml2.cpp.o.requires

.PHONY : src/mapgen/CMakeFiles/mapgen.dir/requires

src/mapgen/CMakeFiles/mapgen.dir/clean:
	cd /home/akarim/ikowapi/mapgenerator/build/src/mapgen && $(CMAKE_COMMAND) -P CMakeFiles/mapgen.dir/cmake_clean.cmake
.PHONY : src/mapgen/CMakeFiles/mapgen.dir/clean

src/mapgen/CMakeFiles/mapgen.dir/depend:
	cd /home/akarim/ikowapi/mapgenerator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/akarim/ikowapi/mapgenerator /home/akarim/ikowapi/mapgenerator/src/mapgen /home/akarim/ikowapi/mapgenerator/build /home/akarim/ikowapi/mapgenerator/build/src/mapgen /home/akarim/ikowapi/mapgenerator/build/src/mapgen/CMakeFiles/mapgen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/mapgen/CMakeFiles/mapgen.dir/depend

