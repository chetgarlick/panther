#include "PauseMenu.h"
#include <iostream>

PauseMenu::PauseMenu()  : selected(0), initialTextVectLength(3), LRKeyHeld(false), enterHeld(false){

}

PauseMenu::~PauseMenu(){

}

void PauseMenu::Init(std::function <void()> pauseFunc){
    //TODO:
}

void PauseMenu::Load(){
//TODO:
}

void PauseMenu::Update(){
//TODO:
}

void PauseMenu::HandlePlayerInput(){
//TODO:
}

void PauseMenu::Draw(sf::RenderWindow& window){
//TODO:
    if(isPaused){
        for(auto i : btnVect){
            i.Draw(window);
        }
    }
}