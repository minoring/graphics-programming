#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
  GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
  GLCall(glDeleteVertexArrays(1, &m_Renderer_ID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
  vb.Bind();
  const auto& elements = layout.GetElements();

  for (unsigned int i = 0; i < elements.size(); ++i) {
    const auto& element = elements[i];
    GLCall(glEnableVertexArrtibArray(i));
    GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
    offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
  }
}

void VertexArray::Bind() const
{
  GLCall(glBindVertexAray(m_RendererID));
}

void VertexArray::Unbind() const
{
  GLCall(glBindVertexArray(0));
}