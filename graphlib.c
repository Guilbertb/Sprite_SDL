/************************************************/
/*                                              */
/* 			   GRAPHLIB.C		*/
/* Librairie graphique pour la SDL  		*/
/*						*/
/* Auteur : Pierre Louis Aublin			*/
/*				                */
/* Date : février 2006                          */
/* Modifié par Bruno Guilbert 2013              */
/************************************************/

/*
libsdl1.2-dev
apt-get install libsdl-ttf2.0-dev
apt-get install libfreetype6-dev


libsdl-image1.2-dev
*/


/* fichiers d'en-tête */
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

/* constantes de fin de programme */
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define PAUSE 50000000

enum {
  C_NOIR, C_BLEU_FONCE, C_VERT_FONCE, C_CYAN_FONCE, C_ROUGE_FONCE,
  C_MAGENTA_FONCE, C_OCRE, C_GRIS_CLAIR, C_GRIS, C_BLEU, C_VERT,
  C_CYAN, C_ROUGE, C_MAGENTA, C_JAUNE, C_BLANC,

  NB_COULEURS
};

SDL_Surface* affichage;
Uint32 couleurs[NB_COULEURS];

void initSDL(int x,int y, char titre[])
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Erreur � l'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  atexit(SDL_Quit);
  affichage = SDL_SetVideoMode(x, y, 32, SDL_SWSURFACE);

  if (affichage == NULL) {
    fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_WM_SetCaption(titre, NULL);
}


/* --------------------------------------------------------------------------
   Create_text
   --------------------------------------------------------------------------
   Fonction privee de creation de texte.
   --------------------------------------------------------------------------
   E: Position X du texte.
   E: Position Y du texte.
   E: Taille de la police.
   E: Couleur de la police (a creer avec la fonction SDL_MapRGB).
   E: Nom de la police a utiliser.
   E: Texte a rendre.
   S:
   -------------------------------------------------------------------------- */
void Create_text (
                         short x, short y,
                         short font_size, Uint32 i_color,
                         const char * p_font_face, const char * p_message)
{
   TTF_Font      *   p_font      = NULL;
   SDL_Surface   *   s_text      = NULL;
   SDL_Rect          rect_dest;
   SDL_Color         color;
 
 
 
   /* ----- Initialisation de SDL_ttf ----- */
 
   if (TTF_Init () < 0)
   {

         printf("Impossible d'initialiser SDL_ttf !\n");

 
      return;
   }
 
   /* ----- */
 
 
 
 
   /* ----- Chargement de toutes les donnees necessaires ----- */
 
   /* Recuperation des informations de couleurs. */
   color.r = (i_color & SDL_MapRGB (affichage->format, 255, 0, 0)) >> 16;
   color.g = (i_color & SDL_MapRGB (affichage->format, 0, 255, 0)) >> 8;
   color.b = (i_color & SDL_MapRGB (affichage->format, 0, 0, 255));
 
 
   /* Chargement de la police */
   p_font = TTF_OpenFont (p_font_face, font_size);
 
   if (! p_font)
   {

         printf ("Impossible de charger la police !\n" );
 
      return;
   }
 
   /* ----- */
 
 
 
 
   /* ----- Rendu du texte ----- */
 
   s_text = TTF_RenderText_Solid (p_font, p_message, color);
 
 
   /* Mise en place du message sur la surface de jeu */
   if (s_text == NULL)
   {

         printf ("Impossible de rendre le texte !\n");
   }
   else if (s_text != NULL)
   {
      rect_dest.x = x;
      rect_dest.y = y;
      rect_dest.w = s_text->w;
      rect_dest.h = s_text->h;
 
      /* On blit la surface a  l'ecran */
      SDL_BlitSurface (s_text, NULL, affichage, & rect_dest);
      SDL_FreeSurface (s_text);
   }
 
 
   /* Fermeture de la police */
   TTF_CloseFont (p_font);
 
   /* ----- */
 
 
 
 
   return;
}


void initTTF(void)
{
 /* char txt[10]="Bonjour";*/
/*  SDL_Rect text; */
  SDL_Surface *text=NULL;
  SDL_Color couleurTxt;
  TTF_Font *font;
  TTF_Init();
	
  font = TTF_OpenFont("DS-DIGI.TTF", 300);
 
  
  text = TTF_RenderText_Solid(font, "Bonjour", couleurTxt);
  SDL_BlitSurface(text, NULL, affichage, NULL);
  
}

void initCouleurs(void)
{
  couleurs[C_NOIR]          = SDL_MapRGB(affichage->format, 0x00, 0x00, 0x00);
  couleurs[C_BLEU_FONCE]    = SDL_MapRGB(affichage->format, 0x00, 0x00, 0x80);
  couleurs[C_VERT_FONCE]    = SDL_MapRGB(affichage->format, 0x00, 0x80, 0x00);
  couleurs[C_CYAN_FONCE]    = SDL_MapRGB(affichage->format, 0x00, 0x80, 0x80);
  couleurs[C_ROUGE_FONCE]   = SDL_MapRGB(affichage->format, 0x80, 0x00, 0x00);
  couleurs[C_MAGENTA_FONCE] = SDL_MapRGB(affichage->format, 0x80, 0x00, 0x80);
  couleurs[C_OCRE]          = SDL_MapRGB(affichage->format, 0x80, 0x80, 0x00);
  couleurs[C_GRIS_CLAIR]    = SDL_MapRGB(affichage->format, 0xC0, 0xC0, 0xC0);
  couleurs[C_GRIS]          = SDL_MapRGB(affichage->format, 0x80, 0x80, 0x80);
  couleurs[C_BLEU]          = SDL_MapRGB(affichage->format, 0x00, 0x00, 0xFF);
  couleurs[C_VERT]          = SDL_MapRGB(affichage->format, 0x00, 0xFF, 0x00);
  couleurs[C_CYAN]          = SDL_MapRGB(affichage->format, 0x00, 0xFF, 0xFF);
  couleurs[C_ROUGE]         = SDL_MapRGB(affichage->format, 0xFF, 0x00, 0x00);
  couleurs[C_MAGENTA]       = SDL_MapRGB(affichage->format, 0xFF, 0x00, 0xFF);
  couleurs[C_JAUNE]         = SDL_MapRGB(affichage->format, 0xFF, 0xFF, 0x00);
  couleurs[C_BLANC]         = SDL_MapRGB(affichage->format, 0xFF, 0xFF, 0xFF);
}

void attendreTouche(void)
{
  SDL_Event event;

  do
    SDL_WaitEvent(&event);
  while (event.type != SDL_QUIT && event.type != SDL_KEYDOWN);
}

int touche(void)
{
  SDL_Event event;

  do
    SDL_WaitEvent(&event);
  
  while ((event.type == SDL_KEYDOWN));

return (event.key.keysym.sym);
}





 






void actualiser(void)
{
  SDL_UpdateRect(affichage, 0, 0, 0, 0);
}

void setPixel(int x, int y, Uint32 coul)
{
  *((Uint32*)(affichage->pixels) + x + y * affichage->w) = coul;
}


Uint32 getPixel(int x,int y)
{
 return (*((Uint32*)(affichage->pixels) + x + y * affichage->w));
    
}

void setPixelVerif(int x, int y, Uint32 coul)
{
  if (x >= 0 && x < affichage->w &&
      y >= 0 && y < affichage->h)
    setPixel(x, y, coul);
}

void barre(int x, int y, int w, int h, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;

  SDL_FillRect(affichage, &r, coul);
}

void ligneHorizontale(int x, int y, int w, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = 1;

  SDL_FillRect(affichage, &r, coul);
}

void ligneVerticale(int x, int y, int h, Uint32 coul)
{
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = 1;
  r.h = h;

  SDL_FillRect(affichage, &r, coul);
}

void rectangle(int x, int y, int w, int h, Uint32 coul)
{
  ligneHorizontale(x, y, w, coul);
  ligneHorizontale(x, y + h - 1, w, coul);
  ligneVerticale(x, y + 1, h - 2, coul);
  ligneVerticale(x + w - 1, y + 1, h - 2, coul);
}

void effacerEcran(void)
{
 /* SDL_FillRect(affichage, NULL, couleurs[C_BLANC]);*/
SDL_FillRect(affichage, NULL, 0xFFFFFF);
}

void echangerEntiers(int* x, int* y)
{
  int t = *x;
  *x = *y;
  *y = t;
}

void ligne(int x1, int y1, int x2, int y2, Uint32 coul)
{
  int d, dx, dy, aincr, bincr, xincr, yincr, x, y;

  if (abs(x2 - x1) < abs(y2 - y1)) {
    /* parcours par l'axe vertical */

    if (y1 > y2) {
      echangerEntiers(&x1, &x2);
      echangerEntiers(&y1, &y2);
    }

    xincr = x2 > x1 ? 1 : -1;
    dy = y2 - y1;
    dx = abs(x2 - x1);
    d = 2 * dx - dy;
    aincr = 2 * (dx - dy);
    bincr = 2 * dx;
    x = x1;
    y = y1;

    setPixelVerif(x, y, coul);

    for (y = y1+1; y <= y2; ++y) {
      if (d >= 0) {
	x += xincr;
	d += aincr;
      } else
	d += bincr;

      setPixelVerif(x, y, coul);
    }

  } else {
    /* parcours par l'axe horizontal */

    if (x1 > x2) {
      echangerEntiers(&x1, &x2);
      echangerEntiers(&y1, &y2);
    }

    yincr = y2 > y1 ? 1 : -1;
    dx = x2 - x1;
    dy = abs(y2 - y1);
    d = 2 * dy - dx;
    aincr = 2 * (dy - dx);
    bincr = 2 * dy;
    x = x1;
    y = y1;

    setPixelVerif(x, y, coul);

    for (x = x1+1; x <= x2; ++x) {
      if (d >= 0) {
	y += yincr;
	d += aincr;
      } else
	d += bincr;

      setPixelVerif(x, y, coul);
    }
  }
}

void cercle(int cx, int cy, int rayon, int coul)
{
  int d, y, x;

  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;

  while (y >= x) {
    setPixelVerif(cx + x, cy + y, coul);
    setPixelVerif(cx + y, cy + x, coul);
    setPixelVerif(cx - x, cy + y, coul);
    setPixelVerif(cx - y, cy + x, coul);
    setPixelVerif(cx + x, cy - y, coul);
    setPixelVerif(cx + y, cy - x, coul);
    setPixelVerif(cx - x, cy - y, coul);
    setPixelVerif(cx - y, cy - x, coul);

    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }

    x++;
  }
}

void disque(int cx, int cy, int rayon, int coul)
{
  int d, y, x;

  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;

  while (y >= x) {
    ligneHorizontale(cx - x, cy - y, 2 * x + 1, coul);
    ligneHorizontale(cx - x, cy + y, 2 * x + 1, coul);
    ligneHorizontale(cx - y, cy - x, 2 * y + 1, coul);
    ligneHorizontale(cx - y, cy + x, 2 * y + 1, coul);

    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }

    x++;
  }
}

int quitter(void)
{
	int quitProgram=0;
	
	SDL_Event event;
	/* Lecture des �v�nements dans la queue d'�v�nements */
	while (SDL_PollEvent (&event))
	{
  		switch (event.type)
  		{
    		/* Evenement de fermeture d'application, on sort la boucle */
    		case SDL_QUIT:
      			quitProgram = 1;
      			break;
    	}
  	}
	
	return quitProgram;
}

void patienter(int sec)
{
	time_t temps0, temps;
	temps0=time(0);
	
	do
	{
		temps=time(0);
	} while (temps<temps0+sec);
}

void pause(void)
{
	long i=0;
	
	while (i<PAUSE) i++;
}
