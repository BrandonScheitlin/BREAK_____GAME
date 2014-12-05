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
#ifndef BRICK_H_INCLUDED
#define BRICK_H_INCLUDED

#include "gLibrary.h"


class brick
{
    public:

    //Description:  Set default value of brick
    //Return type:  none
    //Pre:          none
    //Post:         object exists
    brick(int w = 20, int r = 3, ink = white, Point = Point(), char = SQUARE);

    //Description:  Get the point of brick
    //Return type:  point
    //Pre:          object exists
    //Post:         return the point of brick
    Point getLoc ();

    //Description:  draw brick
    //Return type:  none
    //Pre:          none
    //Post:         object exists
    void draw(Plotter&);

    //Description:  set the point of brick
    //Return type:  none
    //Pre:          none
    //Post:         object exists
    void setLoc(Point);

    //Description:  get color of brick
    //Return type:  ink
    //Pre:          object exists
    //Post:         return color of brick
    ink getColor();

    //Description:  set color of brick
    //Return type:  none
    //Pre:          none
    //Post:         object exists
    void setColor(ink a);

    //Description:  get the shape of brick
    //Return type:  char
    //Pre:          object exists
    //Post:         return the shape of brick
    char getShape();

    //Description:  get different case of ball hit brick
    //Return type:  int
    //Pre:          object exists
    //Post:         return interger 1 or 2
    int ballHitBrick(ball b);


    private:
    int width, rows;
    Point loc;
    ink color;
    bool active;
    int hitCount;
    char shape;
};

#endif // BRICK_H_INCLUDED
