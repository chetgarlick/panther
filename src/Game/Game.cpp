#include "Game.h"
#include <iostream>

Game::Game() : isRunning(false), isMenu(false), delta(0){

}

Game::~Game(){

}

void Game::Init(){
    window.create(sf::VideoMode(1920,1080), "PANTHER", sf::Style::Default);
    player.Init();
    framerate.Init();
}

void Game::Load(){
    player.Load();
    framerate.Load();
}

void Game::Update(){
    deltaTimer = clock.restart();
    delta = deltaTimer.asMicroseconds() / 1000.0;

    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){ window.close(); }
    }
    mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    framerate.Update(delta);
    player.Update(delta, mousePos);
}

void Game::Draw(){
    window.clear(sf::Color::Black);
    framerate.Draw(window);
    player.Draw(window);
    window.display();
}

void Game::Run(){
    while(window.isOpen()){
        Update();
        Draw();
    }
}

void Game::Launch(){
    Init();
    Load();
    Run();
}

