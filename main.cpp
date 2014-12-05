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
/*
Data Abstraction
Make objects and make sure the data is in the private area.

Input
Get what key strokes the user is pressing.

Process
Whatever key the person presses make the paddle move in that
direction. Also see if the ball has hit the paddle.

Output
Show the movement of the paddle.

Assumptions
The person will know what the arrow keys are.
*/



#include "gLibrary.h"

int main()
{
    Game game;

    game.play();

    return 0;
}


