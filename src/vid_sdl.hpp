#ifndef __VID_SDL_HPP___
#define __VID_SDL_HPP___

#include <memory>
#include <SDL2/SDL.h>

namespace zzp {

std::shared_ptr<SDL_Window> init_window( const int width = 320, const int height = 200 );

std::shared_ptr<SDL_Renderer> init_renderer( std::shared_ptr<SDL_Window> window );

std::shared_ptr<SDL_Texture> load_texture( const std::shared_ptr<SDL_Renderer> renderer, const std::string fname );

std::shared_ptr<SDL_Texture> create_texture( const std::shared_ptr<SDL_Renderer> renderer, const int w, const int h );

}

#endif
