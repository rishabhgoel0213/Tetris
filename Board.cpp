//
// Created by rishabh on 5/14/22.
//

#include <QPainter>
#include <thread>
#include <QCoreApplication>
#include <QTime>
#include<QDebug>
#include <QKeyEvent>


#include "Board.h"

void Board::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int x = 0; x < 10 * BLOCK_SIZE; x += BLOCK_SIZE)
        for(int y = 0; y < 20 * BLOCK_SIZE; y += BLOCK_SIZE)
            painter.drawRect(x, y, BLOCK_SIZE, BLOCK_SIZE);
    for(int x = 0; x < 4; x++)
    {
        painter.fillRect(pieces->getCurrentBlock()[x][0] * BLOCK_SIZE + block_position[0] * BLOCK_SIZE,
                         pieces->getCurrentBlock()[x][1] * BLOCK_SIZE + block_position[1] * BLOCK_SIZE,
                         BLOCK_SIZE,
                         BLOCK_SIZE,
                         pieces->getColor());
    }
    int color_counter = 0;
    for(int x = 0; x < placed_block_loc.length(); x++)
    {
        painter.fillRect(placed_block_loc[x][0] * BLOCK_SIZE,
                         placed_block_loc[x][1] * BLOCK_SIZE,
                         BLOCK_SIZE,
                         BLOCK_SIZE,
                         placed_block_col[color_counter]);
        if ((x + 1) % 4 == 0)
            color_counter++;
    }
    QWidget::paintEvent(event);
}

Board::Board()
{
    srand(time(0));
    this->grabKeyboard();
    this->resize(10 * BLOCK_SIZE + 1, 20 * BLOCK_SIZE + 1);
    pieces = new Block();
    starting_pos = pieces->getCurrentBlock()[0][0];
    placed_block_loc = {{40, 40}, {40, 40}, {40, 40}, {40, 40}};
}

void Board::checkRules()
{
    for(int x = 0; x < placed_block_loc.length(); x++)
        if(placed_block_loc[x][1] < 0)
            game_state = false;
    is_floating = true;
    for(int x = 0; x < 4; x++)
        for(int y = 0; y < placed_block_loc.length(); y++)
            if(((pieces->getCurrentBlock()[x][0] + block_position[0] == placed_block_loc[y][0]) && (pieces->getCurrentBlock()[x][1] + block_position[1] + 1 == placed_block_loc[y][1])) || (pieces->getCurrentBlock()[x][1] + block_position[1] == 19))
            {
                placeBlock();
                goto next;
            }
    next:
    int row_counter = 0;
    for(int y = 0; y < 20; y++)
    {
        for (int x = 0; x < placed_block_loc.length(); x++)
        {
            if (placed_block_loc[x][1] == y)
                row_counter++;
            if (row_counter == 10)
            {
                clearRow(y);
                break;
            }
        }
        row_counter = 0;
    }
    block_position[1] += 1;

}

void Board::clearRow(int row)
{
    for(int x = 0; x < 10; x++)
    {
        placed_block_loc.removeAll(QVector<int>({x, row}));
    }
    for(int x = 0; x < placed_block_loc.length(); x++)
        if(placed_block_loc[x][1] < row)
            placed_block_loc[x][1]++;
}

void Board::placeBlock()
{
    for(int x = 0; x < 4; x++)
        placed_block_loc.append(QVector<int>({pieces->getCurrentBlock()[x][0] + block_position[0], pieces->getCurrentBlock()[x][1] + block_position[1]}));
    placed_block_col.append(pieces->getColor());
    pieces = new Block();
    is_floating = false;
    starting_pos = pieces->getCurrentBlock()[0][0];
    block_position[0] = 3;
    block_position[1] = -2;
}

QDockWidget* Board::startGame()
{
    if(game_state)
    {
        checkRules();
        this->update();
        delay();
        return this->getHeldBlock();
    }

}

void Board::delay()
{
    QTime dieTime = QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Board::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
        switch (event->key())
        {
            case Qt::Key_W:
                pieces->rotateBlock();
                break;
            case Qt::Key_A:
                if(block_position[0] > 0 - starting_pos)
                    block_position[0] -= 1;
                break;
            case Qt::Key_D:
                if(block_position[0] < 9 - starting_pos)
                block_position[0] += 1;
                break;
            case Qt::Key_S:
                block_position[1] += 1;
                break;
            case Qt::Key_Space:
                while(is_floating)
                    checkRules();
                break;
            case Qt::Key_C:
                holdBlock();
        }
    QWidget::keyPressEvent(event);
}

void Board::holdBlock()
{
    if(held_block->isEmpty())
    {
        held_block = pieces;
        pieces = new Block();
        block_position[0] = 3;
        block_position[1] = -2;
    }
    else
    {
        Block* swap;
        swap = pieces;
        pieces = held_block;
        held_block = swap;
    }
}

QDockWidget* Board::getHeldBlock()
{
    return held_block;
}


