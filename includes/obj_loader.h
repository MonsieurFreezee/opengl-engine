#pragma once
#include <string>
#include <vector>
#include <GL/glew.h>
#include "mesh.h"

void load_OBJ(const std::string &location, std::vector<GLfloat> &vertices, std::vector<GLuint> &indices);

Mesh load_mesh(const std::string &location);
