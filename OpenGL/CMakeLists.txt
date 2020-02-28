cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

project(OpenGL VERSION 0.1
               DESCRIPTION "OpenGL project"
               LANGUAGES C CXX)

add_subdirectory(src)

# set_target_properties(app PROPERTIES LINKER_LANGUAGE CXX)
