cmake_minimum_required(VERSION 3.10)

project(app LANGUAGES C CXX)

set(GLFW_PATH ${CMAKE_SOURCE_DIR}/Dependencies/GLFW)
set(GLEW_PATH ${CMAKE_SOURCE_DIR}/Dependencies/GLEW)

add_executable(app
               Application.cpp
               IndexBuffer.cpp
               Renderer.cpp
               Shader.cpp
               Texture.cpp
               VertexArray.cpp
               VertexBuffer.cpp)

target_include_directories(app PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${GLEW_PATH}/include
    ${GLFW_PATH}/include)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lglfw -lGLEW -framework OpenGL")

target_link_libraries(app PUBLIC 
    tests
    stb_image
    imgui
    ${GLEW_PATH}/lib/libGLEW.a
    ${GLFW_PATH}/lib-macos/libglfw3.a)

add_subdirectory(tests)
add_subdirectory(imgui)
add_subdirectory(stb_image)

add_dependencies(stb_image tests)
add_dependencies(imgui tests)
