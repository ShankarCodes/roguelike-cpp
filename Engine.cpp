#include "Engine.hpp"
#include "ConfigFileReader.hpp"

Engine::Engine() {
	TCODConsole::initRoot(80, 50, "Shankar Roguelike", false, TCOD_RENDERER_SDL2);
	TCOD_sys_set_fps(60);
	map = new Map(80, 50);
	for (int i = 0; i < 20; i++) {
		map->setTileType(30 + i, 20, TILE_WALL);
		map->setTileType(30, 20 + i, TILE_WALL);
		map->setTileType(30 + i, 40, TILE_WALL);
	}
	player = new Actor(60, 40, '@', TCODColor::green);
	addActor(player);
	auto config = getConfig("colors.txt");
	for (const auto& configItem : config) {
		fmt::print("{} = {}\n",configItem.first, configItem.second);
	}
}

Engine::~Engine() {
	delete map;
	delete player;
}

void Engine::addActor(Actor* actor) {
	actors.push_back(actor);
}

void Engine::render() const {
	map->render();
	for (const auto& actor : actors) {
		actor->render();
	}
}

void Engine::handleEvents() {
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);
	switch (key.vk) {
	case TCODK_CHAR:
		switch (key.c) {
		case 'w':
			if(map->isWalkable(player->getXPos(), player->getYPos()-1)) player->moveUp();
			break;
		case 's':
			if(map->isWalkable(player->getXPos(), player->getYPos()+1)) player->moveDown();
			break;
		case 'a':
			if(map->isWalkable(player->getXPos()-1, player->getYPos())) player->moveLeft();
			break;
		case 'd':
			if(map->isWalkable(player->getXPos()+1, player->getYPos())) player->moveRight();
			break;
		}
	default:break;
	}
}
