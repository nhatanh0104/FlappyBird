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

bool GAME_LOAD(SDL_Renderer* gRenderer);

void SetInitialLocation();

bool CheckGameCollision();

void handleEvent(SDL_Event e);

bool GetGameStatus();

void renderGame(SDL_Renderer* gRenderer);

#endif // !GAME__H_