#include "nothofagus.h"
#include "game.h"

Game::Game(unsigned int x, unsigned int y, int max_game_objects, Player* player, Nothofagus::Canvas* canvas) : canvas_width(x), canvas_height(y), canvas(canvas) {
    //Nothofagus::ScreenSize screenSize{ x, y };
    //canvas(Nothofagus::ScreenSize{ x, y }, "Ski-Free", { 1.0, 1.0, 1.0 }, 6);
    this->player = player; 
    this->player_x = ((float)x)/2.0f; 
    this->player_y = ((float)y)*0.75f;
    this->dist_from_player_threshold = ((float)y)*0.25f;
    this->max_game_objects = max_game_objects;
    // this->player = Player(player_x, player_y);
}

void Game::updateFrame(float dt) {
    player->draw(canvas);
    if (player->hasCrashed()) {
        player->checkCrashCounter(dt*0.0006);

    } else {
        float player_speed = player->getSpeed(dt*0.01);
        std::vector<float> player_vel = player->getVelocity();
        std::vector<float> player_bbox = player->getBoundingBox();

        float dx = -player_vel[0]*player_speed*0.01;
        float dy = -player_vel[1]*player_speed*0.01;
        
        // std::cout << "player_speed: "  << player_speed << std::endl;
        // std::cout << "player_vel[0]: " << player_vel[0] << " player_vel[1]: " << player_vel[1] << std::endl;
        // std::cout << "dx: " << dx << " dy: " << dy << std::endl;

        player->restoreTopSpeed(dt);
        if (player->isJumping()) player->checkJumpCounter(dt*0.0006);
        for (auto& obj : game_objects) {
            obj->move(dx, dy);
            if (obj->getExists()) {
                bool collision = obj->is_colliding(player_bbox[0], player_bbox[1], player_bbox[2], player_bbox[3]);
                if (collision) {
                    obj->interact(player);
                }
            }

            if (obj->isOutOfBoundaries(player_y, dist_from_player_threshold)) {
                int new_x = getRandomInt(-30, canvas_width+30);
                int new_y = -getRandomInt(200);
                obj->setPos((float)new_x, (float)new_y);
                obj->setExists(true);
            }
        }
        // game_objects.erase(std::remove_if(game_objects.begin(), game_objects.end(),
        //                                   [&](const std::unique_ptr<Obstacle>& obj) {
        //                                       if (obj->isOutOfBoundaries(player_y, dist_from_player_threshold)) {
        //                                           obj->removeFromCanvas(canvas);
        //                                           return true; // Elimina el objeto del vector
        //                                       }
        //                                       return false;
        //                                   }),
        //                    game_objects.end());

        
    }
}

void Game::addObstacle(std::unique_ptr<Obstacle> obstacle) {
    if (num_game_objects < max_game_objects) {
        game_objects.push_back(std::move(obstacle));
        num_game_objects++;
    }
}

void Game::generateObstacles() {
    // Generar obstáculos de forma aleatoria
    while (num_game_objects < max_game_objects) {
        int random_x = getRandomInt(-30, canvas_width+30);
        int random_y = getRandomInt(-20, canvas_height);

        int obst_int = getRandomInt(5);
        // Crear un obstáculo aleatorio (por ejemplo, una roca o un árbol)
        if (obst_int == 0) {
            addObstacle(std::make_unique<Rock>((float)random_x, (float)random_y));
        } else if (obst_int == 1) {
            addObstacle(std::make_unique<Tree>((float)random_x, (float)random_y));
        } else if (obst_int == 2) {
            addObstacle(std::make_unique<Accelerator>((float)random_x, (float)random_y));
        } else if (obst_int == 3) {
            addObstacle(std::make_unique<Deaccelerator>((float)random_x, (float)random_y));
        } else {
            addObstacle(std::make_unique<Flag>((float)random_x, (float)random_y));
        }
    }
}

void Game::addToCanvas() {
    for (int i = 0; i < num_game_objects; i++) {
        game_objects[i]->addToCanvas(canvas);
    }
    player->addToCanvas(canvas);
}

void Game::draw() {
    for (int i = 0; i < num_game_objects; i++) {
        game_objects[i]->draw(canvas);
    }
    player->draw(canvas);
}

void Game::controllerInput(int m) {
    switch(m) {
        case 1:
            player->moveRight();
            break;
        case 0:
            player->moveFront();
            break;
        case -1:
            player->moveLeft();
            break;
        default:
            player->jump(0.5);
            break;
    }
}

void Game::startGame(Nothofagus::Controller& controller) {
    player->addToCanvas(canvas); 
    canvas->run([this](float dt) { this->updateFrame(dt); }, controller);
}

void Game::stopGame() {
    canvas->close();
}