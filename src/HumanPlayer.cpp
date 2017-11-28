#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Color color, Board &board, Rules *rules, Display *display) : Player(color, board, rules,
                                                                                           display) {}

void HumanPlayer::playMove() {
    const int noMoves = 0;
    vector<int> moves, choice;
    //show board.
    display->showBoard(board);
    //get the player's possible moves.
    rules->whereCanPut(board, color, moves);
    //if no moves for player1.
    if (moves.size() <= noMoves) {
        display->noMoves(color);
        return;
    }
    //show moves.
    display->showMoves(color, moves);
    //get the move.
    getInput(moves, choice);
    //play move.
    board.put(color, choice[0], choice[1]);
}

void HumanPlayer::getInput(std::vector<int> &moves, std::vector<int> &choice) const {
    int row, col;
    while (true) {
        //get row and col.
        cin >> row >> col;
        //if the player didn't input a number.
        if (!cin) {
            //reset fail bit.
            cin.clear();
            //skip bad input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice.push_back(-1);
            choice.push_back(-1);
        } else {
            //row and col -1 in order to use in the vector.
            row--;
            col--;
            choice.push_back(row);
            choice.push_back(col);
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        //loop on the vector.
        for (int i = 0; i < moves.size(); i = i + 2) {
            //if choice is ok, return.
            if (moves[i] == choice[0] && moves[i + 1] == choice[1]) {
                return;
            }
        }
        //if the choice isn't valid.
        display->invalidInput();
        //get new choice.
        choice.clear();
    }
}