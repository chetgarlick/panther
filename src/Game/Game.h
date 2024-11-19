#pragma once
#include <SFML/Graphics.hpp>

#include "../Framerate/Framerate.h"
#include "../Player/Player.h"
#include "../MainMenu/MainMenu.h"
#include "../Button/Button.h"
#include "../PauseMenu/PauseMenu.h"
#include <functional>

class Game{

    private:
        bool isRunning;
        bool isPauseMenu;
        bool isMainMenu;
        Player player;
        Framerate framerate;
        sf::RenderWindow window;
        sf::Clock clock;
        sf::Time deltaTimer;
        double delta;
        sf::Vector2f mousePos;
        MainMenu mainMenu;
        PauseMenu pauseMenu;
        std::function <void()> quitFunc;
        std::function <void()> startGameFunc;
        std::function <void()> pauseFunc;
    public:
        Game();
        ~Game();

        void Init();
        void Load();
        void Update();
        void Draw();
        void Run();
        void Launch();
        void Quit();

};