#pragma once
#ifndef PIPE__H_
#define PIPE__H_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Pipe
{
private:
	SDL_Texture* pipeTexture;
	SDL_Rect pipeRect = { 300, 400, 80, 450 };
public:
	bool loadMedia(SDL_Renderer* gRenderer);

	void renderPipe(SDL_Renderer* gRenderer);
};

#endif // !PIPE__H_

