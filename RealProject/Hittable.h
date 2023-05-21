#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
class Hittable
{
public:
	Hittable();
	virtual const FloatRect getBounds() = 0;
};

