//
// Created by zyinux on 2020/5/17.
//

#ifndef BIUBIUBIU_COLOR_H
#define BIUBIUBIU_COLOR_H

#include "SDL.h"
namespace zyinux{
    class Color{
    public:
        Color(Uint8 a=0,Uint8 r=0,Uint8 g=0,Uint8 b=0):r(r),g(g),b(b),a(a){}
        Uint8 r,g,b,a;
    };
}
#endif //BIUBIUBIU_COLOR_H
