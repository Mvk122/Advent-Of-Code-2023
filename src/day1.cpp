#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <optional>
#include <vector>
#include <map>
#include <limits>
#include <tuple>


#include "fetch_input.h"
#include "solutions.h"

int get_solution_from_line(std::string line, std::optional<std::function<std::string(std::string)>> string_formatter) {
    std::ostringstream current_number;

    if (string_formatter) {
        line = (*string_formatter)(line);
    }

    // Iterate forwards
    for (const char& ch: line) {
        if (isdigit(ch)) {
            current_number << ch;
            break;
        }
    }

    // Iterate backwards
    for (auto it = line.rbegin(); it != line.rend(); ++it) {
        if (isdigit(*it)) {
            current_number << *it;
            break;
        }
    }

    return stoi(current_number.str());
}

std::tuple<int, int> get_first_digit(std::string line) {
    for (int i=0; i< line.size(); i++) {
        if (isdigit(line[i])) {
            return std::make_tuple(line[i] - '0', i);
        }
    }   
    return std::make_tuple(-1, -1);
}


int part_two(std::string line) {
    std::map<std::string, int> spelled_numbers = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    int lowest_position =  std::numeric_limits<int>::max();
    int lowest_number = -1;

    int highest_position = -1;
    int highest_number = -1;


    for (const auto& pair : spelled_numbers) {
        int pos = static_cast<int>(line.find(pair.first, 0));
        
        while (pos != std::string::npos) {
            if (pos < lowest_position) {
                lowest_position = pos;
                lowest_number = pair.second;
            } 
            if (pos > highest_position) {
                highest_position = pos;
                highest_number = pair.second;
            }
            pos =  static_cast<int>(line.find(pair.first, pos+1));
        }
    }

    auto lowest_integer = get_first_digit(line);
    std::reverse(line.begin(), line.end());
    auto highest_integer = get_first_digit(line);


    if (std::get<1>(lowest_integer) < lowest_position && std::get<1>(lowest_integer) != -1) {
        lowest_number = std::get<0>(lowest_integer);
    }

    if (static_cast<int>(line.length()) - 1 - std::get<1>(highest_integer) > highest_position && std::get<1>(highest_integer) != -1) {
        highest_number = std::get<0>(highest_integer);
    } 

    return (lowest_number * 10) + highest_number;    
}

int first_day() {
    std::string in = fetch_input(1);

    std::istringstream iss(in);
    std::string line;

    int total = 0;

    //Iterate over the lines
    while (std::getline(iss, line)) {
        //total += get_solution_from_line(line, {}); // first part
        
        // second part
        std::cout << line << " " <<  part_two(line) << "\n";
        total += part_two(line);
    }

    return total;
}
