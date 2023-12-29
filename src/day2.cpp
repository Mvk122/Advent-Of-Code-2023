#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "fetch_input.h"
#include "solutions.h"


std::ostream& operator<<(std::ostream& os, const Play& play) {
    os << "Red: " << play.red << ", Green: " << play.green << ", Blue: " << play.blue;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Game " << game.id << ":\n";
    for (const Play& play : game.plays) {
        os << play << '\n';
    }
    return os;
}

Game get_game_from_line(std::string line) {
    std::vector<Play> plays;
    
    std::istringstream iss(line);
    std::string word; // dummy variable for storing strings
    int id;

    iss >> word >> id >> word; // Game gets placed in word variable and id is placed in id variable

    std::vector<std::string> play_strings;
    while (std::getline(iss, word, ';')) {
        play_strings.push_back(word);
    }

    for (const auto play: play_strings) {
        std::istringstream play_stream(play);
        std::string colour;
        std::string current;
        int amount = 0;
        Play play_struct = {0, 0, 0};

        while (std::getline(play_stream, current, ',')) {
            std::istringstream(current) >> amount >> colour;

            if (colour == "blue") {
                play_struct.blue = amount;
            } else if (colour == "red") {
                play_struct.red = amount;
            } else if (colour == "green") {
                play_struct.green = amount;
            } else {
                std::cout << "Invalid Colour detected on: " << play << "\n";
            }
        }
        plays.push_back(play_struct);
    }

    return {id, plays};
}

std::vector<Game> get_games_from_input() {
    std::istringstream iss(fetch_input(2));
    std::string line;

    std::vector<Game> games;
    while (std::getline(iss, line)) {
        games.push_back(get_game_from_line(line));
    }

    return games;
}

int solve_day_2() {
    std::vector<Game> games = get_games_from_input();

    int total = 0;
    for (const auto& game: games) {
        bool bad_play = false;
        for (const auto& play: game.plays) {
            if (play.red > 12 || play.green > 13 || play.blue > 14) {
                bad_play = true;
                break;
            }
        }
        if (!bad_play) {
            total += game.id;
        }
    }
    return total;
}

int solve_day_2_2() {
    std::vector<Game> games = get_games_from_input();

    int total = 0;
    for (const auto& game: games) {
        int minimum_blues = 0;
        int minimum_reds = 0;
        int minimum_greens = 0;

        for (const auto& play: game.plays) {
            minimum_reds = std::max(minimum_reds, play.red);
            minimum_blues = std::max(minimum_blues, play.blue);
            minimum_greens = std::max(minimum_greens, play.green);
        }

        total += minimum_blues * minimum_greens * minimum_reds;
    }
    return total;

}
