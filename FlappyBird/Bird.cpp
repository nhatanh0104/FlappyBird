#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "Bird.h"

using namespace std;

const int BIRD_ANIMATION_FRAMES = 3;
const double BIRD_INITIAL_VELOCITY = 9.5 ;
const double BIRD_ACCELARATION = 0.5;

bool Bird::loadMedia(SDL_Renderer* gRenderer)
{
    bool success = true;

    SDL_Surface* birdSurface = IMG_Load("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/yellowbird.png");

    birdRect.w = birdSurface->w / 3;
    birdRect.h = birdSurface->h;

    if (birdSurface == NULL)
    {
        logSDLError(std::cout, "Failed to load from file", true);
        success = false;
    }
    else
    {
        birdSpriteSheet = SDL_CreateTextureFromSurface(gRenderer, birdSurface);

        birdSpriteClips[0].x = 0;
        birdSpriteClips[0].y = 0;
        birdSpriteClips[0].w = 55;
        birdSpriteClips[0].h = 38;

        birdSpriteClips[1].x = 55;
        birdSpriteClips[1].y = 0;
        birdSpriteClips[1].w = 55;
        birdSpriteClips[1].h = 38;

        birdSpriteClips[2].x = 110;
        birdSpriteClips[2].y = 0;
        birdSpriteClips[2].w = 55;
        birdSpriteClips[2].h = 38;
    }

    SDL_FreeSurface(birdSurface);

    return success;
}

void Bird::RenderBirdToLocation(SDL_Renderer* gRenderer)
{
    SDL_Rect* currentClip = &birdSpriteClips[birdRenderFrame / 12];
    if (birdJump == true)

        birdRect.y = bird_initial_location_y - (BIRD_INITIAL_VELOCITY * birdJumpTime - 0.5 * (BIRD_ACCELARATION * birdJumpTime * birdJumpTime));
    
    SDL_RenderCopyEx(gRenderer, birdSpriteSheet, currentClip, &birdRect, degree, NULL, SDL_FLIP_NONE);

    birdRenderFrame++;
    birdJumpFrame++;

    if (birdRenderFrame / 12 >= BIRD_ANIMATION_FRAMES)
    {
        birdRenderFrame = 0;
    }
    if (birdJumpFrame / 2 == 1)
    {
        birdJumpTime++;
        birdJumpFrame = 0;
        if (degree < 30 && birdJump == true) degree++;
    }
}

void Bird::SetBirdInitialLocation(int _x, int _y)
{
    birdRect.x = _x;
    birdRect.y = _y;

    bird_initial_location_y = _y;
}

void Bird::jump(SDL_Event* e)
{
    if (e->type == SDL_KEYDOWN)
    {
        if (e->key.keysym.sym == SDLK_SPACE)
        {
            bird_initial_location_y = birdRect.y;
            birdJumpTime = 0;
            degree = -30;
            birdJump = true;
        }
    }
}

SDL_Rect Bird::getBirdRect()
{
    return birdRect;
}

bool Bird::getBirdJumpBoolValue()
{
    return birdJump;
}
