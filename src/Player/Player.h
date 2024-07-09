#pragma once
#include <SFML/Graphics.hpp>

class Player{

    private: 

        //probably need a texture here?
        sf::Texture texture;

        float moveSpeed;
        sf::RectangleShape bound;
        sf::Vector2i size;

    public:
        //sprite for future
        sf::Sprite sprite;

        Player();
        ~Player();

        void Init();
        void Load();
        void Update(double deltaTime, sf::Vector2f& mousePos);
        void Draw(sf::RenderWindow& window);
        void HandlePlayerInput(double deltaTime);

};