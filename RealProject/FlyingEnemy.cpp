#include "FlyingEnemy.h"
void FlyingEnemy::InitTextures()
{
	if (!(this->texture.loadFromFile("Hittable/ufo.png")))
	{
		cout << "Failed to load FLying enemy texture" << "\n";
	}
}

void FlyingEnemy::InitSprite()
{
	sprite.setTexture(texture);
	
	sprite.setScale(float(0.1), float(0.1));
	
}

FlyingEnemy::FlyingEnemy(float pos_x, float pos_y)
{
	this->InitTextures();
	this->InitSprite();
	this->sprite.setPosition(pos_x, pos_y);

}

void FlyingEnemy::updateEnemy()
{
	this->sprite.move(-50.f, 0.f);
}

void FlyingEnemy::renderEnemy(RenderTarget* target)
{
	target->draw(this->sprite);
}

const FloatRect FlyingEnemy::getBounds()
{
	return this->sprite.getGlobalBounds();
}