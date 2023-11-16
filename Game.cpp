#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1350, 680), "Pet Game");
    this->window->setPosition({ 0, 0 });
    arial.loadFromFile("Assets/Fonts/arial/arial.ttf");
}

Game::Game()
{
    this->initWindow();

    player.Initialize();

    welcome.setFont(arial);
    welcome.Initialize("Welcome", {200, 50}, 20, sf::Color::Green, sf::Color::Black);
    welcome.setPosition({575, 315});

    map.Load("Assets/Map/WholeMap.png");
}

Game::~Game()
{
    delete this->window;
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        switch (this->sfEvent.type)
        {
        case sf::Event::Closed:
            this->window->close();

        case sf::Event::MouseMoved:
            if (welcomeEnabled == true)
            {
                if (welcome.isMouseOver(*window))
                {
                    welcome.setBackColor(sf::Color::White);
                }
                else
                {
                    welcome.setBackColor(sf::Color::Green);
                }
            }
            break;
        
        case sf::Event::MouseButtonPressed:
            if (welcomeEnabled == true)
            {
                if (welcome.isMouseOver(*window))
                {
                    currentArea = "Outside";
                    welcome.Hide();
                    welcomeEnabled = false;
                    player.Load(0, 275);
                    map.setPosition({-1350, 0});
                }
            }
        }
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    player.movementAllow = true;
    player.Update();
    map.Update();
}

void Game::render()
{
    this->window->clear();

    this->window->draw(map.Sprite);
    this->window->draw(player.Sprite);

    welcome.DrawTo(*window);

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
