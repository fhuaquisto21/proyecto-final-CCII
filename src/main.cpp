#include <iostream>

#include "game.h"


Game::Game()
{
    this->initWindow();
    this->initTexture();
    this->initTexture2();
    this->initTexture3();
    
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
    
    this->texture1 = new sf::Texture;

    this->sprite1 = new sf::Sprite;

    this->texture1->loadFromFile("esenario1.png");
       
    this->sprite1->setTexture(*texture1);
 

}


void Game::initTexture2()
{
    this->texture2 = new sf::Texture;

    this->sprite2 = new sf::Sprite;

    this->texture2->loadFromFile("jugador2a.png");
       
    this->sprite2->setTexture(*texture2);

    this->sprite2->setPosition(800,800);



}



void Game::initTexture3()
{
    //std::vector<sf::Sprite> walls;

    this->texture3 = new sf::Texture;

    this->sprite3 = new sf::Sprite;

    this->texture3->loadFromFile("piedra.png");
       
    this->sprite3->setTexture(*texture3);

    this->sprite3->setPosition(140,100);

    walls.push_back(*sprite3);


}




void Game::pollEvents()
{
    while(this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                exit(1);
                break;
                
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    this->sprite2->setPosition(this->sprite2->getPosition().x,this->sprite2->getPosition().y-6 );
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    this->sprite2->setPosition(this->sprite2->getPosition().x,this->sprite2->getPosition().y+6 );
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    this->sprite2->setPosition(this->sprite2->getPosition().x-6,this->sprite2->getPosition().y );
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    this->sprite2->setPosition(this->sprite2->getPosition().x+6,this->sprite2->getPosition().y );
                }
                
                break;
        }
    }
}





void Game::colisiones()

{



   if(this->sprite2->getPosition().x < 0.f)
   {
        this->sprite2->setPosition(0.f, this->sprite2->getPosition().y);
   }

    if(this->sprite2->getPosition().y < 0.f)
   {
        this->sprite2->setPosition(this->sprite2->getPosition().x, 0.f);
   }

   if(this->sprite2->getPosition().x + this->sprite2->getGlobalBounds().width > 1024 )
   {
        this->sprite2->setPosition(1024 - this->sprite2->getGlobalBounds().width, this->sprite2->getPosition().y);
   }


    if(this->sprite2->getPosition().y + this->sprite2->getGlobalBounds().height > 1024 )
   {
        this->sprite2->setPosition(this->sprite2->getPosition().x, 1024 - this->sprite2->getGlobalBounds().height);
   }

}



void Game::render()
{
    this->window->clear();
    this->window->draw(*sprite1);
    this->window->draw(*sprite2);
    for( auto &i : walls) 
    {
        window->draw(i);
    }
    this->window->display();
}

const bool Game::isRunning() const
{
    return this->window->isOpen();
}

void Game::update()
{
    this->pollEvents();
    this->colisiones();
  
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
