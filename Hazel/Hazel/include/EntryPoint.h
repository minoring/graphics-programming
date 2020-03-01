#pragma once

hazel::Application* hazel::CreateApplication();

int main(int argc, char** argv) {
  auto app = hazel::CreateApplication();
  app->Run();
  delete app;
}
