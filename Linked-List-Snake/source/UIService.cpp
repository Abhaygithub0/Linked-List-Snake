#include "../header/UIService.h"
#include "../header/GameService.h"
#include "../header/GraphicService.h"
#include "../header/MainMenuUIController.h"
#include "../header/SplashScreenUIController.h"
#include "../header/LevelSelectionUIController.h"

UIService::UIService()
{
	splash_screen_controller = nullptr;
	main_menu_controller = nullptr;
	level_selection_ui_controller = nullptr;
	game_window = nullptr;

	createControllers();
}

void UIService::createControllers()
{
	splash_screen_controller = new SplashScreenUIController();
	main_menu_controller = new MainMenuUIController();
	level_selection_ui_controller = new LevelSelectionUIController();
}

UIService::~UIService()
{
	destroy();
}

void UIService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGameWindow();
	initializeControllers();
}

void UIService::update()
{
	switch (GameService::getGameState())
	{
	case GameState::SPLASH_SCREEN:
		splash_screen_controller->update();
		break;
	case GameState::MAIN_MENU:
		main_menu_controller->update();
		break;
	case GameState::LEVEL_SELECTION:
		level_selection_ui_controller->update();
		break;
	}
}

void UIService::render()
{
	switch (GameService::getGameState())
	{
	case GameState::SPLASH_SCREEN:
		splash_screen_controller->render();
		break;
	case GameState::MAIN_MENU:
		main_menu_controller->render();
		break;
	case GameState::LEVEL_SELECTION:
		level_selection_ui_controller->render();
		break;
	}
}

void UIService::showScreen()
{
	switch (GameService::getGameState())
	{
	case GameState::SPLASH_SCREEN:
		splash_screen_controller->show();
		break;
	case GameState::MAIN_MENU:
		main_menu_controller->show();
		break;
	case GameState::LEVEL_SELECTION:
		level_selection_ui_controller->show();
		break;
	}
}

void UIService::initializeControllers()
{
	splash_screen_controller->initialize();
	main_menu_controller->initialize();
	level_selection_ui_controller->initialize();
}

void UIService::destroy()
{
	delete(splash_screen_controller);
	delete(main_menu_controller);
	delete(level_selection_ui_controller);
}