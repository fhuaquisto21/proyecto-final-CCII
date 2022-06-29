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
        sf::RenderWindow window;


        sf:Sprite sprite1;
        sf:Vector2u textureSize;
        sf:Texture  texture;


        bool endGame;
        unsigned points;
        int health;



        void initVariables();
        void initWindow();
        void initFonts();
        void initText();
        void initFood();
        void initEnemies();

    public:
        Game();
        virtual ~Game();
        
        void render();
};