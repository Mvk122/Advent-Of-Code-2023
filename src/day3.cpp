#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>


#include "fetch_input.h"
#include "solutions.h"


class Symbol {
    public:
        int x;
        int y;
        char symbol;

    Symbol(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}

    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
        os << "Symbol(x: " << symbol.x 
           << ", y: " << symbol.y 
           << ", symbol: " << symbol.symbol << ")";
        return os;
    }
};

class PartNumber {
    public:
        int start_x;
        int start_y;
        int width;
        int value;

    PartNumber(int start_x, int start_y, int width, int value) : 
        start_x(start_x), start_y(start_y), width(width), value(value) {}

    friend std::ostream& operator<<(std::ostream& os, const PartNumber& partNumber) {
        os << "PartNumber(start_x: " << partNumber.start_x 
           << ", start_y: " << partNumber.start_y 
           << ", width: " << partNumber.width 
           << ", value: " << partNumber.value << ")";
        return os;
    }

    bool isTouchingSymbol(Symbol& symbol) {
       return (symbol.y < this->start_y+2 && symbol.y > this->start_y-2 && symbol.x > this->start_x-2 && symbol.x < (this->start_x + this->width + 1)); 
    }
};

std::vector<Symbol> get_symbols_from_string(std::string input) {
    int x = 0;
    int y = 0;

    std::vector<Symbol> symbols;

    for (char c: input) {
        if (!isdigit(c) && c != '.' && c != '\n') {
            symbols.push_back(Symbol(x, y, c));
        }

        if (c=='\n') {
            x=0;
            y++;
        } else {
            x++;
        }
    }
    return symbols;
}

std::vector<PartNumber> get_parts_from_string(std::string input) {
    std::stringstream current_part;
    int x;
    int y;
    int value;
    std::vector<PartNumber> parts;

    for (char c: input) {

        if (isdigit(c)) {
            current_part << c;
        } else {
            int string_size = static_cast<int>(current_part.str().size());
            if (string_size > 0) {
                parts.push_back(PartNumber(x-string_size, y, string_size, std::stoi(current_part.str())));
                current_part = std::stringstream();
            }  
        }

        if (c=='\n') {
            x=0;
            y++;
        } else {
            x++;
        }
    }
    return parts;

}

int solve_day_3() {
    std::string input = fetch_input(3);
    auto symbols = get_symbols_from_string(input);
    auto parts = get_parts_from_string(input);


    for (auto symbol: symbols) {
        std::cout << symbol << "\n";
    }

    int total = 0;
    for (auto part: parts) {
        for (auto symbol: symbols) {
            if (part.isTouchingSymbol(symbol)) {
                total += part.value;
                break;
            }
        }
    }
    
    return total;
}