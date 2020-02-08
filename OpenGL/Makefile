CC=g++ 
CFLAGS=-std=c++11
LDFLAGS=-lglfw -lGLEW -framework OpenGL
HEADERS=/usr/local/include
SOURCES=src/Application.cpp
OBJS=
TARGET=app

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS) $(OBJS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LDFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGET)
