#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Hittable.h"


using namespace std;
using namespace sf;
class Heart :public Hittable
{
private:
	Texture Hearttexture;
	Sprite sprite;
	IntRect rectTreasureSprite;


	void InitTextures();
	void InitSprite();

public:
	Heart(float pos_x, float pos_y);
	void updateHeart();
	void renderHeart(RenderTarget* target);

	//Accessors
	const FloatRect getBounds();

};

