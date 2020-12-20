#ifndef MENUWORLD_H
#define MENUWORLD_H
#include "Map.h"
#include"IMG.h"
#include"Music.h"
#include "Text.h"



class Menuworld
{
    public:

        Menuworld(SDL_Renderer * rR);
        virtual ~Menuworld();
        void MenuWorldDraw(SDL_Renderer * rR);
        void MainLoop();
        void setPencilColor(SDL_Renderer * rR);
        void doTheJob(SDL_Event *event, Music* oMusic);
        void resetMainMenu_Lock()
        {
            MainMenu_Lock=0;
        }
        short getDecision(short,Map*,Music* oMusic);
    protected:

    private:
        enum MainMenu_options{GAME,OPTIONS,ABOUT,QUIT};
        short optionMainMenu, MainMenu_Lock;

        IMG *iMenuworld_Logo,*iMenuworld_Logo2;
        IMG *optionSelectorIcon;
};

#endif // MENUWORLD_H
