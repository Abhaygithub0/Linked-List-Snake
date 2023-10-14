#include "../header/MainMenuUIController.h"
#include "../header/GameService.h"
#include "../header/GraphicService.h"
#include "../header/SoundService.h"
#include "../header/EventService.h"
#include "../header/ButtonView.h"
#include "../header/Config.h"

MainMenuUIController::MainMenuUIController()
{
    createButtons();
}

MainMenuUIController::~MainMenuUIController()
{
    destroy();
}

void MainMenuUIController::initialize()
{
    initializeButtons();
    registerButtonCallback();
}

void MainMenuUIController::createButtons()
{
    play_button = new ButtonView();
    instructions_button = new ButtonView();
    quit_button = new ButtonView();
}

void MainMenuUIController::initializeButtons()
{
    float x_position = calculateLeftOffsetForButton();

    play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(x_position, play_button_y_position));
    instructions_button->initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(x_position, instructions_button_y_position));
    quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(x_position, quit_button_y_position));
}

void MainMenuUIController::registerButtonCallback()
{
    play_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
    instructions_button->registerCallbackFuntion(std::bind(&MainMenuUIController::instructionsButtonCallback, this));
    quit_button->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
}

float MainMenuUIController::calculateLeftOffsetForButton()
{
    sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
}

void MainMenuUIController::playButtonCallback()
{
    ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
    GameService::setGameState(GameState::LEVEL_SELECTION);
}

void MainMenuUIController::instructionsButtonCallback()
{
    ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
}

void MainMenuUIController::quitButtonCallback()
{
    ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
}

void MainMenuUIController::update()
{
    play_button->update();
    instructions_button->update();
    quit_button->update();
}

void MainMenuUIController::render()
{
    ServiceLocator::getInstance()->getGraphicService()->drawBackground();
    play_button->render();
    instructions_button->render();
    quit_button->render();
}

void MainMenuUIController::show() 
{
    play_button->show();
    instructions_button->show();
    quit_button->show();
}

void MainMenuUIController::destroy()
{
    delete (play_button);
    delete (instructions_button);
    delete (quit_button);
}
