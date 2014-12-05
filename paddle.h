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
#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED

#include "gLibrary.h"

class paddleType
{
    public:
        // description: set default value of width, colors, rows and colume
        // return:      no return type
        // pre:         no
        // post:        object exists
        paddleType (int w = 30, ink c = red, int r = 97, int col = 240);

        // description: draw the paddle
        // return:      no return type
        // pre:         no
        // post:        object exists
        void draw (Plotter&);

        // description: erase the color
        // return:      no return type
        // pre:         no
        // post:        object exists
        void erase (Plotter&);

        // description: move the paddle
        // return:      no return type
        // pre:         no
        // post:        object exists
        void move (int);

        // description: check if the paddle is hit by the ball
        // return:      bool
        // pre:         object exists
        // post:        return hit
        bool hitByBall(ball);

        // description: check if the paddle hit the wall
        // return:      bool
        // pre:         object exists
        // post:        HitWall
        bool paddleHitWall(int);

        // description: take the point
        // return:      Point
        // pre:         object exists
        // post:        return the location of the paddle
        Point getLoc();

        // description: calculate the direction of the ball
        //              when the ball hit the outer of paddle
        // return:      double
        // pre:         object exists
        // post:        return direction
        double ballHitOuterPaddle(ball b);

        // description: calculate the direction of the ball
        //              when the ball hit the inner of paddle
        // return:      double
        // pre:         object exists
        // post:        return direction
        double ballHitInnerPaddle(ball b);

        // description: calculate the direction of the ball
        //              when the ball hit the middle of paddle
        // return:      double
        // pre:         object exists
        // post:        return direction
        double ballHitMiddlePaddle(ball b);

        // description: make sure that the ball in stuck to the
        //              paddle and the user can move the paddle
        //              to anywhere he likes before the start of
        //              the game
        // return:      no return type
        // pre:         no
        // post:        object exists
        void   ballStuckToPaddle(ball, Plotter&);
    private:
        int width;
        Point loc, oldLoc;
        ink color;
        int cols, rows;
};



#endif // PADDLE_H_INCLUDED
