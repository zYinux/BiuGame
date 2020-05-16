//
// Created by zyinux on 2020/5/14.
//

#ifndef SDL2DEMOV_LOGGER_H
#define SDL2DEMOV_LOGGER_H

#include <string>
#include <iostream>

namespace zyinux {
    class Logger {

    public:
        Logger(std::ostream& o,int level=0):os(o),level(level){}

        void info(const std::string &msg) const {
            if (level <= 1)
                print(INFO + msg);
        }

        void debug(const std::string &msg) const {
            if (level <= 0)
                print(DEBUG + msg);
        }


        void error(const std::string &msg) const {
            if (level <= 2)
                print(ERROR + msg);
        }


    private:
        void print(const std::string &msg) const {
            os << msg << "\n" << std::endl;
        }

        std::ostream &os;
        int level = 0;
        std::string DEBUG = "DEBUG:";
        std::string INFO = "INFO:";
        std::string ERROR = "ERROR:";
    };

    static const Logger logger(std::cout,0);
}
#endif //SDL2DEMOV_LOGGER_H
