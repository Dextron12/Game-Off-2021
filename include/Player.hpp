//Gam Off 2021.
//Theme: BUG.
//Author: Dextron12.

//Standard headers
#include <iostream>

//SDL2 Headers
#include <SDL2\SDL.h>

//Custom Headers
#include "Events.hpp"

//Structs

//Classes

class Player{
	private:
		SDL_Rect pos;
		SDL_Texture* sprite;
		Events* EventHandler;

	public:
		Player(Events* EventHandler, float x, float y, SDL_Texture* sprite);

		void update();

		SDL_Rect getPos();
};
