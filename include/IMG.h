#ifndef IMG_H
#define IMG_H

#include "headers.h"



class IMG
{
private:
	SDL_Texture* tIMG;
	SDL_Rect rRect;

public:
	IMG(void);
	IMG(std::string fileName, SDL_Renderer* rR);
	~IMG(void);


	void Draw(SDL_Renderer * rR, int iXOffset, int iYOffset);
	void Draw(SDL_Renderer * rR, int iXOffset, int iYOffset, bool bRoate);
	void DrawVert(SDL_Renderer * rR, int iXOffset, int iYOffset);
	void Draw(SDL_Renderer * rR, SDL_Rect rCrop, SDL_Rect rRect);

	/* ----- get & set ----- */
	SDL_Texture* getIMG();
	void setIMG(std::string fileName, SDL_Renderer* rR);
	SDL_Rect getRect();
};
#endif // IMG_H
