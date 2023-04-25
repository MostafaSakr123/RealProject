#include "Background.h"

//Constructor and Destructor
Background::Background()
{
    this->Initboxes();
    this->InitFonts();
    this->InitText();
    this->InitMusic();
}

Background::~Background()
{

}

void Background::Initboxes()
{
    this->box1.setSize(Vector2f(1200.f, 150.f));
    this->box1.setFillColor(Color(63, 36, 240));
    this->box1.setPosition(Vector2f(0.f, 0.f));

    this->box2.setSize(Vector2f(1200.f, 150.f));
    this->box2.setFillColor(Color(250, 109, 0));
    this->box2.setPosition(Vector2f(0.f, 650.f));

    this->box3.setSize(Vector2f(1200.f, 500.f));
    this->box3.setFillColor(Color::Green);
    this->box3.setPosition(Vector2f(0.f, 150.f));



}

void Background::InitMusic()
{
    if (!(this->music.openFromFile("Music/splash_theme.ogg")))
    {
        cout << "Failed to load music" << "\n";
    }
    else
    {
        music.play();
        music.setLoop(true);
        music.setVolume(10.f);


    }
}



void Background::InitFonts()
{
    if (!(this->font.loadFromFile("Fonts/PixellettersFull.ttf")))
    {
        cout << "Failed to load font" << "\n";
    }
}

void Background::InitText()
{
    this->Text1.setFont(this->font);
    this->Text1.setCharacterSize(180);
    this->Text1.setFillColor(Color::White);
    this->Text1.setString("DINO RUNNER");
    this->Text1.setPosition(200.f, 110.f);

    this->Text2.setFont(this->font);
    this->Text2.setCharacterSize(50);
    this->Text2.setFillColor(Color::White);
    this->Text2.setString("Press ' Enter ' to continue...");
    this->Text2.setPosition(350.f, 500.f);



}

void Background::renderText(RenderTarget& target)
{
   target.draw(this->Text1);
    target.draw(this->Text2);
}

void Background::renderBoxes(RenderTarget& target)
{
    target.draw(this->box1);
    target.draw(this->box2);
    target.draw(this->box3);
}

void Background::renderDinos( RenderTarget& target)
{
    FigureDino1.InitSprite();
    FigureDino1.setColor("Green");
    FigureDino1.setSpritePosition(300.f, 350.f);
    FigureDino1.drawSprite(target);

    FigureDino2.InitSprite();
    FigureDino2.setColor("Red");
    FigureDino2.setSpritePosition(450.f, 350.f);
    FigureDino2.drawSprite(target);

    FigureDino3.InitSprite();
    FigureDino3.setColor("Yellow");
    FigureDino3.setSpritePosition(600.f, 350.f);
    FigureDino3.drawSprite(target);

    FigureDino4.InitSprite();
    FigureDino4.setColor("Blue");
    FigureDino4.setSpritePosition(750.f, 350.f);
    FigureDino4.drawSprite(target);
}


