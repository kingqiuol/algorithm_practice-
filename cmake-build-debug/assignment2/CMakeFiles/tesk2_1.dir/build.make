# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/jinqiu/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/jinqiu/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug

# Include any dependencies generated for this target.
include assignment2/CMakeFiles/tesk2_1.dir/depend.make

# Include the progress variables for this target.
include assignment2/CMakeFiles/tesk2_1.dir/progress.make

# Include the compile flags for this target's objects.
include assignment2/CMakeFiles/tesk2_1.dir/flags.make

assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o: assignment2/CMakeFiles/tesk2_1.dir/flags.make
assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o: ../assignment2/stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o"
	cd /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment2 && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tesk2_1.dir/stack.cpp.o -c /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/assignment2/stack.cpp

assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tesk2_1.dir/stack.cpp.i"
	cd /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment2 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/assignment2/stack.cpp > CMakeFiles/tesk2_1.dir/stack.cpp.i

assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tesk2_1.dir/stack.cpp.s"
	cd /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment2 && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/assignment2/stack.cpp -o CMakeFiles/tesk2_1.dir/stack.cpp.s

assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.requires:

.PHONY : assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.requires

assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.provides: assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.requires
	$(MAKE) -f assignment2/CMakeFiles/tesk2_1.dir/build.make assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.provides.build
.PHONY : assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.provides

assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.provides.build: assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o


# Object files for target tesk2_1
tesk2_1_OBJECTS = \
"CMakeFiles/tesk2_1.dir/stack.cpp.o"

# External object files for target tesk2_1
tesk2_1_EXTERNAL_OBJECTS =

assignment2/tesk2_1.exe: assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o
assignment2/tesk2_1.exe: assignment2/CMakeFiles/tesk2_1.dir/build.make
assignment2/tesk2_1.exe: assignment2/CMakeFiles/tesk2_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tesk2_1.exe"
	cd /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tesk2_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assignment2/CMakeFiles/tesk2_1.dir/build: assignment2/tesk2_1.exe

.PHONY : assignment2/CMakeFiles/tesk2_1.dir/build

assignment2/CMakeFiles/tesk2_1.dir/requires: assignment2/CMakeFiles/tesk2_1.dir/stack.cpp.o.requires

.PHONY : assignment2/CMakeFiles/tesk2_1.dir/requires

assignment2/CMakeFiles/tesk2_1.dir/clean:
	cd /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment2 && $(CMAKE_COMMAND) -P CMakeFiles/tesk2_1.dir/cmake_clean.cmake
.PHONY : assignment2/CMakeFiles/tesk2_1.dir/clean

assignment2/CMakeFiles/tesk2_1.dir/depend:
	cd /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/assignment2 /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment2 /cygdrive/c/Users/jinqiu/Desktop/algorithm_practice/cmake-build-debug/assignment2/CMakeFiles/tesk2_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : assignment2/CMakeFiles/tesk2_1.dir/depend

