#pragma once

unsigned int CompileShader(unsigned int type, const std::string& source);

unsigned int CreateShader(const std::string& vertex_shader,
                          const std::string& fragment_shader);
