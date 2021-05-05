#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Pipe.h"

using namespace std;

bool Pipe::loadMedia(SDL_Renderer* gRenderer)
{
	bool success = true;

	SDL_Surface* pipeSurface = IMG_Load("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/pipe-green(Photo)(noise_scale)(Level3)(width 80).png");
	
	if (pipeSurface == NULL)
	{
		logSDLError(std::cout, "Failed to load pipe texture from file", true);
		bool success = false;
	}
	else
	{
		pipeTexture = SDL_CreateTextureFromSurface(gRenderer, pipeSurface);
	}

	SDL_FreeSurface(pipeSurface);

	return success;
}

void Pipe::renderPipe(SDL_Renderer* gRenderer)
{
	SDL_RenderCopy(gRenderer, pipeTexture, NULL, &pipeRectBottom);

	SDL_RenderCopyEx(gRenderer, pipeTexture, NULL, &pipeRectUpper, 180, NULL, SDL_FLIP_NONE);

	pipeFrame++;

	if (pipeFrame == 1)
	{
		pipeFrame = 0;
		pipeRectBottom.x--;
		pipeRectUpper.x--;
	}
}

Pipe::Pipe(SDL_Renderer* gRenderer)
{
	pipeRectBottom.y = rand() % 150 + 350;
	pipeRectUpper.y = pipeRectBottom.y - 180 - 450;
	this->loadMedia(gRenderer);
}
