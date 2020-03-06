#pragma once

#include "Event.h"

namespace hazel {

class HAZEL_API WindowResizeEvent : public Event {
public:
  WindowResizeEvent(unsigned int width, unsigned int height)
      : m_Width(width), m_Height(height) {}
  inline unsigned int GetWidth() const { return m_Width; }
  inline unsigned int GetHeight() const { return m_Height; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
    return ss.str();
  }

  EVENT_CLASS_TYPE(WindowResize)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
  unsigned int m_Width;
  unsigned int m_Height;
};


class HAZEL_API WindowCloseEvent : public Event {
public:
  WindowCloseEvent() {}

  EVENT_CLASS_TYPE(WindowClose)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};


class HAZEL_API AppTickEvent : public Event {
public:
  AppTickEvent() {}

  EVENT_CLASS_TYPE(AppTick)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};


class HAZEL_API AppUpdateEvent : public Event {
public:
  AppUpdateEvent() {}

  EVENT_CLASS_TYPE(AppUpdate)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};


class HAZEL_API AppRenderEvent : public Event {
public:
  AppRenderEvent() {}

  EVENT_CLASS_TYPE(AppRender)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};


class HAZEL_API MouseButtonEvent : public Event {
public:
  inline int GetMouseButton() const { return m_Button; }

  EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

protected:
  MouseButtonEvent(int button) : m_Button(button) {}

  int m_Button;
};


class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent {
public:
  MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << m_Button;
    return ss.str();
  }

  EVENT_CLASS_TYPE(MouseButtonPressed)
};


class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent {
public:
  MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << m_Button;
    return ss.str();
  }

  EVENT_CLASS_TYPE(MouseButtonReleased)
};

} // namespace hazel
