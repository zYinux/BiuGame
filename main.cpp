#include <iostream>
#include <string>
#include "SDL.h"
#include "src/includes/Logger.h"
#include "src/core/Game.h"
#include "src/core/GameWindow.h"

using namespace std;
using namespace zyinux;
int main() {
    Game game;
    game.init();
    GameWindow gameWindow("title");
    Window & window=gameWindow;
    game.addWindow(window);

//    GameWindow gameWindow2("title");
//    Window & window2=gameWindow2;
//    game.addWindow(window2);

    game.loop();

    game.destroy();
    return 0;
}
