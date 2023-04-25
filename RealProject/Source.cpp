#include <iostream>
#include"Game.h"
using namespace sf;



int main()
{
    Game game;

    // Gameloop

    while(game.running())
    {
        //Update
        
        game.update();

        //Render
        game.render();


    }

    // end of application

    return 0;
}
