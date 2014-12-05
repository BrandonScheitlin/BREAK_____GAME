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
#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "gLibrary.h"

class sideBoundariesReflections
{
  public:
    // description: calculate the reflection of the top boundary
    // return:      double
    // pre:         object exists
    // post:        return the reflection of the top boundary
    double topBoundaryReflection(ball b);

    // description: calculate the reflection of the left boundary
    // return:      double
    // pre:         object exists
    // post:        return the reflection of the left boundary
    double leftBoundaryReflection(ball b);

    // description: calculate the reflection of the right boundary
    // return:      double
    // pre:         object exists
    // post:        return the reflection of the right boundary
    double rightBoundaryReflection(ball b);







};


