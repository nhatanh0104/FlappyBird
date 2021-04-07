#pragma once
#ifndef LTEXTURE__H_
#define LTEXTURE__H_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class LTexture
{
public:
	LTexture();

	~LTexture();

	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);

	void free();

	void render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL);

	void renderToTargetRect(SDL_Renderer* gRenderer, SDL_Rect* destination, SDL_Rect* clip = NULL);

	int getWidth();
	int getHeight();

private:
	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;
};

#endif // !

