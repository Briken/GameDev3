
#include "MainGame.h"



MainGame::MainGame()
{
	m_GameState = GameState::PLAY;
	Window* m_GameWindow = new Window();
}


MainGame::~MainGame()
{

}

void MainGame::Run()
{
	InitWindow();
	GameLoop();
}

void MainGame::InitWindow()
{
	m_GameWindow.InitialiseWindow();
}

void MainGame::ProcessInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			m_GameState = GameState::EXIT;
			break;
		}
	}
}

void MainGame::GameLoop()
{
	while (m_GameState != GameState::EXIT)
	{
		ProcessInput();
		RenderGame();
	}

}

void MainGame::RenderGame()
{
	m_GameWindow.ClearDisplay();



	m_GameWindow.SwapBuffer();
}
