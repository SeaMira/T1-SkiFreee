#include "nothofagus.h"
#include "game.h"

void game_info(int canvas_width, int canvas_height, float speed, int style) {
    ImGui::SetNextWindowSize(ImVec2(canvas_width*2.0f, canvas_height), ImGuiCond_Always);

    ImGui::Begin("SkiFree!");
    ImGui::Text("Control: W, A, S, D, SPACE (jump)");
    ImGui::Text("ENTER (pause), ESCAPE (close)");
    ImGui::Text("Speed: %.2f", speed);
    ImGui::Text("Style: %d", style);
    ImGui::End();
}


int main(int argc, char const *argv[]) {
    unsigned int canvas_width = 150, canvas_height = 100;
    int game_obj = 10;
    bool pause = false;
    Nothofagus::Canvas canvas(Nothofagus::ScreenSize{ canvas_width, canvas_height }, "Ski-Free", { 1.0, 1.0, 1.0 }, 6);
    Player player((float)canvas_width*0.5f, (float)canvas_height*0.75f);

    Game game(canvas_width, canvas_height, game_obj, &player, &canvas);

    game.generateObstacles();
    game.addToCanvas(); 
    float time = 0.0f;

    auto update = [&](float dt) {
        if (!pause) {
            time += dt;
            game.updateFrame(dt);
            game.draw(); 
            float speed = player.getActualSpeed();
            std::vector<float> velocity = player.getVelocity();
            game_info(canvas_width, canvas_height, -18.0f*velocity[1]*speed, player.getStylePoints());

        }
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
            player.playJumpSound();
            player.jump(1.0f);
            player.moveFront();
            player.setActualPixelMap(&canvas);
        }
    });

controller.registerAction({ Nothofagus::Key::ENTER, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        pause = !pause;
    });
controller.registerAction({ Nothofagus::Key::ESCAPE, Nothofagus::DiscreteTrigger::Press }, [&]() { /*game.stopGame();*/ canvas.close(); });

    canvas.run(update, controller);

    return 0;
}