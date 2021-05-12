#pragma once
#ifndef MAIN_MENU__H_
#define MAIN_MENU__H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Button.h"
#include "GameStateEnum.h"

using namespace std;

bool MAIN_MENU_LOAD(SDL_Renderer* gRenderer);

int renderMainMenu(SDL_Renderer* gRenderer);

void menuHandleEvent(SDL_Event e);

#endif // !MAIN_MENU__H_

