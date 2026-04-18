#pragma once
#include <SDL3/SDL_render.h>
#include <string>
#include <unordered_map>

class FResourceManager
{
public:
	FResourceManager() = default;
	~FResourceManager() { CLear(); }

	void Init(SDL_Renderer* rendererRef);

	SDL_Texture* LoadTexture(const std::string& filePath);
	SDL_Texture* GetTexture(const std::string& filePath);
	void CLear();
private:
	std::unordered_map<std::string, SDL_Texture*> textures;

	SDL_Renderer* renderer;

};
