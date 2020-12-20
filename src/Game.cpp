#include "headers.h"
#include <string>
#include<cmath>
#include <sstream>
#include <stdio.h>
#include <SDL2/SDL_mixer.h>
#include "Game.h"
#include "Music.h"

Text* Game ::oText=new Text();
short Game::Node=1;
long Game::Life=5000;
double Game::BatLife=4999;
bool Game::quitGame = false;
int Game::WIN_WIDTH=1366;
int Game::WIN_HEIGHT=768;
float Game::yframeSpeed=-300;
float Game::xframeSpeed=0;//300;

Uint64 Game::startProgram=0;
Uint64 Game::startGame=0;
Uint64 Game::current=0;
Uint64 Game::lastUpdate=0;
bool Game::moveActivePaddle_L_Pressed=false;
bool Game::moveActivePaddle_R_Pressed=false;
SDL_Event* Game:: mainEvent = new SDL_Event();
Music* oMusic = new Music();


Game::Game()
{
    //ctor

    this->quitGame = false;
    this->moveActivePaddle_L_Pressed=false;
    this->moveActivePaddle_R_Pressed=false;
    this->seenHalf=false;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    window = SDL_CreateWindow("CATWOMAN Vs BATMAN, josecherukara@gmail.com",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIN_WIDTH,WIN_HEIGHT,SDL_WINDOW_FULLSCREEN);
    SDL_GetWindowSize(window, &WIN_WIDTH,&WIN_HEIGHT);
    SDL_ShowCursor(SDL_DISABLE);
    std::cout<<"Welcome to the game, Programmer Jose Mathew \n";
    if(window != NULL)
    {
		std::string fileName = "files/images/batman_icon.bmp";
        SDL_Surface* loadedSurface = SDL_LoadBMP(fileName.c_str());
        if( loadedSurface != NULL )
        {
            SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
            SDL_SetWindowIcon(window, loadedSurface);
            rR = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            SDL_FreeSurface(loadedSurface);
            loadedSurface=NULL;
            Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
            activeWorld=MENUWORLD;
            oMap=new Map(activeWorld,rR);

            oMenuWorld=new Menuworld(rR);

            iAbout=new IMG("about",rR);
            iCouple=new IMG("couples2",rR);
            oMenuWorld->setPencilColor(rR);
            oMusic->setVolume(backgroundVol);
            oMusic->PlayMusic();
            // ----- ICO
            // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        }
        else
        {
            quitGame=true;
            printf("could not load icon");
        }
    }
    else
    {
        quitGame=true;
        printf("could not create window");
    }
}
void Game::MainLoop()
{
    std::ostringstream str1;
    std::string geek;
    long temp;
//    Uint64 Current=0;
//    float ElapsedTime=0;
//    Uint64 LastUpdate=0;
//    bool check=false;
    startProgram = SDL_GetPerformanceCounter();
    lastUpdate=startProgram;
    while(!quitGame)
    {
        SDL_PollEvent(mainEvent);
        SDL_RenderFillRect(rR, NULL);
        SDL_SetRenderDrawColor(rR, 3.5, 3.5, 3.5, 255);
        SDL_RenderClear(rR);

        switch(mainEvent->type)
        {
            case SDL_QUIT:
                quitGame=true;
                break;
            default: break;

        }
        switch(activeWorld)
        {
            case MENUWORLD:
                if(oMap->updateframe(xframeSpeed,yframeSpeed,false))
                {
                    ;
                }
                oMap->loadMapLevel11(rR);
                oMenuWorld->doTheJob(mainEvent,oMusic);
                oMenuWorld->MenuWorldDraw(rR);
                break;
            case GAMEOVER:
                Life=5000;
                if(oMap->updateframe(0,-300,false))
                {
                    ;
                }
                oMap->loadMapLevel11(rR);
                oText->Draw(rR,"GAME OVER",525,400,32);
                if(mainEvent->key.keysym.sym==SDLK_ESCAPE)
                {
                    activeWorld=MENUWORLD;
                    oMenuWorld->resetMainMenu_Lock();
                }
                break;

            case GAMEWORLD:
                if(oMap->updateframe(xframeSpeed,yframeSpeed,true))
                {
                    ;
                }

                oMap->loadMapGame(rR);

                oMap->oPlayer->Update();
                oMap->loadMapRoad(rR);

                // declaring output string stream

                // Sending a number as a stream into output
                // string

                if(oMap->detectCollision())
                {
                    oMusic->setVolume(foregroundVol);
                    oMusic->PlayChunk(oMusic->cFIRE);
                    oMusic->setVolume(backgroundVol);
                    --Life;
                }
                str1.str("");
                //str1.clear();
                str1 <<Life;
                // the str() coverts number into string
                geek.assign("CATWOMAN LIFE : ");
                geek.append(str1.str());
                geek.append("    BATMAN LIFE : ");
                temp=BatLife;
                str1.str("");
                str1<<temp;

                geek.append(str1.str());

                oText->Draw(rR,geek,600,50);

                if(oMap->oBatman->getActiveStat())
                {
                    BatLife-=0.01;
                   if(oMap->oBatman->FLY)
                    {
                      //  std::cout<<"ITS STILL FLYING";
                        oMap->oBatman->setMoveSpeed(1);
                        oMap->oBatman->flyBatman();
                    }
                    else if(Node==0&&!oMap->oBatman->SLAP)
                    {
                        if(oMap->oBatman->getXPos()>oMap->oPlayer->getXPos())
                        {
                            oMap->oBatman->setMoveDirection(false);
                            oMap->oBatman->setMoveSpeed(0);
                            oMap->oBatman->bMove=false;
                            if((oMap->oBatman->getXPos()-oMap->oPlayer->getXPos())>150)
                            {
                                oMap->oBatman->bMove=true;
                                oMap->oBatman->setMoveSpeed(-1);
                                oMap->oBatman->moveBatman();
                            }
                            else if(oMap->oPlayer->bMove)
                            {
                                oMap->oBatman->bMove=true;
                                oMap->oBatman->moveBatman();
                            }
                            else if(Node!=3)
                                oMap->oBatman->setBatmanSpriteID(0);
                        }
                        else if(oMap->oBatman->getXPos()<oMap->oPlayer->getXPos())
                        {
                            oMap->oBatman->setMoveDirection(true);
                            oMap->oBatman->setMoveSpeed(0);
                            oMap->oBatman->bMove=false;
                            if((oMap->oPlayer->getXPos()-oMap->oBatman->getXPos())>150)
                            {
                                oMap->oBatman->bMove=true;
                                oMap->oBatman->setMoveSpeed(1);
                                oMap->oBatman->moveBatman();

                            }
                            else if(oMap->oPlayer->bMove)
                            {
                                oMap->oBatman->bMove=true;
                                oMap->oBatman->moveBatman();
                            }
                            else if(Node!=3)
                            oMap->oBatman->setBatmanSpriteID(0);
                        }

                    }
                    if(!Node&&!oMap->oBatman->STRUCK&&!oMap->oPlayer->STRUCK&&!oMap->oBatman->SLAP
                    &&oMap->oBatman->FIGHTMODE&&!(rand()%500))
                    {
                        oMap->oBatman->bMove=false;
                        oMap->oBatman->RIGHT_MOVE=false,oMap->oBatman->LEFT_MOVE=false,
                        oMap->oBatman->UP_MOVE=false,oMap->oBatman->DOWN_MOVE=false,
                        oMap->oBatman->SLAP=true,oMap->oBatman->STRUCK=false;
                        oMap->oPlayer->SLAP=false;oMap->oPlayer->STRUCK=false;
                        oMusic->setVolume(foregroundVol);
                        oMusic->PlayChunk(oMusic->cCOIN);
                        oMusic->setVolume(backgroundVol);
                        oMap->oBatman->setBatmanSpriteID(oMap->oBatman->inthitStart);
                        oMap->oBatman->FIGHTMODE=true;
                    }

                    if(!Node&&oMap->oBatman->SLAP)
                    {
                        if(oMap->oBatman->hitBatman())
                        {

                            if(oMap->oBatman->moveDirection&&-oMap->oBatman->getXPos()+oMap->oPlayer->getXPos()<100)
                            {
                                        oMap->oPlayer->bMove=false;
                                        oMap->oPlayer->RIGHT_MOVE=false,oMap->oPlayer->LEFT_MOVE=false,
                                        oMap->oPlayer->SLAP=false;
                                        oMap->oPlayer->STRUCK=true;
                                        oMap->oBatman->SLAP=false;
                                        oMap->oBatman->bMove=false;
                                        oMap->oBatman->STRUCK=false;
                                        oMap->oPlayer->setMoveSpeed(0);
                                        Life-=100;
                                        oMusic->setVolume(foregroundVol);
                                        oMusic->PlayChunk(oMusic->cMUSHROOMMEAT);
                                        oMusic->setVolume(backgroundVol);
                                        oMap->oPlayer->setCatwomanSpriteID(oMap->oPlayer->intStruck);


                            }
                            else if(!Node&&!oMap->oBatman->moveDirection&&oMap->oBatman->getXPos()-oMap->oPlayer->getXPos()<100)
                            {

                                        oMap->oPlayer->bMove=false;
                                        oMap->oPlayer->RIGHT_MOVE=false,oMap->oPlayer->LEFT_MOVE=false,
                                        oMap->oPlayer->SLAP=false;
                                        oMap->oPlayer->STRUCK=true;
                                        oMap->oBatman->SLAP=false;
                                        oMap->oBatman->bMove=false;
                                        oMap->oBatman->STRUCK=false;
                                        oMap->oPlayer->setMoveSpeed(0);
                                        Life-=100;
                                        oMusic->setVolume(foregroundVol);
                                        oMusic->PlayChunk(oMusic->cMUSHROOMMEAT);
                                        oMusic->setVolume(backgroundVol);
                                        oMap->oPlayer->setCatwomanSpriteID(oMap->oPlayer->intStruck);

                            }
                        }
                    }

                    if(oMap->oBatman->getYPos()>oMap->oPlayer->getYPos())
                    {
                        oMap->oPlayer->Draw(rR);
                        oMap->oBatman->Draw(rR);
                    }
                    else
                    {
                        oMap->oBatman->Draw(rR);
                        oMap->oPlayer->Draw(rR);
                    }
                }
                else oMap->oPlayer->Draw(rR);
                if(Node==1)
                {
                    oText->Draw(rR,"BANE HAS WARNED THE RESIDENTS NOT TO LEAVE GOTHAM",50,200,8);
                    oText->Draw(rR,"CATWOMAN IS TRYING TO ESCAPE",50,212,8);
                }
                else if(Node==2)
                {
                    oMap->oPlayer->bMove=false;
                    oMap->oPlayer->setMoveSpeed(0);
                    oMap->oBatman->bMove=false;
                    oMap->oBatman->setMoveSpeed(0);
                    xframeSpeed=0;
                    yframeSpeed=0;

                }

                if(Node==2&&mainEvent->type==SDL_KEYDOWN&&mainEvent->key.keysym.sym==SDLK_n)
                {
                    Node=0;
                }
                if(Node==1&&mainEvent->type==SDL_KEYDOWN)
                    Node=0;
                if(Node==0&&Life<=0)
                {
                    activeWorld=GAMEOVER;
                    seenHalf=false;
                    oMap->oBatman->FIGHTMODE=false;
                    oMap->oBatman->bMove=false;
                    oMap->oBatman->setActiveStat(false);
                    oMap->oBatman->setXPos(0);
                    oMap->oBatman->setYPos(200);

                    oMap->oPlayer->setCatwomanSpriteID(0);
                    oMenuWorld->resetMainMenu_Lock();
                    oMap->setMapParams(5*WIN_HEIGHT,WIN_WIDTH,0,0);
                    xframeSpeed=0;
                    yframeSpeed=-300;
                    oMap->oPlayer->setXPos(84);
                    oMap->oPlayer->setYPos(468);
                    oMap->oPlayer->setMoveDirection(true);
                    oMap->oPlayer->bMove=false;
                    oMap->oPlayer->RIGHT_MOVE=false,oMap->oPlayer->LEFT_MOVE=false,
                    oMap->oPlayer->UP_MOVE=false,oMap->oPlayer->DOWN_MOVE=false,
                    oMap->oPlayer->SLAP=false,oMap->oPlayer->STRUCK=false;
                    Life=5000;
                    BatLife=4999;
                    break;
                }

                else if(!Node&&mainEvent->type==SDL_KEYDOWN&& mainEvent->key.keysym.sym==SDLK_ESCAPE)
                {


                        Life=5000;
                        BatLife=4999;
                        oMap->oBatman->FIGHTMODE=false;
                        oMap->oBatman->SLAP=false;

                        seenHalf=false;
                        oMap->oBatman->bMove=false;
                        oMap->oBatman->setActiveStat(false);
                        oMap->oBatman->setXPos(0);
                        oMap->oBatman->setYPos(200);

                        activeWorld=MENUWORLD;
                        oMenuWorld->resetMainMenu_Lock();
                        oMap->setMapParams(5*WIN_HEIGHT,WIN_WIDTH,0,0);
                        xframeSpeed=0;
                        yframeSpeed=-300;
                        oMap->oPlayer->setCatwomanSpriteID(0);
                        oMap->oPlayer->setXPos(84);
                        oMap->oPlayer->setYPos(468);
                        oMap->oPlayer->setMoveDirection(true);
                        oMap->oPlayer->bMove=false;
                        oMap->oPlayer->RIGHT_MOVE=false,oMap->oPlayer->LEFT_MOVE=false,
                        oMap->oPlayer->UP_MOVE=false,oMap->oPlayer->DOWN_MOVE=false,
                        oMap->oPlayer->SLAP=false,oMap->oPlayer->STRUCK=false;
                        break;
                }

                if(!Node&&!oMap->oPlayer->STRUCK&&!oMap->oPlayer->SLAP&&mainEvent->type==SDL_KEYDOWN&&mainEvent->key.keysym.sym==SDLK_SPACE)
                {
                    oMap->oPlayer->bMove=false;
                    oMap->oPlayer->RIGHT_MOVE=false,oMap->oPlayer->LEFT_MOVE=false,
                    oMap->oPlayer->UP_MOVE=false,oMap->oPlayer->DOWN_MOVE=false,
                    oMap->oPlayer->SLAP=true,oMap->oPlayer->STRUCK=false;
                    oMusic->setVolume(foregroundVol);
                    oMusic->PlayChunk(oMusic->cCOIN);
                    oMusic->setVolume(backgroundVol);
                    oMap->oPlayer->setCatwomanSpriteID(oMap->oPlayer->inthitStart);
                    if(oMap->oBatman->getActiveStat()&&!oMap->oBatman->FLY)
                        oMap->oBatman->FIGHTMODE=true;
                }
                if(!Node&&!oMap->oPlayer->STRUCK&&!oMap->oPlayer->RIGHT_MOVE&&mainEvent->type==SDL_KEYDOWN&&mainEvent->key.keysym.sym==SDLK_RIGHT)
                {
                    oMap->oPlayer->bMove=true;
                    oMap->oPlayer->RIGHT_MOVE=true,oMap->oPlayer->LEFT_MOVE=false,oMap->oPlayer->SLAP=false;
                    oMap->oPlayer->setMoveDirection(true);
                }
                if(!Node&&!oMap->oPlayer->STRUCK&&!oMap->oPlayer->LEFT_MOVE&&mainEvent->type==SDL_KEYDOWN&&mainEvent->key.keysym.sym==SDLK_LEFT)
                {
                    oMap->oPlayer->bMove=true;
                    oMap->oPlayer->RIGHT_MOVE=false,oMap->oPlayer->LEFT_MOVE=true,oMap->oPlayer->SLAP=false;
                    oMap->oPlayer->setMoveDirection(false);

                }
                if(!Node&&!oMap->oPlayer->STRUCK&&!oMap->oPlayer->UP_MOVE&&mainEvent->type==SDL_KEYDOWN&&mainEvent->key.keysym.sym==SDLK_UP)
                {

                    if(oMap->oBatman->getActiveStat()&&!oMap->oBatman->FLY)
                    {
                        if(oMap->oPlayer->getXPos()+100<oMap->oBatman->getXPos()||oMap->oPlayer->getXPos()>oMap->oBatman->getXPos()+100)
                        {
                            oMap->oPlayer->UP_MOVE=true,oMap->oPlayer->DOWN_MOVE=false,
                            oMap->oPlayer->SLAP=false,oMap->oPlayer->STRUCK=false;
                        }
                    }
                    else
                    {
                        oMap->oPlayer->UP_MOVE=true,oMap->oPlayer->DOWN_MOVE=false,
                        oMap->oPlayer->SLAP=false,oMap->oPlayer->STRUCK=false;

                    }
                }
                if(Node==0&&!oMap->oPlayer->STRUCK&&!oMap->oPlayer->DOWN_MOVE&&mainEvent->type==SDL_KEYDOWN&&mainEvent->key.keysym.sym==SDLK_DOWN)
                {

                    if(oMap->oBatman->getActiveStat()&&!oMap->oBatman->FLY)
                    {
                        if(oMap->oPlayer->getXPos()+100<oMap->oBatman->getXPos()||oMap->oPlayer->getXPos()>oMap->oBatman->getXPos()+100)
                        {

                            oMap->oPlayer->UP_MOVE=false,oMap->oPlayer->DOWN_MOVE=true,oMap->oPlayer->SLAP=false,
                            oMap->oPlayer->STRUCK=false;
                        }
                    }
                    else
                    {
                            oMap->oPlayer->UP_MOVE=false,oMap->oPlayer->DOWN_MOVE=true,oMap->oPlayer->SLAP=false,
                            oMap->oPlayer->STRUCK=false;
                    }
                }

                if(Node==0&&oMap->oPlayer->RIGHT_MOVE&&mainEvent->type==SDL_KEYUP&&mainEvent->key.keysym.sym==SDLK_RIGHT)
                {
                    oMap->oPlayer->setCatwomanSpriteID(0);
                    oMap->oPlayer->RIGHT_MOVE=false;
                    oMap->oPlayer->bMove=false;
                    xframeSpeed=0;
                    oMap->oPlayer->bMove=false;
                    oMap->oPlayer->setMoveSpeed(0);
                }

                if(Node==0&&oMap->oPlayer->LEFT_MOVE&&mainEvent->type==SDL_KEYUP&&mainEvent->key.keysym.sym==SDLK_LEFT)
                {
                    oMap->oPlayer->setCatwomanSpriteID(0);
                    oMap->oPlayer->LEFT_MOVE=false;
                    oMap->oPlayer->bMove=false;
                    xframeSpeed=0;
                    oMap->oPlayer->bMove=false;
                    oMap->oPlayer->setMoveSpeed(0);
                }
                if(Node==0&&mainEvent->type==SDL_KEYUP&&mainEvent->key.keysym.sym==SDLK_UP)
                {
                    oMap->oPlayer->UP_MOVE=false;
                }
                if(Node==0&&mainEvent->type==SDL_KEYUP&&mainEvent->key.keysym.sym==SDLK_DOWN)
                {
                    oMap->oPlayer->DOWN_MOVE=false;
                }

                if(Node==0&&oMap->oPlayer->SLAP==true)
                {
                    oMap->oPlayer->setMoveSpeed(0);
                    xframeSpeed=0;
                }
                if(Node==0&&oMap->oPlayer->RIGHT_MOVE&&oMap->oPlayer->bMove)
                {
                    if(oMap->oPlayer->getXPos()>WIN_WIDTH*0.6)
                    {
                        oMap->oPlayer->setMoveSpeed(0);
                        xframeSpeed=300;
                    }
                    else if(oMap->oPlayer->getXPos()<WIN_WIDTH*0.6)

                    {
                        oMap->oPlayer->setMoveSpeed(1);
                        xframeSpeed=0;
                    }
                }
                if(Node==0&&oMap->oPlayer->LEFT_MOVE&&oMap->oPlayer->bMove)
                {
                    if(oMap->oPlayer->getXPos()<WIN_WIDTH*0.3)
                    {
                        oMap->oPlayer->setMoveSpeed(0);
                        xframeSpeed=-300;
                    }
                    else  if(oMap->oPlayer->getXPos()>WIN_WIDTH*0.3)

                    {
                        oMap->oPlayer->setMoveSpeed(-1);
                        xframeSpeed=0;
                    }
                }
                if(Node==0&&oMap->oPlayer->UP_MOVE)
                {
                    if(oMap->oPlayer->getYPos()>460)
                        oMap->oPlayer->moveinYPos(-1);
                }
                if(Node==0&&oMap->oPlayer->DOWN_MOVE)
                {
                    if(oMap->oPlayer->getYPos()<540)
                        oMap->oPlayer->moveinYPos(1);
                }
                if(Node==0&&!seenHalf&&!oMap->oBatman->getActiveStat()&&oMap->oPlayer->getXPos()+oMap->getframeXbegin()>
                oMap->getMapWidth()/2.0-100&&oMap->oPlayer->getXPos()+oMap->getframeXbegin()<
                oMap->getMapWidth()/2.0+100)
                {
                    //std::cout<<"ONLY ONCE SETTING";
                    seenHalf=true;
                }
                if(Node==0&&seenHalf&&!oMap->oBatman->getActiveStat()&&oMap->oPlayer->getXPos()+oMap->getframeXbegin()>oMap->getMapWidth()-WIN_WIDTH/2.0)
                {

                    oMap->oBatman->bMove=false;
                    oMap->oBatman->FLY=true;
                    oMap->oBatman->setActiveStat(true);
                }
                /*
                if(((int)BatLife)%200==0&&(Node==0||Node==1))
                {
                    //std::cout<<"Node=2";
                    Node=2;
                    oMusic->setVolume(foregroundVol);
                    oMusic->PlayChunk(oMusic->cVINE);
                    oMusic->setVolume(backgroundVol);
                }*/
                break;
            case LETSCHAT:
                Life=5000;
                if(oMap->updateframe(0,-300,false))
                {
                    ;
                }
                oMap->loadMapLevel11(rR);
                iCouple->Draw(rR,WIN_WIDTH-300,WIN_HEIGHT/2);
              //  oText->Draw(rR,"GAME OVER",525,400,32);
                if(mainEvent->key.keysym.sym==SDLK_ESCAPE)
                {
                    activeWorld=MENUWORLD;
                    oMenuWorld->resetMainMenu_Lock();
                }
                break;

            case OPTIONSWORLD:
                if(oMap->updateframe(0,-300,false))
                {
                    ;
                }
                oMap->loadMapLevel11(rR);
                oMenuWorld->MenuWorldDraw(rR);
                oText->Draw(rR,"PRESS ARROW KEYS ",100,340);
                oText->Draw(rR,"TO ADJUST VOLUME",100,365);
                if(mainEvent->key.keysym.sym==SDLK_ESCAPE)
                {
                    activeWorld=MENUWORLD;
                    oMenuWorld->resetMainMenu_Lock();
                }
                else if(mainEvent->key.keysym.sym==SDLK_UP)
                {
                    if(backgroundVol<117)
                        backgroundVol+=0.1;
                    oMusic->setVolume(backgroundVol);
                }
                if(mainEvent->key.keysym.sym==SDLK_DOWN)
                {
                    if(backgroundVol>1)
                        backgroundVol-=0.1;
                    oMusic->setVolume(backgroundVol);
                }
                break;
            case ABOUTWORLD:
                if(oMap->updateframe(xframeSpeed,yframeSpeed,false))
                {
                    ;
                }
                oMap->loadMapLevel11(rR);
                oMenuWorld->MenuWorldDraw(rR);
                iAbout->Draw(rR,60,340);
                Game::oText->Draw(rR,"Boyfriend MATHEW PRESENTS",0,0);
                if(mainEvent->key.keysym.sym==SDLK_ESCAPE)
                {
                    activeWorld=MENUWORLD;

                    oMenuWorld->resetMainMenu_Lock();
                }
                break;
            case QUITWORLD:
                if(oMap->updateframe(xframeSpeed,yframeSpeed,false))
                {
                    ;
                }
                oMap->loadMapLevel11(rR);
                quitGame=true;

            default:

                if(oMap->updateframe(xframeSpeed,yframeSpeed,false))
                {
                    ;
                }
                oMap->loadMapLevel11(rR);
                break;
        }
        activeWorld=oMenuWorld->getDecision(activeWorld,oMap,oMusic);
        SDL_RenderPresent(rR);

    }

}

void Game::waitforkeystroke()
{

	SDL_PollEvent(mainEvent);
	while(mainEvent->type!=SDL_KEYDOWN)
	{
		SDL_PollEvent(mainEvent);
	}
}

Game::~Game()
{
    if(oMenuWorld!=NULL)
    {
        delete oMenuWorld;
        oMenuWorld=NULL;
    }
    if(mainEvent!=NULL)
    {
        delete mainEvent;
        mainEvent=NULL;
    }
    if(oMap!=NULL)
    {
        delete oMap;
        oMap=NULL;
    }
    if(iAbout!=NULL)
    {
        delete iAbout;
        iAbout=NULL;
    }
    if(iCouple!=NULL)
    {
        delete iCouple;
        iCouple=NULL;
    }
    if(oText!=NULL)
    {
        delete oText;
        oText=NULL;
    }
	SDL_DestroyRenderer(rR);
	SDL_DestroyWindow(window);
    //dtor
}
