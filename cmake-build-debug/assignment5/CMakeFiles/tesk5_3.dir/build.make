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
include assignment5/CMakeFiles/tesk5_3.dir/depend.make

# Include the progress variables for this target.
include assignment5/CMakeFiles/tesk5_3.dir/progress.make

# Include the compile flags for this target's objects.
include assignment5/CMakeFiles/tesk5_3.dir/flags.make

assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj: assignment5/CMakeFiles/tesk5_3.dir/flags.make
assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj: ../assignment5/winner_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\algorithm_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment5 && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tesk5_3.dir\winner_tree.cpp.obj -c D:\github\algorithm_practice\assignment5\winner_tree.cpp

assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tesk5_3.dir/winner_tree.cpp.i"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment5 && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\algorithm_practice\assignment5\winner_tree.cpp > CMakeFiles\tesk5_3.dir\winner_tree.cpp.i

assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tesk5_3.dir/winner_tree.cpp.s"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment5 && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\algorithm_practice\assignment5\winner_tree.cpp -o CMakeFiles\tesk5_3.dir\winner_tree.cpp.s

assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.requires:

.PHONY : assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.requires

assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.provides: assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.requires
	$(MAKE) -f assignment5\CMakeFiles\tesk5_3.dir\build.make assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.provides.build
.PHONY : assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.provides

assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.provides.build: assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj


# Object files for target tesk5_3
tesk5_3_OBJECTS = \
"CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj"

# External object files for target tesk5_3
tesk5_3_EXTERNAL_OBJECTS =

assignment5/tesk5_3.exe: assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj
assignment5/tesk5_3.exe: assignment5/CMakeFiles/tesk5_3.dir/build.make
assignment5/tesk5_3.exe: assignment5/CMakeFiles/tesk5_3.dir/linklibs.rsp
assignment5/tesk5_3.exe: assignment5/CMakeFiles/tesk5_3.dir/objects1.rsp
assignment5/tesk5_3.exe: assignment5/CMakeFiles/tesk5_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\algorithm_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tesk5_3.exe"
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment5 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tesk5_3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
assignment5/CMakeFiles/tesk5_3.dir/build: assignment5/tesk5_3.exe

.PHONY : assignment5/CMakeFiles/tesk5_3.dir/build

assignment5/CMakeFiles/tesk5_3.dir/requires: assignment5/CMakeFiles/tesk5_3.dir/winner_tree.cpp.obj.requires

.PHONY : assignment5/CMakeFiles/tesk5_3.dir/requires

assignment5/CMakeFiles/tesk5_3.dir/clean:
	cd /d D:\github\algorithm_practice\cmake-build-debug\assignment5 && $(CMAKE_COMMAND) -P CMakeFiles\tesk5_3.dir\cmake_clean.cmake
.PHONY : assignment5/CMakeFiles/tesk5_3.dir/clean

assignment5/CMakeFiles/tesk5_3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\algorithm_practice D:\github\algorithm_practice\assignment5 D:\github\algorithm_practice\cmake-build-debug D:\github\algorithm_practice\cmake-build-debug\assignment5 D:\github\algorithm_practice\cmake-build-debug\assignment5\CMakeFiles\tesk5_3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : assignment5/CMakeFiles/tesk5_3.dir/depend

