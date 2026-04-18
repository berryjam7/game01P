#include "ResourceManager.h"
#include "SDL3_image/SDL_image.h"

void FResourceManager::Init(SDL_Renderer* rendererRef)
{
	renderer = rendererRef;
}

SDL_Texture* FResourceManager::LoadTexture(const std::string& filePath)
{
	if (textures.contains(filePath))
	{
		return textures[filePath];
	}
	// disk to CPU
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (!surface)
	{
		return nullptr;
	}
	// CPU to GPU
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);

	textures[filePath] = texture;
	return texture;
}

SDL_Texture* FResourceManager::GetTexture(const std::string& filePath)
{
	if (!textures.contains(filePath))
	{
		return nullptr;
	}

	SDL_Texture* texture = textures[filePath];
	return texture;
}

void FResourceManager::CLear()
{
	// clear textures in GPU memory first
	for (auto& [key, texture] : textures)
	{
		SDL_DestroyTexture(texture);
	}

	// clear hash map
	textures.clear();
}


