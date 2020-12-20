#ifndef SCREENBLOCK_H
#define SCREENBLOCK_H
#include "headers.h"
#include "IMG.h"

class ScreenBlock
{
    public:
        ScreenBlock(bool active,IMG* temp);
        virtual ~ScreenBlock();
        void setBlock(bool active,int xPos,int yPos,int xlen,int ylen,IMG *oScreenBlocktile);
        bool isactive();
        IMG * getIMGpointer();
        int getxPos();
        int getyPos();

    protected:

    private:
        bool active;
        int xPos;
        int yPos;
        int xlen;
        int ylen;
        IMG *iScreenBlocktile;
};

#endif // SCREENBLOCK_H
