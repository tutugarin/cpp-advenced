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

# Include any dependencies generated for this target.
include glog/glog-build/CMakeFiles/stacktrace_unittest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glog/glog-build/CMakeFiles/stacktrace_unittest.dir/compiler_depend.make

# Include the progress variables for this target.
include glog/glog-build/CMakeFiles/stacktrace_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include glog/glog-build/CMakeFiles/stacktrace_unittest.dir/flags.make

glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o: glog/glog-build/CMakeFiles/stacktrace_unittest.dir/flags.make
glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o: glog/glog-src/src/stacktrace_unittest.cc
glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o: glog/glog-build/CMakeFiles/stacktrace_unittest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o"
	cd /Users/ershoff/cpp-advenced/build/glog/glog-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o -MF CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o.d -o CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o -c /Users/ershoff/cpp-advenced/build/glog/glog-src/src/stacktrace_unittest.cc

glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.i"
	cd /Users/ershoff/cpp-advenced/build/glog/glog-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/build/glog/glog-src/src/stacktrace_unittest.cc > CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.i

glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.s"
	cd /Users/ershoff/cpp-advenced/build/glog/glog-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/build/glog/glog-src/src/stacktrace_unittest.cc -o CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.s

# Object files for target stacktrace_unittest
stacktrace_unittest_OBJECTS = \
"CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o"

# External object files for target stacktrace_unittest
stacktrace_unittest_EXTERNAL_OBJECTS =

stacktrace_unittest: glog/glog-build/CMakeFiles/stacktrace_unittest.dir/src/stacktrace_unittest.cc.o
stacktrace_unittest: glog/glog-build/CMakeFiles/stacktrace_unittest.dir/build.make
stacktrace_unittest: glog/glog-build/libglogtest.a
stacktrace_unittest: glog/glog-build/CMakeFiles/stacktrace_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../stacktrace_unittest"
	cd /Users/ershoff/cpp-advenced/build/glog/glog-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stacktrace_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glog/glog-build/CMakeFiles/stacktrace_unittest.dir/build: stacktrace_unittest
.PHONY : glog/glog-build/CMakeFiles/stacktrace_unittest.dir/build

glog/glog-build/CMakeFiles/stacktrace_unittest.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/glog/glog-build && $(CMAKE_COMMAND) -P CMakeFiles/stacktrace_unittest.dir/cmake_clean.cmake
.PHONY : glog/glog-build/CMakeFiles/stacktrace_unittest.dir/clean

glog/glog-build/CMakeFiles/stacktrace_unittest.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/build/glog/glog-src /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/glog/glog-build /Users/ershoff/cpp-advenced/build/glog/glog-build/CMakeFiles/stacktrace_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glog/glog-build/CMakeFiles/stacktrace_unittest.dir/depend

