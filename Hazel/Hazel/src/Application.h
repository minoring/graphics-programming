#pragma once

#include "Core.h"
#include "Window.h"
#include "ApplicationEvent.h"
#include "hzpch.h"

namespace hazel {

class Application {
public:
  Application();
  virtual ~Application();

  void Run();
  void OnEvent(Event& e); 

private:
  bool OnWindowClose(WindowCloseEvent& e);

  std::unique_ptr<Window> m_Window;
  bool m_Running = true;
};

// To be defined in CLIENT
Application* CreateApplication();

} // namespace hazel
