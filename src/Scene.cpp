//Game Off 2021
//Theme: BUG
//Author: Dextron12

#include "Scene.hpp"

Scene::Scene(Events* EventHandler, Player* PlayerHandler){
    scene.EventObject = EventHandler;
    scene.playerObject = PlayerHandler;
}

void Scene::render(SDL_Renderer* renderer){
    //Render tiles(map)

    //Render entities

    //Rende rplayer
    scene.playerObject->update(renderer, scene.EventObject);

    //render ui
}