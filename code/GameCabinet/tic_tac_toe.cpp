#include "tic_tac_toe.h"
#include <cstdio>
#include <conio.h>

void tic_tac_toe::initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j);
        }
    }
    currentPlayer = 'X';
}

void tic_tac_toe::print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

bool tic_tac_toe::check_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool tic_tac_toe::check_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

bool tic_tac_toe::make_move(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("잘못된 입력입니다. 다시 시도하세요.\n");
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

void tic_tac_toe::switch_player() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void tic_tac_toe::game_init() {
    initialize_board();
    printf("[%s] 게임을 초기화합니다.\n", game_title_str);
}

void tic_tac_toe::game_start() {
    printf("[%s] 게임을 시작합니다!\n", game_title_str);
    while (true) {
        print_board();
        printf("플레이어 %c, 위치(1-9)를 입력하세요: ", currentPlayer);
        int input = _getch();
        printf("%c\n", input);
        int position = input - '0';

        if (!make_move(position)) continue;

        if (check_win()) {
            print_board();
            printf("플레이어 %c 승리!축하합니다!!\n", currentPlayer);
            break;
        }
        if (check_draw()) {
            print_board();
            printf("무승부입니다!\n");
            break;
        }
        switch_player();
    }
}

void tic_tac_toe::game_over() {
    printf("[%s] 게임이 종료되었습니다.\n", game_title_str);
}

void tic_tac_toe::key_input(int key_code) {
    // 틱택토는 키보드 입력을 내부적으로 받기 때문에 무시
}
