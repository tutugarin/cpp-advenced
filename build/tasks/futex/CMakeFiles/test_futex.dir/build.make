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
include tasks/futex/CMakeFiles/test_futex.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/futex/CMakeFiles/test_futex.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/futex/CMakeFiles/test_futex.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/futex/CMakeFiles/test_futex.dir/flags.make

tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o: tasks/futex/CMakeFiles/test_futex.dir/flags.make
tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o: ../contrib/gmock_main.cc
tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o: tasks/futex/CMakeFiles/test_futex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o -MF CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o.d -o CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o -c /Users/ershoff/cpp-advenced/contrib/gmock_main.cc

tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/contrib/gmock_main.cc > CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.i

tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/contrib/gmock_main.cc -o CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.s

tasks/futex/CMakeFiles/test_futex.dir/test.cpp.o: tasks/futex/CMakeFiles/test_futex.dir/flags.make
tasks/futex/CMakeFiles/test_futex.dir/test.cpp.o: ../tasks/futex/test.cpp
tasks/futex/CMakeFiles/test_futex.dir/test.cpp.o: tasks/futex/CMakeFiles/test_futex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/futex/CMakeFiles/test_futex.dir/test.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/futex/CMakeFiles/test_futex.dir/test.cpp.o -MF CMakeFiles/test_futex.dir/test.cpp.o.d -o CMakeFiles/test_futex.dir/test.cpp.o -c /Users/ershoff/cpp-advenced/tasks/futex/test.cpp

tasks/futex/CMakeFiles/test_futex.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_futex.dir/test.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/futex/test.cpp > CMakeFiles/test_futex.dir/test.cpp.i

tasks/futex/CMakeFiles/test_futex.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_futex.dir/test.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/futex/test.cpp -o CMakeFiles/test_futex.dir/test.cpp.s

# Object files for target test_futex
test_futex_OBJECTS = \
"CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o" \
"CMakeFiles/test_futex.dir/test.cpp.o"

# External object files for target test_futex
test_futex_EXTERNAL_OBJECTS =

test_futex: tasks/futex/CMakeFiles/test_futex.dir/__/__/contrib/gmock_main.cc.o
test_futex: tasks/futex/CMakeFiles/test_futex.dir/test.cpp.o
test_futex: tasks/futex/CMakeFiles/test_futex.dir/build.make
test_futex: libgmock.a
test_futex: tasks/futex/CMakeFiles/test_futex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../test_futex"
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_futex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/futex/CMakeFiles/test_futex.dir/build: test_futex
.PHONY : tasks/futex/CMakeFiles/test_futex.dir/build

tasks/futex/CMakeFiles/test_futex.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/tasks/futex && $(CMAKE_COMMAND) -P CMakeFiles/test_futex.dir/cmake_clean.cmake
.PHONY : tasks/futex/CMakeFiles/test_futex.dir/clean

tasks/futex/CMakeFiles/test_futex.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/tasks/futex /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/tasks/futex /Users/ershoff/cpp-advenced/build/tasks/futex/CMakeFiles/test_futex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/futex/CMakeFiles/test_futex.dir/depend
