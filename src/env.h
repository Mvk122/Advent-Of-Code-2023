#ifndef ENV_H
#define ENV_H

#include <map>
#include <string>

std::map<std::string, std::string> parse_env_file();
std::map<std::string, std::string> parse_env_file(const std::string& filename);

#endif