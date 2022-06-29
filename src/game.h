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


        sf::Sprite* sprite1;
    
        sf::Texture*  texture1;

        sf::Sprite* sprite2;
   
        sf::Texture* texture2;

        
        sf::Sprite* sprite3;
  
        sf::Texture* texture3;

        std::vector<sf::Sprite> walls;

        sf::FloatRect nextPos;

        sf::RectangleShape nextBox;
        


        sf::Event ev;


        bool endGame;
        unsigned points;
        int health;  


        




    public:
        Game();  
        void initVariables();
        void initWindow();

        void initTexture();
        void initTexture2();
        void initTexture3();

        void  colisiones();  

        
        const bool isRunning() const;

        virtual ~Game();
        void pollEvents();
        
        void render();
        void update();
};