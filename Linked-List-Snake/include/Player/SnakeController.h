#pragma once
namespace Player {


    enum class SnakeState
    {
        ALIVE,
        DEAD,
    };
    class SnakeController {
    public:
        SnakeController();  // Default constructor
        ~SnakeController(); // Destructor

        void initialize(); // To be called when the object is created
        void update();     // To be called on every frame
        void render();     // To be called on every frame
    };
}
