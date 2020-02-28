cmake_minimum_required(VERSION 3.10)

project(imgui LANGUAGES C CXX)

# set(GLFW_PATH ${CMAKE_SOURCE_DIR}/Dependencies/GLFW)
# set(GLEW_PATH ${CMAKE_SOURCE_DIR}/Dependencies/GLEW)

set(GLFW_PATH /usr/local)
set(GLEW_PATH /usr/local)

add_library(imgui STATIC
            imgui_draw.cpp
            imgui_impl_glfw_gl3.cpp
            imgui.cpp
            imgui_demo.cpp)

target_include_directories(imgui PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${GLEW_PATH}/include
    ${GLFW_PATH}/include)

if (APPLE)
target_compile_options(imgui PRIVATE -lglfw -lGLEW -framework OpenGL)

# target_link_libraries(imgui PRIVATE
                      # ${GLEW_PATH}/lib/libGLEW.a
                      # ${GLFW_PATH}/lib-macos/libglfw3.a)
endif()

target_include_directories(imgui PRIVATE
                           ${CMAKE_SOURCE_DIR}/include/imgui)
