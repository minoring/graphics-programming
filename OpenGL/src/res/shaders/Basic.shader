#shader vertex
#version 410

layout(location = 0) in vec4 position;

void main()
{
  gl_Position = position;
}

#shader fragment
#version 410

uniform vec4 u_Color;
layout(location = 0) out vec4 color;

void main()
{
  color = u_Color;
}
