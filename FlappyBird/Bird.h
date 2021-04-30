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
		SDL_Texture* birdSpriteSheet;
		SDL_Rect birdSpriteClips[3];
		SDL_Rect birdRect;
		int frame1 = 0;
		int frame2 = 0;
		double birdJumpTime;
		bool birdJump = false;
		double bird_initial_location_y;
		double degree = 0;
	public:
		bool loadMedia(SDL_Renderer* gRenderer);

		void RenderBirdToLocation(SDL_Renderer* gRenderer);

		void SetBirdInitialLocation(int _x, int _y);

		void jump(SDL_Event* e);
};

#endif // !BIRD__H_
