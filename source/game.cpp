#include <game.h>

Game::Game(unsigned int x, unsigned int y) : canvas_width(x), canvas_height(y), canvas(Nothofagus::ScreenSize{ x, y }, "Ski-Free", { 1.0, 1.0, 1.0 }, 6) {
    //Nothofagus::ScreenSize screenSize{ x, y };
    //canvas(Nothofagus::ScreenSize{ x, y }, "Ski-Free", { 1.0, 1.0, 1.0 }, 6);
    this->player_x = ((float)x)/2.0f; 
    this->player_y = ((float)y)*0.75f;
    this->player = Player(player_x, player_y);
}

auto Game::updateFrame(float dt) {
    player.draw(canvas);
    if (player.hasCrashed()) {
        player.checkCrashCounter(dt);

    } else if (player.isJumping()) {
        player.checkJumpCounter(dt);

    } else {
        float player_speed = player.getSpeed(dt);
        std::vector<float> player_vel = player.getVelocity();
        std::vector<float> player_bbox = player.getBoundingBox();

        float dx = -player_vel[0]*player_speed;
        float dy = -player_vel[1]*player_speed;

        for (auto& obj : game_objects) {
            obj->move(dx, dy);
            if (obj->getExists()) {
                bool collision = obj->is_colliding(player_bbox[0], player_bbox[1], player_bbox[2], player_bbox[3]);
                if (collision) {
                    obj->interact(player);
                }
            }
        }
        game_objects.erase(std::remove_if(game_objects.begin(), game_objects.end(),
                                          [&](const std::unique_ptr<Obstacle>& obj) {
                                              if (obj->isOutOfBoundaries(player_y, dist_from_player_threshold)) {
                                                  obj->removeFromCanvas(canvas);
                                                  return true; // Elimina el objeto del vector
                                              }
                                              return false;
                                          }),
                           game_objects.end());

    }
}

void Game::controllerInput(int m) {
    switch(m) {
        case 1:
            player.moveRight();
            break;
        case 0:
            player.moveFront();
            break;
        case -1:
            player.moveLeft();
            break;
        default:
            player.jump(0.5);
            break;
    }
}


void Game::startGame(Nothofagus::Controller& controller) {
    player.addToCanvas(canvas); 
    canvas.run([this](float dt) { this->updateFrame(dt); }, controller);
}

void Game::stopGame() {
    canvas.close();
}