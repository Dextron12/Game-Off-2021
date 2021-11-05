#include "Events.hpp"
#include <iostream>

Events::Events(){
	now = SDL_GetPerformanceCounter();
	last = 0;
	deltaTime = 0;
}

void Events::update(){
	while(SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT){
			m_quit = true;
		}

		if (event.type == SDL_WINDOWEVENT){
			if (event.window.event == SDL_WINDOWEVENT_RESIZED){
				m_resize = true;
			}
		}

		if (event.type == SDL_MOUSEMOTION){
			SDL_GetMouseState(&controller.mousePos.x, &controller.mousePos.y);
		}

		//Key events | KEYDOWN
		if (event.type == SDL_KEYDOWN){
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				controller.w = true;
				break;
			case SDLK_a:
				controller.a = true;
				break;
			case SDLK_s:
				controller.s = true;
				break;
			case SDLK_d:
				controller.d = true;
				break;

			case SDLK_UP:
				controller.up = true;
				break;
			case SDLK_LEFT:
				controller.left = true;
				break;
			case SDLK_DOWN:
				controller.down = true;
				break;
			case SDLK_RIGHT:
				controller.right = true;
				break;
			default:
				//Perhaps push other keys into a list, so program can get access to all keys.
				break;
			}
		}

		//Key events | KEYUP
		if (event.type == SDL_KEYUP){
			switch (event.key.keysym.sym){
				case SDLK_w:
					controller.w = false;
					break;
				case SDLK_a:
					controller.a = false;
					break;
				case SDLK_s:
					controller.s = false;
					break;
				case SDLK_d:
					controller.d = false;

				//Arrow Keys
				case SDLK_UP:
					controller.up = false;
					break;
				case SDLK_LEFT:
					controller.left = false;
					break;
				case SDLK_DOWN:
					controller.down = false;
					break;
				case SDLK_RIGHT:
					controller.right = false;
					break;
			}
		}

	}
	//Update DeltaTime
	last = now;
	now = SDL_GetPerformanceCounter();
	deltaTime = ((now - last)*1000/(double)SDL_GetPerformanceFrequency());

	
}

bool Events::ApplicationQuit(){
	return m_quit;
}

bool Events::ApplicationResized(){
	return m_resize;
}

gamePad Events::getGamePad(){
	return controller;
}