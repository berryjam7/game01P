#pragma once

#include <SDL3/SDL.h>
#include <entt/entt.hpp>
#include <memory>
#include <string>
#include "SDLDeleter.h"

class FGame
{
public:
	FGame() = default;

	// prevent multiple instance
	FGame(const FGame&) = delete;
	FGame& operator=(const FGame&) = delete;

	void Initialize();
	void GameLoop();
	void Shutdown();

private:
	void ProcessInput();
	void Update(const float deltaTime);
	void Render();

	FWindowPtr window;
	FRendererPtr renderer;

	Uint64 lastTickTime;

	entt::registry registry;

	bool bIsRunning = false;
};