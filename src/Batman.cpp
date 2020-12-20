#include "Batman.h"

#include "Player.h"
#include "Game.h"
Batman::Batman()
{
    //ctor
}
Batman::Batman(SDL_Renderer *rR,float fXPos,float fYPos)
{
    this->fXPos=fXPos;
    this->fYPos=fYPos;
    this->iSpriteID=0;
    this->iFrameID=0;
    this->bMove=false;
    this->RIGHT_MOVE=false;
    this->LEFT_MOVE=false;
    this->UP_MOVE=false;
    this->DOWN_MOVE=false;
    this->SLAP=false;
    this->STRUCK=false;
    this->FLY=false;
    this->FIGHTMODE=false;
    this->moveDirection=true;
    this->currentMaxMove=4;
    this->moveSpeed=1;



 	// ----- LOAD SPRITE
	std::vector<std::string> tempS;
	std::vector<unsigned int> tempI;

	srand((unsigned)time(NULL));

	// ----- 0
	tempS.push_back("batmanstanding");//catwomanGirlfriend");
	tempI.push_back(0);
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
    intmoveStart=1;
	tempS.push_back("batmanrunning1");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 2
	tempS.push_back("batmanrunning2");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 3
	tempS.push_back("batmanrunning3");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("batmanrunning4");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("batmanrunning5");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("batmanrunning6");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	intmoveEnd=6;
	inthitStart=7;
	tempS.push_back("batmanhit1");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("batmanhit2");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
    tempS.push_back("batmanhit3");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("batmanhit4");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	inthitEnd=10;
    intflyStart=11;
    tempS.push_back("batmanflying1");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("batmanflying2");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
    intflyEnd=12;
 /*   tempS.push_back("batmanBoyfriend");
	sBatman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	intBoyfriend=13;*/
    active=false;
	// ----- 4
}
Batman::~Batman()
{
    for(std::vector<Sprite*>::iterator i = sBatman.begin(); i != sBatman.end(); i++)
    {
		delete (*i);
	}

    //dtor
}

bool Batman::getActiveStat()
{
    return active;
}

void Batman::setMoveSpeed(int moveSpeed)
{
    this->moveSpeed=moveSpeed;
}
int Batman::getBatmanSpriteID() {
	return iSpriteID;
}


void Batman::setMoveDirection(bool D)
{

    moveDirection=D;
}
void Batman::setXPos(float fXPos)
{
    this->fXPos=fXPos;
}
int Batman::getXPos()
{
    return fXPos;
}
int Batman::getYPos()
{
    return fYPos;
}
void Batman::setYPos(float fYPos)
{
    this->fYPos=fYPos;
}

bool Batman::hitBatman()
{
	if(SLAP)
	{

	    current = SDL_GetPerformanceCounter();
        float elapsedTime=(current-lastUpdate)/(float)SDL_GetPerformanceFrequency();

        updateXPos(moveSpeed);
        if(iSpriteID<inthitEnd)
        {
            if(elapsedTime>.2)
            {
                ++iSpriteID;
                lastUpdate=SDL_GetPerformanceCounter();
            }
        }
        else
        {
            if(elapsedTime>.2)
            {
                iSpriteID=inthitStart;
                SLAP=false;
                lastUpdate=SDL_GetPerformanceCounter();
                return true;
            }
        }
            //    SDL_Delay(100);
	}
	return false;
}

void Batman::moveBatman()
{

	if(bMove)
	{

	    current = SDL_GetPerformanceCounter();
        float elapsedTime=(current-lastUpdate)/(float)SDL_GetPerformanceFrequency();

        updateXPos(moveSpeed);
        if(iSpriteID<intmoveEnd)
        {
            if(elapsedTime>.1)
            {
                ++iSpriteID;
                lastUpdate=SDL_GetPerformanceCounter();
            }
        }
        else
        {
            if(elapsedTime>.1)
            {
                iSpriteID=intmoveStart;
                lastUpdate=SDL_GetPerformanceCounter();
            }
        }
            //    SDL_Delay(100);
	}
}
void Batman:: moveinYPos(float l)
{
    fYPos+=0.1*l;
}
void Batman::setBatmanSpriteID(int iID)
{
    iSpriteID=iID;
}

void Batman:: updateXPos(int moveSpeed)
{
    fXPos+=0.4*moveSpeed;
}
void Batman::setActiveStat(bool D)
{
    this->active=D;
}

void Batman::flyBatman()
{

    updateXPos(moveSpeed);
    current = SDL_GetPerformanceCounter(); current = SDL_GetPerformanceCounter();
    float elapsedTime=(current-lastUpdate)/(float)SDL_GetPerformanceFrequency();
    if(elapsedTime>.1)
    {

        if(fYPos+200<Game::WIN_HEIGHT-32*4-100)
        {
        //   float elapsedTime=(current-lastUpdate)/(float)SDL_GetPerformanceFrequenc
            setBatmanSpriteID(intflyStart);
            moveinYPos(2);
        }
        else if(fYPos+200<Game::WIN_HEIGHT-32*2)
        {
            setBatmanSpriteID(intflyEnd);
            moveinYPos(2);
        }
        else
        {
            std::cout<<"flying stopped";
            setBatmanSpriteID(0);
            bMove=false;
            FLY=false;
            setMoveSpeed(0);

        }
    }
}

void Batman::Draw(SDL_Renderer* rR)
{

		sBatman[getBatmanSpriteID()]->getTexture()->Draw(rR, (int)fXPos, (int)fYPos ,!moveDirection);
}

