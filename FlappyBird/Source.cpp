#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "LTexture.h"

using namespace std;

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal = false);

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 800;
const int BIRD_ANIMATION_FRAMES = 3;
const string WINDOW_TITLE = "Flappy Bird";

SDL_Rect birdSpriteClips[BIRD_ANIMATION_FRAMES];
LTexture birdSpriteSheet;

bool loadMedia()
{
    bool success = true;
    if (!birdSpriteSheet.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/Debug/FlappyBirdAssets/sprites/yellowbird.png", gRenderer))
    {
        logSDLError(cout, "load from file");
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

int main(int argc, char* argv[])
{
    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT,  WINDOW_TITLE);

    LTexture backgroundTexture;

    SDL_Rect backgroundRender = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    backgroundTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/Debug/FlappyBirdAssets/sprites/background-day(Photo)(noise_scale)(Level3)(width 450).png", gRenderer);
    
    if (!loadMedia())
    {
        logSDLError(cout, "Load media");
    }
    else
    {
        bool quit = false;

        SDL_Event e;

        int frame = 0;

        while (!quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                if (e.type == SDL_KEYDOWN)
                {
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                        quit = true;
                }
            }
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);

            backgroundTexture.render(0, 0, gRenderer);


            SDL_Rect* currentClip = &birdSpriteClips[frame / 20];
            birdSpriteSheet.render(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 7 *3, gRenderer, currentClip);

            SDL_RenderPresent(gRenderer);

            ++frame;

            if (frame / 20 >= BIRD_ANIMATION_FRAMES)
                frame = 0;
        }
    }

    waitUntilKeyPressed();
    
    quitSDL(gWindow, gRenderer);
    return 0;
}