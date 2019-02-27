//
// Created by 79373 on 2018-6-19.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "board.h"

class Game {
    Board board;
    bool isGameOver();
public:
    void playGame();

};


#endif //PROJECT_GAME_H
