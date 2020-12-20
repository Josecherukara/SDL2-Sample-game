#ifndef GAME_H
#define GAME_H
#include "IMG.h"
#include"Menuworld.h"
#include"Map.h"
#include"Music.h"
class Game
{
    public:
        Game();
        bool seenHalf;
        static Text *oText;

        static short Node;
        static long Life;
        static double BatLife;
        static bool quitGame;
        static int WIN_WIDTH,WIN_HEIGHT;
        static float xframeSpeed,yframeSpeed;
        static Uint64 startProgram,startGame,current,lastUpdate;
        enum {aBRICK,aLIGHT,aNIGHTSKY,aPOLLONBRICK,aPOLLONROAD,aROAD,aROADSIDE,aWINDOW,aWINDOWWOOD,
        aPOLLONSKY,aPOLLONROADSIDE,aPOLLONNIGHT,aROADWITHZEBRA,aGLASS1,aGLASS2,aNIGHT};
        enum{MENUWORLD,GAMEWORLD,OPTIONSWORLD,ABOUTWORLD,QUITWORLD,GAMEOVER,LETSCHAT};
        virtual ~Game();

        static void waitforkeystroke();
        void MainLoop();



//        bool LoadGameInstance();
    protected:

    private:

        SDL_Window *window;
        SDL_Renderer *rR;
        static SDL_Event *mainEvent;
        Map *oMap;
        Menuworld *oMenuWorld;
        IMG* iAbout;
        IMG* iCouple;
        short activeWorld;
    //    static Map* oMap;
        static bool moveActivePaddle_L_Pressed, moveActivePaddle_R_Pressed;

};

#endif // GAME_H
