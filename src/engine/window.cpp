#include <GL/glew.h>

#include "window.h"
#include <iostream>
#include <cstdlib> // exit()
#include <cstdint>

// Create the GLFWwindow instance
GLFWwindow* Window::create_window(uint16_t width, uint16_t height, const std::string &title) const
{
    // Initialize GLFW
    static bool is_glfw_init {false}; // if someone finds an even worse snake_case variable name for that (and glew down there vvv), don't hesitate to replace
    if (!is_glfw_init)
    {
        glfwInit();
        is_glfw_init = true;
    }

    // Antialiasing x4
    glfwWindowHint(GLFW_STENCIL_BITS, 4);
    glfwWindowHint(GLFW_SAMPLES, 4);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window {glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr)};

    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    int viewport_width, viewport_height;
    glfwGetFramebufferSize(window, &viewport_width, &viewport_height);
    glViewport(0, 0, viewport_width, viewport_height);

    // Initialize GLEW
    static bool is_glew_init {false};
    if (!is_glew_init)
    {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            std::cerr << "Failed to initialize GLEW\n";
            glfwTerminate();
            exit(-1);
        }
    }

    return {window};
}

// Constructor
Window::Window(uint16_t width, uint16_t height, const std::string &title):
    m_window {create_window(width, height, title)}
{

}

// Destructor
Window::~Window()
{
    glfwTerminate();
}

const GLFWwindow& Window::get_window() const
{
    return {*m_window};
}

void Window::set_key_callback(void (*callback)(GLFWwindow*, int, int, int, int))
{
    glfwSetKeyCallback(m_window, callback);
}

void Window::set_title(const std::string &title)
{
    glfwSetWindowTitle(m_window, title.c_str());
}

bool Window::is_closing() const
{
    return {glfwWindowShouldClose(m_window) == true};
}

void Window::update() const
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

// Callback for exiting the window when pressing ESCAPE
void key_callback_exit(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // Trick the compiler to not trigger -Werror=unused-parameter
    (void) scancode;
    (void) mode;

    // Check if the escape key is pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
