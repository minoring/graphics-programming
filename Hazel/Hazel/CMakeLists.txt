cmake_minimum_required(VERSION 3.10)

project(hazel LANGUAGES C CXX)

add_library(test SHARED
            src/Test.cpp)

target_include_directories(test PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/include)
