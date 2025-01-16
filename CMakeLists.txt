# The first line of any CMake project should be a call to `cmake_minimum_required`, which checks
# that the installed CMake will be able to understand the following CMakeLists, and ensures that
# CMake's behaviour is compatible with the named version. This is a standard CMake command, so more
# information can be found in the CMake docs.

cmake_minimum_required(VERSION 3.22)

project(neural-plugin VERSION 0.0.1)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# Include the CPM: Cmake dependancy manager.
include (cmake/cpm.cmake)

# Add and configure JUCE.
CPMAddPackage(
    NAME JUCE
    GIT_TAG 8.0.4
    VERSION 8.0.4
    GITHUB_REPOSITORY juce-framework/JUCE
    SOURCE_DIR ${LIB_DIR}/juce
)

# Add and configure RTNeural.
CPMAddPackage(
    NAME RTNeural
    GITHUB_REPOSITORY jatinchowdhury18/RTNeural
    GIT_TAG main
    SOURCE_DIR ${LIB_DIR}/RTNeural
)

include_directories("${LIB_DIR}/RTNeural")

add_subdirectory(src)

