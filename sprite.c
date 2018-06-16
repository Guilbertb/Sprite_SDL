#include <stdio.h>
#include <stdlib.h>

#include "fourmi.c"
#include <math.h>

#include "SDL.h"
#include "graphlib.h"

void fourmi(int cx,int cy,int frame)
{

int FFWIDTH = 16;
int FFHEIGHT = 16;


Uint32 mem[FFWIDTH][FFHEIGHT];

int sprite_x,sprite_y,pos;
Uint32 couleur;
	for (sprite_y=0;sprite_y<FFHEIGHT;sprite_y++)
		for (sprite_x=0;sprite_x<FFWIDTH;sprite_x++)

		{
                mem[sprite_x][sprite_y]=getPixel(cx+sprite_x,cy+sprite_y); /*on sauve avant */
		pos=sprite_x+sprite_y*FFWIDTH;
		if ((fourmi_data[frame][pos])!=0)
                    {
                    /* on reorganise les couleurs  BVR => RVB */
                    couleur= ((fourmi_data[frame][pos] & 0xFF)<<16 )+ ((fourmi_data[frame][pos] & 0xFF00)) + ((fourmi_data[frame][pos] & 0xFF0000)>>16);
                    
                        
		    setPixel(cx+sprite_x,cy+sprite_y,couleur);

                    }
  
                }
}

int main (int argc , char ** argv)
{
unsigned char Tt;
        initSDL(800,600,"FOURMI DE LANGTON");
        effacerEcran();


fourmi(100,100,0);  

/*FlecheDroite();*/
Tt=touche();
printf("touche : %x \n",Tt);

fourmi(100,100,1);
actualiser();
Tt=touche();
printf("touche : %x \n",Tt);

fourmi(100,100,0);  
actualiser();
/*FlecheDroite();*/
Tt=touche();
printf("touche : %x \n",Tt);

fourmi(100,100,1);
actualiser();
Tt=touche();
printf("touche : %x \n",Tt);

return(EXIT_SUCCESS);
}


