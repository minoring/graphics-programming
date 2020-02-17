CC=g++ 
CFLAGS=-std=c++11
LDFLAGS=-lglfw -lGLEW -framework OpenGL
SOURCES=Application.cpp
OBJS=IndexBuffer.o VertexBuffer.o Renderer.o Shader.o
TARGET=app

all: $(TARGET)

$(TARGET): $(SOURCES) $(OBJS)
	$(CC) $(CFLAGS) $(SOURCES) $(OBJS) -o $@ $(LDFLAGS)

IndexBuffer.o: IndexBuffer.cpp IndexBuffer.h Renderer.o

VertexBuffer.o: VertexBuffer.cpp VertexBuffer.h Renderer.o

Shader.o: Shader.cpp Shader.h Renderer.o

Renderer.o: Renderer.cpp Renderer.h

clean:
	rm -f *.o
	rm -f $(TARGET)
