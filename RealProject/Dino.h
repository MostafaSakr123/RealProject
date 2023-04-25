#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "IDino.h"

using namespace std;
using namespace sf;
class Dino:  public IDino
{

private:
	bool alive=true;
	Texture GreenTexture;
	Texture RedTexture;
	Texture YellowTexture;
	Texture BlueTexture;
	
	IntRect rectSourceSpirite;
	Clock clock;
	string Color="Green";
	Sprite sprite;
	int frame = 0;
	
	int frameCounter = 0;

	//public functions

	void InitTextures();
	

	




public:
	Dino();
	~Dino();
	string getColor();
	void setColor(string c);
	
	void drawSprite(RenderTarget& target);
	void setSpritePosition(float x, float y);
	void InitSprite();





};


