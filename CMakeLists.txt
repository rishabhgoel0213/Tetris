cmake_minimum_required(VERSION 3.21)
project(TetrisGraphicsQt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TetrisGraphicsQt main.cpp Block.cpp Block.h Board.cpp Board.h Game.cpp Game.h)
target_link_libraries(TetrisGraphicsQt
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

