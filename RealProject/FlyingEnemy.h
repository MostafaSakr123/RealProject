#pragma once
#include "IEnemy.h"
using namespace std;
using namespace sf;
class FlyingEnemy :public IEnemy
{
private:
	Texture texture;
	Sprite sprite;
	IntRect rectTreasureSprite;
	


	void InitTextures();
	void InitSprite();

public:
	FlyingEnemy(float pos_x, float pos_y);
	void updateEnemy();
	void renderEnemy(RenderTarget* target);

	//Accessors
	const FloatRect getBounds();


};


