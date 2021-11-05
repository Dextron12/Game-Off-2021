//Game Off 2021
//Theme: BUG
//Author: Dextron12

#pragma once

//standard includes
#include <iostream>

//SDL2 includes
#include <SDL2\SDL.h>

//Custom Headers
#include "Events.hpp"
#include "Gui.hpp"

class Player{
    private:
        SDL_FRect pos;
        SDL_Texture* sprite;

        bool walking;

        //Acceleration
        int mass = 1;
        float velocity = 0.8;

    public:
        Player(SDL_FRect pos, SDL_Texture* sprite = NULL);

        void update(SDL_Renderer* renderer, Events* EventHandler);

        SDL_Rect getPos();
};