#include<vector>
#include "libtcod.hpp"
#include "Engine.hpp"
int main() {
	Engine engine;
	while (!TCODConsole::isWindowClosed())
	{
		TCODConsole::root->clear();
		engine.handleEvents();
		engine.render();
		TCODConsole::flush();
	}
	return 0;
}
