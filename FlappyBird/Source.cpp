#define SDL_MAIN_HANDLED
#include <iostream>
#include <vector>
#include <ctime>

#include <SDL.h>
#include <SDL_image.h>

#include "SDL_utils.h"

#include "Game.h"
#include "MainMenu.h"
#include "GameStateEnum.h"

using namespace std;

// Global varible
SDL_Window* gWindow;
SDL_Renderer* gRenderer;

const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 800;

const string WINDOW_TITLE = "Flappy Bird";

int currentState = MAIN_MENU;

bool init_TTF()
{
    if (TTF_Init() == -1)
        return false;
}

bool loadEveryThing()
{
    if (!MAIN_MENU_LOAD(gRenderer)) {
        cout << "Fail to load menu\n";
        return false;
    }
    if (!GAME_LOAD(gRenderer)) {
        cout << "Fail to load game components\n";
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    srand(time(0));

    initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    if (!init_TTF()) cout << "Cannot init ttf";

    if (!loadEveryThing())
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

            gameHandleEvent(e);
            menuHandleEvent(e);
        }

        switch (currentState)
        {
        case MAIN_MENU:
            currentState = renderMainMenu(gRenderer);
            break;

        case PLAY:
            renderGame(gRenderer);
            currentState = CheckGameCollision();
            break;

        case GAME_OVER:
            renderScoreBoard(gRenderer);
            if (playAgain()) currentState = PLAY_AGAIN;
            if (quitGame()) currentState = QUIT;
            break;

        case PLAY_AGAIN:
            SetInitialLocation();
            Reset();
            currentState = PLAY;
            break;

        case QUIT:
            quit = true;
            break;
        }
    }

    return 0;
}