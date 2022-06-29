#include <iostream>

#include "game.h"


Game::Game()
{
    this->initWindow();
    this->initTexture();

}

Game::~Game()
{
    delete this->window;
}

void Game::initWindow()
{
    this->videoMode.width = 1024;
    this->videoMode.height = 1024;

    this->window = new sf::RenderWindow (this->videoMode, "video juego" );
    
}

void Game::initTexture()
{

    if(!this->texture1.loadFromFile("esenario1.png")) {
        system( "echo No se pude ");
    }
    this->sprite1.setTexture(this->texture1);
    this->textureSize = this->texture1.getSize();
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
        }
    }
}

void Game::render()
{
    this->window->clear();
    this->window->draw(this->sprite1);
    this->window->display();
}

const bool Game::isRunning() const
{
    return this->window->isOpen();
}

void Game::update()
{
    this->pollEvents();

    if(this->endGame == false)
    {

    }

    if(this-> health <= 0)
    {
        this->endGame = true;
    }

}


using namespace std;

int main(){
    //random seed
    
    //init game engine
    Game game;

    //game loop
    while (game.isRunning())
    {
        //Update
        game.update();

        //Render
        game.render();
    }
    //end of application
    return 0;
}




/*
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>





int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(), "No botes la basura!", sf::Style::Fullscreen);
    sf::View worldview(window.getDefaultView());
    // Load a sprite to display
    // Play the music}
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
*/
