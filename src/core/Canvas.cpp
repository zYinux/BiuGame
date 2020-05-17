//
// Created by zyinux on 2020/5/16.
//

#include "Canvas.h"
#include "Color.h"
#include <typeinfo>


namespace zyinux{

    void zyinux::Canvas::setDrawColor(const zyinux::Color &color) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    }

    void zyinux::Canvas::drawPoint(int x, int y, const zyinux::Color &color) {
        setDrawColor(color);
        SDL_RenderDrawPoint(renderer,x,y);
    }



    void zyinux::Canvas::drawLine(int sx,int sy,int ex,int ey,const zyinux::Color &color) {
        setDrawColor(color);
        SDL_RenderDrawLine(renderer,sx,sy,ex,ey);
    }

    void zyinux::Canvas::drawRect(const SDL_Rect * const rect, const zyinux::Color &color,bool fill,const zyinux::Color *fillColor) {
        setDrawColor(color);
        SDL_RenderDrawRect(renderer,rect);
        if (fill){
            if (fillColor) {
                setDrawColor(*fillColor);
            }
            SDL_RenderFillRect(renderer,rect);
        }
    }


    void zyinux::Canvas::drawTriangle(const zyinux::Triangle triangle, const zyinux::Color &color, bool, const zyinux::Color *fillColor) {
        SDL_Point points[4]{triangle.point1,triangle.point2,triangle.point3,triangle.point1};
        drawLines(points,4,color);
    }

    void Canvas::drawLines(SDL_Point * points, int count,const Color &color) {
        setDrawColor(color);
        SDL_RenderDrawLines(renderer,points,count);
    }

    void Canvas::lockDrawTarget() {
        if (SDL_GetRenderTarget(renderer)!=texture){
            SDL_SetRenderTarget(renderer,texture);
        }
        clearTexture();
    }

    void Canvas::render(int x,int y) {
        SDL_Rect clip{0,0,_width,_height};
        SDL_Rect screen{x,y,_width,_height};
        SDL_RenderCopy(renderer,texture,&clip,&screen);
    }

    void Canvas::unlockDrawTarget() {
        SDL_SetRenderTarget(renderer, nullptr);
    }

    void Canvas::clearTexture() {
        SDL_RenderClear(renderer);
    }
}
