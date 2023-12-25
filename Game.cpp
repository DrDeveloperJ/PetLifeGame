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

    // The defined lambda functions for loading each asset
    auto ArialLoad = [this] {
        if (arial.loadFromFile("Assets/Fonts/arial/arial.ttf"))
        {
            std::cout << "Loaded Arial" << std::endl;
        }};
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
        playAround.Load("Assets/Buttons/PlayingMinigame/PlayAround.png", "Assets/Buttons/PlayingMinigame/OnPlayAround.png", { 102, 102 }, 0, 0, 102, 102);
        playAround.setPosition({ 613, 550 });
        };
    auto PlayingMinigameLoad = [this] {
		playingMinigame.Load("Assets/Minigames/PlayingMinigame/PlayingBG.png", "Assets/Minigames/PlayingMinigame/Explosion.png", "Assets/Minigames/PlayingMinigame/Mouse.png");
		playingMinigame.Initialize({ 100, 90 });
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
    auto currencyLoad = [this] {
        currency.Load("Assets/Bars/Currency/coin.png");
        currency.initialize({ 638, 250 });
        };
    auto sleepFunctionalityLoad = [this] {
        sleepFunctionality.Load("Assets/Map/Interior/BedroomLightOffOverlay.png", "Assets/Bars/Energy/SleepingZ.png", { 0, 0 });
        };
    auto sleepButtonLoad = [this] {
        sleepButton.Load("Assets/Buttons/SleepButtons/SleepButton.png", "Assets/Buttons/SleepButtons/OnSleepButton.png", { 102, 102 }, 0, 0, 102, 102);
        sleepButton.setPosition({ 613, 550 });
        };
    auto wakeButtonLoad = [this] {
        wakeButton.Load("Assets/Buttons/SleepButtons/OnSleepButton.png", "Assets/Buttons/SleepButtons/SleepButton.png", { 102, 102 }, 0, 0, 102, 102);
        wakeButton.setPosition({ 613, 550 });
        };
    auto eatingMinigameLoad = [this] {
        eatingMinigame.Load("Assets/Minigames/EatingMiniGame/EatingBG.png", "Assets/Minigames/EatingMiniGame/Food.png", "Assets/Minigames/EatingMiniGame/CorrectFood.png", "Assets/Minigames/EatingMiniGame/IncorrectFood.png");
        eatingMinigame.Initialize({ 100, 90 });
        };
    auto eatButtonLoad = [this] {
        eatButton.Load("Assets/Buttons/KitchenButtons/EatButton.png", "Assets/Buttons/KitchenButtons/OnEatButton.png", { 102, 102 }, 0, 0, 102, 102);
        eatButton.setPosition({ 613, 550 });
        };
    auto kitchenTableOverlayLoad = [this] {
		kitchenTableOverlayTexture.loadFromFile("Assets/Map/Interior/TableOverlayKitchen.png");
		kitchenTableOverlay.setTexture(kitchenTableOverlayTexture);
		kitchenTableOverlay.setPosition({ 0, 0 });
		};

    // Parallel Processing is used here by splitting each asset loading into multiple threads
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
    std::jthread PlayingMinigameLoadThread(PlayingMinigameLoad);
    std::jthread GoInsideLoadThread(GoInsideLoad);
    std::jthread EntryWayLoadThread(EntryWayLoad);
    std::jthread KitchenLoadThread(KitchenLoad);
    std::jthread BedroomLoadThread(BedroomLoad);
    std::jthread BathroomLoadThread(BathroomLoad);
    std::jthread GoOutsideLoadThread(GoOutsideLoad);
    std::jthread UncleanDebuffLoadThread(UncleanDebuffLoad);
    std::jthread BathMinigameLoadThread(BathMinigameLoad);
    std::jthread BathButtonLoadThread(bathButtonLoad);
    std::jthread currencyLoadThread(currencyLoad);
    std::jthread sleepFunctionalityLoadThread(sleepFunctionalityLoad);
    std::jthread sleepButtonLoadThread(sleepButtonLoad);
    std::jthread wakeButtonLoadThread(wakeButtonLoad);
    std::jthread eatingMinigameLoadThread(eatingMinigameLoad);
    std::jthread kitchenTableOverlayLoadThread(kitchenTableOverlayLoad);
    std::jthread eatButtonLoadThread(eatButtonLoad);
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
                if (!playingMinigame.isActive())
                {
                    // The play around button is disabled if the boredom bar is full
                    if (boredomBar.getValue() == 6)
                    {
                        playAround.setTexture(102, 0, 102, 102);
                        playAround.active = false;
                    }
                    // Else, the play around button is enabled as well as the go inside button
                    else
                    {
                        playAround.setTexture(0, 0, 102, 102);
                        playAround.MouseOver(*window);
                        playAround.active = true;

                        goInside.MouseOver(*window);
                        playAround.MouseOver(*window);
                    }
                }
            }

            // If the player is in the entry way, kitchen, bedroom, or bathroom, check if the mouse is over the buttons for switching areas
            if ((currentArea == "EntryWay") || (currentArea == "Kitchen") || (currentArea == "Bedroom") || (currentArea == "Bathroom"))
            {
                // Applies rollover effect to the buttons
                EntryWay.MouseOver(*window);
                Kitchen.MouseOver(*window);
                Bedroom.MouseOver(*window);
                Bathroom.MouseOver(*window);
            }

            // If the player is in the entry way only then can they leave the house
            if (currentArea == "EntryWay")
            {
                GoOutside.MouseOver(*window);
            }

            // If the player is in the bathroom, check if the mouse is over the bath button unless the bathroom minigame is active
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

            // If the player is in the bedroom, check if the mouse is over the sleep button, unless sleeping where the wake button should be active
            if (currentArea == "Bedroom")
            {
                if (sleepFunctionality.getActive())
                {
                    wakeButton.MouseOver(*window);
                }
                else
                {
                    sleepButton.MouseOver(*window);
                }
            }

            // If the player is in the kitchen, check if the mouse is over the eat button unless the eat minigame is active
            if (currentArea == "Kitchen")
            {
                if (!eatingMinigame.isActive())
                {

                    if (hungerBar.getValue() == 6)
                    {
                        eatButton.setTexture(102, 0, 102, 102);
                        eatButton.active = false;
					}
                    else
                    {
                        eatButton.setTexture(0, 0, 102, 102);
                        eatButton.MouseOver(*window);
                        eatButton.active = true;
					}
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

            // If the player is outside, check if the mouse is over the play around button or the go inside button
            if (currentArea == "Outside")
            {
                if (playingMinigame.isActive())
                {
                    if (playingMinigame.IsOverMouse(*window))
                    {
                        playingMinigame.MouseBlast(boredomBar);
					}
                }
                else
                {
                    if (goInside.ButtonState == 1)
                    {
                        std::cout << "Go Inside" << std::endl;
                        currentArea = "EntryWay";
                        map.setPosition({ -2700, 0 });
                        goInside.switchState(0);
                    }

                    if (playAround.ButtonState == 1)
                    {
                        std::cout << "PlayAroundMinigameOpen" << std::endl;
                        playingMinigame.SetActive(true, boredomBar);
                        playAround.switchState(0);
                    }
                }
            }

            // If the player is in the entry way, kitchen, bedroom, or bathroom, check if the mouse is over the buttons for switching areas, and do so if it is
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

            // If the player is in the bathroom, check if the mouse is over the bath button and open the bath minigame if it is
            if (currentArea == "Bathroom")
            {
                if ((bathButton.ButtonState == 1) && (Unclean.getActive()))
                {
                    std::cout << "BathMinigameOpen" << std::endl;
                    bathMinigame.setActive(true);
                    bathButton.switchState(0);
                }
            }

            // If the player is in the entry way only then can they leave the house
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

            // If the player is in the bedroom, check if the mouse is over the sleep button, unless sleeping where the wake button should be active
            if (currentArea == "Bedroom")
            {
                if (sleepFunctionality.getActive())
                {
                    if (wakeButton.ButtonState == 1)
                    {
                        sleepFunctionality.setActive(false);
                        wakeButton.active = false;
                        sleepButton.active = true;
                        EntryWay.active = true;
                        Kitchen.active = true;
                        Bedroom.active = true;
                        Bathroom.active = true;
                        wakeButton.switchState(0);
                    }
                }
                else
                {
                    if (sleepButton.ButtonState == 1)
                    {
                        sleepFunctionality.setActive(true);
                        sleepButton.active = false;
                        wakeButton.active = true;
                        EntryWay.active = false;
                        Kitchen.active = false;
                        Bedroom.active = false;
                        Bathroom.active = false;
                        sleepButton.switchState(0);
                    }
                }
            }

            // If the player is in the kitchen, check if the mouse is over the eat button (To open the eat minigame) unless the eat minigame is activeu
            if (currentArea == "Kitchen")
            {
                if (eatButton.ButtonState == 1)
                {
                    std::cout << "EatMinigameOpen" << std::endl;
					eatingMinigame.SetActive(true, hungerBar);
					eatButton.switchState(0);
				}

                if (eatingMinigame.isActive())
                {
                    // If the mouse is over the food, switch the food's state based on whether the food is correct or not
                    bool isOverFood1{ eatingMinigame.IsOverFood(*window, 1) };
                    eatingMinigame.FoodSwitchState(1, isOverFood1, hungerBar);
                    bool isOverFood2{ eatingMinigame.IsOverFood(*window, 2) };
                    eatingMinigame.FoodSwitchState(2, isOverFood2, hungerBar);
                    bool isOverFood3{ eatingMinigame.IsOverFood(*window, 3) };
                    eatingMinigame.FoodSwitchState(3, isOverFood3, hungerBar);
                    bool isOverFood4{ eatingMinigame.IsOverFood(*window, 4) };
                    eatingMinigame.FoodSwitchState(4, isOverFood4, hungerBar);
                    bool isOverFood5{ eatingMinigame.IsOverFood(*window, 5) };
                    eatingMinigame.FoodSwitchState(5, isOverFood5, hungerBar);
                    bool isOverFood6{ eatingMinigame.IsOverFood(*window, 6) };
                    eatingMinigame.FoodSwitchState(6, isOverFood6, hungerBar);
                    bool isOverFood7{ eatingMinigame.IsOverFood(*window, 7) };
                    eatingMinigame.FoodSwitchState(7, isOverFood7, hungerBar);
                    bool isOverFood8{ eatingMinigame.IsOverFood(*window, 8) };
                    eatingMinigame.FoodSwitchState(8, isOverFood8, hungerBar);
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

    if (!welcomeEnabled)
    {
        // The deltatime is used to make the animation of the player work
        deltatime = clock.restart().asSeconds();

        // Sleeping animation only if in the bedroom and sleeping
        if ((currentArea == "Bedroom") && (sleepFunctionality.getActive()))
        {
            player.AnimationUpdate(3318, deltatime, 0.15f); // Sets the player's animation
        }
        // IDLE animation
        else
        {
            player.AnimationUpdate(0, deltatime, 0.15f); // Sets the player's animation
        }

        // sleepingZIncrement is used to make the Z's come out at a regular interval
        sleepingZIncrement += deltatime;

        // If the sleepingZIncrement is greater than 0.4 seconds, switch the Z's position (gives the illusion of the Z's coming from the cat)
        if (sleepingZIncrement >= 0.4f)
        {
            sleepingZIncrement = 0;

            switch (sleepFunctionality.currentZ)
            {
            case 0:
                sleepFunctionality.setZ({ 600, 450 }, { 0.5, 0.5 }, -45);
                sleepFunctionality.currentZ = 1;
                break;
            case 1:
                sleepFunctionality.setZ({ 575, 400 }, { 0.5, 0.5 }, -45);
                sleepFunctionality.currentZ = 2;
                break;
            case 2:
                sleepFunctionality.setZ({ 550, 350 }, { 0.5, 0.5 }, -45);
                sleepFunctionality.currentZ = 0;
                break;
            }
        }

        // If the currency is active, update the currency's animation (show the coin spinning)
        if (currency.getActive())
        {
            currency.AnimationUpdate(deltatime, 0.075f);
        }

        // Get the time for each bar and the sponge and food minigames movement
        hungerGameTime = hungerGameClock.getElapsedTime().asSeconds();
        energyGameTime = energyGameClock.getElapsedTime().asSeconds();
        boredomGameTime = boredomGameClock.getElapsedTime().asSeconds();
        uncleanGameTime = uncleanGameClock.getElapsedTime().asSeconds();
        healthGameTime = healthGameClock.getElapsedTime().asSeconds();
        spongeMoveAroundTime = spongeBathClock.getElapsedTime().asSeconds();
        foodMoveAroundTime = foodGameClock.getElapsedTime().asSeconds();

        // If the player is not sleeping and the energy bar goes lower than 2, allow the player to gain a currency as a reward
        if (!sleepFunctionality.getActive())
        {
            if (energyBar.getValue() <= 2)
            {
                sleepFunctionality.setRewardAllowed(true);
            }

            // If the player is not sleeping, decrement the energy bar
            energyBar.DecrementValue(1, energyGameTime, energyTimeBetweenSwitch);
        }
        else // If the player is sleeping, increment the energy bar, and if allowed, give the player a currency as a reward
        {
            energyIncrementTime = energyIncrementClock.getElapsedTime().asSeconds();
            energyBar.IncrementValue(1, energyIncrementTime, energyTimeBetweenIncrement);

            if ((energyBar.getValue() == 6) && (sleepFunctionality.getRewardAllowed()))
            {
                sleepFunctionality.setRewardAllowed(false);
                currency.setActive(true);
                int newCurrencyValue = currencyBar.getValue() + 1;
                currencyBar.updateValue(newCurrencyValue);
            }
        }

        // If the player is not sleeping, decrement the hunger bar and boredom bar
        hungerBar.DecrementValue(1, hungerGameTime, hungerTimeBetweenSwitch);
        boredomBar.DecrementValue(1, boredomGameTime, boredomTimeBetweenSwitch);

        // Restart the clocks for each bar and the sponge and food minigames movement
        if (hungerGameTime >= hungerTimeBetweenSwitch)
        {
            hungerGameTime = hungerGameClock.restart().asSeconds();
        }
        if (energyIncrementTime >= energyTimeBetweenIncrement)
        {
            energyIncrementTime = energyIncrementClock.restart().asSeconds();
        }
        if (energyGameTime >= energyTimeBetweenSwitch)
        {
            energyGameTime = energyGameClock.restart().asSeconds();
        }
        if (boredomGameTime >= boredomTimeBetweenSwitch)
        {
            boredomGameTime = boredomGameClock.restart().asSeconds();
        }

        // The unclean debuff is active after a set amount of time
        if ((uncleanGameTime >= uncleanTimeBetweenSwitch) && (!Unclean.getActive()) && (!bathMinigame.isActive()))
        {
            // Prepares the bath minigame for use
            Unclean.setActive(true);
            bathMinigame.bathBar.resetValue();
            bathMinigame.bathBar.setCurrentX(1200);
            bathMinigame.bathBar.setTexture(1200, 0, 200, 100);
            energyTimeBetweenSwitch -= Unclean.change;
            boredomTimeBetweenSwitch -= Unclean.change;
            hungerTimeBetweenSwitch -= Unclean.change;
            uncleanGameTime = uncleanGameClock.restart().asSeconds();
        }

        int checkDecrementHealth = 0;

        if (hungerBar.getValue() == 0)
        {
            checkDecrementHealth++;
        }
        if (energyBar.getValue() == 0)
        {
            checkDecrementHealth++;
        }
        if (boredomBar.getValue() == 0)
        {
            checkDecrementHealth++;
        }

        //decrement the health bar if 2 bars are empty
        if (checkDecrementHealth >= 2)
        {
            healthBar.DecrementHealthValue(1, healthGameTime, healthTimeBetweenSwitch);
            if (healthGameTime >= healthTimeBetweenSwitch)
            {
                healthGameTime = healthGameClock.restart().asSeconds();
            }
        }
    }

    // If the play around game is active, check if the playing minigame is finished
    if (currentArea == "Outside")
    {
        if (playingMinigame.isActive())
        {
            playingMinigame.MiniGameFinishedCheck(boredomBar, currency, currencyBar);
		}
	}

    // If the bath minigame is active, move the sponge around randomly
    if (currentArea == "Bathroom")
    {
        if (bathMinigame.isActive())
        {
            bathMinigame.SpongeMoveAround(spongeBathClock, spongeMoveAroundTime, spongeBathTimeBetweenSwitch);

            bathTime = bathClock.getElapsedTime().asSeconds();

            // If the bath minigame is active and the mouse is over the sponge, increment the bath bar
            if ((bathTime >= bathTimeBetweenSwitch) && (bathMinigame.isOverSponge()))
            {
                bathMinigame.bathBar.IncrementValue(1, bathTime, bathTimeBetweenSwitch);
                bathTime = bathClock.restart().asSeconds();
            }

            // if the mouse goes off the sponge stop incrementing the bath bar
            if (!bathMinigame.isOverSponge())
            {
                bathTime = bathClock.restart().asSeconds();
            }

            // Check if the bath minigame is finished
            bathMinigame.miniGameFinishedCheck(Unclean, uncleanGameClock, hungerTimeBetweenSwitch, energyTimeBetweenSwitch, boredomTimeBetweenSwitch, currency, currencyBar);
        }

        // Set the bathbutton to active or inactive based on whether the unclean debuff is active
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

    // If the eating minigame is active, check if the eating minigame is finished
    if (currentArea == "Kitchen")
    {
        if (eatingMinigame.isActive())
        {
            eatingMinigame.MiniGameFinishedCheck(hungerBar, currency, currencyBar);
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
    // Otherwise, draw the game
    else
    {
        if (currency.getActive())
        {
            currency.draw(*window);
        }

        if (currentArea == "Outside")
        {
            if (playingMinigame.isActive())
            {
				playingMinigame.Draw(*window);
			}
            else
            {
                goInside.DrawTo(*window);
                playAround.DrawTo(*window);
            }

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
            if (!eatingMinigame.isActive())
            {
                window->draw(kitchenTableOverlay);

                EntryWay.active = true;
                Kitchen.active = true;
                Bedroom.active = true;
                Bathroom.active = true;

                EntryWay.DrawTo(*window);
                Kitchen.DrawTo(*window);
                Bedroom.DrawTo(*window);
                Bathroom.DrawTo(*window);
                eatButton.DrawTo(*window);
            }
            else
            {
                EntryWay.active = false;
                Kitchen.active = false;
                Bedroom.active = false;
                Bathroom.active = false;
                eatingMinigame.Draw(*window);
            }

            currencyBar.DrawTo(*window);
            healthBar.DrawSpriteOnlyTo(*window);
            hungerBar.DrawSpriteOnlyTo(*window);
            energyBar.DrawSpriteOnlyTo(*window);
            boredomBar.DrawSpriteOnlyTo(*window);
        }
        if (currentArea == "Bedroom")
        {
            if (!sleepFunctionality.getActive())
            {
                EntryWay.DrawTo(*window);
                Kitchen.DrawTo(*window);
                Bedroom.DrawTo(*window);
                Bathroom.DrawTo(*window);
                sleepButton.DrawTo(*window);
            }
            else
            {
                sleepFunctionality.Draw(*window);
                wakeButton.DrawTo(*window);
            }

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

        if (Unclean.getActive())
        {
            Unclean.DrawTo(*window);
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
