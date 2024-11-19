#include "MainMenu.h"
#include <iostream>
#include <functional>

MainMenu::MainMenu() : selected(0), initialTextVectLength(3), LRKeyHeld(false), enterHeld(false){
    sf::Vector2f initSize(100, 50);
    std::string btnTextArr[3] = {"Play", "Quit", "Other"};
    for(int i=0; i<initialTextVectLength; i++){
        sf::Vector2f initPos(10+75*i, 10+75*i);
        std::string newString = btnTextArr[i];
        Button tmpBtn(newString, initSize, initPos);
        btnVect.push_back(tmpBtn);
    }
}

MainMenu::~MainMenu(){

}

void MainMenu::Init(std::function <void()> quitFunc, std::function <void()> startGameFunc){
    for(int i=0; i<initialTextVectLength; i++){
        btnVect[i].Init();
        if(btnVect[i].getRawText()=="Quit"){ btnVect[i].SetFire(quitFunc); }
        if(btnVect[i].getRawText()=="Play"){ btnVect[i].SetFire(startGameFunc);}
    }
}

void MainMenu::Load(){
    font.loadFromFile("../Assets/Fonts/arial.ttf");
    for(int i=0; i<initialTextVectLength; i++){
        btnVect[i].Load(font);
    }
}

void MainMenu::Update(){
    //once we are here we know we are in main menu times
    HandlePlayerInput();
    for(int i=0; i<initialTextVectLength; i++){
        btnVect[i].Update();
        btnVect[i].setSelected(false);
    }
    btnVect[selected].setSelected(true);

}

void MainMenu::HandlePlayerInput(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(!LRKeyHeld){
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

void MainMenu::Draw(sf::RenderWindow& window){
    for(auto i : btnVect){
        i.Draw(window);
    }
}