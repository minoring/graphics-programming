cmake_minimum_required(VERSION 3.16)

project(hazel-project LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(Hazel/vendor/spdlog/include)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug)
    add_definitions(-DHZ_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DHZ_RELEASE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release)
endif()

add_subdirectory(Hazel)
add_subdirectory(Sandbox)
