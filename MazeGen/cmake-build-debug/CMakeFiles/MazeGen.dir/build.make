# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/imakepoptarts/CLionProjects/MazeGen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/imakepoptarts/CLionProjects/MazeGen/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MazeGen.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MazeGen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MazeGen.dir/flags.make

CMakeFiles/MazeGen.dir/main.cpp.o: CMakeFiles/MazeGen.dir/flags.make
CMakeFiles/MazeGen.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/imakepoptarts/CLionProjects/MazeGen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MazeGen.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MazeGen.dir/main.cpp.o -c /home/imakepoptarts/CLionProjects/MazeGen/main.cpp

CMakeFiles/MazeGen.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MazeGen.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/imakepoptarts/CLionProjects/MazeGen/main.cpp > CMakeFiles/MazeGen.dir/main.cpp.i

CMakeFiles/MazeGen.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MazeGen.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/imakepoptarts/CLionProjects/MazeGen/main.cpp -o CMakeFiles/MazeGen.dir/main.cpp.s

# Object files for target MazeGen
MazeGen_OBJECTS = \
"CMakeFiles/MazeGen.dir/main.cpp.o"

# External object files for target MazeGen
MazeGen_EXTERNAL_OBJECTS =

MazeGen: CMakeFiles/MazeGen.dir/main.cpp.o
MazeGen: CMakeFiles/MazeGen.dir/build.make
MazeGen: CMakeFiles/MazeGen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/imakepoptarts/CLionProjects/MazeGen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MazeGen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MazeGen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MazeGen.dir/build: MazeGen
.PHONY : CMakeFiles/MazeGen.dir/build

CMakeFiles/MazeGen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MazeGen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MazeGen.dir/clean

CMakeFiles/MazeGen.dir/depend:
	cd /home/imakepoptarts/CLionProjects/MazeGen/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imakepoptarts/CLionProjects/MazeGen /home/imakepoptarts/CLionProjects/MazeGen /home/imakepoptarts/CLionProjects/MazeGen/cmake-build-debug /home/imakepoptarts/CLionProjects/MazeGen/cmake-build-debug /home/imakepoptarts/CLionProjects/MazeGen/cmake-build-debug/CMakeFiles/MazeGen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MazeGen.dir/depend
