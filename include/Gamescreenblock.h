#ifndef GAMESCREENBLOCK_H
#define GAMESCREENBLOCK_H
#include"IMG.h"


class Gamescreenblock
{
    public:
        short id;
        Gamescreenblock();
        Gamescreenblock(IMG*,short);
        IMG * getIMGpointer();
        short getid();
        virtual ~Gamescreenblock();
        void disp()
        {
            std::cout<<id;
        }
    protected:

    private:
    IMG* tile;
};

#endif // GAMESCREENBLOCK_H
