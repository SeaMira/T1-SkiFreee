

#include "./models/game_objects.h"
#include "./models/player.h"
#include <vector>
#include <memory>

class Game {
public:
    Game(unsigned int x, unsigned int y);

    void controllerInput(int m);
    auto updateFrame(float dt);

    void startGame(Nothofagus::Controller& controller);
    void stopGame();

private:
    unsigned int canvas_width, canvas_height;
    float player_x, player_y, dist_from_player_threshold;
    Player player;
    std::vector<std::unique_ptr<Obstacle>> game_objects[100];
    int max_game_objects = 100;
    int num_game_objects = 0;

    Nothofagus::Canvas canvas;

};

