cmake_minimum_required(VERSION 3.16)

project(sandbox LANGUAGES C CXX)

add_executable(sandbox
               src/SandboxApp.cpp)

target_include_directories(sandbox PUBLIC ${CMAKE_SOURCE_DIR}/Hazel)

target_link_libraries(sandbox PUBLIC
                      hazel)
