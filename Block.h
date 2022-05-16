//
// Created by rishabh on 5/12/22.
//

#ifndef TETRISGRAPHICSQT_BLOCK_H
#define TETRISGRAPHICSQT_BLOCK_H
#include <QWidget>
#include <QDockWidget>
#include <QRect>
#include <cstdlib>
#include <QVector3D>
#include <random>
#include <QColor>

#define BLOCK_SIZE 20


class Block: public QDockWidget
{
public:
    Block(int t = rand() % 7, int p = rand() % 4);
    QVector<QVector<int>> getCurrentBlock();
    QColor getColor();
    bool isEmpty();
    void rotateBlock();
    int getLowestRow();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QColor block_color;
    int type, position;
    static constexpr int blocks_array[8][4][4][2] =
    {
            //Square
            {
                    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
                    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
                    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
                    {{0, 0}, {1, 0}, {0, 1}, {1, 1}}

            },
            //Line
            {
                    {{1, 2}, {2, 2}, {3, 2}, {4, 2}},
                    {{2, 1}, {2, 2}, {2, 3}, {2, 4}},
                    {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
                    {{2, 0}, {2, 1}, {2, 2}, {2, 3}}

            },
            //L Shape
            {
                    {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
                    {{0, 1}, {1, 1}, {2, 1}, {0, 2}},
                    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
                    {{0, 1}, {1, 1}, {2, 0}, {2, 1}}

            },
            //Reverse L
            {
                    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
                    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
                    {{1, 0}, {1, 1}, {1, 2}, {2, 0}},
                    {{0, 1}, {1, 1}, {2, 2}, {2, 1}}
            },
            //Z Shape
            {
                    {{1, 1}, {1, 2}, {2, 0}, {2, 1}},
                    {{0, 1}, {1, 1}, {1, 2}, {2, 2}},
                    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
                    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}
            },
            //S Shape
            {
                    {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
                    {{0, 2}, {1, 1}, {1, 2}, {2, 1}},
                    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
                    {{0, 1}, {1, 0}, {1, 1}, {2, 0}}

            },
            //T Shape
            {
                    {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
                    {{0, 1}, {1, 1}, {1, 2}, {2, 1}},
                    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
                    {{0, 1}, {1, 0}, {1, 1}, {2, 1}}

            },
            {
                    {{-40, -40}, {-40, -40}, {-40, -40}, {-40, -40}},
                    {{-40, -40}, {-40, -40}, {-40, -40}, {-40, -40}},
                    {{-40, -40}, {-40, -40}, {-40, -40}, {-40, -40}},
                    {{-40, -40}, {-40, -40}, {-40, -40}, {-40, -40}}
            }
    };
};


#endif //TETRISGRAPHICSQT_BLOCK_H
