#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu() : selected(0), initialTextVectLength(3), LRKeyHeld(false){

}

MainMenu::~MainMenu(){

}

void MainMenu::Init(){
    for(int i=0; i<initialTextVectLength; i++){
        sf::Text tmpText;
        textVect.push_back(tmpText);
    }
    textVect[0].setString("Play");
    textVect[1].setString("Quit");
    textVect[2].setString("Settings");
    textVect[0].setPosition(sf::Vector2f(0,0));
    textVect[1].setPosition(sf::Vector2f(100,100));
    textVect[2].setPosition(sf::Vector2f(200,200));
}

void MainMenu::Load(){
    for(int i=0; i<textVect.size();i++){
        textVect[i].setFont(font);
        if(font.loadFromFile("../Assets/Fonts/arial.ttf")){ std::cout << "Arial.ttf font loaded successfully into textVect at i="<< i << std::endl;
        } else { std::cout << "failed to load font file" << std:: endl; }
    }
}

void MainMenu::Update(){
    //once we are here we know we are in main menu times
    HandlePlayerInput();

}

void MainMenu::HandlePlayerInput(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(!LRKeyHeld){
            selected += 1;
            if(selected >= textVect.size()) selected = textVect.size() - 1;
            std::cout <<"D FIRED! SELECTED VALUE AND TEXT: " << selected << (std::string)textVect[selected].getString() << std::endl;
            LRKeyHeld = true;
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if(!LRKeyHeld){
            selected -= 1;
            if(selected < 0) selected = 0;
            std::cout <<"A FIRED! SELECTED VALUE AND TEXT: " << selected << (std::string)textVect[selected].getString() << std::endl;
            LRKeyHeld = true;
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        std::cout <<"ENTER FIRED! SELECTED VALUE AND TEXT: " << selected << (std::string)textVect[selected].getString() << std::endl;
        // LRKeyHeld = true;
    } else{
        LRKeyHeld = false;
    }
}

void MainMenu::Draw(sf::RenderWindow& window){
    for(auto i : textVect){
        window.draw(i);
    }
}