#define SDL_MAIN_HANDLED
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "LTexture.h"
#include "Bird.h"
#include "Base.h"
#include "Pipe.h"

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
const int NUMBER_OF_PIPES = 4;

int main(int argc, char* argv[])
{
    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    int frame = 0;

    SDL_Event e;
    bool quit = false;

    Bird myFlappyBird;
    if (!myFlappyBird.loadMedia(gRenderer))
        cout << "Unable to load bird texture from file/n";

    Base myBase;
    if (!myBase.loadMedia(gRenderer))
        cout << "Unable to load base texture from file/n";

    vector<Pipe> pipeVector;

    LTexture backgroundTexture;
    backgroundTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/background-day(Photo)(noise_scale)(Level3)(width 450).png", gRenderer);
    
    myFlappyBird.SetBirdInitialLocation(100, 350);
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            myFlappyBird.jump(&e);
        }


        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

        SDL_RenderClear(gRenderer);

        backgroundTexture.render(0, 0, gRenderer, NULL);

        if (frame >= 250)
        {
            Pipe* newPipe = new Pipe(gRenderer);
            pipeVector.push_back(*newPipe);
            frame = 0;
        }
        
        for (int i = 0; i < pipeVector.size(); i++)
        {
            pipeVector[i].renderPipe(gRenderer);
        }

        myBase.renderBase(gRenderer);

        myFlappyBird.RenderBirdToLocation(gRenderer);

        SDL_RenderPresent(gRenderer);

        frame++;
    }

    waitUntilKeyPressed();

    quitSDL(gWindow, gRenderer);
    return 0;
}