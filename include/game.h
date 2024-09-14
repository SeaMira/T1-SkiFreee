#include "obstacles/tree.h"
#include "obstacles/flag.h"
#include "obstacles/rock.h"
#include "obstacles/accel.h"
#include "obstacles/deaccel.h"
#include "player.h"
#include "enemy.h"
#include <vector>
#include <memory>
#include <iostream>


class Game {
public:
    Game(unsigned int x, unsigned int y, int max_game_objects, Player* player, Nothofagus::Canvas* canvas, Enemy* enemy);

    void controllerInput(int m);
    void updateFrame(float dt);

    void startGame(Nothofagus::Controller& controller);
    void stopGame();

    void addObstacle(std::unique_ptr<Obstacle> obstacle);
    void generateObstacles();

    void checkDist(float dt);
    float getDist();
    void addToCanvas();
    void draw();
    bool end();

    Player* player;
    Nothofagus::Canvas* canvas;
    Enemy* enemy;
private:
    std::vector<std::unique_ptr<Obstacle>> game_objects;

    unsigned int canvas_width, canvas_height;
    float player_x, player_y, dist_from_player_threshold;
    int max_game_objects = 100;
    int num_game_objects = 0;
    float goal_dist;
    float dist_from_player;


};

