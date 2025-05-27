#pragma once
#include "IGame.h"

#include <string>

enum GameMode {
    MODE_STANDARD = 1,
    MODE_REACTION = 2
};

class RockPaperScissors : public IGame {
public:
    void game_init() override;
    void game_start() override;
    void game_over() override;
    void key_input(int key_code) override;

private:
    GameMode selected_mode = MODE_STANDARD;
    int userChoice;
    int computerChoice;
    bool isRunning;

    void draw_title();
    void select_mode();
    bool play_standard();
    bool play_reaction();
    void printChoice(int choice);
    int determineWinner(int userChoice, int computerChoice);
};