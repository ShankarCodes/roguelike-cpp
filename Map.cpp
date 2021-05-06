#include "Map.hpp"


Map::Map(int width, int height) : width(width), height(height) {
	tiles = new Tile[width * height];
}

Map::~Map() {
	delete[] tiles;
}

void Map::setTileType(int x, int y, TileType type) {
	// row * width + height for row major
	tiles[y * width + x].tileType = type;
	switch (type) {
	case TILE_WALL: tiles[y * width + x].canWalk = false; break;
	}
}

bool Map::isWalkable(int x, int y) {
	return tiles[y * width + x].canWalk;
}

void Map::render() const {
	static const TCODColor darkWall(0, 0, 100);
	static const TCODColor darkFloor(50, 50, 150);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			switch (tiles[y * width + x].tileType) {
			case TILE_FLOOR:
				TCODConsole::root->setCharBackground(x, y, darkFloor);
				//TCODConsole::root->putChar(x, y, '.');
				break;
			case TILE_WALL:
				TCODConsole::root->setCharBackground(x, y, darkWall);
				//TCODConsole::root->putChar(x, y, '');
				//TCODConsole::root->setCharForeground(x, y, TCODColor::darkBlue);
				break;
			}
		}
	}

}
