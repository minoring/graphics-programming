cmake_minimum_required(VERSION 3.10)

project(OpenGL VERSION 0.1
               DESCRIPTION "OpenGL project"
               LANGUAGES C CXX)

add_executable(app src/Application.cpp)

target_include_directories(app PUBLIC Dependencies/GLEW/include
                                      /usr/local/include)

target_link_libraries(app ${CMAKE_SOURCE_DIR}/Dependencies/GLEW/lib/libGLEW.a)
if(APPLE)
  target_link_libraries(app glfw "-framework OpenGL")
endif()
