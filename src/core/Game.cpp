//
// Created by zyinux on 2020/5/15.
//

#include "Game.h"
#include "SDL_ttf.h"
#include "GameException.h"
#include "Window.h"
#include <memory>
#include <string>
namespace zyinux {

    const std::string Game::TAG = "Game:";

    void Game::initTTF() {
        if (TTF_Init() == -1)
            throw GameException("init ttf error:" + std::string(TTF_GetError()));
    }

    void Game::initSDL(Uint32 flag) {
        //初始化SDL，该初始化应该整个app只需要一次
        if (SDL_Init(flag) == -1) {
            throw GameException("init SDL2 error:" + std::string(SDL_GetError()));
        }

        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    }

    void Game::initMixer() {

    }

    void Game::destroy() {
        //将结束事件传递给所有的window
        while (!windows.empty()){
            auto window=windows.top();
            windows.pop();

            //window.destroy();
        }
        SDL_Quit();
    }

    void Game::loop() {
        bool run= true;
        while (run){
            SDL_Event event;
            SDL_PollEvent(&event);
            if (SDL_QUIT == event.type) { // 如果事件为推出SDL，结束循环。
               run= false;
            } else{
                auto top=windows.top();
                (*top)->draw();
            }
        }
    }

    void Game::addWindow(Window & window) {
        windows.push(std::make_shared<Window*>(&window));
        SDL_Event event;
        window.onWindowEvent(event);
    }
}