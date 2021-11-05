//Game Off 2021
//Theme: BUG
//Author: Dextron12

#pragma once

//standard headers
#include <iostream>

//SDL2 Headers
#include <SDL2\SDL.h>

//Custom Headers
#include "Events.hpp"
#include "Player.hpp"

struct sceneType{
    //Objects
    Player *playerObject;
    Events* EventObject;
};

class Scene{
    private:
        sceneType scene;

    public:
        Scene(Events* EventHandler, Player* PlayerHandler);

        void render(SDL_Renderer* renderer);

        void destroyScene();
};