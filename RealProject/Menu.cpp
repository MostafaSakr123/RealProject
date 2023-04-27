#include "Menu.h"

Menu::Menu(RenderTarget& window, float width, float height, string ar[], int m, string mN)
{
	if (!font.loadFromFile("Fonts/CoffeCake.ttf")) { cout << "Font Error"; }
	for (int i = 0; i < m; i++)
	{
		stringArray[i] = ar[i];
	}
	for (int i = 0; i < m; i++)
	{
		textArray[i].setFont(font);
		textArray[i].setCharacterSize(40);
		textArray[i].setString(stringArray[i]);
		textArray[i].setFillColor(Color::White);
		textArray[i].setPosition(Vector2f(width / 2 - 100, height / 16 * ((8 - m / 2) + i)));
		textArray[i].setOutlineColor(Color::Red);
	}
	move = -1;
	menuName.setFont(font);
	menuName.setString(mN);
	menuName.setFillColor(Color::White);
	menuName.setPosition(width/4-100, 150.f);
	menuName.setCharacterSize(70);
	setKeyboardIcons();
}

void Menu::displayMenuName(RenderTarget& window)
{
	window.draw(menuName);
}


void Menu::setOptions(RenderTarget& window, int m)
{
	for (int i = 0; i < m; i++)
		window.draw(textArray[i]);
}

void Menu::setBackground(RenderTarget& window, string fileName)
{
	Background.setSize(Vector2f(window.getSize().x, window.getSize().y));
	Backg.loadFromFile(fileName);
	Background.setTexture(&Backg);
	window.draw(Background);
}

//bool Menu::updateMousePos(RenderWindow& window)
//{
//	mousePosWindow = Mouse::getPosition(window);
//	mousePosView = window.mapPixelToCoords(mousePosWindow);
//	for (int i = 0; i < 4; i++)
//	{
//		if (textArray[i].getGlobalBounds().contains(mousePosView))
//		{
//			textArray[i].setFillColor(Color::Blue);
//			return true;
//		}
//		else if ((!textArray[i].getGlobalBounds().contains(mousePosView)) && move != i)
//		{
//			textArray[i].setFillColor(Color::White);
//			return false;
//		}
//
//	}
//
//}


void Menu::setKeyboardIcons()
{
	liftClick.loadFromFile("controllers_icons/mouse.png");
	moving.loadFromFile("controllers_icons/mouse.png");
	enter.loadFromFile("controllers_icons/enter.png");
	down.loadFromFile("controllers_icons/arrows.png");
	up.loadFromFile("controllers_icons/arrows.png");
	backSpace.loadFromFile("controllers_icons/back.png");
	liftClickSpr.setTexture(liftClick);
	movingSpr.setTexture(moving);
	enterSpr.setTexture(enter);
	downSpr.setTexture(down);
	upSpr.setTexture(up);
	backSpaceSpr.setTexture(backSpace);
	liftClickSpr.setTextureRect(IntRect(225, 0, 115, 143));
	liftClickSpr.setScale(1 / 2.f, 1 / 2.f);
	liftClickSpr.setPosition(1130.f, 630.f);
	movingSpr.setTextureRect(IntRect(0, 0, 115, 143));
	movingSpr.setScale(1 / 2.f, 1 / 2.f);
	movingSpr.setPosition(1070.f, 630.f);
	enterSpr.setTextureRect(IntRect(0, 0, 107, 96));
	enterSpr.setScale(3 / 4.f, 3 / 4.f);
	enterSpr.setPosition(1110.f, 710.f);
	downSpr.setTextureRect(IntRect(490, 0, 83, 82));
	downSpr.setScale(3 / 4.f, 3 / 4.f);
	downSpr.setPosition(1050.f, 710.f);
	upSpr.setTextureRect(IntRect(162, 0, 83, 82));
	upSpr.setScale(3 / 4.f, 3 / 4.f);
	upSpr.setPosition(980.f, 710.f);
	backSpaceSpr.setTextureRect(IntRect(0, 0,98,98 ));
	backSpaceSpr.setScale(3 / 4.f, 3 / 4.f);
	backSpaceSpr.setPosition(900.f, 710.f);
}

void Menu::renderKeyboardSpr(RenderTarget& window)
{
	window.draw(liftClickSpr);
	window.draw(movingSpr);
	window.draw(enterSpr);
	window.draw(downSpr);
	window.draw(upSpr);
}

void Menu::renderBackSpaceSpr(RenderTarget& window)
{
	window.draw(backSpaceSpr);
}


void Menu::displayTime(RenderTarget& window)
{
	currentTime.setFillColor(Color::White);
	currentTime.setFont(font);
	currentTime.setPosition(0, 0);
	time_t now = time(0);
	char* date_time = ctime(&now);
	currentTime.setString(string(date_time));
	window.draw(currentTime);
}
int Menu::getMove(int m)
{
	for (int i = 0; i < m; i++)
	{
		if (textArray[i].getFillColor() == Color::Blue)
			selected = i;
	}
	return selected;
}

void Menu::moveUp(int m)
{
	if (move - 1 >= 0)
	{
		textArray[move].setFillColor(Color::White);
		move--;
		if (move == -1)
		{
			move = (m-2);
		}
		textArray[move].setFillColor(Color::Blue);
	}
}
void Menu::moveDown(int m)
{
	if (move + 1 <= m)
	{
		textArray[move].setFillColor(Color::White);
		move++;
		if (move == m)
		{
			move = 0;
		}
		textArray[move].setFillColor(Color::Blue);
	}
}
Menu::~Menu()
{
	delete this->stringArray;
	delete this->textArray;
}