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
#include "Canvas.h"

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
               int h) :
                title(t), _height(h), _width(w), _flag(flag), _x(x), _y(y) {
            window = SDL_CreateWindow(title.c_str(), x, y, w, h, flag);

            if (!window)
                throw GameException("create Window fail :" + std::string(SDL_GetError()));
            createRenderer();
            initCanvas();
            logger.debug("create window:" + t);
        }

        Window(const Window &);

        //处理各种事件
        virtual bool onWindowEvent(const SDL_Event &event) = 0;


        //绘制当前window
        virtual void draw() = 0;

        //销毁window
        virtual void destroy() = 0;

        void initCanvas();

    protected:
        std::stack<std::shared_ptr<Scenes>> sceness;
        SDL_Window *window;
        SDL_Renderer *renderer;
        Canvas canvas;
        int _width;
        int _height;
        int _x, _y;
        Uint32 _flag;
        const std::string &title;

    private:
        void createRenderer() {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        }
    };
}


#endif //BIUBIUBIU_WINDOW_H
