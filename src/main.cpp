//Game Off 2021 Game Jam Entry.
//Dextron12
//Theme: BUG.

//Standard includes
#include <iostream>

//SDL2 Headers
#include <SDL2\SDL.h>

//custom Headers
#include "Events.hpp"
#include "Player.hpp"

class Program{
	private:
		int width = 800; int height = 600;
		
		SDL_Window* window;
		SDL_Renderer* renderer;

		bool running = false;

		//Event Handler
		Events EventHandler;

	public:
		Program(){
			//init sdl2
			if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
				std::cout << "Initiation Error: " << SDL_GetError() << std::endl;
			}
			//Create WIndow
			window = SDL_CreateWindow("BUG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
			//Check window
			if (window == NULL){
				std::cout << "Initiation Error: " << SDL_GetError() << std::endl;
			}
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			//Check renderer
			if (renderer == NULL){
				std::cout << "Initiation Error: " << SDL_GetError() << std::endl;
			}

			//Gotten this far. Initiation complete!
			running = true;

			render();
		}

		void render(){
			Player player(SDL_FRect{200,200,32,32});
			while (!EventHandler.ApplicationQuit()){
				EventHandler.update();
				SDL_SetRenderDrawColor(renderer, 140, 140, 140, 255);
				SDL_RenderClear(renderer);

				player.update(renderer, &EventHandler);


				SDL_RenderPresent(renderer);
			}
		}
};

int main(int argc, char* argv[]){
	Program program;
	//Terminate application
	return 0;
}