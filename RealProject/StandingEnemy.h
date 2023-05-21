#pragma once
#include "IEnemy.h"
using namespace std;
using namespace sf;
class StandingEnemy :public IEnemy
{
private:
	Texture texture;
	Sprite sprite;
	IntRect rectTreasureSprite;
	int frame = 0;
	int frameCounter = 0;


	void InitTextures();
	void InitSprite();

public:
	StandingEnemy(float pos_x, float pos_y);
	void updateEnemy();
	void renderEnemy(RenderTarget* target);

	//Accessors
	const FloatRect getBounds();


};

