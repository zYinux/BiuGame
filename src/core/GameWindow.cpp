//
// Created by zyinux on 2020/5/15.
//

#include "GameWindow.h"
#include "Color.h"
#include "Canvas.h"

namespace zyinux {

    bool GameWindow::onWindowEvent(const SDL_Event &event) {
        if (event.type == SDL_QUIT) {
            return true;
        } else {
            //todo::把事件分发给window。或者这里需要先分发window的draw?
        }
        return false;
    }

    void GameWindow::draw() {
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);
        onDraw();
        SDL_SetRenderTarget(renderer, nullptr);
        SDL_RenderPresent(renderer);
    }

    void GameWindow::destroy() {

    }

    GameWindow::~GameWindow() {

    }

    void GameWindow::onDraw() {
        Color color(55,255,44,52);
        Color fillColor(255,255,44,52);

        canvas.lockDrawTarget();
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
//        canvas.drawPoint(10, 10, color);
//        canvas.drawLine(10,10,10,100,color);
//        canvas.drawLine(100,100,10,100,color);
//        canvas.drawLine(100,100,100,10,color);
//        canvas.drawLine(10,10,100,10,color);


        SDL_Rect rect{10,10,100,100};
        canvas.drawRect(&rect,color, true,&fillColor);

        Triangle triangle{{50,  0},
                          {0,   100},
                          {100, 100}};
        canvas.drawTriangle(triangle, color);

        canvas.unlockDrawTarget();
        canvas.render(100,100);

    }
}

