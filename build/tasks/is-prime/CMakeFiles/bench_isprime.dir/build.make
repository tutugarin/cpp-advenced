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
include tasks/is-prime/CMakeFiles/bench_isprime.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/is-prime/CMakeFiles/bench_isprime.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/is-prime/CMakeFiles/bench_isprime.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/is-prime/CMakeFiles/bench_isprime.dir/flags.make

tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.o: tasks/is-prime/CMakeFiles/bench_isprime.dir/flags.make
tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.o: ../tasks/is-prime/run.cpp
tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.o: tasks/is-prime/CMakeFiles/bench_isprime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.o -MF CMakeFiles/bench_isprime.dir/run.cpp.o.d -o CMakeFiles/bench_isprime.dir/run.cpp.o -c /Users/ershoff/cpp-advenced/tasks/is-prime/run.cpp

tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bench_isprime.dir/run.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/is-prime/run.cpp > CMakeFiles/bench_isprime.dir/run.cpp.i

tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bench_isprime.dir/run.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/is-prime/run.cpp -o CMakeFiles/bench_isprime.dir/run.cpp.s

tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.o: tasks/is-prime/CMakeFiles/bench_isprime.dir/flags.make
tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.o: ../tasks/is-prime/is_prime.cpp
tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.o: tasks/is-prime/CMakeFiles/bench_isprime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.o -MF CMakeFiles/bench_isprime.dir/is_prime.cpp.o.d -o CMakeFiles/bench_isprime.dir/is_prime.cpp.o -c /Users/ershoff/cpp-advenced/tasks/is-prime/is_prime.cpp

tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bench_isprime.dir/is_prime.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/is-prime/is_prime.cpp > CMakeFiles/bench_isprime.dir/is_prime.cpp.i

tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bench_isprime.dir/is_prime.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/is-prime/is_prime.cpp -o CMakeFiles/bench_isprime.dir/is_prime.cpp.s

# Object files for target bench_isprime
bench_isprime_OBJECTS = \
"CMakeFiles/bench_isprime.dir/run.cpp.o" \
"CMakeFiles/bench_isprime.dir/is_prime.cpp.o"

# External object files for target bench_isprime
bench_isprime_EXTERNAL_OBJECTS =

bench_isprime: tasks/is-prime/CMakeFiles/bench_isprime.dir/run.cpp.o
bench_isprime: tasks/is-prime/CMakeFiles/bench_isprime.dir/is_prime.cpp.o
bench_isprime: tasks/is-prime/CMakeFiles/bench_isprime.dir/build.make
bench_isprime: libbenchmark.a
bench_isprime: tasks/is-prime/CMakeFiles/bench_isprime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bench_isprime"
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bench_isprime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/is-prime/CMakeFiles/bench_isprime.dir/build: bench_isprime
.PHONY : tasks/is-prime/CMakeFiles/bench_isprime.dir/build

tasks/is-prime/CMakeFiles/bench_isprime.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/tasks/is-prime && $(CMAKE_COMMAND) -P CMakeFiles/bench_isprime.dir/cmake_clean.cmake
.PHONY : tasks/is-prime/CMakeFiles/bench_isprime.dir/clean

tasks/is-prime/CMakeFiles/bench_isprime.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/tasks/is-prime /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/tasks/is-prime /Users/ershoff/cpp-advenced/build/tasks/is-prime/CMakeFiles/bench_isprime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/is-prime/CMakeFiles/bench_isprime.dir/depend
