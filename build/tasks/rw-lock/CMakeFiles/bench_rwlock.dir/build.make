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
include tasks/rw-lock/CMakeFiles/bench_rwlock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/rw-lock/CMakeFiles/bench_rwlock.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/rw-lock/CMakeFiles/bench_rwlock.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/rw-lock/CMakeFiles/bench_rwlock.dir/flags.make

tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.o: tasks/rw-lock/CMakeFiles/bench_rwlock.dir/flags.make
tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.o: ../tasks/rw-lock/run.cpp
tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.o: tasks/rw-lock/CMakeFiles/bench_rwlock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-lock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.o -MF CMakeFiles/bench_rwlock.dir/run.cpp.o.d -o CMakeFiles/bench_rwlock.dir/run.cpp.o -c /Users/ershoff/cpp-advenced/tasks/rw-lock/run.cpp

tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bench_rwlock.dir/run.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-lock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/rw-lock/run.cpp > CMakeFiles/bench_rwlock.dir/run.cpp.i

tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bench_rwlock.dir/run.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-lock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/rw-lock/run.cpp -o CMakeFiles/bench_rwlock.dir/run.cpp.s

# Object files for target bench_rwlock
bench_rwlock_OBJECTS = \
"CMakeFiles/bench_rwlock.dir/run.cpp.o"

# External object files for target bench_rwlock
bench_rwlock_EXTERNAL_OBJECTS =

bench_rwlock: tasks/rw-lock/CMakeFiles/bench_rwlock.dir/run.cpp.o
bench_rwlock: tasks/rw-lock/CMakeFiles/bench_rwlock.dir/build.make
bench_rwlock: libbenchmark.a
bench_rwlock: tasks/rw-lock/CMakeFiles/bench_rwlock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bench_rwlock"
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-lock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bench_rwlock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/rw-lock/CMakeFiles/bench_rwlock.dir/build: bench_rwlock
.PHONY : tasks/rw-lock/CMakeFiles/bench_rwlock.dir/build

tasks/rw-lock/CMakeFiles/bench_rwlock.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/tasks/rw-lock && $(CMAKE_COMMAND) -P CMakeFiles/bench_rwlock.dir/cmake_clean.cmake
.PHONY : tasks/rw-lock/CMakeFiles/bench_rwlock.dir/clean

tasks/rw-lock/CMakeFiles/bench_rwlock.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/tasks/rw-lock /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/tasks/rw-lock /Users/ershoff/cpp-advenced/build/tasks/rw-lock/CMakeFiles/bench_rwlock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/rw-lock/CMakeFiles/bench_rwlock.dir/depend

