#pragma once

#include "Test.h"
#include "Texture.h"

#include <memory>

namespace test {

class TestTexture2D : public Test {
public:
  TestTexture2D();
  ~TestTexture2D();

  void OnUpdate(float deltatime) override;
  void OnRender() override;
  void OnImGuiRender() override;

private:
  glm::vec3 m_Translation_a;
  glm::vec3 m_Translation_b;
  std::unique_ptr<VertexArray> m_VAO;
  std::unique_ptr<IndexBuffer> m_IndexBuffer;
  std::unique_ptr<Shader> m_Shader;
  std::unique_ptr<Texture> m_Texture;
  std::unique_ptr<VertexBuffer> m_VertexBuffer;
  glm::mat4 m_Proj, m_View;
};

}  // namespace test