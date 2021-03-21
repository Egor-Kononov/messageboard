#pragma once
#include "Direction.hpp"
#include <string>


namespace ariel{

    class Board
    {
    private:
    public:
        Board();
        ~Board();
        void post(unsigned int r,unsigned int c, Direction d,const std::string &str);
        static std::string read(unsigned int r,unsigned int c, Direction d, unsigned int len);
        void show() const;
    };
    
}