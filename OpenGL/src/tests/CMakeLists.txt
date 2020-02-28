cmake_minimum_required(VERSION 3.10)

project(tests VERSION 0.1
        LANGUAGES C CXX)

add_library(tests STATIC 
            Test.cpp
            TestClearColor.cpp 
            TestTexture2D.cpp)

target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/include
                                        ${CMAKE_SOURCE_DIR}/Dependencies/GLEW/include
                                        ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include)
