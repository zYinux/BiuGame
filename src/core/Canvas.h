//
// Created by zyinux on 2020/5/16.
//

#ifndef BIUBIUBIU_CANVAS_H
#define BIUBIUBIU_CANVAS_H
#include "SDL.h"
#include "Graphics.h"
namespace zyinux{



    class Color;
    class Canvas {
    public:
        Canvas()=default;
        Canvas(SDL_Renderer * r,int w,int h):renderer(r),_width(w),_height(h){
            texture=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_TARGET,w,h);
        }
        void drawPoint(int x,int y,const Color& color);
        void drawLine(int sx,int sy,int ex,int ey,const zyinux::Color &color);
        void drawLines(SDL_Point * ,int count,const zyinux::Color &color);
        void drawRect(const SDL_Rect * const ,const zyinux::Color &,bool = false,const Color * = nullptr);
        void drawTriangle(const Triangle ,const zyinux::Color &,bool = false,const Color * = nullptr);

        void render(int x,int y);
        void lockDrawTarget();

        void unlockDrawTarget();
    private:
        void setDrawColor(const Color& color);

        void clearTexture();

        SDL_Renderer *renderer;
        SDL_Texture *texture;
        int _width,_height;

    };
}


#endif //BIUBIUBIU_CANVAS_H
