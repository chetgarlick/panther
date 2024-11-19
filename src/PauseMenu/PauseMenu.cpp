#include "PauseMenu.h"
#include <iostream>

PauseMenu::PauseMenu()  : selected(0), initialTextVectLength(3), LRKeyHeld(false), enterHeld(false){
    sf::Vector2f initSize(100,50);
    std::string btnTextArr[3] = {"Resume", "Quit", "Other"};
    for(int i=0; i < initialTextVectLength; i++){
        sf::Vector2f initPos(10+75 * i, 10+75 * i);
        std::string newString = btnTextArr[i];
        Button tmpBtn(newString, initSize, initPos);
        btnVect.push_back(tmpBtn);
    }
}

PauseMenu::~PauseMenu(){

}

void PauseMenu::Init(std::function <void()> quitFunc, std::function <void()> pauseFunc){
    selected = 0;
    for(int i=0; i<initialTextVectLength; i++){
        btnVect[i].Init();
        if(btnVect[i].getRawText()=="Quit"){ btnVect[i].SetFire(quitFunc); }
        if(btnVect[i].getRawText()=="Resume"){ btnVect[i].SetFire(pauseFunc);}
    }
}

void PauseMenu::Load(){
    for(int i=0; i<initialTextVectLength; i++){
        btnVect[i].Load();
    }
}

void PauseMenu::Update(){
    HandlePlayerInput();
    for(int i=0; i<initialTextVectLength; i++){
        btnVect[i].Update();
        btnVect[i].setSelected(false);
    }
    btnVect[selected].setSelected(true);
}

void PauseMenu::HandlePlayerInput(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(!LRKeyHeld){
            std::cout<<"D?!"<<std::endl;
            btnVect[selected].setSelected(false);
            selected += 1;
            if(selected >= btnVect.size()) selected = btnVect.size() - 1;
            LRKeyHeld = true;
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if(!LRKeyHeld){
            selected -= 1;
            if(selected < 0) selected = 0;
            LRKeyHeld = true;
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        if(!enterHeld){
            enterHeld = true;
            btnVect[selected].Fire();
        }
    } else{
        LRKeyHeld = false;
        enterHeld = false;
    }
}

void PauseMenu::Draw(sf::RenderWindow& window){
//TODO:
    for(auto i : btnVect){
        i.Draw(window);
    }
}