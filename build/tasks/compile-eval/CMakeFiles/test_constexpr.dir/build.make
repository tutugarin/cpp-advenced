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
include tasks/compile-eval/CMakeFiles/test_constexpr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/compile-eval/CMakeFiles/test_constexpr.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/compile-eval/CMakeFiles/test_constexpr.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/compile-eval/CMakeFiles/test_constexpr.dir/flags.make

tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o: tasks/compile-eval/CMakeFiles/test_constexpr.dir/flags.make
tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o: ../tasks/compile-eval/test_constexpr.cpp
tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o: tasks/compile-eval/CMakeFiles/test_constexpr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/compile-eval && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o -MF CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o.d -o CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o -c /Users/ershoff/cpp-advenced/tasks/compile-eval/test_constexpr.cpp

tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_constexpr.dir/test_constexpr.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/compile-eval && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/compile-eval/test_constexpr.cpp > CMakeFiles/test_constexpr.dir/test_constexpr.cpp.i

tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_constexpr.dir/test_constexpr.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/compile-eval && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/compile-eval/test_constexpr.cpp -o CMakeFiles/test_constexpr.dir/test_constexpr.cpp.s

# Object files for target test_constexpr
test_constexpr_OBJECTS = \
"CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o"

# External object files for target test_constexpr
test_constexpr_EXTERNAL_OBJECTS =

test_constexpr: tasks/compile-eval/CMakeFiles/test_constexpr.dir/test_constexpr.cpp.o
test_constexpr: tasks/compile-eval/CMakeFiles/test_constexpr.dir/build.make
test_constexpr: libcontrib_catch_main.a
test_constexpr: tasks/compile-eval/CMakeFiles/test_constexpr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../test_constexpr"
	cd /Users/ershoff/cpp-advenced/build/tasks/compile-eval && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_constexpr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/compile-eval/CMakeFiles/test_constexpr.dir/build: test_constexpr
.PHONY : tasks/compile-eval/CMakeFiles/test_constexpr.dir/build

tasks/compile-eval/CMakeFiles/test_constexpr.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/tasks/compile-eval && $(CMAKE_COMMAND) -P CMakeFiles/test_constexpr.dir/cmake_clean.cmake
.PHONY : tasks/compile-eval/CMakeFiles/test_constexpr.dir/clean

tasks/compile-eval/CMakeFiles/test_constexpr.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/tasks/compile-eval /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/tasks/compile-eval /Users/ershoff/cpp-advenced/build/tasks/compile-eval/CMakeFiles/test_constexpr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/compile-eval/CMakeFiles/test_constexpr.dir/depend

