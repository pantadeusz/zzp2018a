#ifndef __A_GAME__
#define  __A_GAME__

#include "vid_sdl.hpp"
#include <map>
#include <chrono>
#include <memory>

namespace zzp {


class Game {
protected:

// std::chrono::high_resolution_clock::now()
    //std::chrono::time_point<std::chrono::high_resolution_clock,duration_t> prev_time;
	//std::chrono::steady_clock::time_point prev_time;
	std::chrono::high_resolution_clock::time_point prev_time;


	std::shared_ptr<SDL_Window> window;
	std::shared_ptr<SDL_Renderer> renderer;


public:
	// przyrost czasu symulacji w sekundach
	std::chrono::duration<double> dt;

	// initialize video card
	void init_video();

	// loading textures
	void init_textures();


	// creating data and functions for particle effects
	void init_particles();

	// prepare everything to game
	void init( );

	// start game. This initializes timer!
	void start();

	// get inputs from users
	int l_input();

	// apply physics to everything
	void l_physics();
	// draw whole scene
	void l_draw();
	// wait for next frame
	void l_sync();

};

}


#endif
