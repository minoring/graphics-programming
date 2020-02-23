#include "TestTexture2D.h"
#include "../vendor/imgui/imgui.h"
#include "../Renderer.h"

#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"

#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"

#include "../VertexBuffer.h"
#include "../VertexBufferLayout.h"
#include "../VertexArray.h"
#include "../Renderer.h"

namespace test {

TestTexture2D::TestTexture2D() 
    : m_Proj(glm::ortho(0.f, 960.f, 0.f, 540.f, -1.0f, 1.0f)),
      m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, 0.f))),
      m_Translation_a(200.f, 200.f, 0.0f),
      m_Translation_b(400.f, 200.f, 0.0f) {
  float positions[] = {
       -50.f,  -50.f, 0.0f, 0.0f, // 0
        50.f,  -50.f, 1.0f, 0.0f, // 1
        50.f,   50.f, 1.0f, 1.0f, // 2
       -50.f,   50.f, 0.0f, 1.0f, // 3
  };
  unsigned int indices[] = {0, 1, 2, 2, 3, 0};

  GLCall(glEnable(GL_BLEND));
  GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

  m_VertexBuffer = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));
  m_VertexBuffer->Bind();
  VertexBufferLayout layout;
  layout.Push<float>(2);
  layout.Push<float>(2);
  m_VAO = std::make_unique<VertexArray>();
  m_VAO->Bind();
  m_VAO->AddBuffer(*m_VertexBuffer, layout);

  m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6);
  m_IndexBuffer->Bind();

  m_Shader = std::make_unique<Shader>("res/shaders/Basic.shader");
  m_Shader->Bind();
  m_Shader->SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
  m_Shader->SetUniform1i("u_Texture", 0);

  m_Texture = std::make_unique<Texture>("res/textures/Cat.png");
}

TestTexture2D::~TestTexture2D() {}

void TestTexture2D::OnUpdate(float deltatime) {}

void TestTexture2D::OnRender()
{
  GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
  GLCall(glClear(GL_COLOR_BUFFER_BIT));

  Renderer renderer;

  m_Texture->Bind();
  {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), m_Translation_a);
    glm::mat4 mvp = m_Proj * m_View * model;
    m_Shader->Bind();
    m_Shader->SetUniformMat4f("u_MVP", mvp);
    renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
  }

  {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), m_Translation_b);
    glm::mat4 mvp = m_Proj * m_View * model;
    m_Shader->Bind();
    m_Shader->SetUniformMat4f("u_MVP", mvp);
    renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
  }
}

void TestTexture2D::OnImGuiRender() {
  ImGui::SliderFloat3("Translation A", &m_Translation_a.x, 0.0f, 960.0f);
  ImGui::SliderFloat3("Translation B", &m_Translation_b.x, 0.0f, 960.0f);
  ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 
      1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

}  // namespace test