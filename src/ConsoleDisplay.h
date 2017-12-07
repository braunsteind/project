#ifndef EX2_CONSOLEDISPLAY_H
#define EX2_CONSOLEDISPLAY_H

#include "Display.h"
#include <iostream>

class ConsoleDisplay : public Display {
public:
    virtual void announceWinner(Color winner) const;

    virtual void showBoard(Board &board) const;

    virtual void noMoves(Color color) const;

    virtual void showMoves(Color player, vector<Point> &moves) const;

    virtual void invalidInput() const;

    virtual void announceMove(Color player, int row, int column) const;

    virtual void announceNoMove(Color player) const;

    virtual Mode runMenu() const;

    virtual void connectedToServer() const override;

    void waitingForOtherPlayer() const override;
};

#endif //EX2_CONSOLEDISPLAY_H