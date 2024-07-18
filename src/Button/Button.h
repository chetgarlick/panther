#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class Button{
    private:
        sf::Text btnText;
        sf::Font font;
        sf::RectangleShape btnRect;
        sf::Vector2f size;
        sf::Vector2f position;
        std::string rawText;
        bool selected;
        std::function <void()> btnFunc;

    public:
        Button(std::string text, sf::Vector2f initSize, sf::Vector2f initPos);
        ~Button();

        void Init();
        void Load();
        void Load(sf::Font& newFont);
        void Update();
        void Draw(sf::RenderWindow& window);
        void Fire();
        void SetFire(std::function <void()> newFunc);
        sf::Vector2f getSize();
        sf::Vector2f getPosition();
        void setSize(sf::Vector2f newSize);
        void setPosition(sf::Vector2f newPos);
        void setSelected(bool newSelected);
        std::string getRawText();

};