#include "Button.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"

bool Button::loadButton(SDL_Renderer* gRenderer, string path)
{
	bool success = true;

	SDL_Surface* buttonSurface = IMG_Load(path.c_str());

	buttonRect.w = buttonSurface->w;
	buttonRect.h = buttonSurface->h;

	if (buttonSurface == NULL)
	{
		logSDLError(std::cout, "Fail load button surface", true);
		success = false;
	}
	else {
		ButtonTexture = SDL_CreateTextureFromSurface(gRenderer, buttonSurface);
	}

	SDL_FreeSurface(buttonSurface);

	return success;
}

void Button::renderButton(int _x, int _y, SDL_Renderer* gRenderer)
{
	buttonRect.x = _x;
	buttonRect.y = _y;

	SDL_RenderCopy(gRenderer, ButtonTexture, NULL, &buttonRect);
}

bool Button::isMouseInside()
{
	bool inside = false;

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	if (mouseX > buttonRect.x &&
		mouseX <= buttonRect.x + buttonRect.w &&
		mouseY > buttonRect.y &&
		mouseY <= buttonRect.y + buttonRect.h)
			inside = true;

	return inside;
}

bool Button::isPressed(SDL_Event *e)
{
	bool press = false;

	if (this->isMouseInside())
	{
		if (e->type == SDL_MOUSEBUTTONDOWN)
			press = true;
	}

	return press;
}
