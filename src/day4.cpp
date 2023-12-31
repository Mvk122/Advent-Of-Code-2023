#include <vector>
#include <sstream>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>

#include "fetch_input.h"
#include "solutions.h"

void parse_line(std::istringstream input, std::vector<int> &numbers, std::unordered_set<int> &winning) {
    std::string first_half;
    std::getline(input, first_half, '|');

    int current_number;
    while (input >> current_number) {
        numbers.push_back(current_number);
    }

    std::istringstream first_half_ss(first_half);
    std::getline(first_half_ss, first_half, ':'); // Get rid of Card:

    while (first_half_ss >> current_number) {
        winning.insert(current_number);
    }
}

int solve_day_4() {
    std::istringstream input_ss(fetch_input(4));
    std::string current_line;

    int total = 0;
    while (std::getline(input_ss, current_line)) {
        std::vector<int> numbers;
        std::unordered_set<int> winning;
        parse_line(std::istringstream(current_line), numbers, winning);

        for (const auto w: winning) {
            std::cout << w << " ";
        }
        std::cout << "\n";

        int current = 0;
        for (const auto n: numbers) {
            if (winning.count(n) > 0) {
                current++;
            } 
        }
        if (current > 0) {
            total += static_cast<int>(std::pow(2, current-1));
        }
    }
    return total;
}