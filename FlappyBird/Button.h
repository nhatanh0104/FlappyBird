#pragma once
#ifndef BUTTON_H__
#define BUTTON_H__

#include <iostream>
#include <SDL.h>
#include <string>

using namespace std;

class Button
{
private:
	SDL_Texture* ButtonTexture;
	SDL_Rect buttonRect;
	bool isPressed = false;

public:
	bool loadButton(SDL_Renderer* gRenderer, string path);

	void renderButton(int _x, int _y, SDL_Renderer* gRenderer);

	bool isMouseInside();

	void handleEvent(SDL_Event* e);

	bool isButtonPressed();
};

#endif // !BUTTON_H__



