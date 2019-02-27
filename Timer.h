//
// Created by 79373 on 2018-6-19.
//

#ifndef PROJECT_TIMER_H
#define PROJECT_TIMER_H

#include <ctime>

class Timer {
private:
   clock_t begin=clock();
public:
    void printTimeConsumed();
    void freshen();
    int getTimeConsumed();
};


#endif //PROJECT_TIMER_H
