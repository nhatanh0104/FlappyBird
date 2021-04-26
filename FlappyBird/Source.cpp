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
const int PIPE_GAP = 150;
const int BIRD_INITIAL_VELOCITY = 5;
const int BIRD_ACCELARATION = 10;

SDL_Rect birdSpriteClips[BIRD_ANIMATION_FRAMES];
LTexture birdSpriteSheet;

SDL_Rect baseSpriteClips[4];
LTexture baseSpriteSheet;

bool LoadBaseMedia()
{
    bool success = true;
    if (!baseSpriteSheet.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/base(Photo)(noise_scale)(Level3)(width 450).png", gRenderer))
    {
        logSDLError(std::cout, "load from file", true);
        success = false;
    }
    else
    {
        baseSpriteClips[0].x = 0;
        baseSpriteClips[0].y = 0;
        baseSpriteClips[0].w = 450;
        baseSpriteClips[0].h = 150;

        baseSpriteClips[1].x = 8;
        baseSpriteClips[1].y = 0;
        baseSpriteClips[1].w = 450;
        baseSpriteClips[1].h = 150;

        baseSpriteClips[2].x = 16;
        baseSpriteClips[2].y = 0;
        baseSpriteClips[2].w = 450;
        baseSpriteClips[2].h = 150;

        baseSpriteClips[3].x = 24;
        baseSpriteClips[3].y = 0;
        baseSpriteClips[3].w = 450;
        baseSpriteClips[3].h = 150;
    }

    return success;
}

int main(int argc, char* argv[])
{
    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    /*LTexture backgroundTexture;
    if (!backgroundTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/background-day(Photo)(noise_scale)(Level3)(width 450).png", gRenderer))
    {
        logSDLError(std::cout, "Load Background Texture", true);
    }*/

    //LTexture baseTexture;
    //if (!baseTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/base(Photo)(noise_scale)(Level3)(width 450).png", gRenderer))
    //{
    //    logSDLError(std::cout, "Load base texture", true);
    //}

    /*LTexture PipeTexture;
    if (!PipeTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/pipe-green(Photo)(noise_scale)(Level3)(width 80).png", gRenderer))
    {
        logSDLError(std::cout, "Load pipe", true);
    }*/

    SDL_Rect birdRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 7 * 3, birdSpriteSheet.getWidth() / 3, birdSpriteSheet.getHeight() };

    if (!loadMedia() || !LoadBaseMedia())
    {
        logSDLError(std::cout, "Load media", true);
    }
    else
    {
        bool quit = false;

        bool drop = false;

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
                    else if (e.key.keysym.sym == SDLK_UP)
                    {
                        birdRect.y = (birdRect.y + SCREEN_HEIGHT - 10) % SCREEN_HEIGHT;
                        drop = true;
                    }
                }
            }
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);

            backgroundTexture.render(0, 0, gRenderer);
            PipeTexture.render(300, SCREEN_HEIGHT - 400, gRenderer);
            /*baseTexture.render(0, SCREEN_HEIGHT - baseTexture.getHeight(), gRenderer);*/

            SDL_Rect* currentBirdClip = &birdSpriteClips[frame / 10];
            birdSpriteSheet.renderToTargetRect(gRenderer, &birdRect, currentBirdClip);

            SDL_Rect* currentBaseClip = &baseSpriteClips[frame / 10];
            baseSpriteSheet.render(0, SCREEN_HEIGHT - baseSpriteSheet.getHeight(), gRenderer, currentBaseClip);

            SDL_RenderPresent(gRenderer);

            ++frame;

            if (frame / 10 >= BIRD_ANIMATION_FRAMES)
            {
                frame = 0;
            }
        }
    }

    /*waitUntilKeyPressed();*/
    
    quitSDL(gWindow, gRenderer);
    return 0;
}