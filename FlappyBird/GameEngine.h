#pragma once
#ifndef GAME_ENGINE__H_
#define GAME_ENGINE__H_
#include <SDL.h>
#include <iostream>

using namespace std;

bool CheckRectCollision(SDL_Rect a, SDL_Rect b);

char* intToChar(int N);

#endif // !GAME_ENGINE__H_

