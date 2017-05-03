#include "io_utils.h"

std::runtime_error unknown_file(const std::string& file_name)
{
    return std::runtime_error{"Error while opening " + file_name + ": file doesn't exists."};
}
