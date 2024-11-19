#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include "../Button/Button.h"


class PauseMenu{
    private:
        int selected;
        int initialTextVectLength;
        bool LRKeyHeld;
        bool enterHeld;
        bool isPaused;
        sf::Text menuText;
        std::vector <Button> btnVect;
        sf::Font font;

    public:
        PauseMenu();
        ~PauseMenu();

        void Init(std::function <void()> pauseFunc, std::function <void()> quitFunc);
        void Load();
        void Update();
        void HandlePlayerInput();
        void Draw(sf::RenderWindow& window);
};