#include "ScreenBlock.h"

ScreenBlock::ScreenBlock(bool active, IMG* temp)
{
    this->active=active;
    this->iScreenBlocktile=temp;
}
bool ScreenBlock::isactive()
{
    return active;
}
ScreenBlock::~ScreenBlock()
{
    //dtor
}

void ScreenBlock::setBlock(bool active,int xPos,int yPos,int xlen,int ylen,IMG *oScreenBlocktile)
{
   this->active=active;
    this->xPos=xPos;
    this->yPos=yPos;
    this->xlen=xlen;
    this->ylen=ylen;
    this->iScreenBlocktile=oScreenBlocktile;

}

IMG* ScreenBlock::getIMGpointer()
{
    return iScreenBlocktile;
}
int ScreenBlock::getxPos()
{
    return xPos;
}
int ScreenBlock::getyPos()
{
    return yPos;
}
