//
// Created by 79373 on 2018-6-20.
//

#ifndef PROJECT_AI_H
#define PROJECT_AI_H


#include "board.h"

class AI {
private:

    double minMax(Board &board,int depth, double alpha, double beta,bool maxPlayer);
public:
    std::string bestMove(Board &board,int depth);
    double  evaluation(Board &board);

};


#endif //PROJECT_AI_H
