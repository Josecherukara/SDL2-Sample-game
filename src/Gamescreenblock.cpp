#include "Gamescreenblock.h"
#include "Game.h"

IMG* Gamescreenblock::getIMGpointer()
{
    return tile;
}
short Gamescreenblock::getid()
{
    return id;
}
Gamescreenblock::Gamescreenblock(IMG* tiletemp,short idtemp)
{
    tile=tiletemp;
    id=idtemp;
    //ctor
}
Gamescreenblock::Gamescreenblock()
{
    id=Game::aNIGHT;
    this->tile=NULL;
    //ctor
}

Gamescreenblock::~Gamescreenblock()
{
    //dtor
}
