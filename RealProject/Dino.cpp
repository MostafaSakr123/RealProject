#include "Dino.h"

void Dino::InitTextures()
{
	if (!(this->GreenTexture.loadFromFile("Player/sheets/DinoSprites_0.png")))
	{
		cout << "Failed to load green texture" << "\n";
	}
	if (!(this->RedTexture.loadFromFile("Player/sheets/DinoSprites_1.png")))
	{
		cout << "Failed to load red texture" << "\n";
	}
	if (!(this->YellowTexture.loadFromFile("Player/sheets/DinoSprites_2.png")))
	{
		cout << "Failed to load yellow texture" << "\n";
	}
	if (!(this->BlueTexture.loadFromFile("Player/sheets/DinoSprites_3.png")))
	{
		cout << "Failed to load blue texture" << "\n";
	}
	GreenTexture.loadFromFile("Player/sheets/DinoSprites_0.png");
	RedTexture.loadFromFile("Player/sheets/DinoSprites_1.png");
	YellowTexture.loadFromFile("Player/sheets/DinoSprites_2.png");
	BlueTexture.loadFromFile("Player/sheets/DinoSprites_3.png");

	

}
void Dino::InitSprite()
{
	
		if (Color == "Green")
			sprite.setTexture(GreenTexture);
		else if (Color == "Red")
			sprite.setTexture(RedTexture);
		else if (Color == "Yellow")
			sprite.setTexture(YellowTexture);
		else if (Color == "Blue")
			sprite.setTexture(BlueTexture);

		
		
		

			sprite.setTextureRect(IntRect(24 * frame, 0, 24, 24));
			sprite.setScale(5.f, 5.f);
			if (frameCounter == 5)
			{
				frame = (frame + 1) % 11;
				frameCounter = 0;
			}
			frameCounter++;
		
	
}



// Constructor and Destructor

Dino::Dino()
{
	this->InitTextures();
	

}

Dino::~Dino()
{
	alive = false;
}

string Dino::getColor()
{
	return Color;
}

void Dino::setColor(string c)
{
	Color = c;
}

void Dino::drawSprite(RenderTarget& target)
{
	target.draw(sprite);
}

void Dino::setSpritePosition(float x, float y)
{
	sprite.setPosition(x, y);
}
