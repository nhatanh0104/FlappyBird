#pragma once
#ifndef BASE__H_
#define BASE__h_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Base
{
private:
	SDL_Texture* baseTexture;
	SDL_Rect baseSpriteClips[4];
	SDL_Rect baseRect = { 0, 800 - 134, 450, 134 };
	int baseFrame = 0;
public:
	bool loadMedia(SDL_Renderer* gRenderer);
	
	void renderBase(SDL_Renderer* gRenderer);

};

#endif // !BASE__H_

