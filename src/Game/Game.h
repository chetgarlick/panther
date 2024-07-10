#pragma once
#include <SFML/Graphics.hpp>

#include "../Framerate/Framerate.h"
#include "../Player/Player.h"

class Game{

    private:
        bool isRunning;
        bool isMenu;
        Player player;
        Framerate framerate;
        sf::RenderWindow window;
        sf::Clock clock;
        sf::Time deltaTimer;
        double delta;
        sf::Vector2f mousePos;

    public:
        Game();
        ~Game();

        void Init();
        void Load();
        void Update();
        void Draw();
        void Run();
        void Launch();

};