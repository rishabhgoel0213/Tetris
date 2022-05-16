//
// Created by rishabh on 5/15/22.
//

#ifndef TETRISGRAPHICSQT_GAME_H
#define TETRISGRAPHICSQT_GAME_H
#include <QMainWindow>
#include "Board.h"

class Game: public QMainWindow
{
public:
    void begin();
    Game();

protected:
    bool event(QEvent *event) override;
private:
    Board* game_board = new Board();
    QDockWidget *hold;
};


#endif //TETRISGRAPHICSQT_GAME_H
