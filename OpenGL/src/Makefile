CXX=g++
CC=g++
CXXFLAGS=-g -Wall -MMD -std=c++11
LDFLAGS=-lglfw -lGLEW -framework OpenGL
SOURCES=Application.cpp
OBJS=IndexBuffer.o VertexBuffer.o Renderer.o VertexArray.o Shader.o Texture.o vendor/stb_image/stb_image.o
TARGET=app

all: $(TARGET)

$(TARGET): $(SOURCES) $(OBJS)
	$(CC) $(CXXFLAGS) $(SOURCES) $(OBJS) -o $@ $(LDFLAGS)

IndexBuffer.o: IndexBuffer.cpp IndexBuffer.h Renderer.o

VertexBuffer.o: VertexBuffer.cpp VertexBuffer.h Renderer.o

Shader.o: Shader.cpp Shader.h Renderer.o

VertexArray.o: VertexArray.h VertexArray.cpp VertexBufferLayout.h Renderer.o VertexBuffer.o

Renderer.o: Renderer.cpp Renderer.h

Texture.o: Texture.cpp Texture.h

stb_image.o: vendor/stb_image/stb_image.h vendor/stb_image/stb_image.cpp

clean:
	rm -f *.o
	rm -f *.d
	rm -rf *.gch
	rm -f $(TARGET)
