# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/build_release

# Include any dependencies generated for this target.
include CMakeFiles/rays.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rays.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rays.dir/flags.make

CMakeFiles/rays.dir/rays.cpp.o: CMakeFiles/rays.dir/flags.make
CMakeFiles/rays.dir/rays.cpp.o: ../rays.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rays.dir/rays.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rays.dir/rays.cpp.o -c /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/rays.cpp

CMakeFiles/rays.dir/rays.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rays.dir/rays.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/rays.cpp > CMakeFiles/rays.dir/rays.cpp.i

CMakeFiles/rays.dir/rays.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rays.dir/rays.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/rays.cpp -o CMakeFiles/rays.dir/rays.cpp.s

# Object files for target rays
rays_OBJECTS = \
"CMakeFiles/rays.dir/rays.cpp.o"

# External object files for target rays
rays_EXTERNAL_OBJECTS =

rays: CMakeFiles/rays.dir/rays.cpp.o
rays: CMakeFiles/rays.dir/build.make
rays: libcore.a
rays: /usr/lib/x86_64-linux-gnu/libOpenGL.so
rays: glad/libglad.a
rays: glfw/src/libglfw3.a
rays: /usr/lib/x86_64-linux-gnu/librt.so
rays: /usr/lib/x86_64-linux-gnu/libm.so
rays: CMakeFiles/rays.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/build_release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rays"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rays.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rays.dir/build: rays

.PHONY : CMakeFiles/rays.dir/build

CMakeFiles/rays.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rays.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rays.dir/clean

CMakeFiles/rays.dir/depend:
	cd /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/build_release /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/build_release /home/kooresh/CSC317/computer-graphics-bounding-volume-hierarchy/build_release/CMakeFiles/rays.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rays.dir/depend

