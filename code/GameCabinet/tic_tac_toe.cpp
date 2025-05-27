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
        printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
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
    printf("[%s] ������ �ʱ�ȭ�մϴ�.\n", game_title_str);
}

void tic_tac_toe::game_start() {
    printf("[%s] ������ �����մϴ�!\n", game_title_str);
    while (true) {
        print_board();
        printf("�÷��̾� %c, ��ġ(1-9)�� �Է��ϼ���: ", currentPlayer);
        int input = _getch();
        printf("%c\n", input);
        int position = input - '0';

        if (!make_move(position)) continue;

        if (check_win()) {
            print_board();
            printf("�÷��̾� %c �¸�!�����մϴ�!!\n", currentPlayer);
            break;
        }
        if (check_draw()) {
            print_board();
            printf("���º��Դϴ�!\n");
            break;
        }
        switch_player();
    }
}

void tic_tac_toe::game_over() {
    printf("[%s] ������ ����Ǿ����ϴ�.\n", game_title_str);
}

void tic_tac_toe::key_input(int key_code) {
    // ƽ����� Ű���� �Է��� ���������� �ޱ� ������ ����
}
