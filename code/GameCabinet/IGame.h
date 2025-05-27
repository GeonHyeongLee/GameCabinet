#pragma once

// 1. 인터페이스 정의
class IGame {
public:
    virtual ~IGame() = default;
    virtual void game_init() = 0;
    virtual void game_start() = 0;
    virtual void game_over() = 0;
    virtual void key_input(int key_code) = 0;
};