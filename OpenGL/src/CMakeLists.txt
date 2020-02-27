cmake_minimum_required(VERSION 3.10)

project(src VERSION 0.1
            LANGUAGES C CXX)

add_library(src
            Application.cpp
            IndexBuffer.cpp
            Renderer.cpp
            Shader.cpp
            Texture.cpp
            VertexArray.cpp
            VertexBuffer.cpp)

# set(CMAKE_STATIC_LINKER_FLAGS src -lglfw -lGLEW -framework OpenGL)


target_link_libraries(src PUBLIC tests stb_image imgui)

target_include_directories(src PUBLIC ${CMAKE_SOURCE_DIR}/include/
                                      ${CMAKE_SOURCE_DIR}/Dependencies/GLEW/include/
                                      ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include/)

add_subdirectory(tests)
add_subdirectory(vendor/stb_image)
add_subdirectory(vendor/imgui)

add_dependencies(stb_image tests)
add_dependencies(imgui tests)
