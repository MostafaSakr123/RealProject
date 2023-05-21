#include "Treasure.h"
void Treasure::InitTextures()
{
	if (!(this->Treasuretexture.loadFromFile("Hittable/Flying_Treasure.png")))
	{
		cout << "Failed to load Treasure texture" << "\n";
	}
	
}

void Treasure::InitSprite()
{
	
	if (type == 0)
	{
		sprite.setTexture(Treasuretexture);
		sprite.setTextureRect(IntRect(135, 0, 375, 385));
	}
	if (type == 1)
	{
		sprite.setTexture(Treasuretexture);
		sprite.setTextureRect(IntRect(135, 425, 375, 385));
	}
	sprite.setScale(float(0.15), float(0.15));
}

Treasure::Treasure(float pos_x, float pos_y,int t)
{
	type = t;
	this->InitTextures();
	this->InitSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

void Treasure::updateTreasure()
{
	this->sprite.move(-35.f, 0.f);
}

void Treasure::renderTreasure(RenderTarget* target)
{
	target->draw(this->sprite);
}

void Treasure::InitType(int t)
{
	type = t;
}

const FloatRect Treasure::getBounds()
{
	return this->sprite.getGlobalBounds();
}

int Treasure::getType()
{
	return type;
}


