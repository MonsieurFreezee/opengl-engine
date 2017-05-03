#include "player.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

Player::Player(const Entity &entity, const Model &model):
    Entity {entity},
    m_model {model}
{

}

Player::Player(const Model &model):
    Entity {Position {}, Rotation {}},
    m_model {model}
{

}

void Player::render(const ShaderProgram &shader_program) const
{
    // Update object position in the world
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(get_position_X(),
                                            get_position_Y(),
                                            get_position_Z()));
    model = glm::rotate(model, glm::radians(get_rotation_X()), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(get_rotation_Y()), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(get_rotation_Z()), glm::vec3(0.0f, 0.0f, 1.0f));

    GLint model_loc = glGetUniformLocation(shader_program.get_ID(), "model");
    glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));

    m_model.render(shader_program);
}

void Player::update()
{
    set_position_X(sin(glfwGetTime() / 10));
    set_rotation_X(glfwGetTime() * 10);
    set_rotation_Y(glfwGetTime() * 10);
    set_rotation_Z(glfwGetTime() * 10);
}
