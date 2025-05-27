#pragma once
#include "IGame.h"

class dice_game : public IGame {
    const char* game_title_str = "주사위 게임";
    int rounds;
    int playerScore;
    int computerScore;

    // 실제 주사위 굴림 및 애니메이션 처리
    int rollDice();
    void printRoundResult(int round, int playerRoll, int computerRoll);
    void printFinalResult();

public:
    dice_game(int rounds = 5);
    void game_init() override;
    void game_start() override;
    void game_over() override;
    void key_input(int key_code) override;
};