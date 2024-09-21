#include "nothofagus.h"
#include "game.h"
#include "audio.h"



void game_info(int canvas_width, int canvas_height, float speed, int style, float time, float dist) {
    int hours = static_cast<int>(time/1000.0f) / 3600;
    int minutes = (static_cast<int>(time/1000.0f) % 3600) / 60;
    int seconds = static_cast<int>(time/1000.0f) % 60;

    ImGui::SetNextWindowSize(ImVec2(canvas_width*2.0f, canvas_height), ImGuiCond_Always);

    ImGui::Begin("SkiFree!");
    ImGui::Text("Time Elapsed: %02d:%02d:%02d", hours, minutes, seconds);
    ImGui::Text("Control: W, A, S, D, SPACE (jump)");
    ImGui::Text("ENTER (pause), ESCAPE (close)");
    ImGui::Text("Speed: %.2f", speed); ImGui::SameLine();
    ImGui::Text("Style: %d", style); ImGui::SameLine();
    ImGui::Text("Distance: %.2f", dist);
    ImGui::End();
}


int main(int argc, char const *argv[]) {
    /// AUDIO 
    RustyAudio::Builder jumpSoundBuilder;
    for (int i = 0 ; i < 30; i++)
        jumpSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(10, 0.2,  i*50));
    RustyAudio::Buffer jumpSoundBuffer = jumpSoundBuilder.generate(48000, 2);
    RustyAudio::Player jumpSoundPlayer;
    jumpSoundPlayer.init(jumpSoundBuffer);


    RustyAudio::Builder crashSoundBuilder;
    crashSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(50, 0.1, 200));
    crashSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(10, 0.1, 0));
    crashSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(200, 0.1, 200));
    RustyAudio::Buffer crashSoundBuffer = crashSoundBuilder.generate(100000, 2);
    RustyAudio::Player crashSoundPlayer;
    crashSoundPlayer.init(crashSoundBuffer);

    RustyAudio::Builder speedUpSoundBuilder;
    for (int i = 0 ; i < 30; i++)
        speedUpSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(20, 0.1,  500*sin((float)i*2.0f*3.1415f/30.0f)));
    RustyAudio::Buffer speedUpSoundBuffer = speedUpSoundBuilder.generate(48000, 2);
    RustyAudio::Player speedUpSoundPlayer;
    speedUpSoundPlayer.init(speedUpSoundBuffer);

    RustyAudio::Builder speedDownSoundBuilder;
    for (int i = 0 ; i < 15; i++)
        speedDownSoundBuilder.append(std::make_unique<RustyAudio::WaveformSinusoid>(20, 0.1,  500*sin(3.1415f/2.0f + (float)i*2.0f*3.1415f/30.0f)));
    RustyAudio::Buffer speedDownSoundBuffer = speedDownSoundBuilder.generate(48000, 2);
    RustyAudio::Player speedDownSoundPlayer;
    speedDownSoundPlayer.init(speedDownSoundBuffer);


    unsigned int canvas_width = 150, canvas_height = 100;
    int game_obj = 18;
    bool pause = false;


    Nothofagus::Canvas canvas(Nothofagus::ScreenSize{ canvas_width, canvas_height }, "Ski-Free", { 1.0, 1.0, 1.0 }, 6);
    Player player((float)canvas_width*0.5f, (float)canvas_height*0.75f);
    int enemy_x_pos = getRandomInt(-30, canvas_width+30);
    int apparition_time = (float)getRandomInt(120000, 240000);
    Enemy enemy((float)enemy_x_pos, (float)(canvas_height+16), apparition_time);

    Game game(canvas_width, canvas_height, game_obj, &player, &canvas, &enemy);

    game.generateObstacles();
    game.addToCanvas(); 
    float time = 0.0f;
    auto update = [&](float dt) {
        if (!pause) {
            time += dt;
            game.updateFrame(dt);
            game.draw(); 
            if (jumpSoundPlayer.isPlaying()) jumpSoundPlayer.play();
            if (player.hasCrashed()) crashSoundPlayer.play();
            if (player.getIsAccellerating()) speedUpSoundPlayer.play(); 
            if (player.getIsSlowing()) speedDownSoundPlayer.play(); 
            float speed = player.getActualSpeed();
            std::vector<float> velocity = player.getVelocity();
            game_info(canvas_width, canvas_height, -18.0f*velocity[1]*speed, player.getStylePoints(), time, game.getDist());

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
            jumpSoundPlayer.play();
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