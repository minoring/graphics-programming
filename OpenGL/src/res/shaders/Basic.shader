#shader vertex
#version 410

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_Texcoord;

void main()
{
  gl_Position = position;
  v_Texcoord = texCoord;
}

#shader fragment
#version 410

layout(location = 0) out vec4 color;

in vec2 v_Texcoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
  vec4 texColor = texture(u_Texture,  v_Texcoord);
  color = u_Color;
  color = texColor;
}
