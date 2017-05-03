#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texture_coords;

out vec2 pass_texture_coords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    pass_texture_coords = texture_coords;
}
