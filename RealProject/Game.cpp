#include "Game.h"
//Private Functions
void Game::InitVariables()
{
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->window=new RenderWindow(VideoMode(1200, 800), "Dino runner", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);
}

//Constructors and Destructors

Game::Game()
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
            if (this->ev.key.code == Keyboard::Escape)
                this->window->close();
            if (this->ev.key.code == Keyboard::Enter)
            {
            
                
            }
            break;


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
    

    this->window->display();  //Display on screen what has been rendered to the window so far.
}


