cmake_minimum_required(VERSION 3.10)

project(imgui VERSION 0.1
              LANGUAGES C CXX)

add_library(imgui STATIC
            imgui_draw.cpp
            imgui_impl_glfw_gl3.cpp
            imgui.cpp
            imgui_demo.cpp)
