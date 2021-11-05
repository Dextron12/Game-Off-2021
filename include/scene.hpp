#include <iostream>
#include <vector>

//SDL2 headers
#include <SDL2\SDL.h>

//Custom headers
#include "Player.hpp"
#include "Events.hpp"

struct scene{
	//Event Handler object
	SDL_Renderer* renderer;

	Events* EventHandler;
	Player* PlayerHandler;
	//List of tiles.
	//std::vector<Tiles>

	//List of entities
	//std::vector<SOme parent class of classes that cans tore ally different types of entity>

	//List of rooms (set of structs)


	//Player Object, Perferebly as pointer
	//Inventory Object, Perferebly as pointer
	//Mission Object
};

class Scene{
	//A class that contains all data required to render game(scene).
	//It works by using data stored in its struct to render required resources
	private: //If your name is Ponitiem & you're wondering why I'm declaring private when classes default to private. The answer is because I can and.... It's Pythonic... I Hope!
		scene renderData; //Data structure for all data needed to render scene.

	public:
		Scene(SDL_Renderer* renderer, Events* EventHandler, Player* PlayerHandler); // Should add Tile and Entity Handler.

		void update(); //Call to update currently bound scene.

		void createScene(SDL_Renderer* renderer, Events* EventHandler, Player* PlayerHandler); //Generates a new scene object and binds it as new scene. Old scene data cannot be accessed when new scene data is bound!

		void destroyScene(); //Unbounds currently bound scene. Use this function to free resources.


};

