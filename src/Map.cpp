#include "Map.h"
#include "Game.h"
#include "Player.h"
#include "Sprite.h"
Map::Map(int activeworld,SDL_Renderer *rR)
{
    //ctor
    MapWidth=Game::WIN_WIDTH;
    MapHeight=5*Game::WIN_HEIGHT;
    frameXbegin=0;
    frameYbegin=0;
    frameXend=frameXbegin+Game::WIN_WIDTH+64;
    frameYend=frameYbegin+Game::WIN_HEIGHT+64;

            IMG *temp=new IMG("space1",rR);

            screenBlocktile.push_back(temp);
            temp=new IMG("space2",rR);
            screenBlocktile.push_back(temp);
            temp=new IMG("space3",rR);
            screenBlocktile.push_back(temp);
            temp=new IMG("abrick",rR);
            Gamescreenblock* gametemp=new Gamescreenblock(temp,Game::aBRICK);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("alight",rR);
            gametemp=new Gamescreenblock(temp,Game::aLIGHT);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("anightsky",rR);
            gametemp=new Gamescreenblock(temp,Game::aNIGHTSKY);
            gamescreenBlocktile.push_back(gametemp);

            temp=new IMG("apollonbrick",rR);
            gametemp=new Gamescreenblock(temp,Game::aPOLLONBRICK);
            gamescreenBlocktile.push_back(gametemp);

            temp=new IMG("apollonroad",rR);
            gametemp=new Gamescreenblock(temp,Game::aPOLLONROAD);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("aroad",rR);
            gametemp=new Gamescreenblock(temp,Game::aROAD);
            gamescreenBlocktile.push_back(gametemp);

            temp=new IMG("aroadside",rR);
            gametemp=new Gamescreenblock(temp,Game::aROADSIDE);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("awindow",rR);
            gametemp=new Gamescreenblock(temp,Game::aWINDOW);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("awindowwood",rR);
            gametemp=new Gamescreenblock(temp,Game::aWINDOWWOOD);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("apollonsky",rR);
            gametemp=new Gamescreenblock(temp,Game::aPOLLONSKY);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("apollonroadside",rR);
            gametemp=new Gamescreenblock(temp,Game::aPOLLONROADSIDE);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("apollonnight",rR);
            gametemp=new Gamescreenblock(temp,Game::aPOLLONNIGHT);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("aroadwithzebra",rR);
            gametemp=new Gamescreenblock(temp,Game::aROADWITHZEBRA);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("aglass1",rR);
            gametemp=new Gamescreenblock(temp,Game::aGLASS1);
            gamescreenBlocktile.push_back(gametemp);
            temp=new IMG("aglass2",rR);
            gametemp=new Gamescreenblock(temp,Game::aGLASS2);
            gamescreenBlocktile.push_back(gametemp);

            oPlayer = new Player(rR, 84,460);
            oBatman = new Batman(rR,0,200);
            createMapLevel11();
            InitGameMap();
            MapHeight=Game::WIN_HEIGHT;
            MapWidth=(gameMap[0].length()-1)*32;
            createMapGame();
            createMapRoad();
            MapWidth=Game::WIN_WIDTH;
            MapHeight=5*Game::WIN_HEIGHT;

}
Player* Map::getPlayer()
{
    return oPlayer;
}
float Map::getframeXbegin()
{
    return frameXbegin;
}
float Map::getMapWidth()
{
    return MapWidth;
}

Batman* Map::getBatman()
{
    return oBatman;
}
void Map::setMapParams(float MapHeight,float MapWidth,float frameXbegin,float frameYbegin)
{
    this->MapHeight=MapHeight;
    if(MapWidth==0)
        this->MapWidth=32*(gameMap[0].length()-1);
    else
        this->MapWidth=MapWidth;
    this->frameXbegin=frameXbegin;
    this->frameYbegin=frameYbegin;
    this->frameYend=frameYbegin+Game::WIN_HEIGHT;
    this->frameXend=frameXbegin+Game::WIN_WIDTH;
}
bool Map:: InitGameMap()
{
    gameMap[0]  ="............................................................................................................................................................................................................................................................................................................";
    gameMap[1]  ="............................................................................................................................................................................................................................................................................................................";
    gameMap[2]  ="............................................................................................................................................................................................................................................................................................................";
    gameMap[3]  ="............................................................................................................................................................................................................................................................................................................";
    gameMap[4]  ="..................................################################################..................................................................................................................................................................................#.......................................";
    gameMap[5]  ="..................................################################################................................................................................................................................................................................#####.....................................";
    gameMap[6]  ="..................................###3333######111111#######11111111111###########..................................................................................................................................................................................#.......................................";
    gameMap[7]  ="..................................###3333######133331#######13333333331###########..................................................................................................................................................................................#.......................................";
    gameMap[8]  ="..................................###3333######133331#######13333333331###########.....................................................................................................################.....................................................##################..............................";
    gameMap[9]  ="..................................#############111111#######11111111111###########.....................................................................................................################.....................................................#######3333#######..............................";
    gameMap[10] ="...........a......................################a###############################...............a...........................................a.........................................######3333######.......................a.............................#######3333#######................a.............";
    gameMap[11] ="...........N......................################B###############################...............N...........................................N.........................................######3333######.......................N.............................#######3333#######................N.............";
    gameMap[12] ="...........N......................################B###############################...............N.........###############...................N.........................................######3333######.......................N.............................##################................N.............";
    gameMap[13] ="...........N......................###11111########B######11111111111111111########...............N.........###############...................N.........................................################.......................N.............................##################................N.............";
    gameMap[14] ="...........N......................###13331########B######13333333333333331########...............N.........#####33333#####...................N...........##############################################.......................N......#......................##################................N.............";
    gameMap[15] ="...........N......................###13331##111###B######13333333333333331########...............N.........#####33333#####...................N...........#######################111111#################.......................N....#####....................#######1111#######................N.............";
    gameMap[16] ="...........N......................###11111##111###B######11111111111111111########...............N.........#11##33333#####...................N...........#######################111111#################.......................N......#......................#######1111#######................N.............";
    gameMap[17] ="...........N......................##########111###B###############################...............N.........#11############...................N...........#######################111111#################.......................N......#......................#######1111#######................N.............";
    gameMap[18] ="...........N......................##########111###B###############################...............N.........#11############...................N...........#######################111111#################.......................N......#......................#######1111#######................N.............";
    gameMap[19] ="22222222222P22222222222222222222222222222222222222P2222222222222222222222222222222222222222222222P2222222222222222222222222222222222222222222P22222222222222222222222222222222222222222222222222222222222222222222222222222222P222222222222222222222222222222222222222222222222222222222222222P2222222222222";
    gameMap[20] ="444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444";
    gameMap[21] ="444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444";
    gameMap[22] ="444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444";
    gameMap[23] ="222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";


    roadMap[0]  ="........................................................F.............................................................................FFFFFFFFFF...........................................................................F.........F................F...........F.......................F..............FFF";
    roadMap[1]  ="........................................................G............................F...................................................GGG...............................................F.........................G............................................G...........F....F......G.............FGFG";
    roadMap[2]  =".....................................................................................G.................................................................G..................................G.......................G.......................F..................................G.....G...................GGGF.";
    for(int i=0;i<24;++i)
    {
        gameMap[i].append(gameMap[i],0,43);
    }
    roadMap[0].append(roadMap[0],0,43);
    roadMap[1].append(roadMap[1],0,43);
    roadMap[2].append(roadMap[2],0,43);
    //|for roadwithzebra
    return true;
}

void Map::createMapGame()
{
//std::cout<<MapWidth<<"INSDIE CREATEMAPGAME1";
    unsigned m=0,n=0;
    for(int i = 0; i < MapHeight/32.0; i++)
    {
        //std::cout<<MapWidth<<"INSDIE CREATEMAPGAME2";
        if(m>23)
        {
            m=0;
        }

		std::vector<GameScreenBlock_2*> temp;
        n=0;
		for(int j = 0; j < MapWidth/32.0; j++)
		{
            if(n>gameMap[m].length()-1)
            {
                n=0;
            }
            //std::cout<<"INSDIE CREATEMAPGAME3";
            if(gameMap[m].compare(n,1,"#")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aBRICK]->id  ==Game::aBRICK)
                {
                   // std::cout<<gamescreenBlocktile[Game::aBRICK]->id <<"="<<Game::aBRICK<<"|";
                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aBRICK]);
                }
                temp.push_back(temp1);
                //else std::cout<<"Here";
            }
            else if (gameMap[m].compare(n,1,"s")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aNIGHTSKY]->id==Game::aNIGHTSKY)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aNIGHTSKY]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"2")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aROADSIDE]->id==Game::aROADSIDE)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aROADSIDE]);
		        }
		        temp.push_back(temp1);
            }
             else if (gameMap[m].compare(n,1,"B")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aPOLLONBRICK]->id==Game::aPOLLONBRICK)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aPOLLONBRICK]);
		        }
		        temp.push_back(temp1);
            }

            else if (gameMap[m].compare(n,1,"3")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aWINDOW]->id==Game::aWINDOW)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aWINDOW]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"1")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aWINDOWWOOD]->id==Game::aWINDOWWOOD)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aWINDOWWOOD]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"|")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aROADWITHZEBRA]->id==Game::aROADWITHZEBRA)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aROADWITHZEBRA]);
		        }
		        temp.push_back(temp1);
            }

            else if (gameMap[m].compare(n,1,"4")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aROAD]->id==Game::aROAD)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aROAD]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"P")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aPOLLONROADSIDE]->id==Game::aPOLLONROADSIDE)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aPOLLONROADSIDE]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"N")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aPOLLONNIGHT]->id==Game::aPOLLONNIGHT)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aPOLLONNIGHT]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"5")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aPOLLONSKY]->id==Game::aPOLLONSKY)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aPOLLONSKY]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"6")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aPOLLONROAD]->id==Game::aPOLLONROAD)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aPOLLONROAD]);
		        }
		        temp.push_back(temp1);
            }
            else if (gameMap[m].compare(n,1,"a")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aLIGHT]->id==Game::aLIGHT)
                {

                    temp1->setBlock(1,j*32,i*32,32,32,gamescreenBlocktile[Game::aLIGHT]);
		        }
		        temp.push_back(temp1);
            }

            else if (gameMap[m].compare(n,1,".")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
		        temp1->setBlock(0,j*32,i*32,32,32,NULL);
		        temp.push_back(temp1);
            }
            else
            {       std::cout<<m<<"  "<<n<<"Confused"<<gameMap[m][n]<<"ErrorBlock";
                    Game::waitforkeystroke();
            }
            //std::cout<<MapWidth<<"  "<<MapHeight<<"  "<<i*32<<"  "<<j*32<<std::endl;
            ++n;

        }
        ++m;

		bgmapgame.push_back(temp);
	}

}


void Map::createMapRoad()
{
//std::cout<<MapWidth<<"INSDIE CREATEMAPGAME1";
    unsigned int n=0;
    for(int m = 0,i=0; m < 3; m++,i++)
    {
        //std::cout<<MapWidth<<"INSDIE CREATEMAPGAME2";
        std::vector<GameScreenBlock_2*> temp;
        n=0;
        //printf("length %d \n",roadMap[m].length());
		for(int j = 0; j < MapWidth/32.0; j++)
		{
            if(n>roadMap[m].length()-1)
            {
                n=0;
            }
            //std::cout<<"INSDIE CREATEMAPGAME3";
            if(roadMap[m].compare(n,1,"F")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aGLASS1]->id  ==Game::aGLASS1)
                {
                   // std::cout<<gamescreenBlocktile[Game::aBRICK]->id <<"="<<Game::aBRICK<<"|";
                    temp1->setBlock(1,j*32,(20+i)*32,32,32,gamescreenBlocktile[Game::aGLASS1]);
                }
                temp.push_back(temp1);
                glasscollision *temp2=new glasscollision;
                temp2->x=j*32;
                temp2->y=(20+i)*32;
                oGlassCollision.push_back(temp2);

                //else std::cout<<"Here";
            }
            else if(roadMap[m].compare(n,1,"G")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aGLASS2]->id  ==Game::aGLASS2)
                {
                   // std::cout<<gamescreenBlocktile[Game::aBRICK]->id <<"="<<Game::aBRICK<<"|";
                    temp1->setBlock(1,j*32,(20+i)*32,32,32,gamescreenBlocktile[Game::aGLASS2]);
                }
                temp.push_back(temp1);
                glasscollision *temp2=new glasscollision;
                temp2->x=j*32;
                temp2->y=(20+i)*32;
                oGlassCollision.push_back(temp2);
                //else std::cout<<"Here";
            }
            else if (roadMap[m].compare(n,1,".")==0)
            {
                GameScreenBlock_2 *temp1=new GameScreenBlock_2(0,NULL);
                if(gamescreenBlocktile[Game::aROAD]->id==Game::aROAD)
                {

                    temp1->setBlock(1,j*32,(20+i)*32,32,32,gamescreenBlocktile[Game::aROAD]);
		        }
		        temp.push_back(temp1);
            }
            else
            {       std::cout<<"m "<<m<<" n "<<n<<" i "<<i<<" j "<<j<<"road Confused"<<roadMap[m][n]<<"roadErrorBlock"<<std::endl;
                    Game::waitforkeystroke();
            }
            //std::cout<<MapWidth<<"  "<<MapHeight<<"  "<<i*32<<"  "<<j*32<<std::endl;
            ++n;

        }
        bgmaproad.push_back(temp);
	}

}

short Map::detectCollision()
{

    for(unsigned int i=0;i<oGlassCollision.size();++i)
    {
//        std::cout<<oGlassCollision[i]->x<<" Player Pos "<<oPlayer->getXPos()<<std::endl;

        if(frameXbegin+oPlayer->getXPos()+150>oGlassCollision[i]->x
        &&frameXbegin+oPlayer->getXPos()<oGlassCollision[i]->x+32
        &&frameYbegin+oPlayer->getYPos()+190<oGlassCollision[i]->y+32
        &&frameYbegin+oPlayer->getYPos()+190>oGlassCollision[i]->y)
            return 1;
    }
    return 0;
}
void Map::loadMapGame(SDL_Renderer *rR)
{
    int deltafXPos=0,deltafYPos=0;
    int I=(int)(frameYbegin/32);
    int J=(int)(frameXbegin/32);
    deltafXPos=frameXbegin-bgmapgame[I][J]->getxPos(),deltafYPos=frameYbegin-bgmapgame[I][J]->getyPos();

    for(int i=I;i*32<frameYend;++i)
    {
        for(int j=J;(j-J)*32-deltafXPos<Game::WIN_WIDTH;++j)
        {
            if(bgmapgame[i][j]->isactive())
            {
                if(bgmapgame[i][j]->getBlockpointer()==NULL)
                {
                    printf("ErrorBlock");
                    Game::waitforkeystroke();
                }
                else if(bgmapgame[i][j]->getBlockpointer()->getIMGpointer()==NULL)
                {
                    printf("ErrorImage");
                    Game::waitforkeystroke();
                }
                else
                {

                    bgmapgame[i][j]->getBlockpointer()->getIMGpointer()->Draw(rR,bgmapgame[i][j]->
                    getxPos()-bgmapgame[I][J]->getxPos()-deltafXPos,bgmapgame[i][j]->getyPos()-bgmapgame[I][J]->
                    getyPos()-deltafYPos);

                 //   SDL_RenderPresent(rR);
                 //   Game::waitforkeystroke();
                 //   std::cout<<"\n i "<<i<<" j "<<j<<" J "<<J<<" pos i J"<<bgmapgame[i][J]->getxPos()<<" pos i j"<<bgmapgame[i][j]->getxPos()<<"\n";
                 //   std::cout<<bgmapgame[i][j]->getBlockpointer()->getid();
                }

            }

        }
    }

}
void Map::loadMapRoad(SDL_Renderer *rR)
{
    int deltafXPos=0,deltafYPos=0;
    int I=0;//(int)(frameYbegin/32);
    int J=(int)(frameXbegin/32);
    deltafXPos=frameXbegin-bgmaproad[I][J]->getxPos(),deltafYPos=frameYbegin-bgmaproad[I][J]->getyPos();

    for(int i=0;i<3;++i)
    {
        for(int j=J;(j-J)*32-deltafXPos<Game::WIN_WIDTH;++j)
        {
            if(bgmaproad[i][j]->isactive())
            {
                if(bgmaproad[i][j]->getBlockpointer()==NULL)
                {
                    printf("ErrorBlock");
                    Game::waitforkeystroke();
                }
                else if(bgmaproad[i][j]->getBlockpointer()->getIMGpointer()==NULL)
                {
                    printf("ErrorImage");
                    Game::waitforkeystroke();
                }
                else
                {

                   // if(bgmaproad[i][j]->getyPos()/*+bgmaproad[i][j]->getyLen()  */<oPlayer->getYPos()+200)
           //         {
                        bgmaproad[i][j]->getBlockpointer()->getIMGpointer()->Draw(rR,bgmaproad[i][j]->
                        getxPos()-bgmaproad[I][J]->getxPos()-deltafXPos,bgmaproad[i][j]->getyPos()-bgmaproad[I][J]->
                        getyPos()-deltafYPos);
                      //  oPlayer->Draw(rR);
                    //}
                    /*else
                    {
                        oPlayer->Draw(rR);

                        bgmaproad[i][j]->getBlockpointer()->getIMGpointer()->Draw(rR,bgmaproad[i][j]->
                        getxPos()-bgmaproad[I][J]->getxPos()-deltafXPos,bgmaproad[i][j]->getyPos()-bgmaproad[I][J]->
                        getyPos()-deltafYPos-bgmaproad[i][j]->getyLen()+32);
                    }
                    */
                 //   SDL_RenderPresent(rR);
                 //   Game::waitforkeystroke();
                 //   std::cout<<"\n i "<<i<<" j "<<j<<" J "<<J<<" pos i J"<<bgmapgame[i][J]->getxPos()<<" pos i j"<<bgmapgame[i][j]->getxPos()<<"\n";
                 //   std::cout<<bgmapgame[i][j]->getBlockpointer()->getid();
                }

            }

        }
    }

}

void Map::createMapSnow()
{
    ;
}
void Map::createMapLevel11()
{
    for(int i = 0; i < MapWidth/32.0+2; i++)
    {
		std::vector<ScreenBlock*> temp;
		for(int j = 0; j < MapHeight/32.0+2; j++)
		{
		    if(!(rand()%30))
		    {
		        ScreenBlock *temp1=new ScreenBlock(1,screenBlocktile[0]);
		        temp1->setBlock(1,i*32,j*32,32,32,screenBlocktile[rand()%screenBlocktile.size()]);
		        temp.push_back(temp1);

		    }
		    else
		    {
                ScreenBlock *temp1=new ScreenBlock(0,NULL);
                temp1->setBlock(0,i*32,j*32,32,32,NULL);
		        temp.push_back(temp1);
            }
        }

		bgmap.push_back(temp);
	}
}

short Map::updateframe(float x,float y,bool gameWorld)
{
    Game::current = SDL_GetPerformanceCounter();
    elapsedTime=(Game::current-Game::lastUpdate)/(float)SDL_GetPerformanceFrequency();
    Game::lastUpdate=Game::current;
    if(frameYend>MapHeight)
    {

            frameYbegin=0;//MapHeight-Game::WIN_HEIGHT;
            frameYend=frameYbegin+Game::WIN_HEIGHT;

    }
    else if(frameYbegin<0)
    {

            frameYbegin=MapHeight-Game::WIN_HEIGHT;
            frameYend=frameYbegin+Game::WIN_HEIGHT;

    }
    else
    {
        frameYbegin+=y*elapsedTime;
        frameYend+=y*elapsedTime;
    }
    if(frameXend>MapWidth)
    {
            frameXbegin=0;//MapHeight-Game::WIN_HEIGHT;
            frameXend=frameXbegin+Game::WIN_WIDTH+64;

    }
    else if(frameXbegin<0)
    {
            frameXbegin=MapWidth-Game::WIN_WIDTH;
            frameXend=frameXbegin+Game::WIN_WIDTH;

    }
    else
    {
        frameXbegin+=x*elapsedTime;
        frameXend+=x*elapsedTime;
    }

    return 0;
}
void Map::loadMapSnow(SDL_Renderer *rR)
{;}
void Map::loadMapLevel11(SDL_Renderer *rR)
{
    int deltafXPos,deltafYPos;
    deltafXPos=frameXbegin-(int)(frameXbegin/32)+64;
    deltafYPos=frameYbegin-(int)(frameYbegin/32)+64;
    for(int i=(int)(frameXbegin/32);i*32<frameXend;++i)
    {

        for(int j=(int)(frameYbegin/32);j*32<frameYend;++j)
        {
            if(bgmap[i][j]->isactive())
            {
                if(bgmap[i][j]->getIMGpointer()==NULL)
                {
                    printf("Error");
                    Game::waitforkeystroke();
                }
                else bgmap[i][j]->getIMGpointer()->Draw(rR,bgmap[i][j]->getxPos()-deltafXPos,bgmap[i][j]->getyPos()-deltafYPos);
            }
        }
    }

 }


Map::~Map()
{
    for (unsigned int i=0;i<screenBlocktile.size();++i)
        delete screenBlocktile[i];
    screenBlocktile.clear();
    for (unsigned int i=0;i<oGlassCollision.size();++i)
        delete oGlassCollision[i];
    oGlassCollision.clear();

    for(unsigned int i=0;i<bgmap.size();++i)
    {
        for(unsigned int j=0;j<bgmap[i].size();++j)
            delete bgmap[i][j];
        bgmap[i].clear();
    }
    bgmap.clear();
    for (unsigned int i=0;i<gamescreenBlocktile.size();++i)
        delete gamescreenBlocktile[i];
    gamescreenBlocktile.clear();
    for(unsigned int i=0;i<bgmap.size();++i)
    {
        for(unsigned int j=0;j<bgmap[i].size();++j)
            delete bgmapgame[i][j];
        bgmapgame[i].clear();
    }
    bgmapgame.clear();

    //dtor
}
