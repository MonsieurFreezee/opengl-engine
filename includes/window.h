#pragma once

#include <GLFW/glfw3.h>
#include <string>

class Window
{
private:
    GLFWwindow* m_window;

    GLFWwindow* create_window(uint16_t width, uint16_t height, const std::string &title) const;

public:
    Window(uint16_t width, uint16_t height, const std::string &title);
    ~Window();

    const GLFWwindow& get_window() const;

    void set_key_callback(void (*callback)(GLFWwindow*, int, int, int, int));
    void set_title(const std::string &title);

    bool is_closing() const;
    void update() const;
};

void key_callback_exit(GLFWwindow* window, int key, int scancode, int action, int mode);
