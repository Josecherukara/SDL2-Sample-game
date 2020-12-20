#ifndef GAMESCREENBLOCK_2_H
#define GAMESCREENBLOCK_2_H

#include "headers.h"
#include "Gamescreenblock.h"

class GameScreenBlock_2
{
    public:
        GameScreenBlock_2(bool active,Gamescreenblock* temp);
        GameScreenBlock_2();
        virtual ~GameScreenBlock_2();
        void setBlock(bool active,int xPos,int yPos,int xlen,int ylen,Gamescreenblock *oScreenBlocktile);
        bool isactive();
        Gamescreenblock * getBlockpointer();
        int getxPos();
        int getyPos();
        int getyLen();
    protected:

    private:
        bool active;
        int xPos;
        int yPos;
        int xlen;
        int ylen;
        Gamescreenblock *iScreenBlocktile;
};
#endif // GAMESCREENBLOCK_2_H
