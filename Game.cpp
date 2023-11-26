#include "Game.h"
#include <thread>
#include "Timer.h"

// Initializes the window
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1350, 680), "Pet Game");
    this->window->setPosition({ 0, 0 });

}

// Constructor
Game::Game()
{
    this->initWindow();

    player.Initialize();

    Timer time; //Instantiates a Timer, when the scope of this function ends, the destructor is called and the timer ends

    // Loads the assets
    auto ArialLoad = [this] {
        if (arial.loadFromFile("Assets/Fonts/arial/arial.ttf"))
        {
            std::cout << "Loaded Arial" << std::endl;
        }

        };
    auto MapLoad = [this] {map.Load("Assets/Map/WholeMap.png"); };
    auto TitleLoad = [this] {title.Load("Assets/GameTitle.png"); };
    auto PlayerLoad = [this] {player.Load("Assets/Player/Textures/CatResized/Cat_SpriteSheet.png"); };
    auto CurrencyBarLoad = [this] {
        currencyBar.Initialize(0, { 0.50, 0.50 }, arial);
        currencyBar.Load("Assets/Bars/Currency/CurrencyBar.png");
        currencyBar.setPosition({ 1100, 15 }, { 1225, 32 });
        };
    auto healthBarLoad = [this] {
        healthBar.Initialize(4, { 4, 4 });
        healthBar.Load("Assets/Bars/Health/Heart.png", 0, 0, 17, 17);
        healthBar.setPosition({ 10, 10 });
        };
    auto hungerBarLoad = [this] {
        hungerBar.Initialize(6, { 1.5, 1.5 });
        hungerBar.Load("Assets/Bars/Hunger/spritesheet.png", 0, 0, 200, 100);
        hungerBar.setPosition({ 80, -25 });
        };
    auto energyBarLoad = [this] {
        energyBar.Initialize(6, { 1.5, 1.5 });
        energyBar.Load("Assets/Bars/Energy/spritesheet.png", 0, 0, 200, 100);
        energyBar.setPosition({ 340, -25 });
        };
    auto boredomBarLoad = [this] {
        boredomBar.Initialize(6, { 1.5, 1.5 });
        boredomBar.Load("Assets/Bars/Boredom/spritesheet.png", 0, 0, 200, 100);
        boredomBar.setPosition({ 600, -25 });
        };
    auto WelcomeLoad = [this] {
        welcome.Load("Assets/Buttons/WelcomeButton.png", "Assets/Buttons/OnWelcomeButton.png", { 184, 50 });
        welcome.setPosition({ 575, 315 });
        };
    auto PlayAroundLoad = [this] {
        playAround.Load("Assets/Buttons/PlayAround.png", "Assets/Buttons/OnPlayAround.png", { 184, 50 });
        playAround.setPosition({ 275, 585 });
        };
    auto GoInsideLoad = [this] {
        goInside.Load("Assets/Buttons/GoInside.png", "Assets/Buttons/OnGoInside.png", { 184, 50 });
        goInside.setPosition({ 875, 585 });
        };

    // Parallel Processing is used here by splitting each asset that is loaded into multiple threads
    std::jthread ArialLoadThread(ArialLoad);
    std::jthread MapLoadThread(MapLoad);
    std::jthread TitleLoadThread(TitleLoad);
    std::jthread PlayerLoadThread(PlayerLoad);
    std::jthread CurrencyBarLoadThread(CurrencyBarLoad);
    std::jthread HealthBarLoadThread(healthBarLoad);
    std::jthread HungerBarLoadThread(hungerBarLoad);
    std::jthread EnergyBarLoadThread(energyBarLoad);
    std::jthread BoredomBarLoadThread(boredomBarLoad);
    std::jthread WelcomeLoadThread(WelcomeLoad);
    std::jthread PlayAroundLoadThread(PlayAroundLoad);
    std::jthread GoInsideLoadThread(GoInsideLoad);
}

// Destructor
Game::~Game()
{
    delete this->window;
}

// Updates the SFML events
void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        // Closes the window if the close button is pressed
        switch (this->sfEvent.type)
        {
        case sf::Event::Closed:
            this->window->close();

            // If the mouse is moved, check if it is over the welcome button
        case sf::Event::MouseMoved:
            if (welcomeEnabled)
            {
                welcome.MouseOver(*window);
            }
            if (currentArea == "Outside")
            {
                goInside.MouseOver(*window);
                playAround.MouseOver(*window);

            }
            break;

            // If the mouse button is pressed, check if it is over the welcome button
        case sf::Event::MouseButtonPressed:
            if (welcomeEnabled)
            {
                if (welcome.ButtonState == 1)
                {
                    currentArea = "Outside";
                    welcomeEnabled = false; // Disables the welcome screen
                    player.visible = true; // Makes the player visible
                    player.setTexture(0, 0); // Sets the player's texture
                    map.setPosition({ -1350, 0 }); // Sets the map's initial position
                }
            }
        }
    }
}

// Updates the game
void Game::update()
{
    this->updateSFMLEvents();

    player.movementAllow = true;
    player.Update();
    map.Update();
    
    deltatime = clock.restart().asSeconds();
    player.AnimationUpdate(0, deltatime, 0.15f); // Sets the player's animation
    gameTime = gameClock.getElapsedTime().asSeconds();
    hungerBar.DecrementValue(1, gameTime, timeBetweenSwitch);
    energyBar.DecrementValue(1, gameTime, timeBetweenSwitch);
    boredomBar.DecrementValue(1, gameTime, timeBetweenSwitch);
    if (gameTime >= timeBetweenSwitch)
    {
        gameTime = gameClock.restart().asSeconds();
    }
    
}

// Renders the game
void Game::render()
{
    this->window->clear();

    this->window->draw(map.Sprite);

    // If the player is visible, draw the player
    if (player.visible)
    {
        this->window->draw(player.Sprite);
    }

    // If welcome screen is enabled (if the user is currently on the welcome screen), draw the welcome screen
    if (welcomeEnabled)
    {
        this->window->draw(title.Sprite);
        welcome.DrawTo(*window);
    }
    if (currentArea == "Outside")
    {
        goInside.DrawTo(*window);
        playAround.DrawTo(*window);
        currencyBar.DrawTo(*window);
        healthBar.DrawSpriteOnlyTo(*window);
        hungerBar.DrawSpriteOnlyTo(*window);
        energyBar.DrawSpriteOnlyTo(*window);
        boredomBar.DrawSpriteOnlyTo(*window);
    }

    this->window->display();
}

// Runs the game
void Game::run()
{
    while (this->window->isOpen())
    {

        this->update();
        this->render();
    }
}
