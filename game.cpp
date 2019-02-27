//
// Created by 79373 on 2018-6-19.
//
#include <unistd.h>
#include <conio.h>
#include "game.h"
#include "Tools.h"
#include "Timer.h"
#include "Rank.h"
#include "AI.h"

using  namespace std;

bool Game::isGameOver() {
    return (!board.isPossibleMove())||board.isLastGrade();
}

void Game::playGame() {
    cout<<"w s a d to play the game, r to start"<<endl;
    cout<<"there some tools for you enter z shuffle the board and x clean a block if you enter c that will begin a automatical game";
    cout<< "if you want to back to the main menu enter quit"<<endl<<"good luck!"<<endl;
    string order;
    board.printBoard();
    Timer timer;
    Timer timer_step;
    int i=1;
    while (true) {
        while(!kbhit()){
            if(timer_step.getTimeConsumed()>=10*i){
                if(board.generateNextNumber(1)){
                     cout<<"long time no move.. an extra block is given"<<endl;
                     board.printBoard();
                    timer_step.printTimeConsumed();
                     i++;
                }
            }
        }
       getline(cin,order);
        if (order == "quit") {
            break;
        } else if (order == "c") {
            while (!isGameOver()) {
                AI ai;
                string move = ai.bestMove(board, 5);
                board.move(move);
                board.generateNextNumber(1);
                board.printBoard();
                cout << "AI's next move: " << move << endl;
                timer_step.printTimeConsumed();
                timer_step.freshen();
            }
                cout << "Game Over! enter r to restart, enter other go back the main menu" << endl;
                string order1;
                cin >> order1;
                if (order1 == "r") {
                    board.reset();
                    board.printBoard();
                    timer.freshen();
                    timer_step.freshen();
                    continue;
                } else {
                    return;
                }
        } else if (order == "r") {
                timer.freshen();
                timer_step.freshen();
                board.reset();
                board.printBoard();
                i=1;
                continue;
        }
        Tools tools;
        if (board.move(order)) {
            board.generateNextNumber(1);
            board.printBoard();
            timer_step.printTimeConsumed();
            timer_step.freshen();
            i=1;
        } else if (tools.shuffleBoard(board, order)) {
            cout<<"you have used the shuffle tool!"<<endl;
            board.printBoard();
        } else if (tools.clean_one_block(board, order)) {
            cout<<"a block has been cleaned"<<endl;
            board.printBoard();
        }
        if (isGameOver()) {
            if(board.isLastGrade()){
                Rank rank;
                rank.addRanks(timer.getTimeConsumed());
                cout<<"you win this game ! you can look up your ranking in the rank list"<<endl;
            } else{
                cout<<"you lose this game don't worry try again"<<endl;
            }

            cout << " enter r to restart, enter other go back the main menu" << endl;
            string order1;
            cin >> order1;
            if (order1 == "r") {
                board.reset();
                board.printBoard();
                timer.freshen();
                i=1;
            } else {
                return;
            }
        }
    }
}


