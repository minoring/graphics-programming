cmake_minimum_required(VERSION 3.13)

project(app LANGUAGES C CXX)

# set(GLFW_PATH ${CMAKE_SOURCE_DIR}/Dependencies/GLFW)
# set(GLEW_PATH ${CMAKE_SOURCE_DIR}/Dependencies/GLEW)

set(GLFW_PATH /usr/local)
set(GLEW_PATH /usr/local)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lglfw -lGLEW -framework OpenGL")

add_executable(app
               Application.cpp
               IndexBuffer.cpp
               Renderer.cpp
               Shader.cpp
               Texture.cpp
               VertexArray.cpp
               VertexBuffer.cpp)

target_compile_options(app PRIVATE -lglfw -lGLEW -framework OpenGL)

target_include_directories(app PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${GLEW_PATH}/include
    ${GLFW_PATH}/include)

target_link_libraries(app PUBLIC 
    tests
    stb_image
    imgui)
    # ${GLEW_PATH}/lib/libGLEW.a
    # ${GLFW_PATH}/lib-macos/libglfw3.a)

add_subdirectory(tests)
add_subdirectory(imgui)
add_subdirectory(stb_image)

add_dependencies(stb_image tests)
add_dependencies(imgui tests)
