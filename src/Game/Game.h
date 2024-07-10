#pragma once
#include <SFML/Graphics.hpp>

#include "../Framerate/Framerate.h"
#include "../Player/Player.h"
#include "../MainMenu/MainMenu.h"

class Game{

    private:
        bool isRunning;
        bool isMainMenu;
        Player player;
        Framerate framerate;
        sf::RenderWindow window;
        sf::Clock clock;
        sf::Time deltaTimer;
        double delta;
        sf::Vector2f mousePos;
        MainMenu mainMenu;

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