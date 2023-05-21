#include <iostream>
#include"Game.h"
#include <time.h>


using namespace sf;



int main()
{
    srand(time(0));
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


}
