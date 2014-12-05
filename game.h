/*
Authors: Chuks Egbuchunam, Zehao Huang, Jiaqi Ma
         Brandon Scheitlin, Trent Matthews
Assignment Title: Breakout
Assignment Details: Make a game that breaks blocks
                    with a ball and paddle.
Due Date: After Thanksgiving
Date Created: 11/11/2014
Date Last Modified: 11/12/2014
*/
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "gLibrary.h"



class Game
{
    public:
    //Description:  set default value of game
    //Return Type:  none
    //Pre:          none
    //Post:         object exists
    Game();

    //Description: Start and run the game
    //Return Type:  none
    //Pre:          none
    //Post:         object exists
    void play();

    private:
    int key;
    Plotter screen;
    paddleType paddle;
    ball gameBall, fallingBall[240];
    brick wall[WALL_ROWS][WALL_COLS];
    sideBoundariesReflections Reflections;
    bool gameOver, active;
    Point point;


};

#endif // GAME_H_INCLUDED

#endif // GAME_H_INCLUDED
