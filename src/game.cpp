#include <game.h>

Game::Game(int x, int y) : canvas_width(x), canvas_height(y) {
    Nothofagus::ScreenSize screenSize{ x, y };
    canvas = Nothofagus::Canvas(screenSize, "Ski-Free", { 1.0, 1.0, 1.0 }, 6);
    player_x = ((float)x)/2.0f; 
    player_y = ((float)y)*0.75f;
    player = new Player(player_x, player_y);
}

auto Game::updateFrame(float dt) {
    player.draw(canvas);
    if (player.has_crashed()) {
        player.checkCrashCounter(dt);

    } else if (player.is_jumping()) {
        player.checkJumpCounter(dt);

    } else {
        float player_speed = player.getSpeed(dt);
        std::vector<float> player_vel = player.getVelocity();
        std::vector<float> player_bbox = player.getBoundingBox();

        float dx = -player_vel[0]*player_speed;
        float dy = -player_vel[1]*player_speed;

        for (int i = 0; i < num_game_objects; i++) {
            game_objects[i].move(dx, dy);
            if (game_objects[i].getExists()) {
                bool collision = game_objects[i].is_colliding(player_bbox[0], player_bbox[1], player_bbox[2], player_bbox[3]);
                if (collision) {
                    game_objects[i].interact(player);
                }
            }
        }
        int j = 0;
        while (j < num_game_objects) {
            if (game_objects[j].isOutOfBoundaries(player_y, dist_from_player_threshold)) {
                num_game_objects--;
                game_objects[j].removeFromCanvas(canvas);
                game_objects.remove(i);
            } else {
                j++;
            }
        }

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
    canvas.run(this->updateFrame, controller);
}

void Game::stopGame() {
    canvas.close();
}