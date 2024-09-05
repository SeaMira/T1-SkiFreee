

#include "./models/game_objects.h"
#include <vector>

class Game {
    public:
        Game(int x, int y);

        void controllerInput(int m);
        void updateFrame(float dt);

        void startGame(Nothofagus::Controller& controller);
        void stopGame();

    private:
        int canvas_width, canvas_height;
        float player_x, player_y, dist_from_player_threshold;
        Player player;
        std::vector<Obstacle> game_objects[100];
        int max_game_objects = 100;
        int num_game_objects = 0;

        Nothofagus::Canvas canvas;

}

