
#include "GameScreenBlock_2.h"
GameScreenBlock_2::GameScreenBlock_2()
{
    this->active=0;
    Gamescreenblock *temp=new Gamescreenblock(NULL,0);
    this->iScreenBlocktile=temp;
}
GameScreenBlock_2::GameScreenBlock_2(bool active, Gamescreenblock* temp)
{
    this->active=active;
    this->iScreenBlocktile=temp;
}
bool GameScreenBlock_2::isactive()
{
    return active;
}
GameScreenBlock_2::~GameScreenBlock_2()
{
    ;   //dtor
}

void GameScreenBlock_2::setBlock(bool active,int xPos,int yPos,int xlen,int ylen,Gamescreenblock *oScreenBlocktile)
{
   this->active=active;
    this->xPos=xPos;
    this->yPos=yPos;
    this->xlen=xlen;
    this->ylen=ylen;
    this->iScreenBlocktile=oScreenBlocktile;

}

Gamescreenblock* GameScreenBlock_2::getBlockpointer()
{
    return iScreenBlocktile;
}
int GameScreenBlock_2::getxPos()
{
    return xPos;
}
int GameScreenBlock_2::getyPos()
{
    return yPos;
}
int GameScreenBlock_2::getyLen()
{
    return ylen;
}
