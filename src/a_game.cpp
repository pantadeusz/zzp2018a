#include "a_game.hpp"

//#include "p_particles.hpp"
#include "vid_sdl.hpp"
//
#include <thread>
//#include <vector>
//#include <algorithm>
//#include <random>
//#include <map>
//#include <list>

#include <functional>

#include <iostream>

using namespace std::chrono_literals;

namespace zzp
{

// initialize video card
void Game::init_video()
{
	window = init_window(640, 480);
	renderer = init_renderer(window);
}

// loading textures
void Game::init_textures()
{
}

// creating data and functions for particle effects
void Game::init_particles()
{
}

// prepare everything to game
void Game::init()
{
	dt = 0.015s;
	init_video();
	init_textures();
	init_particles();
}

// start game. This initializes timer!
void Game::start()
{
	prevTime = std::chrono::high_resolution_clock::now(); //std::chrono::steady_clock::now(); // w sekundach
}

// get inputs from users
int Game::l_input()
{
	int closeGame = false;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			closeGame = true;
			break;
		}
	}

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_SPACE])
	{
		// nacisnieto klawisz spacji
	}
	return closeGame;
}

// apply physics to everything
void Game::l_physics()
{
}

// draw whole scene
void Game::l_draw()
{
	// grafika
	SDL_SetRenderDrawColor(renderer.get(), 0, 16, 0, 0);
	SDL_RenderClear(renderer.get());

	// SDL_RenderCopyEx(renderer.get(), ...

	SDL_RenderPresent(renderer.get());
}

// wait for next frame
void Game::l_sync()
{
	std::this_thread::sleep_until(prevTime + std::chrono::duration<double>(dt));
	prevTime = std::chrono::high_resolution_clock::now(); //prevTime + std::chrono::duration<double>(dt);
}
}
