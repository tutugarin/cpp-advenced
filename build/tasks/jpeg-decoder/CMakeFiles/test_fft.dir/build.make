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
include tasks/jpeg-decoder/CMakeFiles/test_fft.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/jpeg-decoder/CMakeFiles/test_fft.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/jpeg-decoder/CMakeFiles/test_fft.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/jpeg-decoder/CMakeFiles/test_fft.dir/flags.make

tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o: tasks/jpeg-decoder/CMakeFiles/test_fft.dir/flags.make
tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o: ../tasks/jpeg-decoder/fftw/test_fft.cpp
tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o: tasks/jpeg-decoder/CMakeFiles/test_fft.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o"
	cd /Users/ershoff/cpp-advenced/build/tasks/jpeg-decoder && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o -MF CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o.d -o CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o -c /Users/ershoff/cpp-advenced/tasks/jpeg-decoder/fftw/test_fft.cpp

tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_fft.dir/fftw/test_fft.cpp.i"
	cd /Users/ershoff/cpp-advenced/build/tasks/jpeg-decoder && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ershoff/cpp-advenced/tasks/jpeg-decoder/fftw/test_fft.cpp > CMakeFiles/test_fft.dir/fftw/test_fft.cpp.i

tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_fft.dir/fftw/test_fft.cpp.s"
	cd /Users/ershoff/cpp-advenced/build/tasks/jpeg-decoder && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ershoff/cpp-advenced/tasks/jpeg-decoder/fftw/test_fft.cpp -o CMakeFiles/test_fft.dir/fftw/test_fft.cpp.s

# Object files for target test_fft
test_fft_OBJECTS = \
"CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o"

# External object files for target test_fft
test_fft_EXTERNAL_OBJECTS =

test_fft: tasks/jpeg-decoder/CMakeFiles/test_fft.dir/fftw/test_fft.cpp.o
test_fft: tasks/jpeg-decoder/CMakeFiles/test_fft.dir/build.make
test_fft: libcontrib_catch_main.a
test_fft: tasks/jpeg-decoder/libdecoder.a
test_fft: /opt/homebrew/lib/libfftw3.dylib
test_fft: /opt/homebrew/lib/libpng.dylib
test_fft: /opt/homebrew/lib/libjpeg.dylib
test_fft: glog/glog-build/libglog.a
test_fft: tasks/jpeg-decoder/CMakeFiles/test_fft.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ershoff/cpp-advenced/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../test_fft"
	cd /Users/ershoff/cpp-advenced/build/tasks/jpeg-decoder && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_fft.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/jpeg-decoder/CMakeFiles/test_fft.dir/build: test_fft
.PHONY : tasks/jpeg-decoder/CMakeFiles/test_fft.dir/build

tasks/jpeg-decoder/CMakeFiles/test_fft.dir/clean:
	cd /Users/ershoff/cpp-advenced/build/tasks/jpeg-decoder && $(CMAKE_COMMAND) -P CMakeFiles/test_fft.dir/cmake_clean.cmake
.PHONY : tasks/jpeg-decoder/CMakeFiles/test_fft.dir/clean

tasks/jpeg-decoder/CMakeFiles/test_fft.dir/depend:
	cd /Users/ershoff/cpp-advenced/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ershoff/cpp-advenced /Users/ershoff/cpp-advenced/tasks/jpeg-decoder /Users/ershoff/cpp-advenced/build /Users/ershoff/cpp-advenced/build/tasks/jpeg-decoder /Users/ershoff/cpp-advenced/build/tasks/jpeg-decoder/CMakeFiles/test_fft.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/jpeg-decoder/CMakeFiles/test_fft.dir/depend
