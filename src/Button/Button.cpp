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
    btnText.setString(rawText);
    btnRect.setSize(size);
    btnRect.setPosition(position);
    btnRect.setFillColor(sf::Color::White);
    btnText.setFillColor(sf::Color::Red);
    btnText.setPosition(position);  
    btnText.setScale(0.75,0.75);
}
void Button::Load(){
    if(font.loadFromFile("../Assets/Fonts/arial.ttf")){
        btnText.setFont(font);
        std::cout << "Arial.ttf font loaded successfully" << std::endl;
    } else {
        std::cout << "failed to load font file" << std:: endl;
    }
}
void Button::Update(){
    
}
void Button::Draw(sf::RenderWindow& window){
    window.draw(btnRect);
    window.draw(btnText);
}
void Button::Fire(){
    //TODO: understand passing lambdas / functions between classes, 
    std::cout<< "FIRING BUTTON OF TEXT::" << rawText << std::endl;
    if(rawText=="Quit"){
        //TODO: call Game.h quit from here
    }
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
    btnRect.setPosition(newPos);
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