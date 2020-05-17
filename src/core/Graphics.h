//
// Created by zyinux on 2020/5/17.
//

#ifndef BIUBIUBIU_GRAPHICS_H
#define BIUBIUBIU_GRAPHICS_H
#include "SDL.h"
namespace zyinux{

//    struct Point{
//        int x;
//        int y;
//    };

    struct Triangle{
        Triangle(SDL_Point p1,SDL_Point p2,SDL_Point p3):point1(p1),point2(p2),point3(p3){}
        SDL_Point point1,point2,point3;
    };
}
#endif //BIUBIUBIU_GRAPHICS_H
