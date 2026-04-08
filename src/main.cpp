#include "core/Game.h"
#include <iostream>

int main(int argc, char* argv[]) {
    FGame& game = FGame::getInstance();
    game.Initialize();
    game.GameLoop();
    game.Shutdown();
    return 0;
}
