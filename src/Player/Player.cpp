#include "Player.h"
#include <iostream>

Player::Player() : moveSpeed(0.5f){

}

Player::~Player(){

}

void Player::Init(std::function <void()> pauseFunc){
    bound.setFillColor(sf::Color::Red); //this will be transparent when we get a sprite and texture
    bound.setOutlineColor(sf::Color::Red);
    bound.setOutlineThickness(1);
    //bound.setPosition(sf::Vector2f(0,0));
    size = sf::Vector2i(64,64);
	playerPause = pauseFunc;
    //bound.setSize(size);
}

void Player::Load(){
    if (texture.loadFromFile("../Assets/Images/box.png")){
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 0;

		//sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		//sprite.setTextureRect()
        sprite.setPosition(sf::Vector2f(0, 0));

		sprite.scale(sf::Vector2f(1, 1));

		bound.setSize(
			sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y)
		);
	}
	else
	{
		std::cout << "Player texture failed to loaded!" << std::endl;
	}
}

void Player::Update(double deltaTime, sf::Vector2f& mousePos){
    HandlePlayerInput(deltaTime);
}


void Player::HandlePlayerInput(double deltaTime){
    sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.setPosition(position + sf::Vector2f(1, 0) * moveSpeed * (float)deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.setPosition(position + sf::Vector2f(-1, 0) * moveSpeed * (float)deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.setPosition(position + sf::Vector2f(0, -1) * moveSpeed * (float)deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.setPosition(position + sf::Vector2f(0, 1) * moveSpeed * (float)deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		if(playerPause!=NULL){ playerPause(); } else { std::cout << "null player pause!" << std::endl; }
	}

}

void Player::Draw(sf::RenderWindow& window){
    window.draw(sprite);
}