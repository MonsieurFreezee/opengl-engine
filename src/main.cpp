#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "window.h"
#include <string>

// Render object
#include "render.h"
#include "shader_program.h"
#include "camera.h"
#include "position.h"

// Player object
#include "player.h"
#include "model.h"
#include "obj_loader.h"
#include "texture.h"

// Debug
#include <iostream>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main()
{
    Window window {WINDOW_WIDTH, WINDOW_HEIGHT, "Test"};
    window.set_key_callback(key_callback_exit);

    Render render {ShaderProgram {"res/shaders/vertex_shader.vs", "res/shaders/fragment_shader.fs"},
                   Camera        {Position {0.0f, 0.0f, -3.0f}}};

    render.add(new Player {Model {load_mesh("res/models/sphere.obj"),
                                  Texture {"res/textures/wood.jpg"}}});

    double time {0.0};
    double time_elapsed {0};
    const double UPDATE_TIME {1.0};
    int frames {0};
    double average {0};

    // Wireframe mode
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    while (!window.is_closing())
    {
        time = glfwGetTime();
        if (time_elapsed + UPDATE_TIME < time)
        {
            average += frames;
            window.set_title(std::to_string(static_cast<int>(frames/UPDATE_TIME)) + "fps (~" + std::to_string(average / time) + "fps)");
            time_elapsed += UPDATE_TIME;
            frames = 0;
        }
        else ++frames;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        render.render();
        window.update();
    }

    return {0};
}
