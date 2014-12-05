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
#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "gLibrary.h"

class ball
{
    public:
        //Description:  Set default value of ball
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        ball(Point = Point(), ink = red, char = SQUARE, double = .2, double = 3.14/2);

        //Description:  Draw the ball
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void draw(Plotter&);

        //Description:  Set movement of ball
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void move();

        //Description:  Get location of point
        //Return type:  Point
        //Pre:          object exists
        //Post:         return the location
        Point getLoc();

        //Description:  set location of point
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void setLoc(Point);

         //Description:  Get color of ball
        //Return type:  ink
        //Pre:          object exists
        //Post:         return the color of ball
        ink getColor();

         //Description:  Get shape of ball
        //Return type:  char
        //Pre:          object exists
        //Post:         return the shape of ball
        char getShape();

        //Description:  get speed of ball
        //Return type:  double
        //Pre:          object exists
        //Post:         return the speed of ball
        double getSpeed();

        //Description:  set speed of ball
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void setSpeed(double);

        //Description:  erase the color
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void erase(Plotter&);

        //Description:  check if ball hit rightwall
        //Return type:  0 or 1
        //Pre:          object exists
        //Post:         return true or false
        bool ballHitRightWall(ball, int);

        //Description:  check if ball hit leftwall
        //Return type:  0 or 1
        //Pre:          object exists
        //Post:         return true or false
        bool ballHitLeftWall(ball, int);

        //Description:  check if ball hit top wall
        //Return type:  0 or 1
        //Pre:          object exists
        //Post:         return true or false
        bool ballHitTopWall(ball b, int row);

        //Description:  check if ball hit the bottomwall
        //Return type:  1 or 0
        //Pre:          object exists
        //Post:         return true or false
        bool ballHitBottomWall(ball b, int row);

        //Description:  set direction of ball
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void setDir(double d);

        //Description:  get direction of ball
        //Return type:  double
        //Pre:          object exists
        //Post:         return the direction
        double getDir();

        //Description:  get old location of point
        //Return type:  point
        //Pre:          object exists
        //Post:         return the old location of point
        Point getOldLoc();

        //Description:  set old loctaion of point
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void setOldLoc(Point loc);

        //Description:  set old direction of ball
        //Return type:  none
        //Pre:          none
        //Post:         object exists
        void setOldDir(double d);

        //Description:  get old direction of ball
        //Return type:  double
        //Pre:          object exists
        //Post:         return old direction of ball
        double getOldDir();

        //Description:  get new direction
        //Return type:  double
        //Pre:          object exists
        //Post:         return new direction
        double newDir();

        //Description:  keep ball move in the direction between zero and two PI
        //Return type:  double
        //Pre:          object exists
        //Post:         return direction between 0 to two PI
        double keepBallinZerotoTwoPi();

    private:
        Point loc, oldLoc;
        ink color;
        char shape;
        double speed, dir, oldDir;
};

#endif // BALL_H_INCLUDED
