#pragma once

#include "Core.h"

hazel::Application* hazel::CreateApplication();

int main(int argc, char** argv) {
  hazel::Log::Init();
  HZ_CORE_WARN("Initialized Log!");
  int a = 5;
  HZ_INFO("Hello Var={0}!", a);

  auto app = hazel::CreateApplication();
  app->Run();
  delete app;
}
