#pragma once
#include <sfml/Graphics/RenderWindow.hpp>
class EventService;
class GraphicService;
class SoundService;
class LevelService;
class ElementService;
class UIService;

class ServiceLocator
{
private:
    sf::RenderWindow* game_window;
    EventService* event_service;
    GraphicService* graphic_service;
    SoundService* sound_service;
    LevelService* level_service;
    ElementService* element_service;
    UIService* ui_service;

    ServiceLocator();
    ~ServiceLocator();

    void createServices();
    void clearAllServices();

public:
    static ServiceLocator* getInstance();

    void initialize();
    void update();
    void render();

    sf::RenderWindow* getGameWindow();
    EventService* getEventService();
    GraphicService* getGraphicService();
    SoundService* getSoundService();
    LevelService* getLevelService();
    ElementService* getElementService();
    UIService* getUIService();
    void deleteServiceLocator();
};