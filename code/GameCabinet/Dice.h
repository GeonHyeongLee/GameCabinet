#pragma once
#include "IGame.h"

class dice_game : public IGame {
    const char* game_title_str = "�ֻ��� ����";
    int rounds;
    int playerScore;
    int computerScore;

    // ���� �ֻ��� ���� �� �ִϸ��̼� ó��
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