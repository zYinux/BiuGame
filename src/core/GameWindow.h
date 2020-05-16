//
// Created by zyinux on 2020/5/15.
//

#ifndef BIUBIUBIU_GAMEWINDOW_H
#define BIUBIUBIU_GAMEWINDOW_H
#include "Window.h"

namespace zyinux{
    class GameWindow : public Window {
    public:

        GameWindow(const std::string &t,
               int x = SDL_WINDOWPOS_CENTERED,
               int y = SDL_WINDOWPOS_CENTERED,
               Uint32 flag = SDL_WINDOW_SHOWN,
               int w = 400,
               int h = 400) : Window(t,x,y,flag,w,h){}

        //处理各种事件
        bool onWindowEvent(const SDL_Event &event) override ;

        //绘制当前window
        void draw()override ;

        //销毁window
        void destroy()override ;

        ~GameWindow()override ;
    };
}


#endif //BIUBIUBIU_GAMEWINDOW_H
