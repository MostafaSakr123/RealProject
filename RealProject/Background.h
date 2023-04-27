#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include "Dino.h"

using namespace sf;
using namespace std;
class Background
{
private:
	//font
	Font font;


	//Text
	Text Text1;
	Text Text2;

	//Music and Sounds

	Music music;
	Music music2;
	

	RectangleShape box1, box2, box3;
	Dino FigureDino1, FigureDino2, FigureDino3, FigureDino4;
	
	//Functions
	

public:
	Background();
	~Background();

	void Initboxes();
	void InitFonts();
	void InitText();
	void InitMusic();
	void renderText(RenderTarget& target);
	void renderBoxes(RenderTarget& target);
	void renderDinos( RenderTarget& target);
	void muteMusic();
	void muteMusic2();
};

