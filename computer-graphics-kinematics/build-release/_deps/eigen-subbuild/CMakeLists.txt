# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(eigen-populate NONE)

include(ExternalProject)
ExternalProject_Add(eigen-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://gitlab.com/libeigen/eigen.git" "GIT_TAG" "tags/3.3.7" "GIT_SHALLOW" "TRUE"
                    SOURCE_DIR          "/home/kooresh/CSC317/computer-graphics-kinematics/build-release/_deps/eigen-src"
                    BINARY_DIR          "/home/kooresh/CSC317/computer-graphics-kinematics/build-release/_deps/eigen-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
