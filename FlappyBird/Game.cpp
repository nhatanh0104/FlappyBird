#include "Game.h"
#include "SDL_utils.h"
#include "GameEngine.h"
#include "LTexture.h"
#include "Bird.h"
#include "Base.h"
#include "Pipe.h"

const int BIRD_ANIMATION_FRAMES = 3;
const int PIPE_GAP = 150;
const int BIRD_INITIAL_VELOCITY = 5;
const int BIRD_ACCELARATION = 10;
const int NUMBER_OF_PIPES = 4;

bool quit = false;

Bird myFlappyBird;
Base myBase;
Pipe PipeArray[4];
vector<Pipe> pipeVector;
LTexture backgroundTexture;
LTexture gameTitle;
LTexture readyMessage;

Button playButton;

bool collision = false;
bool buttonPress = false;

SDL_Event e;

int frame = 0;
int index_of_pipe = 0;
int score = 0;

bool GAME_LOAD(SDL_Renderer* gRenderer)
{
    bool success = true;

    if (!myFlappyBird.loadMedia(gRenderer))
    {
        cout << "Unable to load bird texture from file/n";
        success = false;
    }

    if (!myBase.loadMedia(gRenderer))
    {
        cout << "Unable to load base texture fromfile/n";
        success = false;
    }

    for (int i = 0; i < NUMBER_OF_PIPES; i++)
    {
        PipeArray[i].loadMedia(gRenderer);
    }

    backgroundTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/background-day(Photo)(noise_scale)(Level3)(width 450).png", gRenderer);
    readyMessage.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/ready-message.png", gRenderer);
    gameTitle.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/game-title.png", gRenderer);

    playButton.loadButton(gRenderer, "D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/play-button.png");

    return success;
}

void SetInitialLocation()
{
    myFlappyBird.SetBirdInitialLocation(80, 350);
    for (int i = 0; i < NUMBER_OF_PIPES; i++)
    {
        PipeArray[i].setPipePosition(480);
    }
}

bool CheckGameCollision()
{
    for (int i = 0; i < pipeVector.size(); i++)
    {
        if (CheckRectCollision(myFlappyBird.getBirdRect(), pipeVector[i].getPipeRectUpper()) ||
            CheckRectCollision(myFlappyBird.getBirdRect(), pipeVector[i].getPipeRectBottom()))
        {
            collision = true;
        }
    }

    return collision;
}

void handleEvent(SDL_Event e)
{
    myFlappyBird.jump(&e);
    if (playButton.isPressed(&e))
        buttonPress = true;
}

bool GetGameStatus()
{
    return quit;
}

void renderGame(SDL_Renderer* gRenderer)
{

    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

    SDL_RenderClear(gRenderer);

    backgroundTexture.render(0, 0, gRenderer, NULL);

    for (int i = 0; i < pipeVector.size(); i++)
    {
        pipeVector[i].renderPipe(gRenderer);
        if (pipeVector[i].getPipePosition() < -350)
        {
            pipeVector[i].setPipePosition(480);
            pipeVector.erase(pipeVector.begin() + i);
        }
    }

    if (frame >= 250 && myFlappyBird.getBirdJumpBoolValue() == true)
    {
        if(PipeArray[index_of_pipe].getPipePosition() == 480)
            pipeVector.push_back(PipeArray[index_of_pipe]);
        index_of_pipe++;
        if (index_of_pipe == 4) index_of_pipe = 0;
        frame = 0;
    }

    myBase.renderBase(gRenderer);

    if (buttonPress == false)
    {
        gameTitle.render(50, 150, gRenderer, NULL);
        playButton.renderButton(150, 600, gRenderer);
    }
    if (buttonPress == true)
    {
        myFlappyBird.RenderBirdToLocation(gRenderer);

        if (!myFlappyBird.getBirdJumpBoolValue())
            readyMessage.render(125, 250, gRenderer, NULL);
    }
    SDL_RenderPresent(gRenderer);

    frame++;
}
