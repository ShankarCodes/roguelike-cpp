#pragma once
#include<libtcod.hpp>

enum TileType {
	TILE_FLOOR,
	TILE_WALL,
};
struct Tile {
	bool canWalk = true;
	TileType tileType = TILE_FLOOR;
};

class Map {
public:
	Map(int width, int height);
	~Map();
	void render() const;
	void setTileType(int x, int y, TileType type);
	bool isWalkable(int x, int y);
private:
	int width, height;
	Tile* tiles;
};