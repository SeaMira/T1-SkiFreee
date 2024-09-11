#include "obstacles/tree.h"
#include "obstacles/flag.h"
#include "obstacles/rock.h"
#include "obstacles/accel.h"
#include "obstacles/deaccel.h"
#include "player.h"
#include <vector>
#include <memory>
#include <iostream>


class Game {
public:
    Game(unsigned int x, unsigned int y, int max_game_objects, Player* player, Nothofagus::Canvas* canvas);

    void controllerInput(int m);
    void updateFrame(float dt);

    void startGame(Nothofagus::Controller& controller);
    void stopGame();

    void addObstacle(std::unique_ptr<Obstacle> obstacle);
    void generateObstacles();

    void addToCanvas();
    void draw();

    Player* player;
    Nothofagus::Canvas* canvas;
private:
    std::vector<std::unique_ptr<Obstacle>> game_objects;

    unsigned int canvas_width, canvas_height;
    float player_x, player_y, dist_from_player_threshold;
    int max_game_objects = 100;
    int num_game_objects = 0;


};

