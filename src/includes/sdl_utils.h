//
// Created by zyinux on 2020/5/14.
//

#ifndef SDL2DEMOV_SDL_UTILS_H
#define SDL2DEMOV_SDL_UTILS_H

#include <SDL.h>
#include <string>

namespace zyinux {
    SDL_Texture *loadBmp(std::string file, SDL_Renderer *renderer);

    SDL_Texture *loadImage(std::string file, SDL_Renderer *renderer);

    void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend, SDL_Rect *clip= nullptr);
}
#endif //SDL2DEMOV_SDL_UTILS_H
