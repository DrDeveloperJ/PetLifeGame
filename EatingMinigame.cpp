#include "EatingMinigame.h"
#include <cstdlib>
#include <iostream>

EatingMinigame::EatingMinigame()
{
}

EatingMinigame::~EatingMinigame()
{
}

void EatingMinigame::Load(std::string backgroundDir, std::string foodDir, std::string correctFoodDir, std::string incorrectFoodDir)
{
    // Loads the textures
    backgroundTexture.loadFromFile(backgroundDir);
    foodTexture.loadFromFile(foodDir);
    correctFoodTexture.loadFromFile(correctFoodDir);
    incorrectFoodTexture.loadFromFile(incorrectFoodDir);

    // Sets the sprites
    background.setTexture(backgroundTexture);
    currentLookedForFood.setTexture(foodTexture);
    food1.setTexture(foodTexture);
    food2.setTexture(foodTexture);
    food3.setTexture(foodTexture);
    food4.setTexture(foodTexture);
    food5.setTexture(foodTexture);
    food6.setTexture(foodTexture);
    food7.setTexture(foodTexture);
    food8.setTexture(foodTexture);
}

void EatingMinigame::Initialize(sf::Vector2f backgroundPosition)
{
    // Initializes the minigame
    background.setPosition(backgroundPosition);
    currentLookedForFood.setPosition({ 600, 70 });
    food1.setPosition({ 375, 250 });
    food2.setPosition({ 525, 250 });
    food3.setPosition({ 675, 250 });
    food4.setPosition({ 825, 250 });
    food5.setPosition({ 375, 450 });
    food6.setPosition({ 525, 450 });
    food7.setPosition({ 675, 450 });
    food8.setPosition({ 825, 450 });
    SetEachFoodType();
}

bool EatingMinigame::CheckCorrectFood(sf::Sprite* foodPick)
{
    // Check it's rect position using getrect and see if it matches the getrect of the currentLookedForFood
    int currentFoodY = foodPick->getTextureRect().top;
    int currentFoodX = foodPick->getTextureRect().left;

    int LookedForFoodY = currentLookedForFood.getTextureRect().top;
    int LookedForFoodX = currentLookedForFood.getTextureRect().left;

    // if the food is correct return true, else return false
    if ((currentFoodY == LookedForFoodY) && (currentFoodX == LookedForFoodX))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EatingMinigame::FoodSwitchState(const int& foodNumber, bool& state, Bar& hungerBar)
{
    // Switches the food to the incorrect state, if it is incorrect, else switches all the foods around
    sf::Sprite* foodPick;
    switch (foodNumber)
    {
    case 1:
        foodPick = &food1;
        break;
    case 2:
        foodPick = &food2;
        break;
    case 3:
        foodPick = &food3;
        break;
    case 4:
        foodPick = &food4;
        break;
    case 5:
        foodPick = &food5;
        break;
    case 6:
        foodPick = &food6;
        break;
    case 7:
        foodPick = &food7;
        break;
    case 8:
        foodPick = &food8;
        break;
    default:
        foodPick = nullptr;
        break;
    }

    if ((state) && (foodPick)) // Only checks if correct, if mouse is pressed on it
    {
        if (CheckCorrectFood(foodPick))
        {
            foodPick->setTexture(correctFoodTexture);
            SetEachFoodType();
            hungerBar.IncrementValue(1);
        }
        else
        {
            foodPick->setTexture(incorrectFoodTexture);
        }
    }
}

void EatingMinigame::SetFoodType(int food, int randomFoodChoice)
{
    // Sets the type of an individual food
    std::srand(time(0)+food);
    int tempFoodTypeX = rand() % 10;
    std::srand(time(0)-food);
    int tempFoodTypeY = rand() % 10;

    if (tempFoodTypeX > 7)
    {
        tempFoodTypeX = 7;
    }
    if (tempFoodTypeY > 7)
    {
        tempFoodTypeY = 7;
    }

    switch (food)
    {
    case 0:
        break;
    case 1:
        food1.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food1.setScale({ 5, 5 });
        break;
    case 2:
        food2.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food2.setScale({ 5, 5 });
        break;
    case 3:
        food3.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food3.setScale({ 5, 5 });
        break;
    case 4:
        food4.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food4.setScale({ 5, 5 });
        break;
    case 5:
        food5.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food5.setScale({ 5, 5 });
        break;
    case 6:
        food6.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food6.setScale({ 5, 5 });
        break;
    case 7:
        food7.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food7.setScale({ 5, 5 });
        break;
    case 8:
        food8.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        food8.setScale({ 5, 5 });
        break;
    }

    if (food == randomFoodChoice)
    {
        // if the function is setting the currentlookedforfood, set it to a random food choice
        currentLookedForFood.setTextureRect(sf::Rect{ tempFoodTypeX * 16, tempFoodTypeY * 16, 16, 16 });
        currentLookedForFood.setScale({ 5, 5 });
    }
}

void EatingMinigame::SetEachFoodType()
{
    // Calls SetFoodType for each food including the currentLookedForFood
    std::srand(time(0));
    int randomFoodChoice = rand() % 10;
    if (randomFoodChoice > 8)
    {
        randomFoodChoice = 8;
    }
    if (randomFoodChoice < 1)
    {
		randomFoodChoice = 1;
	}

    resetFoodTextures();

    for (int increment = 1; increment < 9; increment++)
    {
        SetFoodType(increment, randomFoodChoice);
    }
}

void EatingMinigame::resetFoodTextures()
{
    // Resets all the food textures to the default
    food1.setTexture(foodTexture);
	food2.setTexture(foodTexture);
	food3.setTexture(foodTexture);
	food4.setTexture(foodTexture);
	food5.setTexture(foodTexture);
	food6.setTexture(foodTexture);
	food7.setTexture(foodTexture);
	food8.setTexture(foodTexture);
}

bool EatingMinigame::IsOverFood(sf::RenderWindow& window, int food)
{
    //returns weither mouse is over the food or not
    if (active)
    {
        sf::Sprite* foodPick;
        switch (food)
        {
        case 1:
            foodPick = &food1;
            break;
        case 2:
            foodPick = &food2;
            break;
        case 3:
            foodPick = &food3;
            break;
        case 4:
            foodPick = &food4;
            break;
        case 5:
            foodPick = &food5;
            break;
        case 6:
            foodPick = &food6;
            break;
        case 7:
            foodPick = &food7;
            break;
        case 8:
            foodPick = &food8;
            break;
        default:
            foodPick = nullptr;
			break;
        }

        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float spriteX = foodPick->getPosition().x;
        float spriteY = foodPick->getPosition().y;

        float spriteXPosWidth = foodPick->getPosition().x + (foodPick->getLocalBounds().width * 5);
        float spriteYPosHeight = foodPick->getPosition().y + (foodPick->getLocalBounds().height * 5);

        if (mouseX < spriteXPosWidth && mouseX > spriteX && mouseY < spriteYPosHeight && mouseY > spriteY)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false; //return false in case not active (to avoid errors)
}

void EatingMinigame::SetActive(bool newActive, Bar& hungerBar)
{
    active = newActive; // Sets the minigame to active or inactive

    // Check if the hunger bar is low enough to allow a reward
    if (hungerBar.getValue() < 3)
    {
		allowedReward = true;
	}
    else
    {
		allowedReward = false;
	}
}

bool EatingMinigame::isActive()
{
    return active; // Returns if the minigame is active or not
}

void EatingMinigame::MiniGameFinishedCheck(Bar& hungerBar, Currency& currency, Bar& currencyBar)
{
    // Checks if the minigame is finished
    if (hungerBar.getValue() == 6)
    {
		active = false;

        // Give the reward if allowed
        if (allowedReward)
        {
            currency.setActive(true);
            int newCurrencyValue = currencyBar.getValue() + 1;
            currencyBar.updateValue(newCurrencyValue);
            allowedReward = false;
        }
	}
}

void EatingMinigame::Draw(sf::RenderWindow& window)
{
    // Draws all the food and the background
    window.draw(background);
    window.draw(currentLookedForFood);

    window.draw(food1);
    window.draw(food2);
    window.draw(food3);
    window.draw(food4);
    window.draw(food5);
    window.draw(food6);
    window.draw(food7);
    window.draw(food8);
}
