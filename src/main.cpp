#include <SFML/Graphics.hpp>

#include "Framerate/Framerate.h"
#include "Player/Player.h"

int main(){

    sf::RenderWindow window(sf::VideoMode(1920,1080), "PANTHER", sf::Style::Default);
    window.setFramerateLimit(360);
    //sf::CircleShape shape(100.f);
    Player player;
    Framerate frameRate;
    player.Init();
    player.Load();
    frameRate.Init();
    frameRate.Load();
    sf::Clock clock;

    //shape.setFillColor(sf::Color::Green);

    while(window.isOpen()){
        sf::Time deltaTimer = clock.restart();
        double delta = deltaTimer.asMicroseconds() / 1000.0;

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        frameRate.Update(delta);
        player.Update(delta, mousePos);
        window.clear(sf::Color::Black);
        //window.draw(shape);
        frameRate.Draw(window);
        player.Draw(window);
        window.display();
    }


    return 0;
};