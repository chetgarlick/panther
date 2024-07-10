#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Button/Button.h"

class MainMenu{
    private:
        int selected;
        int initialTextVectLength;
        bool LRKeyHeld;
        bool enterHeld;
        sf::Text menuText;
        std::vector <Button> btnVect;
        sf::Font font;

    public:
        MainMenu();
        ~MainMenu();

        void Init();
        void Load();
        void Update();
        void HandlePlayerInput();
        void Draw(sf::RenderWindow& window);
};