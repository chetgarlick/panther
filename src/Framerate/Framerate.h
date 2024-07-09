#pragma once
#include <SFML/Graphics.hpp>

class Framerate{
    private:
        sf::Text framerateText;
        sf::Font font;
        double timer;

    public:
        Framerate();
        ~Framerate();

        void Init();
        void Load();
        void Update(double delta);
        void Draw(sf::RenderWindow& window);

};