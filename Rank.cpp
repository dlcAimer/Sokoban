//
// Created by 79373 on 2018-6-19.
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Rank.h"
using namespace std;


void Rank::addRanks(int consumeTime) {
  ranks.push_back(consumeTime);
  writeRanks();
}

void Rank::printRanks() {
    sort(ranks.begin(), ranks.end(),less<int>());//升
    cout<<"RANKING LIST"<<endl;
    if(ranks.empty()) cout<<"nobody has passed"<<endl;
    for (int i = 0; i <ranks.size() ; ++i) {
        int minutes= (ranks[i])/60;
        int second = (ranks[i])%60;
        cout<<"NO."<<i+1<<": "<<minutes<<" min "<<second<<" secs "<<endl;
    }
}

Rank::Rank() {
   loadRanks();
}
void Rank::loadRanks() {
    ifstream ifs("ranking.txt");
    string line;
    while (getline(ifs,line)){
        ranks.push_back(atoi(line.c_str()));
    }
}

void Rank::writeRanks() {
    ofstream ofs("ranking.txt");
    for (int i = 0; i <ranks.size() ; ++i) {
        ofs<<ranks[i]<<endl;
    }
}
