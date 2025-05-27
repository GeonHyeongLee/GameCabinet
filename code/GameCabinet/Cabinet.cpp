#include <cstdio>
#include <conio.h> // Windows ȯ�濡�� _getch() ���
#include "Cabinet.h"

// 3. ĳ��� Ŭ���� ����
/*
class Cabinet {
    const char* cabinet_model_str = "ĳ��� R123";
    IGame* installed_game = nullptr;
    bool is_running = false;
public:
    void hw_check() {
        printf("[%s] Cabinet ���� üũ, �� üũ ��\n", cabinet_model_str);
    }
    void load_game(IGame* game) {
        installed_game = game;
    }
    void unload_game() {
        delete installed_game;
        installed_game = nullptr;
    }
    void game_init() {
        printf("[%s] �ε�� ������ �ʱ�ȭ �Լ� ȣ�� \n", cabinet_model_str);
        if (installed_game) {
            installed_game->game_init();
        }
        else {
            printf("������ ������ �����ϴ�.\n");
        }
    }
    void game_start() {
        if (installed_game) {
            installed_game->game_start();

            is_running = true;
            while (is_running) {
                int key = _getch(); // Windows������ _getch()
                installed_game->key_input(key);
                printf("[%s] ĳ����� �Է¹��� Ű ��: %d\n", cabinet_model_str, key);
                if (key == 'q') is_running = false;
            }
        }
        else {
            printf("������ ������ �����ϴ�.\n");
        }
    }
};
*/

#include <cstdio>
#include <conio.h> // Windows ȯ�濡�� _getch() ���
#include "Cabinet.h"

void Cabinet::hw_check() {
    printf("[%s] Cabinet ���� üũ, �� üũ ��\n", cabinet_model_str);
}

void Cabinet::load_game(IGame* game) {
    installed_game = game;
}

void Cabinet::unload_game() {
    delete installed_game;
    installed_game = nullptr;
}

void Cabinet::game_init() {
    printf("[%s] �ε�� ������ �ʱ�ȭ �Լ� ȣ�� \n", cabinet_model_str);
    if (installed_game) {
        installed_game->game_init();
    }
    else {
        printf("������ ������ �����ϴ�.\n");
    }
}

void Cabinet::game_start() {
    if (installed_game) {
        installed_game->game_start();
        is_running = true;
        while (is_running) {
            int key = _getch();
            installed_game->key_input(key);
            printf("[%s] ĳ����� �Է¹��� Ű ��: %d\n", cabinet_model_str, key);
            if (key == 'q') is_running = false;
        }
    }
    else {
        printf("������ ������ �����ϴ�.\n");
    }
}