# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrew.r.howard/Projects/BlockTowerGA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew.r.howard/Projects/BlockTowerGA

# Include any dependencies generated for this target.
include CMakeFiles/BlockTowerGA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BlockTowerGA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BlockTowerGA.dir/flags.make

CMakeFiles/BlockTowerGA.dir/src/main.cpp.o: CMakeFiles/BlockTowerGA.dir/flags.make
CMakeFiles/BlockTowerGA.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew.r.howard/Projects/BlockTowerGA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BlockTowerGA.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BlockTowerGA.dir/src/main.cpp.o -c /Users/andrew.r.howard/Projects/BlockTowerGA/src/main.cpp

CMakeFiles/BlockTowerGA.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BlockTowerGA.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew.r.howard/Projects/BlockTowerGA/src/main.cpp > CMakeFiles/BlockTowerGA.dir/src/main.cpp.i

CMakeFiles/BlockTowerGA.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BlockTowerGA.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew.r.howard/Projects/BlockTowerGA/src/main.cpp -o CMakeFiles/BlockTowerGA.dir/src/main.cpp.s

# Object files for target BlockTowerGA
BlockTowerGA_OBJECTS = \
"CMakeFiles/BlockTowerGA.dir/src/main.cpp.o"

# External object files for target BlockTowerGA
BlockTowerGA_EXTERNAL_OBJECTS =

BlockTowerGA: CMakeFiles/BlockTowerGA.dir/src/main.cpp.o
BlockTowerGA: CMakeFiles/BlockTowerGA.dir/build.make
BlockTowerGA: CMakeFiles/BlockTowerGA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew.r.howard/Projects/BlockTowerGA/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BlockTowerGA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BlockTowerGA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BlockTowerGA.dir/build: BlockTowerGA

.PHONY : CMakeFiles/BlockTowerGA.dir/build

CMakeFiles/BlockTowerGA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BlockTowerGA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BlockTowerGA.dir/clean

CMakeFiles/BlockTowerGA.dir/depend:
	cd /Users/andrew.r.howard/Projects/BlockTowerGA && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew.r.howard/Projects/BlockTowerGA /Users/andrew.r.howard/Projects/BlockTowerGA /Users/andrew.r.howard/Projects/BlockTowerGA /Users/andrew.r.howard/Projects/BlockTowerGA /Users/andrew.r.howard/Projects/BlockTowerGA/CMakeFiles/BlockTowerGA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BlockTowerGA.dir/depend

