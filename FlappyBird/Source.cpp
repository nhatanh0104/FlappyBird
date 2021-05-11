#define SDL_MAIN_HANDLED
#include <iostream>
#include <vector>
#include <ctime>

#include <SDL.h>
#include <SDL_image.h>

#include "SDL_utils.h"
#include "LTexture.h"
#include "Bird.h"
#include "Base.h"
#include "Pipe.h"
#include "Game.h"

using namespace std;

// Global varible
SDL_Window* gWindow;
SDL_Renderer* gRenderer;

const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 800;

const string WINDOW_TITLE = "Flappy Bird";

//const int BIRD_ANIMATION_FRAMES = 3;
//const int PIPE_GAP = 150;
//const int BIRD_INITIAL_VELOCITY = 5;
//const int BIRD_ACCELARATION = 10;
//const int NUMBER_OF_PIPES = 4;

int main(int argc, char* argv[])
{
    srand(time(0));

    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    //SDL_Event e;
    //bool quit = false;

    //Bird myFlappyBird;
    //if (!myFlappyBird.loadMedia(gRenderer))
    //    cout << "Unable to load bird texture from file/n";

    //Base myBase;
    //if (!myBase.loadMedia(gRenderer))
    //    cout << "Unable to load base texture from file/n";

    //vector<Pipe> pipeVector;

    //Pipe PipeArray[NUMBER_OF_PIPES];
    //for (int i = 0; i < NUMBER_OF_PIPES; i++)
    //{
    //    PipeArray[i].loadMedia(gRenderer);
    //}

    //LTexture backgroundTexture;
    //backgroundTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/background-day(Photo)(noise_scale)(Level3)(width 450).png", gRenderer);
    //
    //myFlappyBird.SetBirdInitialLocation(80, 350);


    //while (!quit)
    //{
    //    while (SDL_PollEvent(&e) != 0) {
    //        if (e.type == SDL_QUIT) {
    //            quit = true;
    //        }
    //        myFlappyBird.jump(&e);
    //    }


    //    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

    //    SDL_RenderClear(gRenderer);

    //    backgroundTexture.render(0, 0, gRenderer, NULL);

    //    if (frame >= 250 && myFlappyBird.getBirdJumpBoolValue() == true)
    //    {
    //        if(PipeArray[index_of_pipe].getPipePosition() == 480)
    //            pipeVector.push_back(PipeArray[index_of_pipe]);
    //        index_of_pipe++;
    //        if (index_of_pipe == 4) index_of_pipe = 0;
    //        frame = 0;
    //    }
    //    
    //    for (int i = 0; i < pipeVector.size(); i++)
    //    {
    //        pipeVector[i].renderPipe(gRenderer);
    //        if (pipeVector[i].getPipePosition() < -350)
    //        {
    //            pipeVector[i].setPipePosition(480);
    //            pipeVector.erase(pipeVector.begin() + i);
    //        }

    //        if (myFlappyBird.getBirdRect().x == pipeVector[i].getPipeRectBottom().x + pipeVector[i].getPipeRectBottom().w)
    //            score++;   // Check score

    //        if (CheckCollision(myFlappyBird.getBirdRect(), pipeVector[i].getPipeRectUpper()) ||
    //            CheckCollision(myFlappyBird.getBirdRect(), pipeVector[i].getPipeRectBottom()))
    //        {
    //            quitSDL(gWindow, gRenderer);
    //            cout << "Your score: " << score;
    //            return 0;
    //        }              // Check collision
    //    }

    //    myBase.renderBase(gRenderer);

    //    myFlappyBird.RenderBirdToLocation(gRenderer);

    //    SDL_RenderPresent(gRenderer);

    //    frame++;
    //}

    srand(time(0));

    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    if (!GAME_LOAD(gRenderer))
    cout << "Fail to load Game";

    SDL_Event e;

    bool quit = false;

    SetInitialLocation();

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;

            handleEvent(e);
        }

        renderGame(gRenderer);

        if (CheckGameCollision()) return 0;
    }

    return 0;
}