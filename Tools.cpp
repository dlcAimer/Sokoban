//
// Created by 79373 on 2018-6-19.
//

#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Tools.h"
using namespace std;

bool Tools::shuffleBoard(Board &board, const string &order) {
    if(order=="z"||board.isEmpty()){
        vector<int> v;
        for (int i = 0; i <ROW ; ++i) {
            for (int j = 0; j <COL ; ++j) {
                v.push_back(board.gameBoard[i][j]);
            }
        }
        Board prev(board);
        while(prev.equals(board)){
            shuffle(v.begin(),v.end(), std::mt19937(std::random_device()()));
            for (int i = 0; i <ROW ; ++i) {
                for (int j = 0; j <COL ; ++j) {
                    board.gameBoard[i][j]=v[i*ROW+j];
                }
            }
        }
        return true;
    }
    return false;
}

bool Tools::clean_one_block(Board &board, const string &order) {
     if(order=="x"){
         while(!board.isEmpty()){
             int x=rand()%4;
             int y=rand()%4;
             if(board.gameBoard[x][y]!=0){
                 board.gameBoard[x][y]=0;
                 return true;
             }
         }
         cout<<"the board is empty"<<endl;
         return false;
     }
    return false;
}
