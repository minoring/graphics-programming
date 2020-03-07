cmake_minimum_required(VERSION 3.16)

project(hazel LANGUAGES C CXX)

if(APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")
endif(APPLE)

add_library(hazel SHARED
            src/Application.cpp
            src/Log.cpp
            src/Platform/Windows/WindowsWindow.cpp)

target_link_libraries(hazel PUBLIC
                      glfw)

target_include_directories(hazel PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR}/src
                           ${CMAKE_CURRENT_SOURCE_DIR}/Events)

target_precompile_headers(hazel PUBLIC 
                          src/hzpch.h)
