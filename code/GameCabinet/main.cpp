#include <iostream>
#include <conio.h>
#include <cstdio>
#include <vector>
#include <string>

#include "Cabinet.h"
#include "RockPaperScissors.h"
#include "tic_tac_toe.h"
#include "Dice.h"

using namespace std;

// 메뉴를 화면에 표시하는 함수
void displayMenu(const vector<string>& games, int selected) {
    system("cls");
    cout << "=== 게임 메뉴 (↑↓: 이동, Enter: 선택, ESC: 종료) ===\n\n";
    for (int i = 0; i < games.size(); ++i) {
        if (i == selected)
            cout << "> " << games[i] << "\n";
        else
            cout << "  " << games[i] << "\n";
    }
}

int main() {
    vector<string> games = {
        "Rock, Scissors, Paper",
        "Tic Tac Toe",
        "Dice Game"
    };
    bool exit_program = false;

    while (!exit_program) {
        int selected = 0;
        int ch;

        // 화살표 키로 선택 이동 / Enter 또는 ESC 처리
        while (true) {
            displayMenu(games, selected);
            ch = _getch();

            if (ch == 0 || ch == 224) {
                int arrow = _getch();
                if (arrow == 72)       // ↑
                    selected = (selected + games.size() - 1) % games.size();
                else if (arrow == 80)  // ↓
                    selected = (selected + 1) % games.size();
            }
            else if (ch == 27) {      // ESC
                exit_program = true;
                break;
            }
            else if (ch == 13) {      // Enter
                break;
            }
        }

        if (exit_program) {
            cout << "\n프로그램을 종료합니다.\n";
            break;
        }

        // Cabinet 인스턴스 생성 및 선택된 게임 로드
        Cabinet cabinet;
        switch (selected) {
        case 0:
            cabinet.load_game(new RockPaperScissors());
            break;
        case 1:
            cabinet.load_game(new tic_tac_toe());
            break;

        case 2:
            cabinet.load_game(new dice_game());  // Dice 게임 로드
            break;
        }

        // 게임 실행 절차
        cabinet.hw_check();
        cabinet.game_init();
        cabinet.game_start();   // 게임 중 'q' 누르면 여기서 빠져나와 메뉴로 복귀
        cabinet.unload_game();

        cout << "\n메뉴로 돌아갑니다... (아무 키나 누르세요)";
        _getch();
    }

    return 0;
}
