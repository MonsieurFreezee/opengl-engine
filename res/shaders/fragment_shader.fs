#version 330 core

in vec2 pass_texture_coords;

out vec4 color;

uniform sampler2D diffuse_texture;

void main()
{
    // Blame SOIL for that
    color = texture(diffuse_texture, vec2(pass_texture_coords.x, 1 - pass_texture_coords.y));
}
