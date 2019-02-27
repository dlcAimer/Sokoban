//
// Created by 79373 on 2018-6-18.
//
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "board.h"
using namespace std;

void Board::horizonMove(int i, int j, int direction) {

  if(gameBoard[i][j]!=0){
      int nextj=direction>0?(j-1):(j+1);
      while((!outOfBoard(i,nextj))&&!blocked(i,j,gameBoard[i][nextj])){
          gameBoard[i][nextj]+=gameBoard[i][j];
          gameBoard[i][j]=0;
          j+=direction>0?-1:1;
          nextj=direction>0?(j-1):(j+1);
      }
  }
}

void Board::verticalMove(int i, int j, int direction) {
    if(gameBoard[i][j]!=0){
        int nexti=direction>0?(i-1):(i+1);
        while((!outOfBoard(nexti,j))&&!blocked(i,j,gameBoard[nexti][j])){
            gameBoard[nexti][j]+=gameBoard[i][j];
            gameBoard[i][j]=0;
            i+=direction>0?-1:1;
            nexti=direction>0?(i-1):(i+1);
        }
    }
}

Board::Board() {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            gameBoard[i][j]=0;
        }
    }
    generateNextNumber(2);
}

Board::Board(Board &otherBoard) {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
          this->gameBoard[i][j]=otherBoard.gameBoard[i][j];
        }
    }
}

void Board::reset() {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            gameBoard[i][j]=0;
        }
    }
    generateNextNumber(2);
}

bool Board::move(const std::string &order) {
    Board prev(*this);
    if(order=="w"){//up
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < COL; ++j)
                verticalMove(i,j,1);

    } else if(order=="s"){//down
        for (int i = ROW-1; i >=0; --i)
            for (int j = 0; j < COL; ++j)
                verticalMove(i,j,-1);

    } else if(order=="a"){//left
        for (int i = 0; i < ROW; ++i)
            for (int j = 0; j < COL; ++j)
                horizonMove(i,j,1);

    }else if(order=="d"){//right
        for (int i = 0; i < ROW; ++i)
            for (int j = COL-1; j >=0; j--)
                horizonMove(i,j,-1);

    }
    return !equals(prev);
}

void Board::printBoard() {
    std::cout<<"_______________________________"<<std::endl;
    for(int i=0;i<ROW;i++) {

        cout<<"|";
        for(int j=0;j<COL;j++){
            string symbol=gameBoard[i][j]==0?" ":to_string(gameBoard[i][j])<<"|";
            cout<<setw(4)<<symbol;
          //  std::cout<<std::setw(5)<<gameBoard[i][j]<<"|";
        }
        std::cout<<endl<<"________________________________"<<std::endl;
    }
}

bool Board::isFull() {
    return emptyBlocksNum()==0;
}
bool Board::isEmpty() {
    return emptyBlocksNum()==ROW*COL;
}
bool Board::isPossibleMove() {
    if(isFull()){
        Board newBoard(*this);
        newBoard.move("w");
        if(!equals(newBoard)) return true;
        newBoard.move("s");
        if(!equals(newBoard)) return true;
        newBoard.move("a");
        if(!equals(newBoard)) return true;
        newBoard.move("d");
        return !equals(newBoard);
    }
    return true;
}

bool Board::isLastGrade() {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            if (gameBoard[i][j]==2048) return true;
        }
    }
    return false;
}

bool Board::generateNextNumber(int num){
    bool result= false;
   while(num>0&&!isFull()){
    //   srand(time(nullptr));
       int x=rand()%4;
       int y=rand()%4;
       int number=rand()%10==0?4:2;
       if(gameBoard[x][y]==0){
           gameBoard[x][y]=number;
           num--;
       }
       result=true;
   }
    return result;
}

bool Board::equals(Board &other) const {
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            if(other.gameBoard[i][j]!=gameBoard[i][j]) return false;
        }
    }
    return true;
}

bool Board::outOfBoard(int i, int j) const {
    return !(i >= 0 && j >= 0 && i < ROW && j < COL);
}

bool Board::blocked(int i, int j,int val) const {
    return !(val==0||gameBoard[i][j]==val);
}

double Board::getMaxValue() const {
    int result=0;
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            result=max(result,gameBoard[i][j]);
        }
    }
    return log(result)/log(2);
}

double Board::getMonotonicity() const {
    // 保存四个方向格局单调性的评估值
    int totals[] = {0, 0, 0, 0};

    // 上/下 方向
    for (int j = 0; j < 4; j++) {
        int current = 0;
        int next = current + 1;
        while (next < 4) {
            while (next < 4 && gameBoard[next][j] == 0) next++;
            if (next >= 4) next--;
            double currentValue = (gameBoard[current][j] != 0) ? log(gameBoard[current][j]) / log(2) : 0;
            double nextValue = (gameBoard[next][j] != 0) ? log(gameBoard[next][j]) / log(2) : 0;
            if (currentValue > nextValue) {
                totals[2] += nextValue - currentValue;
            } else if (nextValue > currentValue) {
                totals[3] += currentValue - nextValue;
            }
            current = next;
            next++;
        }
    }
    // 左/右 方向
    for (int i = 0; i < 4; i++) {
        int current = 0;
        int next = current + 1;
        while (next < 4) {
            while (next < 4 && gameBoard[i][next] == 0) next++;
            if (next >= 4) next--;
            double currentValue = (gameBoard[i][current] != 0) ? log(gameBoard[i][current]) / log(2) : 0;
            double nextValue = (gameBoard[i][next] != 0) ? log(gameBoard[i][next]) / log(2) : 0;
            if (currentValue > nextValue) {
                totals[0] += nextValue - currentValue;
            } else if (nextValue > currentValue) {
                totals[1] += currentValue - nextValue;
            }
            current = next;
            next++;
        }
    }
    // 取四个方向中最大的值为当前格局单调性的评估值
    return max(totals[0], totals[1]) + max(totals[2], totals[3]);
}

int Board::emptyBlocksNum() const {
    int result = 0;
    for (int i = 0; i <ROW ; ++i) {
        for (int j = 0; j <COL ; ++j) {
            if (gameBoard[i][j]==0) result++;
        }
    }
    return result;
}

std::vector<string> Board::legal_moves() {
    vector <std::string> v;
    Board newBoard1(*this);
    newBoard1.move("w");
    if(!equals(newBoard1)) v.emplace_back("w");
    Board newBoard2(*this);
    newBoard2.move("s");
    if(!equals(newBoard2)) v.emplace_back("s");
    Board newBoard3(*this);
    newBoard3.move("a");
    if(!equals(newBoard3)) v.emplace_back("a");
    Board newBoard4(*this);
    newBoard4.move("d");
    if(!equals(newBoard4)) v.emplace_back("d");
    return v;
}








