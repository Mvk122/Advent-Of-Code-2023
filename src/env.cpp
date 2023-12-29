#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

#include "env.h"

std::map<std::string, std::string> parse_env_file(const std::string& filename) {
    std::map<std::string, std::string> vars;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream line_stream(line);
        std::string key, value;

        if (std::getline(line_stream, key, '=') && std::getline(line_stream, value)) {
            vars[key] = value;
        }
    }

    return vars;
}


std::map<std::string, std::string> parse_env_file() {
    std::filesystem::path current_file_path(__FILE__);
    std::filesystem::path env_file_path = current_file_path.parent_path().parent_path() / ".env";
    return parse_env_file(env_file_path.string());
}