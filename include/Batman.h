#ifndef BATMAN_H
#define BATMAN_H
#include "Sprite.h"

class Batman
{
    public:
        Batman();
        Batman(SDL_Renderer* rR,float fXPos,float fYPos);
        ~Batman();

        void Draw(SDL_Renderer* rR);
        void Update();
        void updateXPos(int iN);
        void updateYPos(int iN);
        void startMove();
        void resetMove();
        void stopMove();
        void setMoveDirection(bool moveDirection);
        void flyBatman();
        void StruckBatman();
        void moveBatman();
        bool hitBatman();
        void setBatmanSpriteID(int iID);
        int getBatmanSpriteID();

        int getXPos();
        void setXPos(float fXPos);
        int getYPos();
        void setYPos(float fYPos);
        int getMoveSpeed();
        void setMoveSpeed(int moveSpeed);
        bool getMove();
        bool getMoveDirection();

        Sprite* getBatmanSprite();
        float current,lastUpdate;
        bool moveDirection;
        bool bMove,RIGHT_MOVE,LEFT_MOVE,UP_MOVE,DOWN_MOVE,SLAP,STRUCK,FIGHTMODE,FLY;
        void moveinYPos(float l);
        int intflyStart,intflyEnd,inthitStart,inthitEnd,intmoveStart,intmoveEnd,intStruck,intBoyfriend;
        bool getActiveStat();
        void setActiveStat(bool);
    protected:

    private:
        std::vector<Sprite*> sBatman;
        int iSpriteID;
        float fXPos,fYPos;
        short life;
        bool active;
        static const int maxMove=4;
        int currentMaxMove;
        int moveSpeed;
        int iFrameID;
        int jumpState;
        int runState;
        float startJumpSpeed;
        float currentJumpSpeed;
        float jumpDistance;

        float currentFallingSpeed;


};

#endif // PLAYER_H
