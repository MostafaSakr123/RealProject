#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Hittable.h"

using namespace std;
using namespace sf;
class Treasure: public Hittable
{
private:
	Texture Treasuretexture;
	Sprite sprite;
	IntRect rectTreasureSprite;
	int type;


	void InitTextures();
	void InitSprite();

public:
	Treasure(float pos_x, float pos_y,int t);
	void updateTreasure();
	void renderTreasure(RenderTarget* target);
	void InitType(int t);
	const FloatRect getBounds();
	int getType();

	
};

