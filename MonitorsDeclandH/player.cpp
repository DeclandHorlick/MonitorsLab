#include "stdafx.h"
#include "player.h"


Player::Player()
{
	myPlayerTex.loadFromFile("ship.png");
	myPlayerSprite.setTexture(myPlayerTex);
	myPlayerSprite.setPosition(100, 100);
	playerPos = myPlayerSprite.getPosition();
}

void Player::Move(float speed)
{
	if (playerPos.x >= 99 && playerPos.x < 200 && playerPos.y <= 100)
	{
		playerPos.x +=speed;
	}
	else if (playerPos.x >= 200 && playerPos.y < 200)
	{
		playerPos.y+=speed;
	}
	else if (playerPos.y >= 200 && playerPos.x >= 100 )
	{
		playerPos.x-=speed;
	}
	else 
	{
		playerPos.y-=speed;
	}
	myPlayerSprite.setPosition(playerPos.x, playerPos.y);
}
void Player::Draw(sf::RenderWindow &window)
{
	window.draw(myPlayerSprite);
}