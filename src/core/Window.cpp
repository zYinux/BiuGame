//
// Created by zyinux on 2020/5/15.
//

#include "Window.h"
#include "SDL.h"
#include "Canvas.h"
void zyinux::Window::initCanvas() {
    canvas = Canvas(renderer,_width,_height);
}
