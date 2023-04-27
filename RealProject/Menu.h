#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "time.h"
#include <ctime>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#pragma warning(disable : 4996)
#pragma warning(disable : 6385)
#pragma warning(disable : 4244)
using namespace sf;
using namespace std;
class Menu
{
private:
	int move;
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	Font font;
	RectangleShape Background;
	RectangleShape Box;
	Texture Backg;
	Texture liftClick;
	Texture moving;
	Texture enter;
	Texture down;
	Texture up;
	Texture backSpace;
	Sprite liftClickSpr;
	Sprite movingSpr;
	Sprite enterSpr;
	Sprite downSpr;
	Sprite upSpr;
	Sprite backSpaceSpr;
	string* stringArray = new string[100];
	Text menuName;
	Text* textArray = new Text[100];
	Text currentTime;
	int selected;
public:
	Menu(RenderTarget& window, float width, float height, string ar[], int m, string mN);
	void displayMenuName(RenderTarget& window);
	void setOptions(RenderTarget& window, int m);
	void setBackground(RenderTarget& window, string fileName);
	//bool updateMousePos(RenderWindow& window);
	void setKeyboardIcons();
	void renderKeyboardSpr(RenderTarget& window);
	void renderBackSpaceSpr(RenderTarget& window);
	void displayTime(RenderTarget& window);
	int getMove(int m);
	void moveUp(int m);
	void moveDown(int m);;
	~Menu();
};
