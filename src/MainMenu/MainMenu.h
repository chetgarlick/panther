#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MainMenu{
    private:
        int selected;
        int initialTextVectLength;
        bool LRKeyHeld;
        sf::Text menuText;
        std::vector <sf::Text> textVect;
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