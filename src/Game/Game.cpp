#include "Game.h"
#include <iostream>

Game::Game() : isRunning(false), isMainMenu(true), delta(0){
    quitFunc = [this](){Quit();};
    startGameFunc = [this](){this->isRunning = true; this->isMainMenu = false;};
    pauseFunc = [this](){this->isRunning = !isRunning; this->isPauseMenu = !isPauseMenu;};
}

Game::~Game(){

}

void Game::Init(){
    window.create(sf::VideoMode(1920,1080), "PANTHER", sf::Style::Default);
    isPauseMenu = false;
    mainMenu.Init(quitFunc, startGameFunc);
    pauseMenu.Init(quitFunc, pauseFunc);
    player.Init(pauseFunc);
    framerate.Init();
}

void Game::Load(){
    mainMenu.Load();
    pauseMenu.Load();
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
    } else if(isPauseMenu){
        pauseMenu.Update();
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
    if(isPauseMenu){
        pauseMenu.Draw(window);
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
