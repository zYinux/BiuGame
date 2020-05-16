//
// Created by zyinux on 2020/5/15.
//

#ifndef BIUBIUBIU_GAMEEXCEPTION_H
#define BIUBIUBIU_GAMEEXCEPTION_H
#include <exception>
#include <stdexcept>
#include "../includes/Logger.h"
namespace zyinux{
    class GameException : public std::runtime_error{
    public:
        explicit GameException(const std::string & msg):std::runtime_error(msg){
            logger.error(msg);
        }
    };
}
#endif //BIUBIUBIU_GAMEEXCEPTION_H
