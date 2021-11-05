//Game Off 2021
//Theme: BUG.
//Author: Dextron12

#pragma once

//Standard headers

//SDL2 Headers
#include <SDL2\SDL.h>

class Primitives{
    public:
        static void Rectangle(SDL_Renderer* renderer, SDL_FRect pos, SDL_Colour colour);

        //Circle
        static void FilledCircle(SDL_Renderer* renderer, int x, int y, int radius, SDL_Colour colour);
        static void OutlinedCircle(SDL_Renderer* renderer, int x, int y, int radius, SDL_Colour);
};

