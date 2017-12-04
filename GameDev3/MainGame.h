#pragma once
#include <glad/glad.h>
#include <GL/glew.h>

#include "Window.h"

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void Run();

private:

	void InitWindow();
	void ProcessInput();
	void GameLoop();
	void RenderGame();


	Window m_GameWindow;
	GameState m_GameState;
};

