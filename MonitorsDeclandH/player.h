#ifndef PLAYER_H
#define PLAYER_H

#include "SFML\Graphics.hpp"

class Player {
private:
	sf::Texture myPlayerTex;
	sf::Sprite myPlayerSprite;
	sf::Vector2f playerPos;

public:
	Player();
	void Move(float speed);
	void Draw(sf::RenderWindow &window);
};

#endif