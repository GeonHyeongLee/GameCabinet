#include "Dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// ������: ���� �� ����, ���� �ʱ�ȭ
dice_game::dice_game(int rounds)
    : rounds(rounds), playerScore(0), computerScore(0) {
}

// �ִϸ��̼ǰ� �Բ� 1~6 ���� ���� ����
int dice_game::rollDice() {
    int finalVal = std::rand() % 6 + 1;
    // ���� �ִϸ��̼� (5�� ���� �� ǥ��)
    for (int i = 0; i < 5; ++i) {
        int r = std::rand() % 6 + 1;
        std::cout << "\r�ֻ��� ������ ��: " << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    std::cout << "\r���: [" << finalVal << "]        " << std::endl;
    return finalVal;
}

// ���庰 ��� ��� �� ���� ����
void dice_game::printRoundResult(int round, int playerRoll, int computerRoll) {
    std::cout << "���� " << round << ": �÷��̾� " << playerRoll
        << " vs ��ǻ�� " << computerRoll << " -> ";
    if (playerRoll > computerRoll) {
        std::cout << "�¸�!\n";
        playerScore++;
    }
    else if (playerRoll < computerRoll) {
        std::cout << "�й�...\n";
        computerScore++;
    }
    else {
        std::cout << "���º�\n";
    }
}

// ���� ���� ��� ���
void dice_game::printFinalResult() {
    std::cout << "\n���� ���� - ���: " << playerScore
        << ", ��ǻ��: " << computerScore << "\n";
    if (playerScore > computerScore) {
        std::cout << "���� �¸�!\n";
    }
    else if (playerScore < computerScore) {
        std::cout << "���� �й�...\n";
    }
    else {
        std::cout << "���º� ����!\n";
    }
}

// ���� �ʱ�ȭ: ���� ���� �� ���� �õ� ����
void dice_game::game_init() {
    playerScore = computerScore = 0;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << "[" << game_title_str << "] ���� �ʱ�ȭ (���� " << rounds << ")\n";
}

// ���� ����
void dice_game::game_start() {
    std::cout << "[" << game_title_str << "] ���� ����!\n";
    for (int i = 1; i <= rounds; ++i) {
        int p = rollDice();
        int c = rollDice();
        printRoundResult(i, p, c);
    }
    printFinalResult();
}

// ���� ���� �޽���
void dice_game::game_over() {
    std::cout << "[" << game_title_str << "] ���� ����\n";
}

// Ű �Է� ��� �� ��
void dice_game::key_input(int key_code) {
    // �ֻ��� ������ ���� ���� ������� �Է� ó������ ����
}
