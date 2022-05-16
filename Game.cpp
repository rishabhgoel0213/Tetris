//
// Created by rishabh on 5/15/22.
//

#include "Game.h"

bool Game::event(QEvent *event)
{
    return QMainWindow::event(event);
}

void Game::begin()
{
    this->setCentralWidget(game_board);
    hold = game_board->getHeldBlock();
    this->addDockWidget(Qt::LeftDockWidgetArea, hold);
    while(true)
    {
        QDockWidget* prev_hold = hold;
        hold = game_board->startGame();
        if(prev_hold != hold)
        {
            this->removeDockWidget(prev_hold);
            this->addDockWidget(Qt::LeftDockWidgetArea, hold);
        }
    }
}

Game::Game()
{
    this->setFixedSize(18 * BLOCK_SIZE, 22 * BLOCK_SIZE);
}
