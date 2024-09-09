#include <models/game_objects.h>
#include <game.h>

int main(int argc, char const *argv[]) {

    Game game(150, 100);

    Nothofagus::Controller controller;

controller.registerAction({ Nothofagus::Key::S, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        game.controllerInput(0);
    });
controller.registerAction({ Nothofagus::Key::A, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
       game.controllerInput(-1);
    });
controller.registerAction({ Nothofagus::Key::D, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        game.controllerInput(1);
    });
controller.registerAction({ Nothofagus::Key::SPACE, Nothofagus::DiscreteTrigger::Press }, [&]()
    {
        game.controllerInput(10);
    });
controller.registerAction({ Nothofagus::Key::ESCAPE, Nothofagus::DiscreteTrigger::Press }, [&]() { game.stopGame(); });

    game.startGame(controller);

    return 0;
}