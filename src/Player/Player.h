#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Player{

    private: 

        //probably need a texture here?
        sf::Texture texture;

        float moveSpeed;
        sf::RectangleShape bound;
        sf::Vector2i size;

        std::function <void()> playerPause;

    public:
        //sprite for future
        sf::Sprite sprite;

        Player();
        ~Player();

        void Init(std::function <void()> pauseFunc);
        void Load();
        void Update(double deltaTime, sf::Vector2f& mousePos);
        void Draw(sf::RenderWindow& window);
        void HandlePlayerInput(double deltaTime);

};