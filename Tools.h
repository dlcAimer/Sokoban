//
// Created by 79373 on 2018-6-19.
//

#ifndef PROJECT_TOOLS_H
#define PROJECT_TOOLS_H
#include "board.h"

class Tools {
public:
    bool shuffleBoard(Board &board,const std::string &order);
    bool clean_one_block(Board &board,const std::string &order);
};


#endif //PROJECT_TOOLS_H
