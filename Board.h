//
// Created by rishabh on 5/14/22.
//

#ifndef TETRISGRAPHICSQT_BOARD_H
#define TETRISGRAPHICSQT_BOARD_H
#include "QWidget"
#include "Block.h"

class Board: public QWidget
{
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

public:
    Board();
    QDockWidget* startGame();
    QDockWidget* getHeldBlock();
    void updatePosition(QKeyEvent *event);

private:
    friend class Game;
    void delay();
    void clearRow(int row);
    void placeBlock();
    void holdBlock();
    void checkRules();
    QVector<QVector<int>> placed_block_loc;
    QVector<QColor> placed_block_col = {Qt::blue};
    int block_position[2] = {3, -2};
    bool is_floating = true;
    bool game_state = true;
    int starting_pos;
    Block* pieces;
    Block* held_block = new Block(7, 0);

};


#endif //TETRISGRAPHICSQT_BOARD_H
