#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include"Background.h"
#include "Dino.h"
#include "Menu.h"

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
	string mainMenuButtons[4] = { "Play","About","Credits","Exit" };
	string diffMenuButtons[2] = { "Easy","Hard" };
	string creditsText[5] = { "This game is made by","Mohamed Hany","Mustafa Sakr", "Nour Osama", "All Rights Reserved@" };
	string aboutText[4] = { "This game is about ","a running dino","jump over enemies and ","avoid hitting them" };
	string howYoPlayText[4] = { "Click 'W' to Jump,","double 'W' to double jump," ,"s to duck" ,"Click 'Enter' to play"};
	Menu main_menu;
	Menu diff_sel_menu;
	Menu about;
	Menu credits;
	Menu howToPlay;
	Menu gamePlay;
	Dino playingDino;
	SoundBuffer JumpBuffer;
	SoundBuffer DuckingBuffer;
	SoundBuffer DoubleJumpBuffer;
	Sound JumpSound;
	Sound DuckingSound;
	Sound DoubleJumpSound;
	int mainSelected = 0;
	int selectedText = 0;
	int selectedText2 = 0;
	int diffucilityMode = 0;
	int startGame=0;
	bool onground;
};

