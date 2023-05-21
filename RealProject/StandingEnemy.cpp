#include "StandingEnemy.h"

void StandingEnemy::InitTextures()
{
	if (!(this->texture.loadFromFile("Hittable/Standing_enemy.png")))
	{
		cout << "Failed to load Standing enemy texture" << "\n";
	}
}

void StandingEnemy::InitSprite()
{
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(30 * frame, 0, 30, 37));
	sprite.setScale(2.f, 2.f);
	if (frameCounter == 7)
	{
		frame = (frame + 1) % 11;
		frameCounter = 0;
	}
	frameCounter++;
}

StandingEnemy::StandingEnemy(float pos_x, float pos_y)
{
	this->InitTextures();
	this->InitSprite();
	this->sprite.setPosition(pos_x, pos_y);

}

void StandingEnemy::updateEnemy()
{
	this->sprite.move(-15.f, 0.f);
}

void StandingEnemy::renderEnemy(RenderTarget* target)
{
	target->draw(this->sprite);
}

const FloatRect StandingEnemy::getBounds()
{
	return this->sprite.getGlobalBounds();
}
