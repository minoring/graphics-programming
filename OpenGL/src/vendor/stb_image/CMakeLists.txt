cmake_minimum_required(VERSION 3.10)

project(stb_image VERSION 0.1
                  LANGUAGES C CXX)

add_library(
    stb_image STATIC
    stb_image.cpp
)

target_include_directories(stb_image PUBLIC stb_image.h)
