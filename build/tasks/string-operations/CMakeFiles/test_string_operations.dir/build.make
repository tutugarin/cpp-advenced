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
include tasks/string-operations/CMakeFiles/test_string_operations.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/string-operations/CMakeFiles/test_string_operations.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/string-operations/CMakeFiles/test_string_operations.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/string-operations/CMakeFiles/test_string_operations.dir/flags.make

tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o: tasks/string-operations/CMakeFiles/test_string_operations.dir/flags.make
tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o: ../tasks/string-operations/string_operations.cpp
tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o: tasks/string-operations/CMakeFiles/test_string_operations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o -MF CMakeFiles/test_string_operations.dir/string_operations.cpp.o.d -o CMakeFiles/test_string_operations.dir/string_operations.cpp.o -c /Users/ershoff/cpp-advenced/tasks/string-operations/string_operations.cpp

tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_string_operations.dir/string_operations.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/string-operations/string_operations.cpp > CMakeFiles/test_string_operations.dir/string_operations.cpp.i

tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_string_operations.dir/string_operations.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/string-operations/string_operations.cpp -o CMakeFiles/test_string_operations.dir/string_operations.cpp.s

tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o: tasks/string-operations/CMakeFiles/test_string_operations.dir/flags.make
tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o: ../tasks/string-operations/string_operations_test.cpp
tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o: tasks/string-operations/CMakeFiles/test_string_operations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o -MF CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o.d -o CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o -c /Users/ershoff/cpp-advenced/tasks/string-operations/string_operations_test.cpp

tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_string_operations.dir/string_operations_test.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/string-operations/string_operations_test.cpp > CMakeFiles/test_string_operations.dir/string_operations_test.cpp.i

tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_string_operations.dir/string_operations_test.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/string-operations/string_operations_test.cpp -o CMakeFiles/test_string_operations.dir/string_operations_test.cpp.s

# Object files for target test_string_operations
test_string_operations_OBJECTS = \
"CMakeFiles/test_string_operations.dir/string_operations.cpp.o" \
"CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o"

# External object files for target test_string_operations
test_string_operations_EXTERNAL_OBJECTS =

test_string_operations: tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations.cpp.o
test_string_operations: tasks/string-operations/CMakeFiles/test_string_operations.dir/string_operations_test.cpp.o
test_string_operations: tasks/string-operations/CMakeFiles/test_string_operations.dir/build.make
test_string_operations: libcontrib_catch_main.a
test_string_operations: tasks/string-operations/CMakeFiles/test_string_operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../test_string_operations"
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_string_operations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/string-operations/CMakeFiles/test_string_operations.dir/build: test_string_operations
.PHONY : tasks/string-operations/CMakeFiles/test_string_operations.dir/build

tasks/string-operations/CMakeFiles/test_string_operations.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/tasks/string-operations && $(CMAKE_COMMAND) -P CMakeFiles/test_string_operations.dir/cmake_clean.cmake
.PHONY : tasks/string-operations/CMakeFiles/test_string_operations.dir/clean

tasks/string-operations/CMakeFiles/test_string_operations.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/tasks/string-operations /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/tasks/string-operations /Users/ershoff/cpp-advenced/build/tasks/string-operations/CMakeFiles/test_string_operations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/string-operations/CMakeFiles/test_string_operations.dir/depend
