//
// Created by rishabh on 5/12/22.
//

#include <QPainter>
#include <iostream>
#include "Block.h"
constexpr int Block::blocks_array[8][4][4][2];


Block::Block(int t, int p)
{
    this->setAllowedAreas(Qt::LeftDockWidgetArea);
    type = t;
    position = p;
    switch(type)
    {
        case 0:
            block_color = Qt::yellow;
            break;
        case 1:
            block_color = QColor(135, 206, 235);
            break;
        case 2:
            block_color = QColor(255, 127, 80);
            break;
        case 3:
            block_color = Qt::blue;
            break;
        case 4:
            block_color = Qt::red;
            break;
        case 5:
            block_color = Qt::green;
            break;
        case 6:
            block_color = QColor(230, 230, 250);
            break;
    }
}

void Block::rotateBlock()
{
    if(position != 3)
        position += 1;
    else
        position = 0;
}

QVector<QVector<int>> Block::getCurrentBlock()
{
    QVector<QVector<int>> block;
    block.resize(4);
    for(int x = 0; x < 4; x++)
        block[x].resize(2);
    for(int x = 0; x < 4; x++)
        for(int y = 0; y < 2; y++)
            block[x][y] = blocks_array[type][position][x][y];
    return block;
}

int Block::getLowestRow()
{
    int lowest = 0;
    for(int x = 0; x < 4; x++)
        if(blocks_array[type][position][x][1] > lowest)
            lowest = blocks_array[type][position][x][1];
    return lowest;
}

QColor Block::getColor()
{
    return block_color;
}

void Block::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int x = 0; x < 5; x++)
        for(int y = 0; y < 5; y++)
            painter.drawRect(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    for(int x = 0; x < 4; x++)
        painter.fillRect(blocks_array[type][position][x][0] * BLOCK_SIZE, blocks_array[type][position][x][1] * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, block_color);
    QWidget::paintEvent(event);
}

bool Block::isEmpty()
{
    if(type == 7)
        return true;
    return false;
}

