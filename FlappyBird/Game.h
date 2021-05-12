#ifndef GAME__H_
#define GAME__H_

// Standard C++ library
#include <iostream>
#include <vector>

//SDL2 library
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h> 

// Game class
#include "SDL_utils.h"
#include "GameEngine.h"
#include "LTexture.h"
#include "Bird.h"
#include "Base.h"
#include "Pipe.h"
#include "Button.h"
#include "GameStateEnum.h"

bool GAME_LOAD(SDL_Renderer* gRenderer);

void SetInitialLocation();

int CheckGameCollision();

void gameHandleEvent(SDL_Event e);

void renderGame(SDL_Renderer* gRenderer);

void renderScoreBoard(SDL_Renderer* gRenderer);

void Reset();

bool playAgain();

bool quitGame();

#endif // !GAME__H_