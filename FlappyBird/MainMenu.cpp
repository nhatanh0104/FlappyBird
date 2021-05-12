#include <SDL.h>
#include "MainMenu.h"
#include "Button.h"
#include "LTexture.h"

LTexture background;
LTexture gameTitle;

Button playButton;
Button exitButton;

Button playAgain;

bool MAIN_MENU_LOAD(SDL_Renderer* gRenderer)
{
	if (!background.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/background-day.png", gRenderer))
	{
		cout << "Failed to load background\n";
		return false;
	}

	if (!gameTitle.loadFromFile("D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/game-title.png", gRenderer))
	{
		cout << "Failed to load game title\n";
		return false;
	}

	if (!playButton.loadButton(gRenderer, "D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/play-button.png"))
	{
		cout << "Failed to load play button\n";
		return false;
	}

	if (!exitButton.loadButton(gRenderer, "D:/FirstYear/Code/GameProjectAssignment/FlappyBirdGame/FlappyBird/FlappyBirdAssets/sprites/exit-button.png"))
	{
		cout << "Failed to load exit button\n";
		return false;
	}

	return true;
}
 
int renderMainMenu(SDL_Renderer* gRenderer)
{
	int gameState = MAIN_MENU;

	background.render(0, 0, gRenderer, NULL);

	gameTitle.render(50, 100, gRenderer, NULL);

	playButton.renderButton(50, 500, gRenderer);

	exitButton.renderButton(250, 500, gRenderer);

	SDL_RenderPresent(gRenderer);

	if (playButton.isButtonPressed())
		gameState = PLAY;
	if (exitButton.isButtonPressed())
		gameState = QUIT;

	return gameState;
}

void menuHandleEvent(SDL_Event e)
{
	playButton.handleEvent(&e);
	exitButton.handleEvent(&e);
}