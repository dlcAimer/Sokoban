//
// Created by 79373 on 2018-6-19.
//
#include <iostream>
#include "Timer.h"

void Timer::printTimeConsumed() {
    clock_t now=clock();
    int consumeTime = (int)(now-begin)/CLOCKS_PER_SEC;
    int minutes= (consumeTime)/60;
    int second = (consumeTime)%60;
    std:: cout<<"time consumed: "<<minutes<<" min "<<second<<" secs "<<std::endl;
}

int Timer::getTimeConsumed() {
    clock_t now=clock();
    int consumeTime = (int)(now-begin)/CLOCKS_PER_SEC;
    return consumeTime ;
}

void Timer::freshen() {
    begin=clock();
}
