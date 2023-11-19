#include "Game.h"
#include <thread>
#include "Timer.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1350, 680), "Pet Game");
    this->window->setPosition({ 0, 0 });
    
}

Game::Game()
{
    this->initWindow();

    player.Initialize();

    Timer time; //Instantiates a Timer, when the scope of this function ends, the destructor is called and the timer ends
    
    auto ArialLoad = [this] {arial.loadFromFile("Assets/Fonts/arial/arial.ttf");};
    auto MapLoad = [this] {map.Load("Assets/Map/WholeMap.png");};
    auto TitleLoad = [this] {title.Load("Assets/GameTitle.png");};
    auto PlayerLoad = [this] {player.Load("Assets/Player/Textures/CatResized/CatSpriteSheet.png");};
    auto WelcomeLoad = [this] {
        welcome.Load("Assets/Buttons/WelcomeButton.png", "Assets/Buttons/OnWelcomeButton.png", { 184, 50 });
        welcome.setPosition({ 575, 315 });
        };

    // Parallel Processing is used here by splitting each asset that is loaded into multiple threads
    std::jthread ArialLoadThread(ArialLoad);
    std::jthread MapLoadThread(MapLoad);
    std::jthread TitleLoadThread(TitleLoad);
    std::jthread PlayerLoadThread(PlayerLoad);
    std::jthread WelcomeLoadThread(WelcomeLoad);
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
            if (welcomeEnabled)
            {
                if (welcome.isMouseOver(*window))
                {
                    welcome.switchState(1);
                }
                else
                {
                    welcome.switchState(0);
                }
            }
            break;
        
        case sf::Event::MouseButtonPressed:
            if (welcomeEnabled)
            {
                if (welcome.isMouseOver(*window))
                {
                    currentArea = "Outside";
                    welcomeEnabled = false;
                    player.setTexture(0, 275);
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
    if (welcomeEnabled)
    {
        this->window->draw(title.Sprite);
        welcome.DrawTo(*window);
    }

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
