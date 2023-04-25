#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class IDino
{
private:
	Texture GreenTexture;
	Texture RedTexture;
	Texture YellowTexture;
	Texture BlueTexture;
	Sprite sprite;
	IntRect rectSourceSpirite;
	Clock clock;



public:
	IDino();
	~IDino();
	



};

