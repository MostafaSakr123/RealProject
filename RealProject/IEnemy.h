#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Hittable.h"
using namespace std;
using namespace sf;
class IEnemy
{
public:
	IEnemy();

	virtual void updateEnemy()=0;
	virtual void renderEnemy(RenderTarget* target)=0;

	//Accessors
	virtual const FloatRect getBounds()=0;
};

