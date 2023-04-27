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

//Constructors and Destructors

Game::Game() :
	main_menu(*window, 1200.f, 800.f, mainMenuButtons, 4, "Main Menu"),
	diff_sel_menu(*window, 1200.f, 800.f, diffMenuButtons, 2, "Select Difficulty"),
	about(*window, 1200.f, 800.f, aboutText, 4, "About"),
	credits(*window, 1200.f, 800.f, creditsText, 5, "Credits"),
	howToPlay(*window, 1200.f, 800.f, howYoPlayText, 4, "How To Play"),
	gamePlay(*window,1200.f,800.f,0,0,"")
{
	this->InitVariables();
	this->InitWindow();
	this->background->Initboxes();
	this->background->InitFonts();
	this->background->InitText();
	this->background->InitMusic();
}

Game::~Game()
{
	delete this->window;
	delete this->background;
	
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
			if (this->ev.key.code == Keyboard::Enter && mainSelected == 0 && selectedText == 0 && selectedText2==0)
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

				break;
			}
			if (selectedText == 1 && diff_sel_menu.getMove(2) == 1 && this->ev.key.code == Keyboard::Enter)
			{
				selectedText2 = 2;
				diffucilityMode = 2;
				selectedText = 0;

				break;
			}
			if ((this->ev.key.code == Keyboard::BackSpace) && (selectedText2 == 1 || selectedText2 == 2))
			{
				selectedText = 1;
				selectedText2 = 0;
				break;
			}
			if ((this->ev.key.code == Keyboard::Enter) && (selectedText2 == 1 || selectedText2 == 2))
			{
				startGame = 1;
				selectedText2 = 0;
				break;
				
			}
			if (startGame == 1 && this->ev.key.code == Keyboard::W )
			{
				playingDino.moveSprite(0,-10.f);

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


			if (selectedText == 1 && this->ev.key.code == Keyboard::Up)
				this->diff_sel_menu.moveUp(2);
			if (selectedText == 1 && this->ev.key.code == Keyboard::Down)
				this->diff_sel_menu.moveDown(2);
		}
	}
}

void Game::update()
{
	this->pollEvents();
}



void Game::render()
{
	this->window->clear();  //Clearing the screen gets rid of anything that was already on the screen, so you end up with a blank canvas to redraw everything on in its updated position


	this->background->renderBoxes(*window);
	this->background->renderText(*window);
	this->background->renderDinos(*window);
	if (startGame == 1)
	{
		gamePlay.setBackground(*window, "background/static/3.png");
		playingDino.InitSprite();
		playingDino.setSpritePosition(50.f, 550.f);
		playingDino.drawSprite(*window);
		
	}
	if (mainSelected == 1)
	{
		this->main_menu.setBackground(*window, "102.png");
		this->main_menu.displayMenuName(*window);
		this->main_menu.displayTime(*window);
		this->main_menu.setOptions(*window, 4);
		this->main_menu.renderKeyboardSpr(*window);
		
		
	}
	if (selectedText == 1 )
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


	this->window->display();  //Display on screen what has been rendered to the window so far.
}


