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

    paddleType::paddleType (int w, ink c,
                   int r, int col)
    {
        width = w;
        color = c;
        rows = r;
        cols = col;
        loc.setX(col/2);
        loc.setY(rows - 1);
        oldLoc = Point(0,0);
    }
    void paddleType::draw (Plotter& g)
    {
        if (oldLoc.getX() != loc.getX())
        {
            g.setColor(color);
            for(int i = -width/2; i <= width/2; i ++)
            {
                g.plot(loc.getX() + i, loc.getY(), SQUARE);
            }
        }
        oldLoc = loc;
    }
    void paddleType::erase (Plotter& g)
    {
        if (oldLoc.getX() != loc.getX())
        {
            g.setColor(black);
            for(int i = -width/2; i <= width/2; i ++)
            {
                g.plot(oldLoc.getX() + i, oldLoc.getY(), SQUARE);
            }
        }
    }
    void paddleType::move (int i)
    {

        loc.setX(loc.getX() + i);
    }
    bool paddleType::hitByBall(ball b)
    {
         bool hit;
         hit = (loc.getY()) <= (b.getLoc().getY());
         if(hit)
         {
             hit = (loc.getX() - width/2) <= (b.getLoc().getX()) &&
                   (loc.getX() + width/2) >= (b.getLoc().getX());

         }
         return hit;
    }
    Point paddleType::getLoc()
    {
        return loc;
    }
    bool paddleType::paddleHitWall (int col)
    {
        bool HitWall = false;
        if (loc.getX() == col)
        {
            HitWall = true;
        }
        return HitWall;
    }
    double paddleType::ballHitOuterPaddle(ball b)
    {
        double directions;
        if(b.getOldDir() > 2*3.14)
        {
            b.setOldDir(b.getOldDir() - 2*3.14);
        }
        if(b.getOldDir() < 0)
        {
            b.setOldDir(b.getOldDir() + 2*3.14);
        }
        if ((loc.getY()) <= (b.getLoc().getY()))
        {
            if ((loc.getX() - width/2) <= (b.getLoc().getX()) && (loc.getX() - width/2 + 3) >= (b.getLoc().getX()))
            {
                if(b.getOldDir() >= 3.14 && b.getOldDir() <= 3*3.14/2)
                {
                    directions = 5*3.14/6;
                }
                else
                {
                    directions = 3.14/2;
                }
            }
            if((loc.getX() + width/2 + 2) >= (b.getLoc().getX()) && (loc.getX() + width/2 - 3) <= (b.getLoc().getX()))
            {
                if(b.getOldDir() >= 3*3.14/2 && b.getOldDir() <= 2*3.14)
                {
                    directions = 3.14/6;
                }
                else
                {
                    directions = 3.14/2;
                }
            }
        }
        return directions;
    }
    double paddleType::ballHitInnerPaddle(ball b)
    {
        double directions;
        if(b.getOldDir() > 2*3.14)
        {
            b.setOldDir(b.getOldDir() - 2*3.14);
        }
        if(b.getOldDir() < 0)
        {
            b.setOldDir(b.getOldDir() + 2*3.14);
        }
        if ((loc.getY()) <= (b.getLoc().getY()))
        {
            if ((loc.getX() - width/2 + 3) <= (b.getLoc().getX()) && (loc.getX() - width/2 + 10) >= (b.getLoc().getX()))
            {
                if(b.getOldDir() >= 3.14 && b.getOldDir() <= 3*3.14/2)
                {
                    directions = 2*3.14/3;
                }
                else
                {
                    directions = 3.14/3;
                }
            }
            if((loc.getX() + width/2 - 3) >= (b.getLoc().getX()) && (loc.getX() + width/2 - 10) <= (b.getLoc().getX()))
            {
                if(b.getOldDir() >= 3*3.14/2 && b.getOldDir() <= 2*3.14)
                {
                    directions = 3.14/3;
                }
                else
                {
                    directions = 2*3.14/3;
                }
            }
        }
        return directions;
    }
    double paddleType::ballHitMiddlePaddle(ball b)
    {
        double directions;
        if ((loc.getY()) <= (b.getLoc().getY()))
        {
            if ((loc.getX() - width/2 + 10) <= (b.getLoc().getX()) && (loc.getX() + width/2 - 10) >= (b.getLoc().getX()))
            {
                directions = -b.getOldDir();
            }
        }
        return directions;
    }

    void paddleType::ballStuckToPaddle(ball gameBall, Plotter& screen)
    {
        int key = 0;
        key = getch();
        while(key != 32)
        {
            if (kbhit())
            {

                key = getch();
                if (key == 224)
                {
                    key = getch();
                }
                if (key == 77 && !paddleHitWall(224))
                {
                    move(1);
                }
                if (key == 75 && !paddleHitWall(15))
                {
                    move(-1);
                }
                erase(screen);
                draw(screen);
                gameBall.erase(screen);
                gameBall.draw(screen);

            }
        }
    }
