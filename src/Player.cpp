#include "Player.h"
#include "Game.h"

Player::Player()
{
   ;
    //ctor
}
Player::Player(SDL_Renderer *rR,float fXPos,float fYPos)
{
    this->fXPos=fXPos;
    this->fYPos=fYPos;
    this->iSpriteID=0;
    this->iScore=0;
    this->iFrameID=0;
    this->bMove=false;
    this->RIGHT_MOVE=false;
    this->LEFT_MOVE=false;
    this->UP_MOVE=false;
    this->DOWN_MOVE=false;
    this->SLAP=false;
    this->STRUCK=false;
    this->moveDirection=true;
    this->currentMaxMove=4;
    this->moveSpeed=1;
    this->changeMoveDirection=false;
    this->iTimePassed=SDL_GetTicks();
    this->iMoveAnimationTime=0;

    	// ----- LOAD SPRITE
	std::vector<std::string> tempS;
	std::vector<unsigned int> tempI;

//	srand((unsigned)time(NULL));

	// ----- 0
	tempS.push_back("catwomanstanding");//catwomanGirlfriend");
	tempI.push_back(0);
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
    intmoveStart=1;
	tempS.push_back("catwomanrunning1");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 2
	tempS.push_back("catwomanrunning2");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	// ----- 3
	tempS.push_back("catwomanrunning3");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanrunning4");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanrunning5");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanrunning6");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanrunning7");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanrunning8");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanrunning9");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanrunning10");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();

	intmoveEnd=10;
	inthitStart=11;
	tempS.push_back("catwomanhit1");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit2");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
    tempS.push_back("catwomanhit3");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit4");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit5");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit6");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit711");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit8");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit9");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit10");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	tempS.push_back("catwomanhit11");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	inthitEnd=21;
	intStruck=22;
	tempS.push_back("catwomanstruck");
	sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
	tempS.clear();
	intGirlfriend=23;
    /*
        tempS.push_back("catwomanGirlfriend");
        sCatwoman.push_back(new Sprite(rR,  tempS, tempI, true));
        tempS.clear();
    */
    // ----- 4
}
void Player::setMoveSpeed(int moveSpeed)
{
    this->moveSpeed=moveSpeed;
}
int Player::getCatwomanSpriteID() {
	return iSpriteID;
}



Player::~Player()
{
    for(std::vector<Sprite*>::iterator i = sCatwoman.begin(); i != sCatwoman.end(); i++)
    {
		delete (*i);
	}
    //dtor
}
void Player::setMoveDirection(bool D)
{

    moveDirection=D;
}
void Player::setXPos(float fXPos)
{
    this->fXPos=fXPos;
}
int Player::getXPos()
{
    return fXPos;
}
int Player::getYPos()
{
    return fYPos;
}
void Player::setYPos(float fYPos)
{
    this->fYPos=fYPos;
}
void Player::hitPlayer()
{
	if(SLAP&&!STRUCK)
	{

	    current = SDL_GetPerformanceCounter();
        float elapsedTime=(current-lastUpdate)/(float)SDL_GetPerformanceFrequency();

        updateXPos(moveSpeed);
        if(iSpriteID<inthitEnd)
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
                iSpriteID=inthitStart;
                SLAP=false;
                lastUpdate=SDL_GetPerformanceCounter();
            }
        }
            //    SDL_Delay(100);
	}
}

void Player::movePlayer()
{

	if(bMove&&!STRUCK)
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
void Player:: moveinYPos(float l)
{
    fYPos+=0.1*l;
}
void Player::setCatwomanSpriteID(int iID)
{
    iSpriteID=iID;
}

void Player:: updateXPos(int moveSpeed)
{
    fXPos+=0.4*moveSpeed;
}

void Player::Update() {
//	playerPhysics();
    hitPlayer();
	movePlayer();
	struckPlayer();
}
void Player::struckPlayer()
{
	if(STRUCK)
	{

	    current = SDL_GetPerformanceCounter();
        float elapsedTime=(current-lastUpdate)/(float)SDL_GetPerformanceFrequency();
        moveSpeed=0;
        updateXPos(moveSpeed);
            if(elapsedTime>1.5)
            {
                std::cout<<"Entered here";
                iSpriteID=inthitStart;
                STRUCK=false;
                bMove=true;
                lastUpdate=SDL_GetPerformanceCounter();
            }

            //    SDL_Delay(100);
	}
}

void Player::Draw(SDL_Renderer* rR)
{

		sCatwoman[getCatwomanSpriteID()]->getTexture()->Draw(rR, (int)fXPos, (int)fYPos ,!moveDirection);
}
