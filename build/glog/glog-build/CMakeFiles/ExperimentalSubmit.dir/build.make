# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ershoff/cpp-advenced

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ershoff/cpp-advenced/build

# Utility rule file for ExperimentalSubmit.

# Include any custom commands dependencies for this target.
include glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/compiler_depend.make

# Include the progress variables for this target.
include glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/progress.make

glog/glog-build/CMakeFiles/ExperimentalSubmit:
	cd /Users/ershoff/cpp-advenced/build/glog/glog-build && /opt/homebrew/Cellar/cmake/3.21.3/bin/ctest -D ExperimentalSubmit

ExperimentalSubmit: glog/glog-build/CMakeFiles/ExperimentalSubmit
ExperimentalSubmit: glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/build.make
.PHONY : ExperimentalSubmit

# Rule to build all files generated by this target.
glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/build: ExperimentalSubmit
.PHONY : glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/build

glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/glog/glog-build && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalSubmit.dir/cmake_clean.cmake
.PHONY : glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/clean

glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/build/glog/glog-src /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/glog/glog-build /Users/ershoff/cpp-advenced/build/glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glog/glog-build/CMakeFiles/ExperimentalSubmit.dir/depend

