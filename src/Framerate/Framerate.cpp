#include "Framerate.h"
#include <iostream>

Framerate::Framerate() : timer(0){

}

Framerate::~Framerate(){

}

void Framerate::Init(){

}

void Framerate::Load(){
    if(font.loadFromFile("../Assets/Fonts/arial.ttf")){
        framerateText.setFont(font);
    } else {
        std::cout << "failed to load font file" << std:: endl;
    }
}

void Framerate::Update(double delta){
    timer += delta;
    if(timer >= 100.0){
        double fps = 1000.0 / delta;
        framerateText.setString("FPS:" + std::to_string((int)fps) + " frametime: " + std::to_string((int)delta));
        timer = 0;
    }
}

void Framerate::Draw(sf::RenderWindow& window){
    //std::cout << "drawing:: " << (std::string)framerateText.getString() << std::endl;
    window.draw(framerateText);
}

