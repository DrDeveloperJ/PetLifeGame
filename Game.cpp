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
    auto ArialLoad = [this] {arial.loadFromFile("Assets/Fonts/arial/arial.ttf");};
    auto MapLoad = [this] {map.Load("Assets/Map/WholeMap.png");};
    auto TitleLoad = [this] {title.Load("Assets/GameTitle.png");};
    auto PlayerLoad = [this] {player.Load("Assets/Player/Textures/CatResized/Cat_SpriteSheet.png"); };
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
                /*
                if (welcome.MouseOver(*window))
                {
                    welcome.switchState(1); // Switches the button to the "on" state
                }
                else
                {
                    welcome.switchState(0); // Switches the button to the "off" state
                }
                */
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
                    map.setPosition({-1350, 0}); // Sets the map's initial position
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
