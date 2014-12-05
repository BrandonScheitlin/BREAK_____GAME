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
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "gLibrary.h"

using namespace std;

class Point
{

    public:
        // description: set default value of point x and y
        // return:      no return type
        // pre:         no
        // post:        object exists
        Point (double xVal = 120, double yVal = 95);
        // description: get value of point x
        // return:      double
        // pre:         object exists
        // post:        return the value of point x
        double getX () const;

        // description: get value of point y
        // return:      double
        // pre:         object exists
        // post:        return the value of point y
        double getY () const;

        // description: set value of point x
        // return:      no return type
        // pre:         no
        // post:        object exists
        void setX (double);

        // description: set value of point y
        // return:      no return type
        // pre:         no
        // post:        object exists
        void setY (double);

        // description: calculate the distance between point x and y
        // return:      double
        // pre:         object exists
        // post:        return the value of distance between point x and y
        double distance (Point p);

    private:
        double x, y;

};


#endif // POINT_H_INCLUDED
