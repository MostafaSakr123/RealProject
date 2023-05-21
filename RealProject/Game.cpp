#include "Game.h"
//Private Functions
void Game::InitVariables()
{
	this->window = nullptr;


	if (!(this->JumpBuffer.loadFromFile("Music/jump.wav")))
	{
		cout << "Failed to load jumping sound effect" << "\n";
	}
	if (!(this->DuckingBuffer.loadFromFile("Music/ducking.wav")))
	{
		cout << "Failed to load ducking sound effect" << "\n";
	}
	if (!(this->DoubleJumpBuffer.loadFromFile("Music/double_jump.wav")))
	{
		cout << "Failed to load double jump sound effect" << "\n";
	}

	JumpSound.setBuffer(JumpBuffer);
	DoubleJumpSound.setBuffer(DoubleJumpBuffer);
	DuckingSound.setBuffer(DuckingBuffer);




}

void Game::InitWindow()
{
	this->window = new RenderWindow(VideoMode(1200, 800), "Dino runner", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::InitHearts()
{
	this->spawnHeartTimerMax = 20.f;
	this->spawnHeartTimer = this->spawnHeartTimerMax;
}

void Game::updateHearts()
{
	this->spawnHeartTimer += 0.5f;
	if (this->spawnHeartTimer >= spawnHeartTimerMax)
	{
		this->hearts.push_back(new Heart(this->window->getSize().x + 100.f, (rand() % (550 - 350 + 1)) + 350.f));
		this->spawnHeartTimer = 0.f;
	}
	for (int i = 0; i < this->hearts.size(); ++i)
	{
		this->hearts[i]->updateHeart();
		//Remove  when they reach the very left of the window
		if (this->hearts[i]->getBounds().left > this->window->getSize().x + 200.f)
		{
			this->hearts.erase(this->hearts.begin() + i);
		}
	}
}

void Game::InitTreasures()
{
	this->spawnTreasureTimerMax = 15.f;
	this->spawnTreasureTimer = this->spawnHeartTimerMax;
}

void Game::updateTreasures()
{
	this->spawnTreasureTimer += 0.5f;
	if (this->spawnTreasureTimer >= spawnTreasureTimerMax)
	{
		this->treasures.push_back(new Treasure(this->window->getSize().x + 100.f, (rand() % (550 - 350 + 1) + 350.f), rand() % 2));
		this->spawnTreasureTimer = 0.f;
	}
	for (int i = 0; i < this->treasures.size(); ++i)
	{
		this->treasures[i]->updateTreasure();
		//Remove  when they reach the very left of the window
		if (this->treasures[i]->getBounds().left > this->window->getSize().x + 200.f)
		{
			this->treasures.erase(this->treasures.begin() + i);
		}
	}
}

void Game::InitStandingEnemies()
{
	this->spawnStandingEnemiesTimerMax = 10.f;
	this->spawnStandingEnemiesTimer = this->spawnStandingEnemiesTimerMax;
}

void Game::updateStandingEnemies()
{
	this->spawnStandingEnemiesTimer += 0.5f;
	if (this->spawnStandingEnemiesTimer >= spawnStandingEnemiesTimerMax)
	{
		this->standingenemies.push_back(new StandingEnemy(this->window->getSize().x + 100.f, 580.f));
		this->spawnStandingEnemiesTimer = 0.f;
	}
	for (int i = 0; i < this->standingenemies.size(); ++i)
	{
		this->standingenemies[i]->updateEnemy();
		//Remove  when they reach the very left of the window
		if (this->standingenemies[i]->getBounds().left > this->window->getSize().x + 200.f)
		{
			this->standingenemies.erase(this->standingenemies.begin() + i);
		}
	}
}

void Game::InitFlyingEnemies()
{
	this->spawnFlyingEnemiesTimerMax = 10.f;
	this->spawnFlyingEnemiesTimer = this->spawnFlyingEnemiesTimerMax;
}

void Game::updateFlyingEnemies()
{
	this->spawnFlyingEnemiesTimer += 0.5f;
	if (this->spawnFlyingEnemiesTimer >= spawnFlyingEnemiesTimerMax)
	{
		this->flyingenemies.push_back(new FlyingEnemy(this->window->getSize().x + 100.f, (rand() % (550 - 350 + 1)) + 350.f));
		this->spawnFlyingEnemiesTimer = 0.f;
	}
	for (int i = 0; i < this->flyingenemies.size(); ++i)
	{
		this->flyingenemies[i]->updateEnemy();
		//Remove  when they reach the very left of the window
		if (this->flyingenemies[i]->getBounds().left > this->window->getSize().x + 200.f)
		{
			this->flyingenemies.erase(this->flyingenemies.begin() + i);
		}
	}
}



void Game::updateCollision()
{
	for (size_t i = 0; i < this->hearts.size(); i++)
	{
		if (this->playingDino.getBounds().intersects(this->hearts[i]->getBounds()))
		{
			this->hearts.erase(this->hearts.begin() + i);
			this->lives++;
		}
	}
	for (size_t i = 0; i < this->treasures.size(); i++)
	{
		if (this->playingDino.getBounds().intersects(this->treasures[i]->getBounds()))
		{
			if (treasures[i]->getType() == 0)
				this->score++;
			if (treasures[i]->getType() == 1)
				this->score += 2;
			this->treasures.erase(this->treasures.begin() + i);


		}
	}
	for (size_t i = 0; i < this->standingenemies.size(); i++)
	{
		if (this->playingDino.getBounds().intersects(this->standingenemies[i]->getBounds()))
		{
			this->standingenemies.erase(this->standingenemies.begin() + i);
			this->lives--;
		}
	}
	for (size_t i = 0; i < this->flyingenemies.size(); i++)
	{
		if (this->playingDino.getBounds().intersects(this->flyingenemies[i]->getBounds()))
		{
			this->flyingenemies.erase(this->flyingenemies.begin() + i);
			this->lives--;
		}
	}
}


void Game::InitFont()
{
	if (!this->font.loadFromFile("Fonts/CoffeCake.ttf")) { cout << "Font Error"; }
}

void Game::InitText()
{
	this->text.setFont(this->font);
	this->text.setFillColor(Color::White);
	this->text.setCharacterSize(32);

}

void Game::updateText()
{
	stringstream ss;
	ss << "Score: " << this->score << "\n" << "Lives: " << lives;
	this->text.setString(ss.str());
}


void Game::renderLivesAndScore(RenderTarget* target)
{
	target->draw(this->text);
}

void Game::profileMaker(string profileName)
{
	oprofileCounter.open("profileNumbers.txt", ios::out | ios::app);
	oprofileCounter << 1;
	oprofileCounter.close();
	iprofileCounter.open("profileNumbers.txt");
	getline(iprofileCounter, line);
	outputArr[line.length()].open(profileName + ".txt");
	outputArr[line.length()] << line.length() << endl;
	outputArr[line.length()].close();
}

string Game::profileScore(string profileN, int sc)
{
	inputArr[line.length()].open(profileN + ".txt");
	while (getline(inputArr[line.length()], newLine))
	{
		lines.push_back(newLine);
	}
	inputArr[line.length()].close();
	outputArr[line.length()].open(profileN + ".txt");
	for (int i = 0; i < 2; i++)
	{
		if (i != 1)
		{
			outputArr[line.length()] << lines[i];
		}
		else if (sc > stoi(lines[1]))
		{
			outputArr[line.length()] << sc;
		}
	}
	return to_string(sc);
}

//Constructors and Destructors

Game::Game() :
	main_menu(*window, 1200.f, 800.f, mainMenuButtons, 4, "Main Menu"),
	diff_sel_menu(*window, 1200.f, 800.f, diffMenuButtons, 2, "Select Difficulty"),
	about(*window, 1200.f, 800.f, aboutText, 4, "About"),
	credits(*window, 1200.f, 800.f, creditsText, 5, "Credits"),
	howToPlay(*window, 1200.f, 800.f, howYoPlayText, 4, "How To Play"),
	gamePlay(*window, 1200.f, 800.f, 0, 0, ""),
	gameOver(*window, 1200.f, 800.f, gameOverText, 4, "GameOver"),
	newOrOld(*window, 1200.f, 800.f, newOrOldText, 2, "Select one Option"),
	createProfile(*window, 1200.f, 800.f,createProfileText, 2, ""),
	oldProfile(*window,1200.f,800.f,oldProfileText,2,"")
{
	this->InitVariables();
	this->InitWindow();
	this->background->Initboxes();
	this->background->InitFonts();
	this->background->InitText();
	this->background->InitMusic();
	this->InitFont();
	this->InitText();
	this->InitHearts();
	this->InitTreasures();
	this->InitStandingEnemies();
	this->InitFlyingEnemies();

}

Game::~Game()
{
	delete this->window;
	delete this->background;
	for (auto* heart : this->hearts)
	{
		delete heart;
	}
	for (auto* treasure : this->treasures)
	{
		delete treasure;
	}
	for (auto* standingenemy : this->standingenemies)
	{
		delete standingenemy;
	}
	for (auto* flyingenemy : this->flyingenemies)
	{
		delete flyingenemy;
	}
	delete[] inputArr;
	delete[] outputArr;
}

// Accessors

const bool Game::running() const
{
	return this->window->isOpen();
}

//Public Functions



void Game::pollEvents()
{
	// polling events
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;

		case   Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Enter && mainSelected == 0 && selectedText == 0 && selectedText2 == 0)
			{
				mainSelected = 1;
				selectedText = 0;
				this->background->muteMusic();

				break;
			}
			if (this->ev.key.code == Keyboard::M)
			{
				this->background->muteMusic2();
				break;
			}
			if (mainSelected == 1 && main_menu.getMove(4) == 0 && this->ev.key.code == Keyboard::Enter)
			{
				selectedText = 1;
				mainSelected = 0;


				break;
			}
			if (mainSelected == 1 && main_menu.getMove(4) == 1 && this->ev.key.code == Keyboard::Enter)
			{
				selectedText = 2;
				mainSelected = 0;

				break;
			}
			if (mainSelected == 1 && main_menu.getMove(4) == 2 && this->ev.key.code == Keyboard::Enter)
			{
				selectedText = 3;
				mainSelected = 0;

				break;
			}

			if (mainSelected == 1 && main_menu.getMove(4) == 3 && this->ev.key.code == Keyboard::Enter)
			{
				this->window->close();
				break;
			}

			if (this->ev.key.code == Keyboard::BackSpace && (selectedText == 1 || selectedText == 2 || selectedText == 3))
			{
				selectedText = 0;
				mainSelected = 1;
				break;
			}
			if (selectedText == 1 && diff_sel_menu.getMove(2) == 0 && this->ev.key.code == Keyboard::Enter)
			{
				selectedText2 = 1;
				diffucilityMode = 1;
				selectedText = 0;
				newOrOldInt = 1;
				break;
			}
			if (selectedText == 1 && diff_sel_menu.getMove(2) == 1 && this->ev.key.code == Keyboard::Enter)
			{
				selectedText2 = 2;
				diffucilityMode = 2;
				selectedText = 0;
				newOrOldInt = 1;
				break;
			}
			if (newOrOldInt == 1 &&  newOrOld.getMove(2) == 0 && this->ev.key.code == Keyboard::Enter)
			{
				createProfilesInt = 1;				
				profilesMenuInt = 0;
				enter = 1;
				break;
			}
			if (newOrOldInt == 1 && newOrOld.getMove(2) == 1 && this->ev.key.code == Keyboard::Enter)
			{
				profilesMenuInt = 1;
				createProfilesInt = 0;
				enter = 1;
				break;
			}
			if (enter == 1 && this->ev.key.code == Keyboard::Enter)
			{
				startGame = 1;
				createProfilesInt = 0;
				profilesMenuInt = 0;
			}
			if ((this->ev.key.code == Keyboard::BackSpace) && (selectedText2 == 1 || selectedText2 == 2))
			{
				selectedText = 1;
				selectedText2 = 0;
				break;
			}
			if (startGame == 1 && this->ev.key.code == Keyboard::W)
			{
				playingDino.moveSprite(0, -10.f);

				JumpSound.play();
				break;
			}
			if (startGame == 1 && this->ev.key.code == Keyboard::S)
			{
				playingDino.makeDuckingAnimation();
				DuckingSound.play();
				break;
			}

			if (mainSelected == 1 && this->ev.key.code == Keyboard::Up)
				this->main_menu.moveUp(4);
			if (mainSelected == 1 && this->ev.key.code == Keyboard::Down)
				this->main_menu.moveDown(4);
			if (mainSelected == 1 && this->ev.key.code == Keyboard::Up)
				this->newOrOld.moveUp(2);
			if (newOrOldInt == 1 && this->ev.key.code == Keyboard::Down)
				this->newOrOld.moveDown(2);
			if (newOrOldInt == 1 && this->ev.key.code == Keyboard::Up)
				this->newOrOld.moveUp(2);
			if (selectedText == 1 && this->ev.key.code == Keyboard::Down)
				this->diff_sel_menu.moveDown(2);
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->updateHearts();
	this->updateTreasures();
	this->updateStandingEnemies();
	this->updateFlyingEnemies();
	this->updateCollision();
	this->updateText();
}



void Game::render()
{
	this->window->clear();  //Clearing the screen gets rid of anything that was already on the screen, so you end up with a blank canvas to redraw everything on in its updated position


	this->background->renderBoxes(*window);
	this->background->renderText(*window);
	this->background->renderDinos(*window);
	if (startGame==1)
	{

		playingDino.InitPlayingDinoSprite();
		playingDino.setSpritePosition(50.f, 400.f);
		gamePlay.setBackground(*window, "background/static/3.png");
		playingDino.drawSprite(*window);
		this->renderLivesAndScore(this->window);
		for (auto* heart : this->hearts)
		{
			heart->renderHeart(this->window);
		}
		for (auto* treasure : this->treasures)
		{
			treasure->renderTreasure(this->window);
		}
		for (auto* standingenemy : this->standingenemies)
		{
			standingenemy->renderEnemy(this->window);
		}
		for (auto* flyingenemy : this->flyingenemies)
		{
			flyingenemy->renderEnemy(this->window);
		}

	}
	if (mainSelected == 1)
	{
		this->main_menu.setBackground(*window, "102.png");
		this->main_menu.displayMenuName(*window);
		this->main_menu.displayTime(*window);
		this->main_menu.setOptions(*window, 4);
		this->main_menu.renderKeyboardSpr(*window);


	}
	if (selectedText == 1)
	{
		this->diff_sel_menu.setBackground(*window, "101.png");
		this->diff_sel_menu.displayMenuName(*window);
		this->diff_sel_menu.displayTime(*window);
		this->diff_sel_menu.setOptions(*window, 2);
		this->diff_sel_menu.renderKeyboardSpr(*window);
		this->diff_sel_menu.renderBackSpaceSpr(*window);


	}
	if (selectedText == 2)
	{
		this->about.setBackground(*window, "102.png");
		this->about.displayMenuName(*window);
		this->about.displayTime(*window);
		this->about.setOptions(*window, 4);
		this->about.renderKeyboardSpr(*window);
		this->about.renderBackSpaceSpr(*window);
	}
	if (selectedText == 3)
	{
		this->credits.setBackground(*window, "102.png");
		this->credits.displayMenuName(*window);
		this->credits.displayTime(*window);
		this->credits.setOptions(*window, 5);
		this->credits.renderKeyboardSpr(*window);
		this->credits.renderBackSpaceSpr(*window);
	}
	if (selectedText2 == 1 || selectedText2 == 2)
	{
		this->howToPlay.setBackground(*window, "3.png");
		this->howToPlay.displayMenuName(*window);
		this->howToPlay.displayTime(*window);
		this->howToPlay.setOptions(*window, 4);
		this->howToPlay.renderKeyboardSpr(*window);
		this->howToPlay.renderBackSpaceSpr(*window);

	}
	if (newOrOldInt == 1)
	{
		this->newOrOld.setBackground(*window, "3.png");
		this->newOrOld.displayMenuName(*window);
		this->newOrOld.displayTime(*window);
		this->newOrOld.setOptions(*window, 2);
		this->newOrOld.renderKeyboardSpr(*window);
		this->newOrOld.renderBackSpaceSpr(*window);
	}
	if (createProfilesInt == 1 && profilesMenuInt==0)
	{
		this->createProfile.setBackground(*window, "3.png");
		this->createProfile.displayMenuName(*window);
		this->createProfile.displayTime(*window);
		this->createProfile.setOptions(*window, 2);
		this->createProfile.renderKeyboardSpr(*window);
		this->createProfile.renderBackSpaceSpr(*window);
		if (ev.type == sf::Event::TextEntered)
		{
			profileInput += ev.text.unicode;
			profileText.setString(profileInput);
			profileText.setFont(font);
			profileText.setCharacterSize(40);
			profileText.setFillColor(Color::White);
			profileText.setPosition(Vector2f(1200 / 2 - 100, 800 / 16 * ((8 - 2 / 2) + 1)));
		}
		profileMaker(profileInput);
		window->draw(profileText);
	}
	if (profilesMenuInt == 1 && createProfilesInt == 0)
	{
		this->oldProfile.setBackground(*window, "3.png");
		this->oldProfile.displayMenuName(*window);
		this->oldProfile.displayTime(*window);
		this->oldProfile.setOptions(*window, 2);
		this->oldProfile.renderKeyboardSpr(*window);
		this->oldProfile.renderBackSpaceSpr(*window);
		if (ev.type == sf::Event::TextEntered)
		{
			profileInput += ev.text.unicode;
			profileText.setString(profileInput);
			profileText.setFont(font);
			profileText.setCharacterSize(40);
			profileText.setFillColor(Color::White);
			profileText.setPosition(Vector2f(1200 / 2 - 100, 800 / 16 * ((8 - 2 / 2) + 1)));
		}
		window->draw(profileText);
	}
	if (this->lives == 0)
	{
		this->gameOver.setBackground(*window, "3.png");
		this->gameOver.displayMenuName(*window);
		this->gameOver.setOptions(*window, 4);
		scoreText.setFont(font);
		scoreText.setCharacterSize(40);
		scoreText.setString(to_string(score));
		scoreText.setFillColor(Color::White);
		scoreText.setPosition(Vector2f(1200 / 2 - 100, 800 / 16 * ((8 - 4 / 2) + 1)));
		scoreText.setOutlineColor(Color::Red);
		bestScoreText.setFont(font);
		bestScoreText.setCharacterSize(40);
		bestScoreText.setString(profileScore(profileInput,score));
		bestScoreText.setFillColor(Color::White);
		bestScoreText.setPosition(Vector2f(1200 / 2 - 100, 800 / 16 * ((8 - 4 / 2) + 1)));
		bestScoreText.setOutlineColor(Color::Red);
		window->draw(bestScoreText);
		window->draw(scoreText);
	}


	this->window->display();  //Display on screen what has been rendered to the window so far.
}


