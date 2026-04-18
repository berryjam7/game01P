#include "Game.h"
#include "ResourceManager.h"

#include <chrono>

void FGame::Initialize()
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		SDL_Log("sdl init Error: %s", SDL_GetError());
		return;
	}
	SDL_Window* rawWindow = SDL_CreateWindow("Game01", 1920, 1080, 0);
	if (!rawWindow)
	{
		SDL_Log("sdl init Error: %s", SDL_GetError());
		return;
	}
	window = FWindowPtr(rawWindow);

	SDL_Renderer* rawRenderer = SDL_CreateRenderer(window.get(), nullptr);
	if (!rawRenderer)
	{
		SDL_Log("sdl init Error: %s", SDL_GetError());
		return;
	}
	renderer = FRendererPtr(rawRenderer);

	// Initialize managers in EnTT context
	auto& resMgr = registry.ctx().emplace<FResourceManager>();
	resMgr.Init(renderer.get());

	bIsRunning = true;

	lastTickTime = SDL_GetTicks();
}

void FGame::GameLoop()
{
	while (bIsRunning)
	{
		Uint64 currentTickTime = SDL_GetTicks();
		float deltaTime = (currentTickTime - lastTickTime) / 1000.0f;
		lastTickTime = currentTickTime;
		ProcessInput();
		Update(deltaTime);
		Render();
	}
}

void FGame::Shutdown()
{
	// TODO: save game data ex) Steam sync

	SDL_Quit();
	return;
}

void FGame::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		// imGui_ImplSDL3_ProcessEvent(&event);

		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			bIsRunning = false;
			break;
			// TODO: expand to InputSystem 
		}
	}
}

void FGame::Update(const float deltaTime)
{
	
}

void FGame::Render()
{
	SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
	SDL_RenderClear(renderer.get());

	// TODO: real rendering

	SDL_RenderPresent(renderer.get());
}
