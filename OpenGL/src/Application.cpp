#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"
#include "tests/Test.h"
#include "tests/TestClearColor.h"

int main(void)
{
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;

  // Define version and compatibility settings
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  GLCall(glfwMakeContextCurrent(window));

  glfwSwapInterval(1);

  if (glewInit() != GLEW_OK)
    std::cout << "Error!" << std::endl;

  std::cout << glGetString(GL_VERSION) << std::endl;

  float positions[] = {
       -50.f,  -50.f, 0.0f, 0.0f, // 0
        50.f,  -50.f, 1.0f, 0.0f, // 1
        50.f,   50.f, 1.0f, 1.0f, // 2
       -50.f,   50.f, 0.0f, 1.0f, // 3
  };
  unsigned int indices[] = {0, 1, 2, 2, 3, 0};

  GLCall(glEnable(GL_BLEND));
  GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

  glm::mat4 proj = glm::ortho(0.f, 960.f, 0.f, 540.f, -1.0f, 1.0f);
  glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, 0.f));

  VertexBuffer vb(positions, 4 * 4 * sizeof(float));
  vb.Bind();
  IndexBuffer ib(indices, 6);
  ib.Bind();
  Shader shader("res/shaders/Basic.shader");
  shader.Bind();

  Texture texture("res/textures/cat.jpeg");
  texture.Bind();
  shader.SetUniform1i("u_Texture", 0);

  VertexArray va;
  va.Bind();
  VertexBufferLayout layout;
  layout.Push<float>(2);
  layout.Push<float>(2);
  va.AddBuffer(vb, layout);

  shader.Unbind();
  ib.Unbind();
  va.Unbind();
  vb.Unbind();

  Renderer renderer;

  ImGui::CreateContext();
  ImGui_ImplGlfwGL3_Init(window, true);
  ImGui::StyleColorsDark();

  glm::vec3 translation_a(200.f, 200.f, 0.0f);
  glm::vec3 translation_b(400.f, 200.f, 0.0f);

  float r = 0.0f;
  float increment = 0.05f;

  test::Test* currentTest = nullptr;
  test::TestMenu* testMenu = new test::TestMenu(currentTest);
  currentTest = testMenu;

  testMenu->RegisterTest<test::TestClearColor>("Clear Color");

  while (!glfwWindowShouldClose(window)) {
    GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
    renderer.Clear();

    ImGui_ImplGlfwGL3_NewFrame();
    if (currentTest) {
      currentTest->OnUpdate(0.0f);
      currentTest->OnRender();

      ImGui::Begin("Test");
      if (currentTest != testMenu && ImGui::Button("<-")) {
        delete currentTest;
        currentTest = testMenu;
      }
      currentTest->OnImGuiRender();
      ImGui::End();
    }

    ImGui::Render();
    ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
