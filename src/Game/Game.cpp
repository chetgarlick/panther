#include "Game.h"
#include <iostream>

Game::Game() : isRunning(false), isMainMenu(true), delta(0){
    quitFunc = [this](){Quit();};
}

Game::~Game(){

}

void Game::Init(){
    window.create(sf::VideoMode(1920,1080), "PANTHER", sf::Style::Default);
    mainMenu.Init(quitFunc);
    player.Init();
    framerate.Init();
}

void Game::Load(){
    mainMenu.Load();
    player.Load();
    framerate.Load();
}

void Game::Update(){
    deltaTimer = clock.restart();
    delta = deltaTimer.asMicroseconds() / 1000.0;

    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){ Quit(); }
    }
    mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    
    if(isMainMenu){
        mainMenu.Update();
    } else if(isRunning){
        framerate.Update(delta);
        player.Update(delta, mousePos);
    }
}

void Game::Draw(){
    window.clear(sf::Color::Black);
    
    if(isMainMenu){
        mainMenu.Draw(window);
    }
    if(isRunning){
        player.Draw(window);
        framerate.Draw(window);
    }
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

void Game::Quit(){
    window.close();
}
