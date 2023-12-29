#include <string>
#include <sstream>
#include <iostream>


#include "fetch_input.h"
#include "solutions.h"

int first_day() {
    std::string in = fetch_input(1);

    std::istringstream iss(in);
    std::string line;

    int total = 0;

    while (std::getline(iss, line)) {
        std::ostringstream current_number;

        for (const char& ch: line) {
            if (isdigit(ch)) {
                current_number << ch;
                break;
            }
        }

        for (auto it = line.rbegin(); it != line.rend(); ++it) {
            if (isdigit(*it)) {
                current_number << *it;
                break;
            }
        }

        std::cout << current_number.str() << "\n";

        total += stoi(current_number.str());
    }

    return total;

}