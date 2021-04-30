#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "LTexture.h"
#include "Bird.h"

using namespace std;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 800;
const int BIRD_ANIMATION_FRAMES = 3;
const string WINDOW_TITLE = "Flappy Bird";
const int PIPE_GAP = 150;
const int BIRD_INITIAL_VELOCITY = 5;
const int BIRD_ACCELARATION = 10;

int main(int argc, char* argv[])
{
    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    SDL_Event e;
    bool quit = false;

    Bird myFlappyBird;
    if (!myFlappyBird.loadMedia(gRenderer))
        cout << "Unable to load from file/n";
    
    myFlappyBird.SetBirdInitialLocation(100, 400);
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            myFlappyBird.jump(&e);
        }


        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

        myFlappyBird.jump(&e);

        SDL_RenderClear(gRenderer);

        myFlappyBird.RenderBirdToLocation(gRenderer);

        SDL_RenderPresent(gRenderer);
    }

    waitUntilKeyPressed();

    quitSDL(gWindow, gRenderer);
    return 0;
}