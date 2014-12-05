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


    Game::Game()
    {
        gameOver = false;
        active = true;
        gameBall.setSpeed(.2);
    }

void Game::play()
{

        PlaySound("www.ringersmobile.comSpongebob-SweetVictory.wav", NULL, SND_LOOP | SND_NOSTOP | SND_ASYNC | SND_NODEFAULT);
        cout << "BREAK THEM BRICKS THO!" << endl;
        cout << "LEVEL 1: YOU HAVE 3 LIVES" << endl;
        cout << "PRESS SPACE TO START SMASHIN'" << endl;

        bool space = false;
    do
    {

        int key;
        if(kbhit())
        {
            key = getch();
            space = true;
        }
    }while( !space );
    int count = 3, cCount = WALL_ROWS * WALL_COLS;
    bool secondlvl = false;
    srand(time(0));
    for(int r = 0; r < WALL_ROWS; r++)
    {
        for(int c = 0; c < WALL_COLS; c++)
        {

            wall[r][c].setColor(ink(rand()%15+1));
            wall[r][c].setLoc(Point(c * 21 + 14, r * 3 + 12));
            wall[r][c].draw(screen);
        }
    }

    paddle.ballStuckToPaddle(gameBall, screen);
    gameBall.setLoc(paddle.getLoc());


    while(!gameOver && !secondlvl)
    {

        paddle.draw(screen);
        gameBall.setOldDir(gameBall.getDir());
        if (kbhit())
        {

            key = getch();
            if (key == 224)
            {
                key = getch();
            }
            if (key == 77 && !paddle.paddleHitWall(224))
            {
                paddle.move(1);
            }
            if (key == 75 && !paddle.paddleHitWall(15))
            {
                paddle.move(-1);
            }
            if(key == 96)
            {

                secondlvl = true;
            }
            paddle.erase(screen);
            paddle.draw(screen);
        }
        if (gameBall.ballHitLeftWall(gameBall, 0))
        {
            gameBall.setDir(Reflections.leftBoundaryReflection(gameBall));
            gameBall.setOldDir(gameBall.getDir());
        }
        if (gameBall.ballHitTopWall(gameBall, 4))
        {
            gameBall.setDir(Reflections.topBoundaryReflection(gameBall));
            gameBall.setOldDir(gameBall.getDir());
        }
        if (gameBall.ballHitRightWall(gameBall, 240) == true)
        {
            gameBall.setDir(Reflections.rightBoundaryReflection(gameBall));
            gameBall.setOldDir(gameBall.getDir());
        }

        if (paddle.hitByBall(gameBall))
        {
            gameBall.setDir(paddle.ballHitOuterPaddle(gameBall));
            gameBall.setDir(paddle.ballHitInnerPaddle(gameBall));
            gameBall.setDir(paddle.ballHitMiddlePaddle(gameBall));
            gameBall.setSpeed(gameBall.getSpeed() + .02);
            gameBall.setOldDir(gameBall.getDir());

        }

            gameBall.erase(screen);
            gameBall.draw(screen);
            gameBall.setOldLoc(gameBall.getLoc());
            gameBall.move();
            paddle.draw(screen);
            Sleep(10);

        if(gameBall.ballHitBottomWall(gameBall, 97))
        {
            count --;
            gameBall.setSpeed(.2);
            cout << "Lives = " << count;
            paddle.ballStuckToPaddle(gameBall, screen);

            if(count == 0)
            {
                PlaySound("Goathelm 1 (long).wav", NULL, SND_LOOP);
                gameOver = true;

            }
            gameBall.setLoc(paddle.getLoc());
        }
        for(int r = 0; r < WALL_ROWS; r++)
        {
            for(int c = 0; c < WALL_COLS; c++)
            {
                if (wall[r][c].getColor() !=  black)
                {
                           switch(wall[r][c].ballHitBrick(gameBall))
                           {
                               case 1: gameBall.setDir(gameBall.newDir());
                               case 2: gameBall.setDir(gameBall.newDir());
                                wall[r][c].setColor(black);
                                wall[r][c].draw(screen);
                                cCount--;
                           }
                            if((gameBall.getLoc().getX() >= wall[r][c].getLoc().getX() - 10) && (gameBall.getLoc().getX() <= wall[r][c].getLoc().getX() + 12))
                            {
                                if(gameBall.getLoc().getY() >= wall[r][c].getLoc().getY() && gameBall.getLoc().getY() <= wall[r][c].getLoc().getY() + 4)
                                {
                                    gameBall.setDir(-gameBall.getDir());
                                    wall[r][c].setColor(black);
                                    wall[r][c].draw(screen);
                                    cCount--;

                                }
                            }




                }
            }
        }
    }
    PlaySound("Where's-the-pizza.wav", NULL, SND_ASYNC);
    if(!gameOver)
    {
        for(int r = 0; r < WALL_ROWS; r++)
        {
            for(int c = 0; c < WALL_COLS; c++)
            {
                wall[r][c].setColor(black);
                wall[r][c].draw(screen);
            }
        }
        int bricks = 0;
        do
        {
            fallingBall[bricks].setLoc(Point(bricks, 3));
            //fallingBall[bricks].erase(screen);
            fallingBall[bricks].draw(screen);
            while(int (fallingBall[bricks].getLoc().getY()) != 90)
            {
                fallingBall[bricks].setDir(3*3.14/2);
                fallingBall[bricks].move();
                fallingBall[bricks].erase(screen);
                fallingBall[bricks].draw(screen);
                fallingBall[bricks].setSpeed(.2);
                Sleep(0);

                 PlaySound("www.ringersmobile.comSpongebob-SweetVictory.wav", NULL, SND_LOOP | SND_NOSTOP | SND_ASYNC | SND_NODEFAULT);
            }
            if(fallingBall[bricks].ballHitBottomWall(fallingBall[bricks], 90))
            {
                fallingBall[bricks].erase(screen);
            }
            bricks += 10;
        }while(bricks != 240);

        int o = 5, d = 10;
        wall[o][d].setColor(red);
        wall[o][d].draw(screen);
        paddle.ballStuckToPaddle(gameBall, screen);
        gameBall.setLoc(paddle.getLoc());
    }
    int o = 5, d = 10;
    count += 5;
    while(!gameOver)
    {


        if (wall[o][d].getColor() !=  black)
        {
            switch(wall[o][d].ballHitBrick(gameBall))
            {
                case 1: gameBall.setDir(gameBall.newDir());
                case 2: gameBall.setDir(gameBall.newDir());

                wall[o][d].setColor(black);
                wall[o][d].draw(screen);
                d--;
                wall[o][d].setColor(red);
                wall[o][d].draw(screen);

            }
            if((gameBall.getLoc().getX() >= wall[o][d].getLoc().getX() - 10) && (gameBall.getLoc().getX() <= wall[o][d].getLoc().getX() + 12))
            {
                if(gameBall.getLoc().getY() >= wall[o][d].getLoc().getY() && gameBall.getLoc().getY() <= wall[o][d].getLoc().getY() + 4)
                {
                    gameBall.setDir(-gameBall.getDir());

                    wall[o][d].setColor(black);
                    wall[o][d].draw(screen);

                    d--;
                    wall[o][d].setColor(red);
                    wall[o][d].draw(screen);
                }
            }
        }

        if(d == -1)
        {
            o--;
            d = 11;
        }


        paddle.draw(screen);
        gameBall.setOldDir(gameBall.getDir());
        if (kbhit())
        {

            key = getch();
            if (key == 224)
            {
                key = getch();
            }
            if (key == 77 && !paddle.paddleHitWall(224))
            {
                paddle.move(1);
            }
            if (key == 75 && !paddle.paddleHitWall(15))
            {
                paddle.move(-1);
            }
            paddle.erase(screen);
            paddle.draw(screen);
        }
        if (gameBall.ballHitLeftWall(gameBall, 0))
        {
            gameBall.setDir(Reflections.leftBoundaryReflection(gameBall));
            gameBall.setOldDir(gameBall.getDir());
        }
        if (gameBall.ballHitTopWall(gameBall, 4))
        {
            gameBall.setDir(Reflections.topBoundaryReflection(gameBall));
            gameBall.setOldDir(gameBall.getDir());
        }
        if (gameBall.ballHitRightWall(gameBall, 240) == true)
        {
            gameBall.setDir(Reflections.rightBoundaryReflection(gameBall));
            gameBall.setOldDir(gameBall.getDir());
        }

        if (paddle.hitByBall(gameBall))
        {
            gameBall.setDir(paddle.ballHitOuterPaddle(gameBall));
            gameBall.setDir(paddle.ballHitInnerPaddle(gameBall));
            gameBall.setDir(paddle.ballHitMiddlePaddle(gameBall));
            gameBall.setSpeed(gameBall.getSpeed() + .02);
            gameBall.setOldDir(gameBall.getDir());

        }


            gameBall.erase(screen);
            gameBall.draw(screen);
            gameBall.setOldLoc(gameBall.getLoc());
            gameBall.move();
            paddle.draw(screen);
            Sleep(10);

        if(gameBall.ballHitBottomWall(gameBall, 97) || d == -1 && o == 0)
        {
            count --;
            gameBall.setSpeed(.2);
            cout << "Lives = " << count;
            paddle.ballStuckToPaddle(gameBall, screen);
            if(count == 0)
            {
                gameOver = true;
                PlaySound("Goathelm 1 (long).wav", NULL, SND_LOOP | SND_ASYNC);
            }
            if(d == -1 && o == 0)
            {
                cout << "CONGRATULATIONS! NOW GET OUTSIDE AND DO SOMETHING!" << endl;
            }
            gameBall.setLoc(paddle.getLoc());
        }

    }


}
