# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\clion\CLion 2016.3.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\clion\CLion 2016.3.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\algorithm_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\algorithm_practice\cmake-build-debug

# Include any dependencies generated for this target.
include assignment6/CMakeFiles/tesk6_2.dir/depend.make

# Include the progress variables for this target.
include assignment6/CMakeFiles/tesk6_2.dir/progress.make

# Include the compile flags for this target's objects.
include assignment6/CMakeFiles/tesk6_2.dir/flags.make

assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj: assignment6/CMakeFiles/tesk6_2.dir/flags.make
assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj: ../assignment6/listedWDigraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\algorithm_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment6 && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tesk6_2.dir\listedWDigraph.cpp.obj -c D:\github\algorithm_practice\assignment6\listedWDigraph.cpp

assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.i"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment6 && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\algorithm_practice\assignment6\listedWDigraph.cpp > CMakeFiles\tesk6_2.dir\listedWDigraph.cpp.i

assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.s"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment6 && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\algorithm_practice\assignment6\listedWDigraph.cpp -o CMakeFiles\tesk6_2.dir\listedWDigraph.cpp.s

assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.requires:

.PHONY : assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.requires

assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.provides: assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.requires
	$(MAKE) -f assignment6\CMakeFiles\tesk6_2.dir\build.make assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.provides.build
.PHONY : assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.provides

assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.provides.build: assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj


# Object files for target tesk6_2
tesk6_2_OBJECTS = \
"CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj"

# External object files for target tesk6_2
tesk6_2_EXTERNAL_OBJECTS =

assignment6/tesk6_2.exe: assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj
assignment6/tesk6_2.exe: assignment6/CMakeFiles/tesk6_2.dir/build.make
assignment6/tesk6_2.exe: assignment6/CMakeFiles/tesk6_2.dir/linklibs.rsp
assignment6/tesk6_2.exe: assignment6/CMakeFiles/tesk6_2.dir/objects1.rsp
assignment6/tesk6_2.exe: assignment6/CMakeFiles/tesk6_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\algorithm_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tesk6_2.exe"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment6 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tesk6_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assignment6/CMakeFiles/tesk6_2.dir/build: assignment6/tesk6_2.exe

.PHONY : assignment6/CMakeFiles/tesk6_2.dir/build

assignment6/CMakeFiles/tesk6_2.dir/requires: assignment6/CMakeFiles/tesk6_2.dir/listedWDigraph.cpp.obj.requires

.PHONY : assignment6/CMakeFiles/tesk6_2.dir/requires

assignment6/CMakeFiles/tesk6_2.dir/clean:
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment6 && $(CMAKE_COMMAND) -P CMakeFiles\tesk6_2.dir\cmake_clean.cmake
.PHONY : assignment6/CMakeFiles/tesk6_2.dir/clean

assignment6/CMakeFiles/tesk6_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\algorithm_practice D:\github\algorithm_practice\assignment6 D:\github\algorithm_practice\cmake-build-debug D:\github\algorithm_practice\cmake-build-debug\assignment6 D:\github\algorithm_practice\cmake-build-debug\assignment6\CMakeFiles\tesk6_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : assignment6/CMakeFiles/tesk6_2.dir/depend

