//
// Created by 79373 on 2018-6-18.
//

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H
const int ROW= 4;
const int COL= 4;

#include <iostream>
#include <vector>

class Board {
private:
    int gameBoard[ROW][COL];
    bool outOfBoard(int i,int j)const;
    bool blocked(int i,int j,int val)const;
    void horizonMove(int i,int j,int direction);
    void verticalMove(int i,int j,int direction);
public:
    Board();//
    Board(Board &otherBoard);
    friend class Tools;
    friend class AI;

    bool generateNextNumber(int num);
    bool isFull();
    bool isEmpty();
    bool equals(Board &other) const ;
    void reset();
    bool move(const std::string &order);
    void printBoard();
    bool isPossibleMove();
    bool isLastGrade();
    std::vector <std::string> legal_moves();
    double getMaxValue() const ;
    double getMonotonicity() const;
    int  emptyBlocksNum() const ;

};


#endif //PROJECT_BOARD_H
