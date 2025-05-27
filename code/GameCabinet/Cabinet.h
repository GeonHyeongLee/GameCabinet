#pragma once
#include "IGame.h"

class Cabinet {
    const char* cabinet_model_str = "Ä³ºñ´Ö R123";
    IGame* installed_game = nullptr;
    bool is_running = false;

public:
    void hw_check();
    void load_game(IGame* game);
    void unload_game();
    void game_init();
    void game_start();
};