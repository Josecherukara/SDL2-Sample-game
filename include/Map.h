#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "ScreenBlock.h"
#include "Gamescreenblock.h"
#include "GameScreenBlock_2.h"
#include "Player.h"
#include "Batman.h"
#include <vector>
struct glasscollision
{
    int x,y;
};
class Map
{
    public:
        Map(int,SDL_Renderer*);
        virtual ~Map();
        float getframeXbegin();
        float getMapWidth();
        void setMapParams(float MapHeight,float MapWidth,float frameXbegin,float frameYbegin);
        void loadMapLevel11(SDL_Renderer *);
        bool InitGameMap();
        void setMapParams(float MapHeight,float MapWidth);
        void createMapLevel11();
        void createMapGame();
        void createMapRoad();
        void createMapSnow();
        void setCollision();
        short detectCollision();
        void loadMapGame(SDL_Renderer *);
        void loadMapSnow(SDL_Renderer *);
        void loadMapRoad(SDL_Renderer *);
        short updateframe(float,float,bool);
        Player* getPlayer();
        Player* oPlayer;
        Batman* oBatman;
        Batman* getBatman();
        std::vector<glasscollision*> oGlassCollision;
    protected:       unsigned int iTimePassed;
        unsigned int iScore;


    private:

        float elapsedTime,frameXbegin,frameYbegin,frameXend,frameYend,MapWidth,MapHeight;
        std::string gameMap[24];
        std::string roadMap[3];
        std::vector<std::vector<ScreenBlock*> > bgmap;
        std::vector<std::vector<GameScreenBlock_2*> > bgmapgame;
        std::vector<std::vector<GameScreenBlock_2*> > bgmaproad;

        std::vector<IMG*> screenBlocktile;
        std::vector<Gamescreenblock*> gamescreenBlocktile;
};

#endif // MAP_H
