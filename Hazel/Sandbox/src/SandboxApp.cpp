#include <Hazel.h>

class Sandbox : public hazel::Application {
public:
  Sandbox() {}
  ~Sandbox() {}
};

hazel::Application* hazel::CreateApplication() {
  return new Sandbox();
}
