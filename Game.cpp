#include "Game.h"
#include <thread>
#include "Timer.h"

// Initializes the window
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1350, 680), "Pet Game");
    this->window->setPosition({ 0, 0 });
    this->window->setFramerateLimit(60);

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
    auto MapLoad = [this] {map.Load("Assets/Map/WholeMapNew.png"); };
    auto TitleLoad = [this] {title.Load("Assets/GameTitle.png"); };
    auto PlayerLoad = [this] {player.Load("Assets/Player/Textures/CatResized/Cat_SpriteSheet.png"); };
    auto CurrencyBarLoad = [this] {
        currencyBar.Initialize(0, { 0.50, 0.50 }, arial);
        currencyBar.Load("Assets/Bars/Currency/CurrencyBar.png");
        currencyBar.setPosition({ 1100, 15 }, { 1225, 32 });
        };
    auto healthBarLoad = [this] {
        healthBar.Initialize(false, true, 4, { 4, 4 });
        healthBar.Load("Assets/Bars/Health/Heart.png", 0, 0, 17, 17);
        healthBar.setPosition({ 10, 10 });
        };
    auto hungerBarLoad = [this] {
        hungerBar.Initialize(false, true, 6, { 1.5, 1.5 });
        hungerBar.Load("Assets/Bars/Hunger/spritesheet.png", 0, 0, 200, 100);
        hungerBar.setPosition({ 80, -25 });
        };
    auto energyBarLoad = [this] {
        energyBar.Initialize(false, true, 6, { 1.5, 1.5 });
        energyBar.Load("Assets/Bars/Energy/spritesheet.png", 0, 0, 200, 100);
        energyBar.setPosition({ 340, -25 });
        };
    auto boredomBarLoad = [this] {
        boredomBar.Initialize(false, true, 6, { 1.5, 1.5 });
        boredomBar.Load("Assets/Bars/Boredom/spritesheet.png", 0, 0, 200, 100);
        boredomBar.setPosition({ 600, -25 });
        };
    auto WelcomeLoad = [this] {
        welcome.Load("Assets/Buttons/WelcomeButton.png", "Assets/Buttons/OnWelcomeButton.png", { 184, 50 }, 0, 0, 200, 50);
        welcome.setPosition({ 575, 315 });
        };
    auto PlayAroundLoad = [this] {
        playAround.Load("Assets/Buttons/PlayAround.png", "Assets/Buttons/OnPlayAround.png", { 184, 50 }, 0, 0, 200, 50);
        playAround.setPosition({ 275, 585 });
        };
    auto GoInsideLoad = [this] {
        goInside.Load("Assets/Buttons/GoInside.png", "Assets/Buttons/OnGoInside.png", { 184, 50 }, 0, 0, 200, 50);
        goInside.setPosition({ 875, 585 });
        };
    auto EntryWayLoad = [this] {
        EntryWay.Load("Assets/Buttons/Interior/EntryWay.png", "Assets/Buttons/Interior/OnEntryWay.png", { 184, 50 }, 0, 0, 200, 50);
        EntryWay.setPosition({ 10, 250 });
        };
    auto KitchenLoad = [this] {
        Kitchen.Load("Assets/Buttons/Interior/Kitchen.png", "Assets/Buttons/Interior/OnKitchen.png", { 184, 50 }, 0, 0, 200, 50);
        Kitchen.setPosition({ 10, 300 });
        };
    auto BedroomLoad = [this] {
        Bedroom.Load("Assets/Buttons/Interior/Bedroom.png", "Assets/Buttons/Interior/OnBedroom.png", { 184, 50 }, 0, 0, 200, 50);
        Bedroom.setPosition({ 10, 350 });
        };
    auto BathroomLoad = [this] {
        Bathroom.Load("Assets/Buttons/Interior/Bathroom.png", "Assets/Buttons/Interior/OnBathroom.png", { 184, 50 }, 0, 0, 200, 50);
        Bathroom.setPosition({ 10, 400 });
        };
    auto GoOutsideLoad = [this] {
        GoOutside.Load("Assets/Buttons/Interior/GoOutside.png", "Assets/Buttons/Interior/OnGoOutside.png", { 184, 50 }, 0, 0, 200, 50);
        GoOutside.setPosition({ 10, 450 });
        };
    auto UncleanDebuffLoad = [this] {
        Unclean.Load("Assets/Debuffs/UncleanDebuff.png", { 1, 1 });
        Unclean.setPosition({ 1263, 290 });
        Unclean.Initialize(10.0f);
        };
    auto BathMinigameLoad = [this] {
        bathMinigame.Load("Assets/Minigames/LightBlueBG.png", "Assets/Minigames/Sponge.png", "Assets/Minigames/OnSponge.png", "Assets/Bars/Bath/spritesheet.png");
        bathMinigame.Initialize({ 100, 90 }, { 300, 150 }, { 500, 70 });
        bathMinigame.setActive(false);
        };
    auto bathButtonLoad = [this] {
        bathButton.Load("Assets/Buttons/BathButtons/BathButton.png", "Assets/Buttons/BathButtons/OnBathButton.png", { 102, 102 }, 0, 0, 102, 102);
        bathButton.setPosition({ 613, 550 });
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
    std::jthread EntryWayLoadThread(EntryWayLoad);
    std::jthread KitchenLoadThread(KitchenLoad);
    std::jthread BedroomLoadThread(BedroomLoad);
    std::jthread BathroomLoadThread(BathroomLoad);
    std::jthread GoOutsideLoadThread(GoOutsideLoad);
    std::jthread UncleanDebuffLoadThread(UncleanDebuffLoad);
    std::jthread BathMinigameLoadThread(BathMinigameLoad);
    std::jthread BathButtonLoadThread(bathButtonLoad);
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
            if ((currentArea == "EntryWay") || (currentArea == "Kitchen") || (currentArea == "Bedroom") || (currentArea == "Bathroom"))
            {
                EntryWay.MouseOver(*window);
                Kitchen.MouseOver(*window);
                Bedroom.MouseOver(*window);
                Bathroom.MouseOver(*window);
            }
            if (currentArea == "EntryWay")
            {
                GoOutside.MouseOver(*window);
            }
            if (currentArea == "Bathroom")
            {
                if (bathMinigame.isActive())
                {
                    bathMinigame.SpongeMouseOver(*window);
                    bathMinigame.SpongeSwitchState(bathMinigame.isOverSponge());
                }
                else
                {
                    bathButton.MouseOver(*window);
                }
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
            if (currentArea == "Outside")
            {
                if (goInside.ButtonState == 1)
                {
                    std::cout << "Go Inside" << std::endl;
                    currentArea = "EntryWay";
                    map.setPosition({ -2700, 0 });
                    goInside.switchState(0);
                }
            }

            if ((currentArea == "EntryWay") || (currentArea == "Kitchen") || (currentArea == "Bedroom") || (currentArea == "Bathroom"))
            {
                if (EntryWay.ButtonState == 1)
                {
                    std::cout << "EntryWay" << std::endl;
                    currentArea = "EntryWay";
                    map.setPosition({ -2700, 0 });
                    EntryWay.switchState(0);
                }
                if (Kitchen.ButtonState == 1)
                {
                    std::cout << "Kitchen" << std::endl;
                    currentArea = "Kitchen";
                    map.setPosition({ -4050, 0 });
                    Kitchen.switchState(0);
                }
                if (Bedroom.ButtonState == 1)
                {
                    std::cout << "Bedroom" << std::endl;
                    currentArea = "Bedroom";
                    map.setPosition({ -5400, 0 });
                    Bedroom.switchState(0);
                }
                if (Bathroom.ButtonState == 1)
                {
                    std::cout << "Bathroom" << std::endl;
                    currentArea = "Bathroom";
                    map.setPosition({ -6750, 0 });
                    Bathroom.switchState(0);
                }
            }

            if (currentArea == "Bathroom")
            {
                if ((bathButton.ButtonState == 1) && (Unclean.getActive()))
                {
                    std::cout << "BathMinigameOpen" << std::endl;
                    bathMinigame.setActive(true);
                    bathButton.switchState(0);
                }
            }

            if (currentArea == "EntryWay")
            {
                if (GoOutside.ButtonState == 1)
                {
                    std::cout << "Go Outside" << std::endl;
                    currentArea = "Outside";
                    map.setPosition({ -1350, 0 });
                    GoOutside.switchState(0);
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

    if (!welcomeEnabled)
    {
        hungerGameTime = hungerGameClock.getElapsedTime().asSeconds();
        energyGameTime = energyGameClock.getElapsedTime().asSeconds();
        boredomGameTime = boredomGameClock.getElapsedTime().asSeconds();
        uncleanGameTime = uncleanGameClock.getElapsedTime().asSeconds();
        healthGameTime = healthGameClock.getElapsedTime().asSeconds();
        spongeMoveAroundTime = spongeBathClock.getElapsedTime().asSeconds();

        hungerBar.DecrementValue(1, hungerGameTime, hungerTimeBetweenSwitch);
        energyBar.DecrementValue(1, energyGameTime, energyTimeBetweenSwitch);
        boredomBar.DecrementValue(1, boredomGameTime, boredomTimeBetweenSwitch);

        if (hungerGameTime >= hungerTimeBetweenSwitch)
        {
            hungerGameTime = hungerGameClock.restart().asSeconds();
        }
        if (energyGameTime >= energyTimeBetweenSwitch)
        {
            energyGameTime = energyGameClock.restart().asSeconds();
        }
        if (boredomGameTime >= boredomTimeBetweenSwitch)
        {
            boredomGameTime = boredomGameClock.restart().asSeconds();
        }

        if ((uncleanGameTime >= uncleanTimeBetweenSwitch) && (!Unclean.getActive()) && (!bathMinigame.isActive()))
        {
            Unclean.setActive(true);
            bathMinigame.bathBar.resetValue();
            bathMinigame.bathBar.setCurrentX(1200);
            bathMinigame.bathBar.setTexture(1200, 0, 200, 100);
            energyTimeBetweenSwitch -= Unclean.change;
            boredomTimeBetweenSwitch -= Unclean.change;
            hungerTimeBetweenSwitch -= Unclean.change;
            uncleanGameTime = uncleanGameClock.restart().asSeconds();
        }

        if (hungerBar.getValue() == 0 && energyBar.getValue() == 0 && boredomBar.getValue() == 0)
        {
            healthBar.DecrementHealthValue(1, healthGameTime, healthTimeBetweenSwitch);
            if (healthGameTime >= healthTimeBetweenSwitch)
            {
                healthGameTime = healthGameClock.restart().asSeconds();
            }
        }
    }

    if (currentArea == "Bathroom")
    {
        if (bathMinigame.isActive())
        {
            bathMinigame.SpongeMoveAround(spongeBathClock, spongeMoveAroundTime, spongeBathTimeBetweenSwitch);

            bathTime = bathClock.getElapsedTime().asSeconds();

            if ((bathTime >= bathTimeBetweenSwitch) && (bathMinigame.isOverSponge()))
            {
                bathMinigame.bathBar.IncrementValue(1, bathTime, bathTimeBetweenSwitch);
                bathTime = bathClock.restart().asSeconds();
            }

            if (!bathMinigame.isOverSponge())
            {
                bathTime = bathClock.restart().asSeconds();
            }

            bathMinigame.miniGameFinishedCheck(Unclean, uncleanGameClock, hungerTimeBetweenSwitch, energyTimeBetweenSwitch, boredomTimeBetweenSwitch);
        }

        if ((!Unclean.getActive()) && (bathButton.active))
        {
            bathButton.active = false;
            bathButton.setTexture(102, 0, 102, 102);
        }

        if ((Unclean.getActive()) && (!bathButton.active))
        {
            bathButton.active = true;
            bathButton.setTexture(0, 0, 102, 102);
        }
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
    else
    {

        if (Unclean.getActive())
        {
            Unclean.DrawTo(*window);
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
        if (currentArea == "EntryWay")
        {
            EntryWay.DrawTo(*window);
            Kitchen.DrawTo(*window);
            Bedroom.DrawTo(*window);
            Bathroom.DrawTo(*window);
            GoOutside.DrawTo(*window);

            currencyBar.DrawTo(*window);
            healthBar.DrawSpriteOnlyTo(*window);
            hungerBar.DrawSpriteOnlyTo(*window);
            energyBar.DrawSpriteOnlyTo(*window);
            boredomBar.DrawSpriteOnlyTo(*window);
        }
        if (currentArea == "Kitchen")
        {
            EntryWay.DrawTo(*window);
            Kitchen.DrawTo(*window);
            Bedroom.DrawTo(*window);
            Bathroom.DrawTo(*window);

            currencyBar.DrawTo(*window);
            healthBar.DrawSpriteOnlyTo(*window);
            hungerBar.DrawSpriteOnlyTo(*window);
            energyBar.DrawSpriteOnlyTo(*window);
            boredomBar.DrawSpriteOnlyTo(*window);
        }
        if (currentArea == "Bedroom")
        {
            EntryWay.DrawTo(*window);
            Kitchen.DrawTo(*window);
            Bedroom.DrawTo(*window);
            Bathroom.DrawTo(*window);

            currencyBar.DrawTo(*window);
            healthBar.DrawSpriteOnlyTo(*window);
            hungerBar.DrawSpriteOnlyTo(*window);
            energyBar.DrawSpriteOnlyTo(*window);
            boredomBar.DrawSpriteOnlyTo(*window);
        }
        if (currentArea == "Bathroom")
        {
            if (!bathMinigame.isActive())
            {
                EntryWay.active = true;
                Kitchen.active = true;
                Bedroom.active = true;
                Bathroom.active = true;

                EntryWay.DrawTo(*window);
                Kitchen.DrawTo(*window);
                Bedroom.DrawTo(*window);
                Bathroom.DrawTo(*window);

                bathButton.DrawTo(*window);
            }

            currencyBar.DrawTo(*window);
            healthBar.DrawSpriteOnlyTo(*window);
            hungerBar.DrawSpriteOnlyTo(*window);
            energyBar.DrawSpriteOnlyTo(*window);
            boredomBar.DrawSpriteOnlyTo(*window);

            if (bathMinigame.isActive())
            {
                EntryWay.active = false;
                Kitchen.active = false;
                Bedroom.active = false;
                Bathroom.active = false;
                bathMinigame.DrawTo(*window);
            }
        }
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
