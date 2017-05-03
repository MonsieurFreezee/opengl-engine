#pragma once
#include "window.h"
#include <string>

class Game
{
private:
    Window m_window;
    std::string m_name;

public:
    Game(std::string name);
}
