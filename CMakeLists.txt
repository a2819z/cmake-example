# CMake version
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

# Declare project
project(MINI_RPG)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

configure_file(config.h.in include/config.h @ONLY)

# Set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Set enable output of compile commands during generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Includes
include_directories(include)
include_directories(lib)

# Compile options
include(cmake/CompileOptions.cmake)

option(BUILD_EXTENSIONS "Build extensions" OFF)

# Build type - Release by default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set resources
#set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Resources)

# Project modules
add_subdirectory(src)

if(BUILD_EXTENSIONS)
    add_subdirectory(extensions)
endif()
