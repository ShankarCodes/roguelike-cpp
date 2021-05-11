#pragma once
#include<vector>
#include<fmt/core.h>

#include "Map.hpp"
#include "Actor.hpp"

class Engine {
public:
	Engine();
	~Engine();
	void addActor(Actor* actor);
	void render() const;
	void handleEvents();
private:
	Map* map = nullptr;
	std::vector<Actor*> actors;
	Actor* player = nullptr;
};
