# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release

# Include any dependencies generated for this target.
include glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include glad/CMakeFiles/glad.dir/flags.make

glad/CMakeFiles/glad.dir/src/glad.c.o: glad/CMakeFiles/glad.dir/flags.make
glad/CMakeFiles/glad.dir/src/glad.c.o: ../libigl/external/glad/src/glad.c
glad/CMakeFiles/glad.dir/src/glad.c.o: glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glad/CMakeFiles/glad.dir/src/glad.c.o"
	cd /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glad/CMakeFiles/glad.dir/src/glad.c.o -MF CMakeFiles/glad.dir/src/glad.c.o.d -o CMakeFiles/glad.dir/src/glad.c.o -c /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/libigl/external/glad/src/glad.c

glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/libigl/external/glad/src/glad.c > CMakeFiles/glad.dir/src/glad.c.i

glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/libigl/external/glad/src/glad.c -o CMakeFiles/glad.dir/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

glad/libglad.a: glad/CMakeFiles/glad.dir/src/glad.c.o
glad/libglad.a: glad/CMakeFiles/glad.dir/build.make
glad/libglad.a: glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glad/CMakeFiles/glad.dir/build: glad/libglad.a
.PHONY : glad/CMakeFiles/glad.dir/build

glad/CMakeFiles/glad.dir/clean:
	cd /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : glad/CMakeFiles/glad.dir/clean

glad/CMakeFiles/glad.dir/depend:
	cd /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/libigl/external/glad /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad /Users/kooreshakhbari/Desktop/OSDB/CSC317/computer-graphics-mass-spring-systems/build-release/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glad/CMakeFiles/glad.dir/depend

