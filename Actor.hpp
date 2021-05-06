#pragma once
#include<libtcod.hpp>

class Actor {
private:
	int displayCharacter;
	int xPosition, yPosition;
	bool is_visible = true;
	TCODColor fgColor;
public:
	Actor(int x, int y, int character, const TCODColor &foregroundColor);
	void moveBy(int dx = 0, int dy = 0);
	bool isVisible();
	void render(TCOD_bkgnd_flag_t bkgndFlag = TCOD_BKGND_DEFAULT) const;
	void setVisibility(bool newVisibility);
	void toggleVisibility();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};