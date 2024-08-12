#pragma once
namespace Player {


    class PlayerService {
    public:
        PlayerService();  // Default constructor
        ~PlayerService(); // Destructor

        void initialize(); // To be called when the object is created
        void update();     // To be called on every frame
        void render();     // To be called on every frame
    };
}

