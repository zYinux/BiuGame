//
// Created by zyinux on 2020/5/15.
//

#ifndef BIUBIUBIU_GAME_H
#define BIUBIUBIU_GAME_H

#include "SDL.h"
#include <stack>
#include <memory>
#include <string>
#include "../includes/Logger.h"
namespace zyinux{

    class Window;

    class Game {
    public:
        static const std::string TAG;
        void init(Uint32 flag=SDL_INIT_EVERYTHING,bool init_ttf=1,bool init_mixer=1){
            logger.debug(TAG+"Game.init()");
            initSDL(flag);
            if (init_ttf)
                initTTF();
            if (init_mixer)
                initMixer();
        }

        void addWindow(Window& window);

        void loop();

        void destroy();

    private:
        void initSDL(Uint32 flag);
        void initTTF();
        void initMixer();

        std::stack<std::shared_ptr<Window *>> windows;
    };
}
#endif //BIUBIUBIU_GAME_H
