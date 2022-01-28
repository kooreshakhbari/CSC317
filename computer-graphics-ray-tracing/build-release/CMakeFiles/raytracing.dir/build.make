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
CMAKE_SOURCE_DIR = /home/kooresh/CSC317/computer-graphics-ray-tracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kooresh/CSC317/computer-graphics-ray-tracing/build-release

# Include any dependencies generated for this target.
include CMakeFiles/raytracing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracing.dir/flags.make

CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.o: CMakeFiles/raytracing.dir/flags.make
CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.o: ../src/DirectionalLight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.o -c /home/kooresh/CSC317/computer-graphics-ray-tracing/src/DirectionalLight.cpp

CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kooresh/CSC317/computer-graphics-ray-tracing/src/DirectionalLight.cpp > CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.i

CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kooresh/CSC317/computer-graphics-ray-tracing/src/DirectionalLight.cpp -o CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.s

CMakeFiles/raytracing.dir/src/PointLight.cpp.o: CMakeFiles/raytracing.dir/flags.make
CMakeFiles/raytracing.dir/src/PointLight.cpp.o: ../src/PointLight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raytracing.dir/src/PointLight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/src/PointLight.cpp.o -c /home/kooresh/CSC317/computer-graphics-ray-tracing/src/PointLight.cpp

CMakeFiles/raytracing.dir/src/PointLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/src/PointLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kooresh/CSC317/computer-graphics-ray-tracing/src/PointLight.cpp > CMakeFiles/raytracing.dir/src/PointLight.cpp.i

CMakeFiles/raytracing.dir/src/PointLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/src/PointLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kooresh/CSC317/computer-graphics-ray-tracing/src/PointLight.cpp -o CMakeFiles/raytracing.dir/src/PointLight.cpp.s

CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.o: CMakeFiles/raytracing.dir/flags.make
CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.o: ../src/blinn_phong_shading.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.o -c /home/kooresh/CSC317/computer-graphics-ray-tracing/src/blinn_phong_shading.cpp

CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kooresh/CSC317/computer-graphics-ray-tracing/src/blinn_phong_shading.cpp > CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.i

CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kooresh/CSC317/computer-graphics-ray-tracing/src/blinn_phong_shading.cpp -o CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.s

CMakeFiles/raytracing.dir/src/raycolor.cpp.o: CMakeFiles/raytracing.dir/flags.make
CMakeFiles/raytracing.dir/src/raycolor.cpp.o: ../src/raycolor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/raytracing.dir/src/raycolor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/src/raycolor.cpp.o -c /home/kooresh/CSC317/computer-graphics-ray-tracing/src/raycolor.cpp

CMakeFiles/raytracing.dir/src/raycolor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/src/raycolor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kooresh/CSC317/computer-graphics-ray-tracing/src/raycolor.cpp > CMakeFiles/raytracing.dir/src/raycolor.cpp.i

CMakeFiles/raytracing.dir/src/raycolor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/src/raycolor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kooresh/CSC317/computer-graphics-ray-tracing/src/raycolor.cpp -o CMakeFiles/raytracing.dir/src/raycolor.cpp.s

CMakeFiles/raytracing.dir/src/reflect.cpp.o: CMakeFiles/raytracing.dir/flags.make
CMakeFiles/raytracing.dir/src/reflect.cpp.o: ../src/reflect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/raytracing.dir/src/reflect.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/src/reflect.cpp.o -c /home/kooresh/CSC317/computer-graphics-ray-tracing/src/reflect.cpp

CMakeFiles/raytracing.dir/src/reflect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/src/reflect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kooresh/CSC317/computer-graphics-ray-tracing/src/reflect.cpp > CMakeFiles/raytracing.dir/src/reflect.cpp.i

CMakeFiles/raytracing.dir/src/reflect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/src/reflect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kooresh/CSC317/computer-graphics-ray-tracing/src/reflect.cpp -o CMakeFiles/raytracing.dir/src/reflect.cpp.s

CMakeFiles/raytracing.dir/main.cpp.o: CMakeFiles/raytracing.dir/flags.make
CMakeFiles/raytracing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/raytracing.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracing.dir/main.cpp.o -c /home/kooresh/CSC317/computer-graphics-ray-tracing/main.cpp

CMakeFiles/raytracing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracing.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kooresh/CSC317/computer-graphics-ray-tracing/main.cpp > CMakeFiles/raytracing.dir/main.cpp.i

CMakeFiles/raytracing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracing.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kooresh/CSC317/computer-graphics-ray-tracing/main.cpp -o CMakeFiles/raytracing.dir/main.cpp.s

# Object files for target raytracing
raytracing_OBJECTS = \
"CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.o" \
"CMakeFiles/raytracing.dir/src/PointLight.cpp.o" \
"CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.o" \
"CMakeFiles/raytracing.dir/src/raycolor.cpp.o" \
"CMakeFiles/raytracing.dir/src/reflect.cpp.o" \
"CMakeFiles/raytracing.dir/main.cpp.o"

# External object files for target raytracing
raytracing_EXTERNAL_OBJECTS =

raytracing: CMakeFiles/raytracing.dir/src/DirectionalLight.cpp.o
raytracing: CMakeFiles/raytracing.dir/src/PointLight.cpp.o
raytracing: CMakeFiles/raytracing.dir/src/blinn_phong_shading.cpp.o
raytracing: CMakeFiles/raytracing.dir/src/raycolor.cpp.o
raytracing: CMakeFiles/raytracing.dir/src/reflect.cpp.o
raytracing: CMakeFiles/raytracing.dir/main.cpp.o
raytracing: CMakeFiles/raytracing.dir/build.make
raytracing: libhw2.a
raytracing: CMakeFiles/raytracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable raytracing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracing.dir/build: raytracing

.PHONY : CMakeFiles/raytracing.dir/build

CMakeFiles/raytracing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracing.dir/clean

CMakeFiles/raytracing.dir/depend:
	cd /home/kooresh/CSC317/computer-graphics-ray-tracing/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kooresh/CSC317/computer-graphics-ray-tracing /home/kooresh/CSC317/computer-graphics-ray-tracing /home/kooresh/CSC317/computer-graphics-ray-tracing/build-release /home/kooresh/CSC317/computer-graphics-ray-tracing/build-release /home/kooresh/CSC317/computer-graphics-ray-tracing/build-release/CMakeFiles/raytracing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/raytracing.dir/depend

