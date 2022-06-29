#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;


        sf::Sprite sprite1;
        sf::Vector2u textureSize;
        sf::Texture  texture1;

        sf::Event ev;


        bool endGame;
        unsigned points;
        int health;  


        void initVariables();
        void initWindow();
        void initTexture();




    public:
        Game();      
        
        const bool isRunning() const;

        virtual ~Game();
        void pollEvents();
        
        void render();
        void update();
};