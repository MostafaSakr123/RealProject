#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include"Background.h"
#include "Dino.h"

using namespace sf;
using namespace std;

class Game
{

public:
	Game();
	~Game();
	void pollEvents();
	void update();
	void render();
	const bool running() const;


private:
	//Private Functions
	void InitVariables();
	void InitWindow();

	// Private members

	Background* background = new Background;
	RenderWindow* window;
	Event ev;
	
};

