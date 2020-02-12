#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
  unsigned int id = glCreateShader(type);
  const char *src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE) {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char *message = (char *)alloca(length * sizeof(char));
    glGetShaderInfoLog(id, length, &length, message);
    std::cout << "Falied to compie "
              << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
              << std::endl;
    std::cout << message << std::endl;
    glDeleteShader(id);
    return 0;
  }

  return id;
}

static unsigned int CreateShader(const std::string vertexShader,
                                 const std::string fragmentShader)
{
  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}

int main(void)
{
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK) {
    std::cout << "Error!" << std::endl;
  }

  std::cout << glGetString(GL_VERSION) << std::endl;

  float positions[6] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
  std::string vertexShader = 
  "#version 120\n"
  "attribute vec4 position;\n"
  "void main()"
  "{"
    "gl_Position = position;"
  "}";
  std::string fragmentShader = 
  "#version 120\n"
  "void main()"
  "{"
    "gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
  "}";

  unsigned int shader = CreateShader(vertexShader, fragmentShader);
  glUseProgram(shader);

  int positionLoc = glGetAttribLocation(shader, "position");
  glEnableVertexAttribArray(positionLoc);
  glVertexAttribPointer(positionLoc, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2,
                        (const void *)0);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glDeleteProgram(shader);

  glfwTerminate();
  return 0;
}
