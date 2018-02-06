#include "a_game.hpp"
#include <iostream>

using namespace zzp;

int main( int argc, char **argv ) {

	// ogarniamy parametry :D
	std::map < std::string, std::string > config;
	for ( int i = 1; i < argc - 1; i += 2 ) {
		config[argv[i]] = argv[i + 1];
	}

	Game game;
	game.init();
	game.start();
	for ( bool game_active = true ; game_active; ) {
		if ( game.l_input() ) game_active = false;
		game.l_physics();
		game.l_draw();
		game.l_sync();
	}
	return 0;
}
