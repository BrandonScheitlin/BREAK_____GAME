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
#include "gLibrary.h"

double sideBoundariesReflections::topBoundaryReflection(ball b)
{
    double reflection;
    while(b.getOldDir() > 2*3.14)
    {
        b.setOldDir(b.getOldDir() - 2*3.14);
    }
    while(b.getOldDir() < 0)
    {
        b.setOldDir(b.getOldDir() + 2*3.14);
    }
    reflection = (-b.getOldDir());
    return reflection;

}
double sideBoundariesReflections::leftBoundaryReflection(ball b)
{
    double reflection;
    while(b.getOldDir() > 2*3.14)
    {
        b.setOldDir(b.getOldDir() - 2*3.14);
    }
    while(b.getOldDir() < 0)
    {
        b.setOldDir(b.getOldDir() + 2*3.14);
    }
    if (b.getOldDir() >= 0 && b.getOldDir() <= 3.14)
    {
        reflection = 3.14 - b.getOldDir();
    }
    if (b.getOldDir() >= 3.14 && b.getOldDir() <= 2*3.14)
    {
        reflection = 3.14 - b.getOldDir();
    }
    return reflection;

}
double sideBoundariesReflections::rightBoundaryReflection(ball b)
{
    double reflection;
    while(b.getOldDir() > 2*3.14)
    {
        b.setOldDir(b.getOldDir() - 2*3.14);
    }
    while(b.getOldDir() < 0)
    {
        b.setOldDir(b.getOldDir() + 2*3.14);
    }
    if (b.getOldDir() >= 0 && b.getOldDir() <= 3.14)
    {
        reflection = 3.14 - b.getOldDir();
    }
    if (b.getOldDir() >= 3.14 && b.getOldDir() <= 2*3.14)
    {
        reflection = 3.14 - b.getOldDir();
    }
    return reflection;

}
