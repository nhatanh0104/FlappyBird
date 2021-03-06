#pragma once
#ifndef PIPE__H_
#define PIPE__H_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

using namespace std;

class Pipe
{
private:
	SDL_Texture* pipeTexture;
	SDL_Rect pipeRectUpper = {480, 0, 80, 450};
	SDL_Rect pipeRectBottom = {480, 0, 80, 450};
	int pipeFrame = 0;
public:
	Pipe();

	bool loadMedia(SDL_Renderer* gRenderer);

	void renderPipe(SDL_Renderer* gRenderer);

	SDL_Rect getPipeRectUpper();

	SDL_Rect getPipeRectBottom();

	int getPipePosition();

	void setPipePosition(int pipePositionXAxis);
};

#endif // !PIPE__H_

