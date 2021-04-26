#ifndef BIRD__H_
#define BIRD__H_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"

using namespace std;

class Bird
{
	private:
		LTexture birdSpriteSheet;
		SDL_Rect birdSpriteClips[3];
	public:
		bool loadMedia(SDL_Renderer* gRenderer);

		void RenderBirdToLocation(SDL_Renderer* gRenderer, SDL_Rect* destination, SDL_Rect* birdSpriteClips);

		void jump(SDL_Rect* birdRect);

		LTexture getLTexture();
};

#endif // !BIRD__H_
