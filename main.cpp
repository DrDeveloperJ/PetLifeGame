#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //-------------------------------------- INITIALIZE ------------------------------------------
    sf::RenderWindow window(sf::VideoMode(1350, 680), "Pet Game");
    //--------------------------------------------------------------------------------------------

    //-------------------------------------- LOAD -------------------------------------------
    //---------------------------------------------------------------------------------------
    
    //---------------------------------- PLAYER ---------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/CatResized/CatSpriteSheet.png"))
    {
        std::cout << "Loaded Player Texture" << std::endl;
        playerSprite.setTexture(playerTexture);

        int xindex = 0;
        int yindex = 0;

        playerSprite.setTextureRect(sf::IntRect(xindex, yindex, 42, 58));
        playerSprite.scale(sf::Vector2f(2, 2)); //To double the size of it
    }
    else
    {
        std::cout << "Failed to load Player Texture" << std::endl;
    }

    //----------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }

        window.clear();
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}