#include "Dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// 생성자: 라운드 수 설정, 점수 초기화
dice_game::dice_game(int rounds)
    : rounds(rounds), playerScore(0), computerScore(0) {
}

// 애니메이션과 함께 1~6 사이 난수 생성
int dice_game::rollDice() {
    int finalVal = std::rand() % 6 + 1;
    // 굴림 애니메이션 (5번 랜덤 값 표시)
    for (int i = 0; i < 5; ++i) {
        int r = std::rand() % 6 + 1;
        std::cout << "\r주사위 굴리는 중: " << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    std::cout << "\r결과: [" << finalVal << "]        " << std::endl;
    return finalVal;
}

// 라운드별 결과 출력 및 점수 집계
void dice_game::printRoundResult(int round, int playerRoll, int computerRoll) {
    std::cout << "라운드 " << round << ": 플레이어 " << playerRoll
        << " vs 컴퓨터 " << computerRoll << " -> ";
    if (playerRoll > computerRoll) {
        std::cout << "승리!\n";
        playerScore++;
    }
    else if (playerRoll < computerRoll) {
        std::cout << "패배...\n";
        computerScore++;
    }
    else {
        std::cout << "무승부\n";
    }
}

// 최종 승패 결과 출력
void dice_game::printFinalResult() {
    std::cout << "\n최종 점수 - 당신: " << playerScore
        << ", 컴퓨터: " << computerScore << "\n";
    if (playerScore > computerScore) {
        std::cout << "게임 승리!\n";
    }
    else if (playerScore < computerScore) {
        std::cout << "게임 패배...\n";
    }
    else {
        std::cout << "무승부 게임!\n";
    }
}

// 게임 초기화: 점수 리셋 및 난수 시드 설정
void dice_game::game_init() {
    playerScore = computerScore = 0;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << "[" << game_title_str << "] 게임 초기화 (라운드 " << rounds << ")\n";
}

// 게임 진행
void dice_game::game_start() {
    std::cout << "[" << game_title_str << "] 게임 시작!\n";
    for (int i = 1; i <= rounds; ++i) {
        int p = rollDice();
        int c = rollDice();
        printRoundResult(i, p, c);
    }
    printFinalResult();
}

// 게임 종료 메시지
void dice_game::game_over() {
    std::cout << "[" << game_title_str << "] 게임 종료\n";
}

// 키 입력 사용 안 함
void dice_game::key_input(int key_code) {
    // 주사위 게임은 내부 진행 방식으로 입력 처리하지 않음
}
