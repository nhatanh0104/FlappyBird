#include <SDL_ttf.h>
#include "Game.h"
#include "SDL_utils.h"
#include "GameEngine.h"
#include "LTexture.h"
#include "Bird.h"
#include "Base.h"
#include "Pipe.h"
#include "GameStateEnum.h"

const int BIRD_ANIMATION_FRAMES = 3;
const int PIPE_GAP = 150;
const int BIRD_INITIAL_VELOCITY = 5;
const int BIRD_ACCELARATION = 10;
const int NUMBER_OF_PIPES = 4;

bool quit = false;

TTF_Font* FlappyBirdy;

Bird myFlappyBird;
Base myBase;
Pipe PipeArray[4];
vector<Pipe> pipeVector;
LTexture backgroundTexture;
LTexture readyMessage;
SDL_Rect HighScoreRect = { 350, 400, 25, 25 };

LTexture gameOver;
LTexture scoreBoard;
Button playAgainButton;
Button quitButton;

bool collision = false;

SDL_Event e;

int frame = 0;
int index_of_pipe = 0;
int score = 0;

bool GAME_LOAD(SDL_Renderer* gRenderer)
{
    bool success = true;

    FlappyBirdy = TTF_OpenFont("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/fonts/flappy-bird-font.ttf", 20);

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

    if (!scoreBoard.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/score-board.png", gRenderer))
    {
        cout << "Failed to load score board\n";
        return false;
    }

    backgroundTexture.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/background-day.png", gRenderer);
    readyMessage.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/ready-message.png", gRenderer);

    gameOver.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/game-over.png", gRenderer);
    playAgainButton.loadButton(gRenderer, "D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/play-button.png");
    quitButton.loadButton(gRenderer, "D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/exit-button.png");
    return success;
}

void renderScore(SDL_Renderer* gRenderer)
{
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(FlappyBirdy, intToChar(score), { 0, 0, 0, 0 });

    SDL_Texture* score = SDL_CreateTextureFromSurface(gRenderer, scoreSurface);

    SDL_RenderCopy(gRenderer, score, NULL, &HighScoreRect);

    SDL_RenderPresent;
}

void SetInitialLocation()
{
    myFlappyBird.SetBirdInitialLocation(80, 350);
    for (int i = 0; i < NUMBER_OF_PIPES; i++)
    {
        PipeArray[i].setPipePosition(480);
    }
}

int CheckGameCollision()
{
    for (int i = 0; i < pipeVector.size(); i++)
    {
        if (CheckRectCollision(myFlappyBird.getBirdRect(), pipeVector[i].getPipeRectUpper()) ||
            CheckRectCollision(myFlappyBird.getBirdRect(), pipeVector[i].getPipeRectBottom()))
        {
            collision = true;
        }
    }

    if (CheckRectCollision(myFlappyBird.getBirdRect(), myBase.getBaseRect()))
        collision = true;
    
    if (collision == true) return GAME_OVER;
    else return PLAY;
}

void gameHandleEvent(SDL_Event e)
{
    myFlappyBird.jump(&e);
    playAgainButton.handleEvent(&e);
    quitButton.handleEvent(&e);
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

        if (pipeVector[i].getPipeRectBottom().x + pipeVector[i].getPipeRectBottom().w == myFlappyBird.getBirdRect().x)
            score++;
    }

    if (frame >= 250 && myFlappyBird.getBirdJumpBoolValue() == true)
    {
        if(PipeArray[index_of_pipe].getPipePosition() == 480)
            pipeVector.push_back(PipeArray[index_of_pipe]);
        index_of_pipe++;
        if (index_of_pipe == 4) index_of_pipe = 0;
        frame = 0;
    }
    
    myFlappyBird.RenderBirdToLocation(gRenderer);

    if (!myFlappyBird.getBirdJumpBoolValue())
        readyMessage.render(125, 250, gRenderer, NULL);

    myBase.renderBase(gRenderer);

    SDL_RenderPresent(gRenderer);

    frame++;
}

void renderScoreBoard(SDL_Renderer* gRenderer)
{
    gameOver.render(50, 100, gRenderer, NULL);

    scoreBoard.render(50, 300, gRenderer, NULL);
    playAgainButton.renderButton(50, 500, gRenderer);
    quitButton.renderButton(250, 500, gRenderer);

    SDL_RenderPresent(gRenderer);
}

void Reset()
{
    pipeVector.clear();
    for (int i = 0; i < NUMBER_OF_PIPES; i++)
    {
        PipeArray[i].setPipePosition(480);
    }

    frame = 0;
    index_of_pipe = 0;
    score = 0;
    
    myFlappyBird.SetBirdInitialLocation(80, 350);
    
    collision = false;
}

bool playAgain()
{
    return playAgainButton.isButtonPressed();
}

bool quitGame()
{
    return quitButton.isButtonPressed();
}