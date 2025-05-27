#include "RockPaperScissors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <thread>


void RockPaperScissors::game_init() {
    srand((unsigned int)time(NULL));
    isRunning = true;
    std::cout << "[RPS] 게임 초기화 완료\n";
}

void RockPaperScissors::draw_title() {
    std::cout << "============================\n";
    std::cout << "   🎮 Rock Paper Scissors 🎮\n";
    std::cout << "============================\n";
}

void RockPaperScissors::game_start() {
    while (isRunning) {
        select_mode();

        bool stayInMode = true;
        while (isRunning && stayInMode) {
            switch (selected_mode) {
            case MODE_STANDARD:
                stayInMode = play_standard();
                break;
            case MODE_REACTION:
                stayInMode = play_reaction();
                break;
            }
        }
    }
}

void RockPaperScissors::select_mode() {
    std::cout << "\033[2J\033[H"; // 화면 정리
    draw_title();

    std::cout << "게임 모드를 선택하세요:\n";
    std::cout << "1. 기본 가위바위보\n";
    std::cout << "2. 반응 속도 측정\n";
    std::cout << "(ESC: 종료)\n";
    std::cout << ">> ";

    char ch = _getch();
    std::cout << ch << std::endl;

    if (ch == 27) {
        isRunning = false;
        return;
    }

    selected_mode = (ch == '2') ? MODE_REACTION : MODE_STANDARD;
    std::cout << "\033[2J\033[H";
}

bool RockPaperScissors::play_standard() {
    std::cout << "\033[2J\033[H";
    std::cout << "(1: 가위, 2: 바위, 3: 보) 선택하세요 (q: 이전, ESC: 종료): ";
    char ch = _getch();
    std::cout << ch << std::endl;
    if (ch == 'q') return false;
    if (ch == 27) {
        isRunning = false;
        return false;
    }
    key_input(ch);
    return true;
}

bool RockPaperScissors::play_reaction() {
    std::cout << "[반응속도 모드]\n상대가 먼저 냅니다...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    computerChoice = rand() % 3 + 1;
    std::cout << "컴퓨터: ";
    printChoice(computerChoice);

    std::cout << "\n0.5초 내에 반응해서 이겨보세요! (1~3, q: 이전, ESC: 종료): ";
    auto start = std::chrono::steady_clock::now();
    char ch = _getch();
    auto end = std::chrono::steady_clock::now();

    if (ch == 'q') return false;
    if (ch == 27) {
        isRunning = false;
        return false;
    }

    std::chrono::duration<double> elapsed = end - start;
    userChoice = ch - '0';
    std::cout << ch << std::endl;

    if (userChoice < 1 || userChoice > 3) {
        std::cout << "잘못된 입력입니다 (1~3).\n";
    }
    else {
        std::cout << "당신: ";
        printChoice(userChoice);

        if (elapsed.count() > 0.5) {
            std::cout << "⏱ 너무 늦었습니다! (" << elapsed.count() << "초)\n";
        }
        else {
            std::cout << "반응 시간: " << elapsed.count() << "초\n";
            int result = determineWinner(userChoice, computerChoice);
            if (result == 1)
                std::cout << "🎉 당신이 이겼습니다!\n";
            else if (result == 0)
                std::cout << "😐 비겼습니다.\n";
            else
                std::cout << "😢 당신이 졌습니다.\n";
        }
    }

    std::cout << "계속하려면 아무 키나 누르세요 (q: 이전, ESC: 종료)...\n";
    char next = _getch();
    if (next == 'q') return false;
    if (next == 27) isRunning = false;
    std::cout << "\033[2J\033[H";
    return true;
}

void RockPaperScissors::game_over() {
    std::cout << "\n==========================\n";
    std::cout << "       게임 종료\n";
    std::cout << "==========================\n" << std::endl;
}

void RockPaperScissors::key_input(int key_code) {
    userChoice = key_code - '0';
    if (userChoice < 1 || userChoice > 3) {
        std::cout << "잘못된 입력입니다. 다시 시도하세요.\n";
        return;
    }

    computerChoice = rand() % 3 + 1;

    std::cout << "\nCom : ";
    printChoice(computerChoice);
    std::cout << "You : ";
    printChoice(userChoice);

    int result = determineWinner(userChoice, computerChoice);
    if (result == 0)
        std::cout << "\n결과: 비겼습니다!\n";
    else if (result == 1)
        std::cout << "\n결과: 당신이 이겼습니다!\n";
    else
        std::cout << "\n결과: 당신이 졌습니다!\n";

    std::cout << "\n계속하려면 아무 키나 누르세요 (q: 이전, ESC: 종료)...\n";
    char next = _getch();
    if (next == 'q') return;
    if (next == 27) {
        isRunning = false;
        game_over();
        return;
    }
    std::cout << "\033[2J\033[H";
}

void RockPaperScissors::printChoice(int choice) {
    switch (choice) {
    case 1:
        std::cout << R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
)";
        break;
    case 2:
        std::cout << R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
)";
        break;
    case 3:
        std::cout << R"(
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
)";
        break;
    default:
        std::cout << "???";
    }
}

int RockPaperScissors::determineWinner(int user, int comp) {
    if (user == comp) return 0;
    if ((user == 1 && comp == 3) || (user == 2 && comp == 1) || (user == 3 && comp == 2)) return 1;
    return -1;
}
