#include "Heart.h"

void Heart::InitTextures()
{
	if (!(this->Hearttexture.loadFromFile("Hittable/Heart.png")))
	{
		cout << "Failed to load Heart texture" << "\n";
	}
}

void Heart::InitSprite()
{
		sprite.setTexture(Hearttexture);
		sprite.setScale(float(0.1), float(0.1));
}

Heart::Heart(float pos_x, float pos_y)
{
	this->InitTextures();
	this->InitSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

void Heart::updateHeart()
{
	this->sprite.move(-35.f, 0.f);
}

void Heart::renderHeart(RenderTarget* target)
{
	target->draw(this->sprite);
}

const FloatRect Heart::getBounds()
{
	return this->sprite.getGlobalBounds();
}





