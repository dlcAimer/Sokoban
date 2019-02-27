#include <iostream>
#include <string>
#include <cstdlib>
#include "Rank.h"
#include "Game.h"
using namespace std;
int main(){
    while(true){
        cout<< " Welcome to 2048 directed by chenxin an"<< endl;
        cout<< " enter start to play a new game. close to exit. u to watch the ranking list"<< endl;
        string command;
        cin>>command;
        if(command=="start"){
            Game newGame;
            newGame.playGame();
        } else if(command=="u"){
            Rank rank;
            rank.printRanks();
        }
        else if (command=="close"){
            exit(0);
        } else{
            cout<<"wrong order"<<endl;
        }
    }

}