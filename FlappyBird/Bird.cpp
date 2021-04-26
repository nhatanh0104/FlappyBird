#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "LTexture.h"
#include "Bird.h"

using namespace std;

const int BIRD_ANIMATION_FRAMES = 3;
const int BIRD_INITIAL_VELOCITY = 5;
const int BIRD_ACCELARATION = 10;
int frame = 0;

bool Bird::loadMedia(SDL_Renderer* gRenderer)
{
    bool success = true;
    if (!birdSpriteSheet.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/yellowbird.png", gRenderer))
    {
        logSDLError(std::cout, "load from file", true);
        success = false;
    }
    else
    {
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

    return success;
}

void Bird::RenderBirdToLocation(SDL_Renderer* gRenderer, SDL_Rect* destination, SDL_Rect* birdSpriteClips)
{
    SDL_Rect* currentClip = birdSpriteClips[frame / 10];
    birdSpriteSheet.renderToTargetRect(gRenderer, destination, currentClip);
}

void Bird::jump(SDL_Rect* birdRect)
{
    
}

LTexture Bird::getLTexture()
{
    return birdSpriteSheet;
}