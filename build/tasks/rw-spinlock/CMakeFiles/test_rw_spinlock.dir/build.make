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
include tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/flags.make

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/flags.make
tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o: ../contrib/gmock_main.cc
tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o -MF CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o.d -o CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o -c /Users/ershoff/cpp-advenced/contrib/gmock_main.cc

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/contrib/gmock_main.cc > CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.i

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/contrib/gmock_main.cc -o CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.s

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.o: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/flags.make
tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.o: ../tasks/rw-spinlock/test.cpp
tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.o: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.o -MF CMakeFiles/test_rw_spinlock.dir/test.cpp.o.d -o CMakeFiles/test_rw_spinlock.dir/test.cpp.o -c /Users/ershoff/cpp-advenced/tasks/rw-spinlock/test.cpp

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_rw_spinlock.dir/test.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/rw-spinlock/test.cpp > CMakeFiles/test_rw_spinlock.dir/test.cpp.i

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_rw_spinlock.dir/test.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/rw-spinlock/test.cpp -o CMakeFiles/test_rw_spinlock.dir/test.cpp.s

# Object files for target test_rw_spinlock
test_rw_spinlock_OBJECTS = \
"CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o" \
"CMakeFiles/test_rw_spinlock.dir/test.cpp.o"

# External object files for target test_rw_spinlock
test_rw_spinlock_EXTERNAL_OBJECTS =

test_rw_spinlock: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/__/__/contrib/gmock_main.cc.o
test_rw_spinlock: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/test.cpp.o
test_rw_spinlock: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/build.make
test_rw_spinlock: libgmock.a
test_rw_spinlock: tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../test_rw_spinlock"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_rw_spinlock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/build: test_rw_spinlock
.PHONY : tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/build

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock && $(CMAKE_COMMAND) -P CMakeFiles/test_rw_spinlock.dir/cmake_clean.cmake
.PHONY : tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/clean

tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/tasks/rw-spinlock /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock /Users/ershoff/cpp-advenced/build/tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/rw-spinlock/CMakeFiles/test_rw_spinlock.dir/depend
