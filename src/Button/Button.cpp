#include "Button.h"
#include <iostream>
#include <string>

Button::Button(std::string text, sf::Vector2f initSize, sf::Vector2f initPos): selected(false){
    rawText = text;
    size = initSize;
    position = initPos;
}
Button::~Button(){

}
void Button::Init(){
    //TODO: understand scale and its relationship to size
    //TODO: center text on button rect btnRect
    //TODO: or maybe we need to calculate box size based on text size?
    // that makes more sense
    btnText.setString(rawText);
    btnRect.setSize(size);
    btnRect.setPosition(position.x - 10, position.y - 10);
    btnRect.setFillColor(sf::Color::White);
    btnText.setFillColor(sf::Color::Red);
    btnText.setPosition(position);  
    btnText.setScale(0.75,0.75);
}
void Button::Load(){
    if(font.loadFromFile("../Assets/Fonts/arial.ttf")){
        btnText.setFont(font);
    } else {
        std::cout << "failed to load font file" << std:: endl;
    }
}

void Button::Load(sf::Font& newFont){
    btnText.setFont(newFont);
}


void Button::Update(){
    
}
void Button::Draw(sf::RenderWindow& window){
    window.draw(btnRect);
    window.draw(btnText);
}
void Button::Fire(){
    //TODO: understand passing lambdas / functions between classes, 
    if(btnFunc!=NULL){
        btnFunc();
    } else {
        std::cout << "null btnfunc!" << std::endl;
    }
}

void Button::SetFire(std::function <void()> newFunc){
    btnFunc = newFunc;
}

sf::Vector2f Button::getSize(){
    return size;
}

sf::Vector2f Button::getPosition(){
    return position;
}

void Button::setSize(sf::Vector2f newSize){
    size = newSize;
    btnRect.setSize(newSize);
    //btnText.setScale()
}

void Button::setPosition(sf::Vector2f newPos){
    position = newPos;
    btnText.setPosition(newPos);
    btnRect.setPosition(newPos.x - 10, newPos.y - 10);
}

void Button::setSelected(bool newSelected){
    selected = newSelected;
    if(newSelected){
        btnRect.setFillColor(sf::Color::Green);
    } else {
        btnRect.setFillColor(sf::Color::White);
    }
}

std::string Button::getRawText(){
    return rawText;
}