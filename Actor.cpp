#include "Actor.hpp"

Actor::Actor(int x, int y, int character, const TCODColor &foregroundColor) {
	this->xPosition = x;
	this->yPosition = y;
	this->displayCharacter = character;
	this->fgColor = foregroundColor;
}

bool Actor::isVisible() {
	return is_visible;
}

void Actor::setVisibility(bool newVisibility) {
	is_visible = newVisibility;
}

void Actor::toggleVisibility() {
	is_visible = !is_visible;
}

void Actor::render(TCOD_bkgnd_flag_t bkgndFlag) const {
	TCODConsole::root->putChar(xPosition, yPosition, displayCharacter, bkgndFlag);
	TCODConsole::root->setCharForeground(xPosition, yPosition, fgColor);
}

void Actor::moveBy(int dx, int dy) {
	xPosition += dx;
	yPosition += dy;
}

void Actor::moveUp() {
	moveBy(0, -1);
}

void Actor::moveDown() {
	moveBy(0, 1);
}

void Actor::moveLeft() {
	moveBy(-1, 0);
}

void Actor::moveRight() {
	moveBy(1, 0);
}
