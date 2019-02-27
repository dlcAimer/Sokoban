//
// Created by 79373 on 2018-6-20.
//

#include <algorithm>
#include "AI.h"
using namespace std;
double AI::evaluation(Board &board) {
    double monoWeigtht=1.0;
    double emptyWeight=3;
    double maxWeight=1.0;
    return monoWeigtht*board.getMonotonicity()+emptyWeight*log(board.emptyBlocksNum())+maxWeight*board.getMaxValue();
}

double AI::minMax(Board &board, int depth, double alpha, double beta, bool maxPlayer) {
    if (depth == 0) {
        return evaluation(board);
    }

    if (maxPlayer) {
        double bestmove = -9999;
        Board prev(board);
        for (int i = 0; i < board.legal_moves().size(); i++) {
            board.move(board.legal_moves()[i]);
            bestmove = max(bestmove, minMax(board,depth - 1,alpha, beta, false));
            board=prev;
            if (alpha < bestmove){
                alpha = bestmove;
                if (alpha >= beta)//剪枝
                    break;
            }

        }
        return bestmove;
    }
    else{
        double bestmove = 9999;
        Board prev(board);
        for (int i = 0; i <16; i++) {

            board.generateNextNumber(1);
            bestmove = min(bestmove, minMax(board,depth - 1,alpha, beta, true));
            board=prev;
            if (bestmove<beta){
                beta=bestmove;
                if (alpha>=beta)
                    break;
            }
        }
        return bestmove;
    }

}
std::string AI::bestMove(Board &board,int depth) {
    double best_move_val=-9999;
    double bestmove=0;
    string result;
    Board prev(board);
    for(int i=0;i<board.legal_moves().size();i++) {
        board.move(board.legal_moves()[i]);
        bestmove = minMax(board, depth - 1,-9999, 9999 , false);
        board=prev;
        if (bestmove >= best_move_val){
            best_move_val = bestmove;
            result= board.legal_moves()[i];
        }
    }
    return result;
}


