#pragma once
#include "IGame.h"

class tic_tac_toe : public IGame {
    const char* game_title_str = "ƽ����";
    char board[3][3];
    char currentPlayer;

    void initialize_board();
    void print_board();
    bool check_win();
    bool check_draw();
    bool make_move(int position);
    void switch_player();

public:
    void game_init() override;
    void game_start() override;
    void game_over() override;
    void key_input(int key_code) override; // ƽ����� Ű �Է� ����� �ƴ�. ���ο��� ó��
};