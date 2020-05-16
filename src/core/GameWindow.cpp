//
// Created by zyinux on 2020/5/15.
//

#include "GameWindow.h"

namespace zyinux{

    bool GameWindow::onWindowEvent(const SDL_Event &event) {
        if (event.type==SDL_QUIT){
            return true;
        } else{
            //todo::把事件分发给window。或者这里需要先分发window的draw?
        }
        return false;
    }

    void GameWindow::draw() {

    }

    void GameWindow::destroy() {

    }

    GameWindow::~GameWindow() {

    }
}

