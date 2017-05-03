#include "string_utils.h"

std::vector<std::string> split(const std::string &str, char character)
{
    std::vector<std::string> split;
    long unsigned int pos {str.find(character)};
    unsigned int initialPos {0};

    while (pos != std::string::npos)
    {
        split.push_back(str.substr(initialPos, pos - initialPos + 1));
        initialPos = pos + 1;

        pos = str.find(character, initialPos);
    }

    // Adds the last one
    split.push_back(str.substr(initialPos, std::min(pos, str.size()) - initialPos + 1));

    return {split};
}
