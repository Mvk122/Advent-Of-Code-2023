#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <string>
#include <vector>

// First day
int first_day();
int part_two(std::string line);

// Second day
struct Play {
    int red;
    int green;
    int blue;
};

struct Game {
    int id;
    std::vector<Play> plays;
};

std::vector<Game> get_games_from_input();
int solve_day_2();
int solve_day_2_2();

// Third day
int solve_day_3();
int solve_day_3_2();

// Fourth day
int solve_day_4();

#endif