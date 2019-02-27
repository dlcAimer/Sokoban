//
// Created by 79373 on 2018-6-19.
//

#ifndef PROJECT_RANK_H
#define PROJECT_RANK_H


#include <iostream>
#include <vector>
class Rank {
private:
   std::vector<int> ranks;
    void writeRanks();
public:
    Rank();
    void loadRanks();
    void addRanks(int consumeTime);
    void printRanks();
};


#endif //PROJECT_RANK_H
