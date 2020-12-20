#ifndef PLAYER_H
#define PLAYER_H
#include "Sprite.h"

class Player
{
    public:
        Player();
        Player(SDL_Renderer* rR,float fXPos,float fYPos);
        ~Player();

        void Draw(SDL_Renderer* rR);
        void Update();
        void playerPhysics();
        void updateXPos(int iN);
        void updateYPos(int iN);
        void powerUPAnimation();

        void moveAnimation();

        void startMove();
        void resetMove();
        void stopMove();
        void setMoveDirection(bool moveDirection);
        bool getChangeMoveDirection();
        void setChangeMoveDirection();
        void struckPlayer();
        void setCatwomanSpriteID(int iID);
        int getCatwomanSpriteID();

        int getXPos();
        void setXPos(float fXPos);
        int getYPos();
        void setYPos(float fYPos);
        int getMoveSpeed();
        void setMoveSpeed(int moveSpeed);
        bool getMove();
        bool getMoveDirection();

        Sprite* getCatwomanSprite();
        unsigned int getScore();
        float current,lastUpdate;
        bool moveDirection;
        bool bMove,RIGHT_MOVE,LEFT_MOVE,UP_MOVE,DOWN_MOVE,SLAP,STRUCK;
        bool changeMoveDirection;
        bool newMoveDirection;
        void moveinYPos(float l);
    int intmoveStart,intmoveEnd,inthitStart,intGirlfriend,inthitEnd,intStruck;

    protected:

    private:
        std::vector<Sprite*> sCatwoman;
        int iSpriteID;
        unsigned int iMoveAnimationTime;

        float fXPos,fYPos;
        short life;

        static const int maxMove=4;
        int currentMaxMove;
        int moveSpeed;
        unsigned int iTimePassed;
        unsigned int iScore;
        int iFrameID;
        int jumpState;
        int runState;
        float startJumpSpeed;
        float currentJumpSpeed;
        float jumpDistance;

        float currentFallingSpeed;

        void movePlayer();
        void hitPlayer();

};

#endif // PLAYER_H
