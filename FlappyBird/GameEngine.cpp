#include "GameEngine.h"
#include <iostream>
#include <SDL.h>

using namespace std;

bool CheckRectCollision(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    return true;
}

char* intToChar(int N)
{
    char toChar[2];
    int i = 1;
    while (N != 0)
    {
        int push = N % 10;
        N = N / 10;
        toChar[i] = (char)(push + '0');
        i++;
    }
    return toChar;
}