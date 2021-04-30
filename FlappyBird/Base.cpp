 #include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Base.h"

using namespace std;

const int BASE_ANIMATION_FRAMES = 4;

bool Base::loadMedia(SDL_Renderer* gRenderer)
{
    bool success = true;

    SDL_Surface* baseSurface = IMG_Load("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/base(Photo)(noise_scale)(Level3)(width 450).png");

    if (baseSurface == NULL)
    {
        logSDLError(std::cout, "Failed to load base texture from file", true);
        success = false;
    }
    else
    {
        baseTexture = SDL_CreateTextureFromSurface(gRenderer, baseSurface);

        baseSpriteClips[0].x = 0;
        baseSpriteClips[0].y = 0;
        baseSpriteClips[0].w = 450;
        baseSpriteClips[0].h = 134;

        baseSpriteClips[1].x = 8;
        baseSpriteClips[1].y = 0;
        baseSpriteClips[1].w = 450;
        baseSpriteClips[1].h = 134;
        
        baseSpriteClips[2].x = 16;
        baseSpriteClips[2].y = 0;
        baseSpriteClips[2].w = 450;
        baseSpriteClips[2].h = 134;

        baseSpriteClips[3].x = 24;
        baseSpriteClips[3].y = 0;
        baseSpriteClips[3].w = 450;
        baseSpriteClips[3].h = 134;
    }

    SDL_FreeSurface(baseSurface);

    return success;
}

void Base::renderBase(SDL_Renderer* gRenderer)
{
    SDL_Rect* currentClip = &baseSpriteClips[baseFrame / 5];

    SDL_RenderCopy(gRenderer, baseTexture, currentClip, &baseRect);

    baseFrame++;

    if (baseFrame / 5 >= BASE_ANIMATION_FRAMES) baseFrame = 0;
}

