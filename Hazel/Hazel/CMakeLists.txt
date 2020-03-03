cmake_minimum_required(VERSION 3.10)

project(hazel LANGUAGES C CXX)

add_library(hazel SHARED
            src/Application.cpp
            src/Log.cpp)

target_include_directories(hazel PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           ${CMAKE_CURRENT_SOURCE_DIR}/Events)
