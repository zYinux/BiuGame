//
// Created by zyinux on 2020/5/15.
//

#ifndef BIUBIUBIU_WINDOW_H
#define BIUBIUBIU_WINDOW_H

#include <stack>
#include <string>
#include "SDL.h"
#include "GameException.h"
#include "../includes/Logger.h"
namespace zyinux {
    class Scenes;

    class Window {

    public:
        virtual ~Window() = default;

        Window(const std::string &t,
               int x,
               int y,
               Uint32 flag,
               int w,
               int h ) :
                title(t), _height(h), _width(w),_flag(flag),_x(x),_y(y) {
            window = SDL_CreateWindow(title.c_str(), x, y, w, h, flag);

            if (!window)
                throw GameException("create Window fail :"+std::string(SDL_GetError()));

            logger.debug("create window:"+t);
        }

        Window(const Window &);

        //处理各种事件
        virtual bool onWindowEvent(const SDL_Event &event) = 0;


        //绘制当前window
        virtual void draw() = 0;

        //销毁window
        virtual void destroy() = 0;

    protected:
        std::stack<std::shared_ptr<Scenes>> sceness;
        SDL_Window *window;
        int _width;
        int _height;
        int _x,_y;
        Uint32 _flag;
        const std::string &title;
    };
}


#endif //BIUBIUBIU_WINDOW_H
