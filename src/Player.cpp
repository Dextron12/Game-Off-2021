//Game Off 2021
//Theme: BUG
//Author: Dextron12

#include "Player.hpp"

Player::Player(SDL_FRect pos, SDL_Texture* sprite){
    std::cout << pos.x << std::endl;
    this->pos = pos;
    this->sprite = sprite;
}

void Player::update(SDL_Renderer* renderer, Events* EventHandler){
    //Update graphics
    if (sprite == NULL){
        Primitives::Rectangle(renderer, pos, SDL_Colour{255,0,0,255});
    } else {
        SDL_RenderCopyF(renderer, sprite, NULL, &pos);
    }
    //std::cout << pos.x << ", " << pos.y << std::endl;

    //Logic

    //Key updates
    if (EventHandler->getGamePad().w == true){
        pos.y -= ((mass * velocity) * EventHandler->deltaTime);
    } else if (EventHandler->getGamePad().s == true){
        pos.y += ((mass * velocity) * EventHandler->deltaTime);
    } else if (EventHandler->getGamePad().a == true){
        pos.x -= ((mass * velocity) * EventHandler->deltaTime);
    } else if (EventHandler->getGamePad().d == true){
        pos.x += ((mass * velocity) * EventHandler->deltaTime);
    }
}

SDL_FRect Player::getPos(){
    return pos;
}