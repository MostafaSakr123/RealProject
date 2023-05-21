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
#include "Heart.h"
#include "Treasure.h"
#include"StandingEnemy.h"
#include "FlyingEnemy.h"
#include <sstream>

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
	void InitHearts();
	void updateHearts();
	void InitTreasures();
	void updateTreasures();
	void InitStandingEnemies();
	void updateStandingEnemies();
	void InitFlyingEnemies();
	void updateFlyingEnemies();
	void updateCollision();
	void InitFont();
	void InitText();
	void updateText();
	void renderLivesAndScore(RenderTarget* target);

	// Private members
	float spawnHeartTimer;
	float spawnHeartTimerMax;
	float spawnTreasureTimer;
	float spawnTreasureTimerMax;
	float spawnStandingEnemiesTimer;
	float spawnStandingEnemiesTimerMax;
	float spawnFlyingEnemiesTimer;
	float spawnFlyingEnemiesTimerMax;
	vector<Heart*> hearts;
	vector<Treasure*> treasures;
	vector<StandingEnemy*> standingenemies;
	vector<FlyingEnemy*> flyingenemies;
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
	Texture groundTexture;
	Sprite groundSprite;
	int score = 0;
	int lives =3;
	Font font;
	Text text;

};

