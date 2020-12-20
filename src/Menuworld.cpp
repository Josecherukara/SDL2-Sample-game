#include "Menuworld.h"
#include "Text.h"
#include "headers.h"
#include "Game.h"
#include "Music.h"


Menuworld::Menuworld(SDL_Renderer * rR)
{
    //ctor
    //iMenuworld_main=new IMG("menuwindow",rR);
    iMenuworld_Logo=new IMG("Logo",rR);
    iMenuworld_Logo2=new IMG("Logo2small",rR);
    optionSelectorIcon=new IMG("menutoken2",rR);
    Game::oText->setFont(rR, "font");

    optionMainMenu=GAME;
    MainMenu_Lock=0;
}
short Menuworld::getDecision(short activeWorld,Map *oMap,Music* oMusic)
{
    if(MainMenu_Lock==0)
    {
        return activeWorld;
    }
    else
    {
        if(optionMainMenu+1==Game::GAMEWORLD)
        {
            oMap->setMapParams(Game::WIN_HEIGHT,0,0,0);//5*Game::WIN_WIDTH,0,0);
            Game::xframeSpeed=0;
            Game::yframeSpeed=0;
            oMap->getPlayer()->lastUpdate=SDL_GetPerformanceCounter();
            Game::Node=1;
           // oMusic->setVolume(foregroundVol);
           // oMusic->PlayChunk(oMusic->cVINE);
           // oMusic->setVolume(backgroundVol);
        }
        else
        {

            oMap->setMapParams(5*Game::WIN_HEIGHT,Game::WIN_WIDTH,0,0);
            Game::xframeSpeed=0;
            Game::yframeSpeed=-300;
        }
        MainMenu_Lock=0;
        return optionMainMenu+1;
    }

}
void Menuworld::setPencilColor(SDL_Renderer * rR)
{
    SDL_SetRenderDrawColor(rR, 1, 6, 9, 255);
}
void Menuworld::MenuWorldDraw(SDL_Renderer * rR)
{

    iMenuworld_Logo->Draw(rR,300,250);
    iMenuworld_Logo2->Draw(rR,550,50);
    Game::oText->Draw(rR,"GAME",100,100);
    Game::oText->Draw(rR,"OPTION",100,150);
    Game::oText->Draw(rR,"ABOUT",100,200);
    Game::oText->Draw(rR,"QUIT",100, 250);
    switch(optionMainMenu)
    {
        case GAME:
            optionSelectorIcon->Draw(rR,60,90);
            break;
        case OPTIONS:
            optionSelectorIcon->Draw(rR,60, 140);
            break;
        case ABOUT:
            optionSelectorIcon->Draw(rR,60,190);
            break;
        case QUIT:
             optionSelectorIcon->Draw(rR,60,240);

    }

}
void Menuworld::doTheJob(SDL_Event *event,Music* oMusic)
{
    static bool downstat=0;
    switch (event->type)
    {
        case SDL_KEYDOWN:
            downstat=1;
            break;
        case SDL_KEYUP:
            if(downstat==1)
            {
                downstat=0;

                switch(event->key.keysym.sym)
                {
                    case SDLK_UP :
                        oMusic->setVolume(foregroundVol);
                        oMusic->PlayChunk(oMusic->cBLOCKHIT);
                        oMusic->setVolume(backgroundVol);
                        if(optionMainMenu==GAME)
                            optionMainMenu=QUIT;
                        else
                            --optionMainMenu;
                        break;
                    case SDLK_DOWN :
                        oMusic->setVolume(foregroundVol);
                        oMusic->PlayChunk(oMusic->cBLOCKHIT);
                        oMusic->setVolume(backgroundVol);
                        if(optionMainMenu==QUIT)
                            optionMainMenu=GAME;
                        else
                            ++optionMainMenu;
                        break;
                    case SDLK_RETURN:
                        oMusic->setVolume(foregroundVol);
                        oMusic->PlayChunk(oMusic->cBULLETBILL);
                        oMusic->setVolume(backgroundVol);
                        MainMenu_Lock=1;

                        break;
                    case SDLK_ESCAPE:
                        oMusic->setVolume(foregroundVol);
                        oMusic->PlayChunk(oMusic->cBLOCKBREAK);
                        oMusic->setVolume(backgroundVol);
                        MainMenu_Lock=0;
                        break;

                }
            }
            break;
    }

}
Menuworld::~Menuworld()
{
    //dtor
    if(iMenuworld_Logo!=NULL)
    {
        delete iMenuworld_Logo;
        iMenuworld_Logo=NULL;
    }
    if(iMenuworld_Logo2!=NULL)
    {
        delete iMenuworld_Logo2;
        iMenuworld_Logo2=NULL;
    }
    if(optionSelectorIcon!=NULL)
    {
        delete optionSelectorIcon;
        optionSelectorIcon=NULL;
    }
     //   delete optionSelectorIcon;

    //delete iMenuworld_main;
}

