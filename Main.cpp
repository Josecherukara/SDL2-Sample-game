#include "headers.h"
#include "Game.h"
#include <iostream>

int WorldSubWorld=0;
float foregroundVol=100;
float backgroundVol=10;

int main(int argc, char *argv[])
{
    Game oG;
    oG.MainLoop();
    return 0;
}
