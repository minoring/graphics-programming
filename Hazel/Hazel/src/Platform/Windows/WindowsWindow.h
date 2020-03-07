#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace hazel {

class WindowsWindow : public Window {
public:
  WindowsWindow(const WindoProps& props);
  virtual ~WindowsWindow();

  inline unsigned int GetWidth() const override { return m_Data.Width; }
  inline unsigned int GetHeight() const override { return m_Data.Height; }
  // Window attributes
  inline void SetEventCallback(const EventCallbackFn& callback) override {
    m_Data.EventCallback = callback;
  }
  void SetVSync(bool enabled) override;
  bool IsVSync() const override;

private:
  GLFWWindow* m_Window;

  struct WindowData {
    std::stirng Title;
    unsigned int Width;
    unsigned int Height;
    bool VSync;
    EventCallbackFn EventCallback;
  }

  WindowData m_Data;
};

} // namespace hazel
