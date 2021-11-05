//Game Off 2021 Game Jam Entry.
//Dextron12
//Theme: BUG.

//Standard includes
#include <iostream>

//SDL2 Headers
#include <SDL2\SDL.h>

//custom Headers
#include "Events.hpp"


class Program{
	private:
		bool running;

		Events EventHandler;
	
	public:
		int width = 800; int height = 600;
		SDL_Window* window;
		SDL_Renderer* renderer;

		Program(){
			//Initiate SDL
			if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
				//Initiation failed.
				std::cout << "Initiation Error: " << SDL_GetError() << std::endl;
			}
			//Create Window
			window = SDL_CreateWindow("B.U.G", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
			if (window == NULL){
				std::cout << "Initiation Error" << SDL_GetError() << std::endl;
			}
			//Create Renderer
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL){
				std::cout << "Initiation Error: " << SDL_GetError() << std::endl;
			}

			//Set up rest of application here.
			running = true;

			//call render loop
			render();

		}

		void render(){
			while (!EventHandler.ApplicationQuit()){
				EventHandler.update();
				SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
				SDL_RenderClear(renderer);


				SDL_RenderPresent(renderer);
				//Handle events
				if (EventHandler.ApplicationResized()){
					width = SDL_GetWindowSurface(window)->w;
					height = SDL_GetWindowSurface(window)->h;
				}
			}
		}
};

int main(int argc, char* argv[]){
	Program program;
	program.render();

	//Terminate application
	return 0;
}