#include "nothofagus.h"
#include "game.h"

int main(int argc, char const *argv[]) {
    unsigned int canvas_width = 150, canvas_height = 100;
    int game_obj = 10;
    Nothofagus::Canvas canvas(Nothofagus::ScreenSize{ canvas_width, canvas_height }, "Ski-Free", { 1.0, 1.0, 1.0 }, 6);
    Player player((float)canvas_width*0.5f, (float)canvas_height*0.75f);

    Game game(canvas_width, canvas_height, game_obj, &player, &canvas);

    game.generateObstacles();
    game.addToCanvas(); 
    float time = 0.0f;

    auto update = [&](float dt) {
        time += dt;
        game.updateFrame(dt);
        game.draw(); 
    };

    Nothofagus::Controller controller;

controller.registerAction({ Nothofagus::Key::S, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        if (!player.isJumping() && !player.hasCrashed()) {
            player.moveFront();
            player.setActualPixelMap(&canvas);
        }
    });
controller.registerAction({ Nothofagus::Key::A, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        if (!player.isJumping() && !player.hasCrashed()) {
            player.moveLeft();
            player.setActualPixelMap(&canvas);
        }
    });
controller.registerAction({ Nothofagus::Key::D, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        if (!player.isJumping() && !player.hasCrashed()) {
            player.moveRight();
            player.setActualPixelMap(&canvas);
        }
    });
controller.registerAction({ Nothofagus::Key::SPACE, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        if (!player.isJumping() && !player.hasCrashed()) {
            player.jump(1.0f);
            player.setActualPixelMap(&canvas);
            player.moveFront();
        }
    });
controller.registerAction({ Nothofagus::Key::ESCAPE, Nothofagus::DiscreteTrigger::Press }, [&]() { /*game.stopGame();*/ canvas.close(); });

    canvas.run(update, controller);

    return 0;
}