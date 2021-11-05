//Game Off 2021 Game Entry
//Dextron12
//Theme: BUG

#pragma once

#include <SDL2\SDL.h>

struct gamePad{
	//WASD keys
	bool w;
	bool a;
	bool s;
	bool d;

	//Arrow keys
	bool up;
	bool left;
	bool down;
	bool right;

	//Mouse
	bool leftClick;
	bool rightClick;
	SDL_Point mousePos;
};


class Events{
	private:
		bool m_quit;
		bool m_resize;

		SDL_Event event;
		gamePad controller;

	public:
		void update();
		void reset();

		//Getters
		gamePad getGamePad();

		bool ApplicationQuit();
		bool ApplicationResized();



};