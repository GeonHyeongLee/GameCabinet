#pragma once
#include "IGame.h"

class tic_tac_toe : public IGame {
    const char* game_title_str = "틱택토";
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
    void key_input(int key_code) override; // 틱택토는 키 입력 방식이 아님. 내부에서 처리
};