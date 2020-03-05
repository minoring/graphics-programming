// https://en.wikipedia.org/wiki/Graham_scan
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <string>
#include "Shader.h"

struct Point {
  float x;
  float y;
};

Point g_min_point;

float CrossProduct(Point first, Point second, Point curr) {
  return (second.x - first.x) * (curr.y - second.y) -
         (second.y - first.y) * (curr.x - first.x);
}

bool ComparePointByAngle(const Point& lhs, const Point& rhs) {
  float cross_product = CrossProduct(g_min_point, lhs, rhs);
  if (cross_product == 0) return lhs.x < rhs.x;
  return cross_product > 0;
}

void InsertRandomPoints(std::vector<Point>* points, const int num_points) {
  std::default_random_engine generator;
  std::uniform_real_distribution<float> dist(-1.0, 1.0);

  for (int i = 0; i < num_points; ++i) {
    Point point;
    point.x = dist(generator);
    point.y = dist(generator);
    points->push_back(point);
    if (point.y < g_min_point.y) {
      g_min_point.y = point.y;
      g_min_point.x = point.x;
    }
  }
}

int main() {
  GLFWwindow* window;

  if (!glfwInit())
    return -1;
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  window = glfwCreateWindow(640, 480, "GrahamScan", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW error!" << std::endl;
    return -1;
  }
  
  std::cout << glGetString(GL_VERSION) << std::endl;

  const int kNumPoints = 3;
  std::vector<Point> points;
  points.reserve(kNumPoints);

  g_min_point.x = std::numeric_limits<float>::max();
  g_min_point.y = std::numeric_limits<float>::max();
  InsertRandomPoints(&points, kNumPoints);

  sort(points.begin(), points.end(), ComparePointByAngle);

  for (int i = 0; i < points.size(); ++i) {
    std::cout << points[i].x << ' ' << points[i].y << '\n';
  }

  unsigned int vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(float) * 2,
      points.data(), GL_STATIC_DRAW);

  const std::string vertex_shader = 
  "#version 410\n"
  "layout (location = 0) in vec4 position;\n"
  "void main()"
  "{"
  "  gl_Position = position;"
  "}";

  const std::string fragment_shader =
  "#version 410\n"
  "layout(location = 0) out vec4 color;"
  "void main()"
  "{"
  "  color = vec4(0.0f, 1.0f, 0.0f, 1.0f);"
  "}";

  unsigned int shader = CreateShader(vertex_shader, fragment_shader);
  glUseProgram(shader);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)(0));

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, points.size());
    glfwSwapBuffers(window);

    glfwPollEvents();
  }
  glDeleteProgram(shader);

  glfwTerminate();

  // for (int i = 0; i < kNumPoints; ++i) {
  //   std::cout << points[i].y << points[i].x << std::endl;
  // }
}
