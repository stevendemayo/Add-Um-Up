//Membres du projet : MOUAFO NJINWOUA Bill Raoul Junior et SITcHEPING GUEYAP Arthur Williams

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
int tab[7][13]={{233,233,233,233,233,233,233,233,233,233,233,233,233},{233,233,233,233,233,233,233,233,233,233,233,233,233},{233,233,233,233,233,233,233,233,233,233,233,233,233},{233,233,233,233,233,233,233,233,233,233,233,233,233},{233,233,233,233,233,233,233,233,233,233,233,233,233},{233,233,233,233,233,233,233,233,233,233,233,233,233},{233,233,233,233,233,233,233,233,233,233,233,233,233}};
int T[7][13];
SDL_Renderer* pRenderer=NULL;
int raoul,save_me=0;
FILE* Savior;
SDL_Event events;
bool isOpen=true;

//fonction retournant la somme modulo 10 des cases autour de la case cliquée
int SomeCase(int x,int y)
{
    int S=0;
    int a,b;
    if(tab[x][y]!=233)
      return(-1);
    if(x>=5 || y>=5)
      return(-1);
    if(x==y && x==0)
    {
      for(a=0;a<2;a++)
        for(b=0;b<2;b++)
        {
          if(tab[a][b]!=233 && (a!=0 || b!=0))
            S=S+tab[a][b];
        }
      return(S%10);
    }
    if(x==0 && y!=0)
    {
      for(a=0;a<2;a++)
          for(b=0;b<5;b++)
          {
              if((tab[a][b]!=233 && (a!=x || b!=y)) && (((a==x && (b==y-1 || b==y+1)) || (a==x+1 && (b==y-1 || b==y+1 || b==y)))))
                S=S+tab[a][b];
          }
      return(S%10);
    }
    if(x!=0 && y==0)
    {
      for(a=0;a<5;a++)
          for(b=0;b<2;b++)
          {
              if((tab[a][b]!=233 && (a!=x || b!=y)) && (((b==y && (a==x-1 || a==x+1)) || (b==y+1 && (a==x-1 || a==x+1 || a==x)))))
                S=S+tab[a][b];
          }
      return(S%10);
    }
    if(x!=0 && y!=0)
    {
        for(a=0;a<5;a++)
            for(b=0;b<5;b++)
            {
                if((tab[a][b]!=233 && (a!=x || b!=y)) && ((a==x-1 && (b==y-1 || b==y || b==y+1) || (a==x && (b==y-1 || b==y+1)) || (a==x+1 &&(b==y-1 || b==y || b==y+1)))))
                S=S+tab[a][b];
            }
      return(S%10);
    }
}
//fonction gérant les fonds d'écran (il y'en a 10 en tout)
void fond()
{
    SDL_Surface* cadre = SDL_LoadBMP("cadre.bmp");

    if(raoul==0)
            {
               SDL_Surface* fond1 = SDL_LoadBMP("fond1.bmp");
               SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond1->format,255,255,255));
               SDL_Texture* pTextureFond1 = SDL_CreateTextureFromSurface(pRenderer, fond1);
               SDL_FreeSurface(fond1);
               SDL_Rect srcf1 = {0, 0, 0, 0};
               SDL_QueryTexture(pTextureFond1, NULL, NULL,&srcf1.w, &srcf1.h);
               SDL_Rect dstf1 = { 0, 0, 13*60, 7*60 };
               SDL_RenderCopy(pRenderer, pTextureFond1, &srcf1, &dstf1);
            }
            if(raoul==1)
            {
                SDL_Surface* fond2 = SDL_LoadBMP("fond2.bmp");
                SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond2->format,255,255,255));
                SDL_Texture* pTextureFond2 = SDL_CreateTextureFromSurface(pRenderer, fond2);
                SDL_FreeSurface(fond2);
                SDL_Rect srcf2 = {0, 0, 0, 0};
                SDL_QueryTexture(pTextureFond2, NULL, NULL,&srcf2.w, &srcf2.h);
                SDL_Rect dstf2 = { 0, 0, 13*60, 7*60 };
                SDL_RenderCopy(pRenderer, pTextureFond2, &srcf2, &dstf2);
            }
            if(raoul==2)
            {
                SDL_Surface* fond3 = SDL_LoadBMP("fond3.bmp");
                SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond3->format,255,255,255));
                SDL_Texture* pTextureFond3 = SDL_CreateTextureFromSurface(pRenderer, fond3);
                SDL_FreeSurface(fond3);
                SDL_Rect srcf3 = {0, 0, 0, 0};
                SDL_QueryTexture(pTextureFond3, NULL, NULL,&srcf3.w, &srcf3.h);
                SDL_Rect dstf3 = { 0, 0, 13*60, 7*60 };
                SDL_RenderCopy(pRenderer, pTextureFond3, &srcf3, &dstf3);
            }
            if(raoul==3)
            {
               SDL_Surface*  fond4 = SDL_LoadBMP("fond4.bmp");
               SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond4->format,255,255,255));
               SDL_Texture* pTextureFond4 = SDL_CreateTextureFromSurface(pRenderer, fond4);
               SDL_FreeSurface(fond4);
               SDL_Rect srcf4 = {0, 0, 0, 0};
               SDL_QueryTexture(pTextureFond4, NULL, NULL,&srcf4.w, &srcf4.h);
               SDL_Rect dstf4 = { 0, 0, 13*60, 7*60 };
               SDL_RenderCopy(pRenderer, pTextureFond4, &srcf4, &dstf4);
            }
            if(raoul==4)
            {
                SDL_Surface* fond5 = SDL_LoadBMP("fond5.bmp");
                SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond5->format,255,255,255));
                SDL_Texture* pTextureFond5 = SDL_CreateTextureFromSurface(pRenderer, fond5);
                SDL_FreeSurface(fond5);
                SDL_Rect srcf5 = {0, 0, 0, 0};
                SDL_QueryTexture(pTextureFond5, NULL, NULL,&srcf5.w, &srcf5.h);
                SDL_Rect dstf5 = { 0, 0, 13*60, 7*60 };
                SDL_RenderCopy(pRenderer, pTextureFond5, &srcf5, &dstf5);
            }
            if(raoul==5)
            {
                 SDL_Surface* fond6 = SDL_LoadBMP("fond6.bmp");
                 SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond6->format,255,255,255));
                 SDL_Texture* pTextureFond6 = SDL_CreateTextureFromSurface(pRenderer, fond6);
                 SDL_FreeSurface(fond6);
                 SDL_Rect srcf6 = {0, 0, 0, 0};
                 SDL_QueryTexture(pTextureFond6, NULL, NULL,&srcf6.w, &srcf6.h);
                 SDL_Rect dstf6 = { 0, 0, 13*60, 7*60 };
                 SDL_RenderCopy(pRenderer, pTextureFond6, &srcf6, &dstf6);
            }
            if(raoul==6)
            {
                SDL_Surface* fond7 = SDL_LoadBMP("fond7.bmp");
                SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond7->format,255,255,255));
                SDL_Texture* pTextureFond7 = SDL_CreateTextureFromSurface(pRenderer, fond7);
                SDL_FreeSurface(fond7);
                SDL_Rect srcf7 = {0, 0, 0, 0};
                SDL_QueryTexture(pTextureFond7, NULL, NULL,&srcf7.w, &srcf7.h);
                SDL_Rect dstf7 = { 0, 0, 13*60, 7*60 };
                SDL_RenderCopy(pRenderer, pTextureFond7, &srcf7, &dstf7);
            }
            if(raoul==7)
            {
                SDL_Surface* fond8 = SDL_LoadBMP("fond8.bmp");
                SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond8->format,255,255,255));
                SDL_Texture* pTextureFond8 = SDL_CreateTextureFromSurface(pRenderer, fond8);
                SDL_FreeSurface(fond8);
                SDL_Rect srcf8 = {0, 0, 0, 0};
                SDL_QueryTexture(pTextureFond8, NULL, NULL,&srcf8.w, &srcf8.h);
                SDL_Rect dstf8 = { 0, 0, 13*60, 7*60 };
                SDL_RenderCopy(pRenderer, pTextureFond8, &srcf8, &dstf8);
            }
            if(raoul==8)
            {
                SDL_Surface* fond9 = SDL_LoadBMP("fond9.bmp");
                SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond9->format,255,255,255));
                SDL_Texture* pTextureFond9 = SDL_CreateTextureFromSurface(pRenderer, fond9);
                SDL_FreeSurface(fond9);
                SDL_Rect srcf9 = {0, 0, 0, 0};
                SDL_QueryTexture(pTextureFond9, NULL, NULL,&srcf9.w, &srcf9.h);
                SDL_Rect dstf9 = { 0, 0, 13*60, 7*60 };
                SDL_RenderCopy(pRenderer, pTextureFond9, &srcf9, &dstf9);
            }
            if(raoul==9)
            {
                SDL_Surface* fond10 = SDL_LoadBMP("fond10.bmp");
                SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond10->format,255,255,255));
                SDL_Texture* pTextureFond10 = SDL_CreateTextureFromSurface(pRenderer, fond10);
                SDL_FreeSurface(fond10);
                SDL_Rect srcf10 = {0, 0, 0, 0};
                SDL_QueryTexture(pTextureFond10, NULL, NULL,&srcf10.w, &srcf10.h);
                SDL_Rect dstf10 = { 0, 0, 13*60, 7*60 };
                SDL_RenderCopy(pRenderer, pTextureFond10, &srcf10, &dstf10);
            }
    SDL_Texture* pTextureCadre = SDL_CreateTextureFromSurface(pRenderer, cadre);
    SDL_FreeSurface(cadre);
    SDL_Rect src = {0, 0, 0, 0};
    SDL_QueryTexture(pTextureCadre, NULL, NULL,&src.w, &src.h);
}

//fonction qui affecte la valeur 233 à la case cliquée et ses cases voisines 233 est ici la valeur désignant une case vide
void Destruct(int x, int y)
{
    SDL_Surface* cadre = SDL_LoadBMP("cadre.bmp");
    SDL_Texture* pTextureCadre = SDL_CreateTextureFromSurface(pRenderer, cadre);
    SDL_FreeSurface(cadre);
    SDL_Rect src = {0, 0, 0, 0};
    SDL_QueryTexture(pTextureCadre, NULL, NULL,&src.w, &src.h);
    int a,b;
    if(x==y && x==0)
    {
      for(a=0;a<2;a++)
        for(b=0;b<2;b++)
        {
          if(tab[a][b]!=233)
          {
              tab[a][b]=233;
              SDL_Delay(100);
              raoul=rand()%10;
              Affich();
              SDL_Delay(100);
          }
        }
    }
    if(x==0 && y!=0)
    {
      for(a=0;a<2;a++)
          for(b=0;b<5;b++)
          {
              if(tab[a][b]!=233 && (((a==x && (b==y-1 || b==y+1 || b==y)) || (a==x+1 && (b==y-1 || b==y+1 || b==y)))))
              {
                  tab[a][b]=233;
                  SDL_Delay(100);
                  raoul=rand()%10;
                  Affich();
                  SDL_Delay(100);
              }
          }
    }
    if(x!=0 && y==0)
    {
      for(a=0;a<5;a++)
          for(b=0;b<2;b++)
          {
              if(tab[a][b]!=233 && (((b==y && (a==x-1 || a==x+1 || a==x)) || (b==y+1 && (a==x-1 || a==x+1 || a==x)))))
              {
                  tab[a][b]=233;
                  SDL_Delay(100);
                  raoul=rand()%10;
                  Affich();
                  SDL_Delay(100);
              }
          }
    }
    if(x!=0 && y!=0)
    {
        for(a=0;a<5;a++)
            for(b=0;b<5;b++)
            {
                if(tab[a][b]!=233 && ((a==x-1 && (b==y-1 || b==y || b==y+1)) || (a==x && (b==y-1 || b==y+1 || b==y)) || (a==x+1 &&(b==y-1 || b==y || b==y+1))))
              {
                  tab[a][b]=233;
                  SDL_Delay(100);
                  raoul=rand()%10;
                  Affich();
                  SDL_Delay(100);
              }
            }
    }
}
//fonction qui vérifie la défaite, elle retourne -1 si la partie est perdue
int Luz()
{
    int x,y;
    for(x=0;x<5;x++)
       for(y=0;y<5;y++)
        {
           if(tab[x][y]==233)
             return(1);
        }
    return(-1);
}
//fonction qui vérifie la victoire, elle retourne 233 si la partie est gagnée
int Winn()
{
    int x,y;
    for(x=0;x<5;x++)
       for(y=0;y<5;y++)
        {
           if(tab[x][y]!=233)
            return(-1);
        }
    return(233);
}

//Génère 13 nombres aléatoire compris entre 0 et 9 dans la sous matrice tab[5][5] de ma matrice
void Alea()
{
    int rx,ry,k=0;
    while(k<13)
    {
        rx=rand()%5;
        ry=rand()%5;
        if(tab[rx][ry]==233)
        {
          tab[rx][ry]=rand()%10;
          k++;
        }
    }

    Affich_Case();
}
//fonction gérant l'affichage
void Affich()
{
    int x,y;

    SDL_Surface* cadre = SDL_LoadBMP("cadre.bmp");
    SDL_Surface* nom01 = SDL_LoadBMP("nom01.bmp");
    SDL_Surface* nom1 = SDL_LoadBMP("nom1.bmp");
    SDL_Surface* nom2 = SDL_LoadBMP("nom2.bmp");
    SDL_Surface* nom3 = SDL_LoadBMP("nom3.bmp");
    SDL_Surface* nom4 = SDL_LoadBMP("nom4.bmp");
    SDL_Surface* nom5 = SDL_LoadBMP("nom5.bmp");
    SDL_Surface* nom6 = SDL_LoadBMP("nom6.bmp");
    SDL_Surface* nom7 = SDL_LoadBMP("nom7.bmp");
    SDL_Surface* nom8 = SDL_LoadBMP("nom8.bmp");
    SDL_Surface* nom9 = SDL_LoadBMP("nom9.bmp");
    SDL_Surface* help = SDL_LoadBMP("help.bmp");
    SDL_Surface* exit = SDL_LoadBMP("exit.bmp");
    SDL_Surface* save = SDL_LoadBMP("save.bmp");
    SDL_Surface* before = SDL_LoadBMP("before.bmp");
    SDL_Surface* fond1 = SDL_LoadBMP("fond1.bmp");
    SDL_Surface* fond2 = SDL_LoadBMP("fond2.bmp");
    SDL_Surface* fond3 = SDL_LoadBMP("fond3.bmp");
    SDL_Surface*  fond4 = SDL_LoadBMP("fond4.bmp");
    SDL_Surface* fond5 = SDL_LoadBMP("fond5.bmp");
    SDL_Surface* fond6 = SDL_LoadBMP("fond6.bmp");
    SDL_Surface* fond7 = SDL_LoadBMP("fond7.bmp");
    SDL_Surface* fond8 = SDL_LoadBMP("fond8.bmp");
    SDL_Surface* fond9 = SDL_LoadBMP("fond9.bmp");
    SDL_Surface* fond10 = SDL_LoadBMP("fond10.bmp");

    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond1->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond2->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond3->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond4->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond5->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond6->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond7->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond8->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond9->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond10->format,255,255,255));

    fond();

    SDL_Texture* pTextureCadre = SDL_CreateTextureFromSurface(pRenderer, cadre);
    SDL_FreeSurface(cadre);
    SDL_Texture* pTextureNom01 = SDL_CreateTextureFromSurface(pRenderer, nom01);
    SDL_FreeSurface(nom01);
    SDL_Texture* pTextureNom1 = SDL_CreateTextureFromSurface(pRenderer, nom1);
    SDL_FreeSurface(nom1);
    SDL_Texture* pTextureNom2 = SDL_CreateTextureFromSurface(pRenderer, nom2);
    SDL_FreeSurface(nom2);
    SDL_Texture* pTextureNom3 = SDL_CreateTextureFromSurface(pRenderer, nom3);
    SDL_FreeSurface(nom3);
    SDL_Texture* pTextureNom4 = SDL_CreateTextureFromSurface(pRenderer, nom4);
    SDL_FreeSurface(nom4);
    SDL_Texture* pTextureNom5 = SDL_CreateTextureFromSurface(pRenderer, nom5);
    SDL_FreeSurface(nom5);
    SDL_Texture* pTextureNom6 = SDL_CreateTextureFromSurface(pRenderer, nom6);
    SDL_FreeSurface(nom6);
    SDL_Texture* pTextureNom7 = SDL_CreateTextureFromSurface(pRenderer, nom7);
    SDL_FreeSurface(nom7);
    SDL_Texture* pTextureNom8 = SDL_CreateTextureFromSurface(pRenderer, nom8);
    SDL_FreeSurface(nom8);
    SDL_Texture* pTextureNom9 = SDL_CreateTextureFromSurface(pRenderer, nom9);
    SDL_FreeSurface(nom9);
    SDL_Texture* pTextureHelp = SDL_CreateTextureFromSurface(pRenderer, help);
    SDL_FreeSurface(help);
    SDL_Texture* pTextureExit = SDL_CreateTextureFromSurface(pRenderer, exit);
    SDL_FreeSurface(exit);
    SDL_Texture* pTextureSave = SDL_CreateTextureFromSurface(pRenderer, save);
    SDL_FreeSurface(save);
    SDL_Texture* pTextureBefore = SDL_CreateTextureFromSurface(pRenderer, before);
    SDL_FreeSurface(before);
    SDL_Texture* pTextureFond1 = SDL_CreateTextureFromSurface(pRenderer, fond1);
    SDL_FreeSurface(fond1);
    SDL_Texture* pTextureFond2 = SDL_CreateTextureFromSurface(pRenderer, fond2);
    SDL_FreeSurface(fond2);
    SDL_Texture* pTextureFond3 = SDL_CreateTextureFromSurface(pRenderer, fond3);
    SDL_FreeSurface(fond3);
    SDL_Texture* pTextureFond4 = SDL_CreateTextureFromSurface(pRenderer, fond4);
    SDL_FreeSurface(fond4);
    SDL_Texture* pTextureFond5 = SDL_CreateTextureFromSurface(pRenderer, fond5);
    SDL_FreeSurface(fond5);
    SDL_Texture* pTextureFond6 = SDL_CreateTextureFromSurface(pRenderer, fond6);
    SDL_FreeSurface(fond6);
    SDL_Texture* pTextureFond7 = SDL_CreateTextureFromSurface(pRenderer, fond7);
    SDL_FreeSurface(fond7);
    SDL_Texture* pTextureFond8 = SDL_CreateTextureFromSurface(pRenderer, fond8);
    SDL_FreeSurface(fond8);
    SDL_Texture* pTextureFond9 = SDL_CreateTextureFromSurface(pRenderer, fond9);
    SDL_FreeSurface(fond9);
    SDL_Texture* pTextureFond10 = SDL_CreateTextureFromSurface(pRenderer, fond10);
    SDL_FreeSurface(fond10);

    SDL_Rect src = {0, 0, 0, 0};
    SDL_Rect src01 = {0, 0, 0, 0};
    SDL_Rect src1 = {0, 0, 0, 0};
    SDL_Rect src2 = {0, 0, 0, 0};
    SDL_Rect src3 = {0, 0, 0, 0};
    SDL_Rect src4 = {0, 0, 0, 0};
    SDL_Rect src5 = {0, 0, 0, 0};
    SDL_Rect src6 = {0, 0, 0, 0};
    SDL_Rect src7 = {0, 0, 0, 0};
    SDL_Rect src8 = {0, 0, 0, 0};
    SDL_Rect src9 = {0, 0, 0, 0};
    SDL_Rect srch = {0, 0, 0, 0};
    SDL_Rect srce = {0, 0, 0, 0};
    SDL_Rect srcs = {0, 0, 0, 0};
    SDL_Rect srcb = {0, 0, 0, 0};
    SDL_Rect srcf1 = {0, 0, 0, 0};
    SDL_Rect srcf2 = {0, 0, 0, 0};
    SDL_Rect srcf3 = {0, 0, 0, 0};
    SDL_Rect srcf4 = {0, 0, 0, 0};
    SDL_Rect srcf5 = {0, 0, 0, 0};
    SDL_Rect srcf6 = {0, 0, 0, 0};
    SDL_Rect srcf7 = {0, 0, 0, 0};
    SDL_Rect srcf8 = {0, 0, 0, 0};
    SDL_Rect srcf9 = {0, 0, 0, 0};
    SDL_Rect srcf10 = {0, 0, 0, 0};

    SDL_QueryTexture(pTextureCadre, NULL, NULL,&src.w, &src.h);
    SDL_QueryTexture(pTextureNom01, NULL, NULL,&src01.w, &src01.h);
    SDL_QueryTexture(pTextureNom1, NULL, NULL,&src1.w, &src1.h);
    SDL_QueryTexture(pTextureNom2, NULL, NULL,&src2.w, &src2.h);
    SDL_QueryTexture(pTextureNom3, NULL, NULL,&src3.w, &src3.h);
    SDL_QueryTexture(pTextureNom4, NULL, NULL,&src4.w, &src4.h);
    SDL_QueryTexture(pTextureNom5, NULL, NULL,&src5.w, &src5.h);
    SDL_QueryTexture(pTextureNom6, NULL, NULL,&src6.w, &src6.h);
    SDL_QueryTexture(pTextureNom7, NULL, NULL,&src7.w, &src7.h);
    SDL_QueryTexture(pTextureNom8, NULL, NULL,&src8.w, &src8.h);
    SDL_QueryTexture(pTextureNom9, NULL, NULL,&src9.w, &src9.h);
    SDL_QueryTexture(pTextureHelp, NULL, NULL,&srch.w, &srch.h);
    SDL_QueryTexture(pTextureExit, NULL, NULL,&srce.w, &srce.h);
    SDL_QueryTexture(pTextureSave, NULL, NULL,&srcs.w, &srcs.h);
    SDL_QueryTexture(pTextureBefore, NULL, NULL,&srcb.w, &srcb.h);
    SDL_QueryTexture(pTextureFond1, NULL, NULL,&srcf1.w, &srcf1.h);
    SDL_QueryTexture(pTextureFond2, NULL, NULL,&srcf2.w, &srcf2.h);
    SDL_QueryTexture(pTextureFond3, NULL, NULL,&srcf3.w, &srcf3.h);
    SDL_QueryTexture(pTextureFond4, NULL, NULL,&srcf4.w, &srcf4.h);
    SDL_QueryTexture(pTextureFond5, NULL, NULL,&srcf5.w, &srcf5.h);
    SDL_QueryTexture(pTextureFond6, NULL, NULL,&srcf6.w, &srcf6.h);
    SDL_QueryTexture(pTextureFond7, NULL, NULL,&srcf7.w, &srcf7.h);
    SDL_QueryTexture(pTextureFond8, NULL, NULL,&srcf8.w, &srcf8.h);
    SDL_QueryTexture(pTextureFond9, NULL, NULL,&srcf9.w, &srcf9.h);
    SDL_QueryTexture(pTextureFond10, NULL, NULL,&srcf10.w, &srcf10.h);

    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {
            if(tab[x][y]==233)
            {
               SDL_Rect dst = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureCadre, &src, &dst);
            }
        }
    }

    for(x=0;x<7;x++)
    {
        for(y=0;y<13;y++)
        {
            if(tab[x][y]==0)
            {
                SDL_Rect dst01 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom01, &src01, &dst01);
            }
            if(tab[x][y]==1)
            {
                SDL_Rect dst1 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom1, &src1, &dst1);
            }
            if(tab[x][y]==2)
            {
                SDL_Rect dst2 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom2, &src2, &dst2);
            }
            if(tab[x][y]==3)
            {
                SDL_Rect dst3 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom3, &src3, &dst3);
            }
            if(tab[x][y]==4)
            {
                SDL_Rect dst4 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom4, &src4, &dst4);
            }
            if(tab[x][y]==5)
            {
                SDL_Rect dst5 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom5, &src5, &dst5);
            }
            if(tab[x][y]==6)
            {
                SDL_Rect dst6 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom6, &src6, &dst6);
            }
            if(tab[x][y]==7)
            {
                SDL_Rect dst7 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom7, &src7, &dst7);
            }
            if(tab[x][y]==8)
            {
                SDL_Rect dst8 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom8, &src8, &dst8);
            }
            if(tab[x][y]==9)
            {
                SDL_Rect dst9 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom9, &src9, &dst9);
            }
          if(tab[6][y]==13)
            {
                SDL_Rect dste = { y*60, 6*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureExit, &srce, &dste);
            }
          if(tab[6][y]==911)
            {
                SDL_Rect dsth = { y*60, 6*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureHelp, &srch, &dsth);
            }
          if(tab[6][y]==-1)
            {
                SDL_Rect dstb = { y*60, 6*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureBefore, &srcb, &dstb);
            }
          if(tab[6][y]==12)
            {
                SDL_Rect dsts = { y*60, 6*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureSave, &srcs, &dsts);
            }
         }
      }

    SDL_RenderPresent(pRenderer);
}
//fonction gérant l'affichage animé (case par case)
void Affich_Case()
{
    int x,y;

        raoul=rand()%10;

    SDL_Surface* cadre = SDL_LoadBMP("cadre.bmp");
    SDL_Surface* nom01 = SDL_LoadBMP("nom01.bmp");
    SDL_Surface* nom1 = SDL_LoadBMP("nom1.bmp");
    SDL_Surface* nom2 = SDL_LoadBMP("nom2.bmp");
    SDL_Surface* nom3 = SDL_LoadBMP("nom3.bmp");
    SDL_Surface* nom4 = SDL_LoadBMP("nom4.bmp");
    SDL_Surface* nom5 = SDL_LoadBMP("nom5.bmp");
    SDL_Surface* nom6 = SDL_LoadBMP("nom6.bmp");
    SDL_Surface* nom7 = SDL_LoadBMP("nom7.bmp");
    SDL_Surface* nom8 = SDL_LoadBMP("nom8.bmp");
    SDL_Surface* nom9 = SDL_LoadBMP("nom9.bmp");
    SDL_Surface* help = SDL_LoadBMP("help.bmp");
    SDL_Surface* exit = SDL_LoadBMP("exit.bmp");
    SDL_Surface* save = SDL_LoadBMP("save.bmp");
    SDL_Surface* before = SDL_LoadBMP("before.bmp");
    SDL_Surface* fond1 = SDL_LoadBMP("fond1.bmp");
    SDL_Surface* fond2 = SDL_LoadBMP("fond2.bmp");
    SDL_Surface* fond3 = SDL_LoadBMP("fond3.bmp");
    SDL_Surface*  fond4 = SDL_LoadBMP("fond4.bmp");
    SDL_Surface* fond5 = SDL_LoadBMP("fond5.bmp");
    SDL_Surface* fond6 = SDL_LoadBMP("fond6.bmp");
    SDL_Surface* fond7 = SDL_LoadBMP("fond7.bmp");
    SDL_Surface* fond8 = SDL_LoadBMP("fond8.bmp");
    SDL_Surface* fond9 = SDL_LoadBMP("fond9.bmp");
    SDL_Surface* fond10 = SDL_LoadBMP("fond10.bmp");

    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond1->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond2->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond3->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond4->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond5->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond6->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond7->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond8->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond9->format,255,255,255));
    SDL_SetColorKey(cadre, SDL_TRUE,SDL_MapRGB(fond10->format,255,255,255));

    fond();

    SDL_Texture* pTextureCadre = SDL_CreateTextureFromSurface(pRenderer, cadre);
    SDL_FreeSurface(cadre);
    SDL_Texture* pTextureNom01 = SDL_CreateTextureFromSurface(pRenderer, nom01);
    SDL_FreeSurface(nom01);
    SDL_Texture* pTextureNom1 = SDL_CreateTextureFromSurface(pRenderer, nom1);
    SDL_FreeSurface(nom1);
    SDL_Texture* pTextureNom2 = SDL_CreateTextureFromSurface(pRenderer, nom2);
    SDL_FreeSurface(nom2);
    SDL_Texture* pTextureNom3 = SDL_CreateTextureFromSurface(pRenderer, nom3);
    SDL_FreeSurface(nom3);
    SDL_Texture* pTextureNom4 = SDL_CreateTextureFromSurface(pRenderer, nom4);
    SDL_FreeSurface(nom4);
    SDL_Texture* pTextureNom5 = SDL_CreateTextureFromSurface(pRenderer, nom5);
    SDL_FreeSurface(nom5);
    SDL_Texture* pTextureNom6 = SDL_CreateTextureFromSurface(pRenderer, nom6);
    SDL_FreeSurface(nom6);
    SDL_Texture* pTextureNom7 = SDL_CreateTextureFromSurface(pRenderer, nom7);
    SDL_FreeSurface(nom7);
    SDL_Texture* pTextureNom8 = SDL_CreateTextureFromSurface(pRenderer, nom8);
    SDL_FreeSurface(nom8);
    SDL_Texture* pTextureNom9 = SDL_CreateTextureFromSurface(pRenderer, nom9);
    SDL_FreeSurface(nom9);
    SDL_Texture* pTextureHelp = SDL_CreateTextureFromSurface(pRenderer, help);
    SDL_FreeSurface(help);
    SDL_Texture* pTextureExit = SDL_CreateTextureFromSurface(pRenderer, exit);
    SDL_FreeSurface(exit);
    SDL_Texture* pTextureSave = SDL_CreateTextureFromSurface(pRenderer, save);
    SDL_FreeSurface(save);
    SDL_Texture* pTextureBefore = SDL_CreateTextureFromSurface(pRenderer, before);
    SDL_FreeSurface(before);
    SDL_Texture* pTextureFond1 = SDL_CreateTextureFromSurface(pRenderer, fond1);
    SDL_FreeSurface(fond1);
    SDL_Texture* pTextureFond2 = SDL_CreateTextureFromSurface(pRenderer, fond2);
    SDL_FreeSurface(fond2);
    SDL_Texture* pTextureFond3 = SDL_CreateTextureFromSurface(pRenderer, fond3);
    SDL_FreeSurface(fond3);
    SDL_Texture* pTextureFond4 = SDL_CreateTextureFromSurface(pRenderer, fond4);
    SDL_FreeSurface(fond4);
    SDL_Texture* pTextureFond5 = SDL_CreateTextureFromSurface(pRenderer, fond5);
    SDL_FreeSurface(fond5);
    SDL_Texture* pTextureFond6 = SDL_CreateTextureFromSurface(pRenderer, fond6);
    SDL_FreeSurface(fond6);
    SDL_Texture* pTextureFond7 = SDL_CreateTextureFromSurface(pRenderer, fond7);
    SDL_FreeSurface(fond7);
    SDL_Texture* pTextureFond8 = SDL_CreateTextureFromSurface(pRenderer, fond8);
    SDL_FreeSurface(fond8);
    SDL_Texture* pTextureFond9 = SDL_CreateTextureFromSurface(pRenderer, fond9);
    SDL_FreeSurface(fond9);
    SDL_Texture* pTextureFond10 = SDL_CreateTextureFromSurface(pRenderer, fond10);
    SDL_FreeSurface(fond10);

    SDL_Rect src = {0, 0, 0, 0};
    SDL_Rect src01 = {0, 0, 0, 0};
    SDL_Rect src1 = {0, 0, 0, 0};
    SDL_Rect src2 = {0, 0, 0, 0};
    SDL_Rect src3 = {0, 0, 0, 0};
    SDL_Rect src4 = {0, 0, 0, 0};
    SDL_Rect src5 = {0, 0, 0, 0};
    SDL_Rect src6 = {0, 0, 0, 0};
    SDL_Rect src7 = {0, 0, 0, 0};
    SDL_Rect src8 = {0, 0, 0, 0};
    SDL_Rect src9 = {0, 0, 0, 0};
    SDL_Rect srch = {0, 0, 0, 0};
    SDL_Rect srce = {0, 0, 0, 0};
    SDL_Rect srcs = {0, 0, 0, 0};
    SDL_Rect srcb = {0, 0, 0, 0};
    SDL_Rect srcf1 = {0, 0, 0, 0};
    SDL_Rect srcf2 = {0, 0, 0, 0};
    SDL_Rect srcf3 = {0, 0, 0, 0};
    SDL_Rect srcf4 = {0, 0, 0, 0};
    SDL_Rect srcf5 = {0, 0, 0, 0};
    SDL_Rect srcf6 = {0, 0, 0, 0};
    SDL_Rect srcf7 = {0, 0, 0, 0};
    SDL_Rect srcf8 = {0, 0, 0, 0};
    SDL_Rect srcf9 = {0, 0, 0, 0};
    SDL_Rect srcf10 = {0, 0, 0, 0};

    SDL_QueryTexture(pTextureCadre, NULL, NULL,&src.w, &src.h);
    SDL_QueryTexture(pTextureNom01, NULL, NULL,&src01.w, &src01.h);
    SDL_QueryTexture(pTextureNom1, NULL, NULL,&src1.w, &src1.h);
    SDL_QueryTexture(pTextureNom2, NULL, NULL,&src2.w, &src2.h);
    SDL_QueryTexture(pTextureNom3, NULL, NULL,&src3.w, &src3.h);
    SDL_QueryTexture(pTextureNom4, NULL, NULL,&src4.w, &src4.h);
    SDL_QueryTexture(pTextureNom5, NULL, NULL,&src5.w, &src5.h);
    SDL_QueryTexture(pTextureNom6, NULL, NULL,&src6.w, &src6.h);
    SDL_QueryTexture(pTextureNom7, NULL, NULL,&src7.w, &src7.h);
    SDL_QueryTexture(pTextureNom8, NULL, NULL,&src8.w, &src8.h);
    SDL_QueryTexture(pTextureNom9, NULL, NULL,&src9.w, &src9.h);
    SDL_QueryTexture(pTextureHelp, NULL, NULL,&srch.w, &srch.h);
    SDL_QueryTexture(pTextureExit, NULL, NULL,&srce.w, &srce.h);
    SDL_QueryTexture(pTextureSave, NULL, NULL,&srcs.w, &srcs.h);
    SDL_QueryTexture(pTextureBefore, NULL, NULL,&srcb.w, &srcb.h);
    SDL_QueryTexture(pTextureFond1, NULL, NULL,&srcf1.w, &srcf1.h);
    SDL_QueryTexture(pTextureFond2, NULL, NULL,&srcf2.w, &srcf2.h);
    SDL_QueryTexture(pTextureFond3, NULL, NULL,&srcf3.w, &srcf3.h);
    SDL_QueryTexture(pTextureFond4, NULL, NULL,&srcf4.w, &srcf4.h);
    SDL_QueryTexture(pTextureFond5, NULL, NULL,&srcf5.w, &srcf5.h);
    SDL_QueryTexture(pTextureFond6, NULL, NULL,&srcf6.w, &srcf6.h);
    SDL_QueryTexture(pTextureFond7, NULL, NULL,&srcf7.w, &srcf7.h);
    SDL_QueryTexture(pTextureFond8, NULL, NULL,&srcf8.w, &srcf8.h);
    SDL_QueryTexture(pTextureFond9, NULL, NULL,&srcf9.w, &srcf9.h);
    SDL_QueryTexture(pTextureFond10, NULL, NULL,&srcf10.w, &srcf10.h);

    for(x=0;x<5;x++)
    {
        for(y=0;y<5;y++)
        {SDL_Delay(100);
            SDL_Rect dst = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureCadre, &src, &dst);
            SDL_RenderPresent(pRenderer);
        }
    }

    for(x=2;x<7;x++)
      {SDL_Delay(100);
          SDL_Rect dst = { 9*60, x*60, 60, 60 };
          SDL_RenderCopy(pRenderer, pTextureCadre, &src, &dst);
          SDL_RenderPresent(pRenderer);
      }

      for(y=1;y<5;y++)
      {SDL_Delay(100);
          SDL_Rect dst = { y*60, 6*60, 60, 60 };
          SDL_RenderCopy(pRenderer, pTextureCadre, &src, &dst);
          SDL_RenderPresent(pRenderer);
      }

    for(x=0;x<7;x++)
    {
        for(y=0;y<13;y++)
        {
            if(tab[x][y]==0)
            {SDL_Delay(100);
                SDL_Rect dst01 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom01, &src01, &dst01);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==1)
            {SDL_Delay(100);
                SDL_Rect dst1 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom1, &src1, &dst1);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==2)
            {SDL_Delay(100);
                SDL_Rect dst2 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom2, &src2, &dst2);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==3)
            {SDL_Delay(100);
                SDL_Rect dst3 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom3, &src3, &dst3);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==4)
            {SDL_Delay(100);
                SDL_Rect dst4 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom4, &src4, &dst4);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==5)
            {SDL_Delay(100);
                SDL_Rect dst5 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom5, &src5, &dst5);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==6)
            {SDL_Delay(100);
                SDL_Rect dst6 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom6, &src6, &dst6);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==7)
            {SDL_Delay(100);
                SDL_Rect dst7 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom7, &src7, &dst7);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==8)
            {SDL_Delay(100);
                SDL_Rect dst8 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom8, &src8, &dst8);
            SDL_RenderPresent(pRenderer);
            }
            if(tab[x][y]==9)
            {SDL_Delay(100);
                SDL_Rect dst9 = { y*60, x*60, 60, 60 };
            SDL_RenderCopy(pRenderer, pTextureNom9, &src9, &dst9);
            SDL_RenderPresent(pRenderer);
            }
          if(tab[x][y]==13)
            {SDL_Delay(100);
                SDL_Rect dste = { y*60, x*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureExit, &srce, &dste);
                SDL_RenderPresent(pRenderer);
            }
          if(tab[x][y]==911)
            {SDL_Delay(100);
                SDL_Rect dsth = { y*60, x*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureHelp, &srch, &dsth);
                SDL_RenderPresent(pRenderer);
            }
          if(tab[x][y]==-1)
            {SDL_Delay(100);
                SDL_Rect dstb = { y*60, x*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureBefore, &srcb, &dstb);
                SDL_RenderPresent(pRenderer);
            }
          if(tab[x][y]==12)
            {SDL_Delay(100);
                SDL_Rect dsts = { y*60, x*60, 60, 60 };
                SDL_RenderCopy(pRenderer, pTextureSave, &srcs, &dsts);
                SDL_RenderPresent(pRenderer);
            }
         }
      }
}
//fonction affichant la page de garde (première page affichée lors de l'ouverture du jeu)
void Garde0()
{
    SDL_Surface* fond0 = SDL_LoadBMP("fond0.bmp");
    SDL_Surface* jouer0 =SDL_LoadBMP("jouer0.bmp");
    SDL_Surface* conti0 =SDL_LoadBMP("conti0.bmp");
    SDL_Surface* conti1 =SDL_LoadBMP("conti1.bmp");
    SDL_Surface* quit =SDL_LoadBMP("quit.bmp");
    SDL_Surface* add =SDL_LoadBMP("AddUmUp.bmp");

    //SDL_SetColorKey(add, SDL_TRUE,SDL_MapRGB(fond0->format,210,28,188));

    SDL_Texture* pTextureFond0 = SDL_CreateTextureFromSurface(pRenderer, fond0);
    SDL_FreeSurface(fond0);
    SDL_Texture* pTextureJouer0 = SDL_CreateTextureFromSurface(pRenderer, jouer0);
    SDL_FreeSurface(jouer0);
    SDL_Texture* pTextureConti0 = SDL_CreateTextureFromSurface(pRenderer, conti0);
    SDL_FreeSurface(conti0);
    SDL_Texture* pTextureConti1 = SDL_CreateTextureFromSurface(pRenderer, conti1);
    SDL_FreeSurface(conti1);
    SDL_Texture* pTextureQuit = SDL_CreateTextureFromSurface(pRenderer, quit);
    SDL_FreeSurface(quit);
    SDL_Texture* pTextureAdd = SDL_CreateTextureFromSurface(pRenderer, add);
    SDL_FreeSurface(add);

    SDL_Rect src0 = {0, 0, 0, 0};
    SDL_Rect srcjou0 = {0, 0, 0, 0};
    SDL_Rect srcconti0 = {0, 0, 0, 0};
    SDL_Rect srcconti1 = {0, 0, 0, 0};
    SDL_Rect srcquit = {0, 0, 0, 0};
    SDL_Rect srcadd = {0, 0, 0, 0};

    SDL_QueryTexture(pTextureFond0, NULL, NULL,&src0.w, &src0.h);
    SDL_QueryTexture(pTextureJouer0, NULL, NULL,&srcjou0.w, &srcjou0.h);
    SDL_QueryTexture(pTextureConti0, NULL, NULL,&srcconti0.w, &srcconti0.h);
    SDL_QueryTexture(pTextureConti1, NULL, NULL,&srcconti1.w, &srcconti1.h);
    SDL_QueryTexture(pTextureQuit, NULL, NULL,&srcquit.w, &srcquit.h);
    SDL_QueryTexture(pTextureAdd, NULL, NULL,&srcadd.w, &srcadd.h);

    SDL_Rect dst0 = { 0, 0, 780, 420 };
    SDL_Rect dstjou0 = { 60*4, 60*2, 60*4, 60 };
    SDL_Rect dstconti0 = { 60*4, 60*3, 60*4, 60 };
    SDL_Rect dstconti1 = { 60*4, 60*3, 60*4, 60 };
    SDL_Rect dstquit = { 60*4, 60*4, 60*4, 60 };
    SDL_Rect dstadd = { 60*3, 60*0, 60*6, 60*2 };

    SDL_RenderCopy(pRenderer, pTextureFond0, &src0, &dst0);
    SDL_RenderCopy(pRenderer, pTextureJouer0, &srcjou0, &dstjou0);
    SDL_RenderCopy(pRenderer, pTextureConti0, &srcconti0, &dstconti0);
    SDL_RenderCopy(pRenderer, pTextureQuit, &srcquit, &dstquit);
    SDL_RenderCopy(pRenderer, pTextureAdd, &srcadd, &dstadd);

    if(save_me>0)
    SDL_RenderCopy(pRenderer, pTextureConti1, &srcconti1, &dstconti1);

    SDL_RenderPresent(pRenderer);
}
//fonction gérant l'animation sur la page de garde
void Garde()
{
    int x,y;
    SDL_Surface* jouer1 =SDL_LoadBMP("jouer1.bmp");
    SDL_Texture* pTextureJouer1 = SDL_CreateTextureFromSurface(pRenderer, jouer1);
    SDL_FreeSurface(jouer1);
    SDL_Rect srcjou1 = {0, 0, 0, 0};
    SDL_QueryTexture(pTextureJouer1, NULL, NULL,&srcjou1.w, &srcjou1.h);

    bool close = false;
while(!close)
{
    while (SDL_PollEvent(&events))
    {
    int i=0;
    int j=0;
    Garde0();

        switch(events.type)
        {
        case SDL_MOUSEBUTTONDOWN:
        i=events.button.y/60;
        j=events.button.x/60;
        break;
        }
    if(i==2 && (j>=4 && j<=7))
    {
        save_me=1;
        SDL_Rect dstjou1 = { 60*4, 60*2, 60*4, 60 };
        SDL_RenderCopy(pRenderer, pTextureJouer1, &srcjou1, &dstjou1);
        SDL_RenderPresent(pRenderer);
        SDL_Delay(100);

        for(x=0;x<5;x++)
           for(y=0;y<5;y++)
             tab[x][y]=233;

        for(x=2;x<7;x++)
          tab[x][9]=rand()%10;

      tab[6][1]=13;
      tab[6][2]=911;
      tab[6][3]=-1;
      tab[6][4]=12;

      Alea();
        close = true;
    }
    if((i==3 && (j>=4 && j<=7)) && save_me>0)
    {
        /*Savior=fopen("Savior.ra","a+");
        if(Savior==NULL)
           printf("Problème d'ouverture");
        else
        {
            fseek(Savior,-1*sizeof(T),SEEK_CUR);
            fread(&T,sizeof(T),1,Savior);
        }
        fclose(Savior);*/

        /*for(x=0;x<7;x++)
          for(y=0;y<13;y++)
            tab[x][y]=T[x][y];*/

            SDL_Delay(100);
            close = true;

        //Affich_Case();
    }
    if(i==4 && (j>=4 && j<=7))
       SDL_Quit();
    }
}
}
int main(int argc, char* argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_EVENTS) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* pWindow=NULL;

    if (SDL_CreateWindowAndRenderer(780, 420, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
srand(time(NULL));

    SDL_Surface* win = SDL_LoadBMP("win.bmp");
    SDL_Surface* losses = SDL_LoadBMP("losses.bmp");
    SDL_Surface* replay = SDL_LoadBMP("replay.bmp");
    SDL_Surface* revench = SDL_LoadBMP("revench.bmp");
    SDL_Surface* yesnoclic = SDL_LoadBMP("yesnoclic.bmp");
    SDL_Surface* yesclic = SDL_LoadBMP("yesclic.bmp");
    SDL_Surface* nonoclic = SDL_LoadBMP("nonoclic.bmp");
    SDL_Surface* noclic = SDL_LoadBMP("noclic.bmp");
    SDL_Surface* aide1 = SDL_LoadBMP("aide1.bmp");
    SDL_Surface* aide2 = SDL_LoadBMP("aide2.bmp");
    SDL_Surface* aide3 = SDL_LoadBMP("aide3.bmp");
    SDL_Surface* aide4 = SDL_LoadBMP("aide4.bmp");
    SDL_Surface* aide5 = SDL_LoadBMP("aide5.bmp");

    SDL_Texture* pTextureWin = SDL_CreateTextureFromSurface(pRenderer, win);
    SDL_FreeSurface(win);
    SDL_Texture* pTextureLosses = SDL_CreateTextureFromSurface(pRenderer, losses);
    SDL_FreeSurface(losses);
    SDL_Texture* pTextureReplay = SDL_CreateTextureFromSurface(pRenderer, replay);
    SDL_FreeSurface(replay);
    SDL_Texture* pTextureRevench = SDL_CreateTextureFromSurface(pRenderer, revench);
    SDL_FreeSurface(revench);
    SDL_Texture* pTextureYesnoclic = SDL_CreateTextureFromSurface(pRenderer, yesnoclic);
    SDL_FreeSurface(yesnoclic);
    SDL_Texture* pTextureYesclic = SDL_CreateTextureFromSurface(pRenderer, yesclic);
    SDL_FreeSurface(yesclic);
    SDL_Texture* pTextureNonoclic = SDL_CreateTextureFromSurface(pRenderer, nonoclic);
    SDL_FreeSurface(nonoclic);
    SDL_Texture* pTextureNoclic = SDL_CreateTextureFromSurface(pRenderer, noclic);
    SDL_FreeSurface(noclic);
    SDL_Texture* pTextureAide1 = SDL_CreateTextureFromSurface(pRenderer, aide1);
    SDL_FreeSurface(aide1);
    SDL_Texture* pTextureAide2 = SDL_CreateTextureFromSurface(pRenderer, aide2);
    SDL_FreeSurface(aide2);
    SDL_Texture* pTextureAide3 = SDL_CreateTextureFromSurface(pRenderer, aide3);
    SDL_FreeSurface(aide3);
    SDL_Texture* pTextureAide4 = SDL_CreateTextureFromSurface(pRenderer, aide4);
    SDL_FreeSurface(aide4);
    SDL_Texture* pTextureAide5 = SDL_CreateTextureFromSurface(pRenderer, aide5);
    SDL_FreeSurface(aide5);

    SDL_Rect srcw = {0, 0, 0, 0};
    SDL_Rect srcl = {0, 0, 0, 0};
    SDL_Rect srcrep = {0, 0, 0, 0};
    SDL_Rect srcrev = {0, 0, 0, 0};
    SDL_Rect srcynoc = {0, 0, 0, 0};
    SDL_Rect srcyc = {0, 0, 0, 0};
    SDL_Rect srcnnoc = {0, 0, 0, 0};
    SDL_Rect srcnc = {0, 0, 0, 0};
    SDL_Rect srca1 = {0, 0, 0, 0};
    SDL_Rect srca2 = {0, 0, 0, 0};
    SDL_Rect srca3 = {0, 0, 0, 0};
    SDL_Rect srca4 = {0, 0, 0, 0};
    SDL_Rect srca5 = {0, 0, 0, 0};

    SDL_QueryTexture(pTextureWin, NULL, NULL,&srcw.w, &srcw.h);
    SDL_QueryTexture(pTextureLosses, NULL, NULL,&srcl.w, &srcl.h);
    SDL_QueryTexture(pTextureReplay, NULL, NULL,&srcrep.w, &srcrep.h);
    SDL_QueryTexture(pTextureRevench, NULL, NULL,&srcrev.w, &srcrev.h);
    SDL_QueryTexture(pTextureYesnoclic, NULL, NULL,&srcynoc.w, &srcynoc.h);
    SDL_QueryTexture(pTextureYesclic, NULL, NULL,&srcyc.w, &srcyc.h);
    SDL_QueryTexture(pTextureNonoclic, NULL, NULL,&srcnnoc.w, &srcnnoc.h);
    SDL_QueryTexture(pTextureNoclic, NULL, NULL,&srcnc.w, &srcnc.h);
    SDL_QueryTexture(pTextureAide1, NULL, NULL,&srca1.w, &srca1.h);
    SDL_QueryTexture(pTextureAide2, NULL, NULL,&srca2.w, &srca2.h);
    SDL_QueryTexture(pTextureAide3, NULL, NULL,&srca3.w, &srca3.h);
    SDL_QueryTexture(pTextureAide4, NULL, NULL,&srca4.w, &srca4.h);
    SDL_QueryTexture(pTextureAide5, NULL, NULL,&srca5.w, &srca5.h);

Garde();

    int x,y,i,j,back=0;

      FILE* FTmat;

      FTmat=fopen("FTmat.ra","w+");

      if(FTmat==NULL)
        printf("Problème d'ouverture");
      else
      {
            fwrite(&tab,sizeof(tab),1,FTmat);
      }
      fclose(FTmat);

    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            //case SDL_MouseMotionEvent:

            case SDL_MOUSEBUTTONDOWN:
//affiche lors d'un clic les numeros correspondant à une case de la matrice dans le format: case : y-x. y représentant la ligne et x la colonne
                 printf("case : %d-%d\n",events.button.y/60,events.button.x/60);

                if(Winn()==-1 && Luz()==1)
                {
                i=events.button.y/60;
                j=events.button.x/60;
//affectation à la case cliquée précédente le numero en haut de la liste de choix aléatoire et mise à jour de la liste de choix
                 int R;
                 R=SomeCase(i,j);
                 if(tab[i][j]==233 && (i<5 && j<5))
                 {
                     tab[i][j]=tab[2][9];

                     for(x=2;x<6;x++)
                        tab[x][9]=tab[x+1][9];

                     tab[6][9]=rand()%10;

                     FTmat=fopen("FTmat.ra","a+");

                     if(FTmat==NULL)
                       printf("Problème d'ouverture");
                     else
                     {
                         back++;
                        fwrite(&tab,sizeof(tab),1,FTmat);
                     }
                     fclose(FTmat);
                 }
                 else
                 {
                   if(tab[i][j]==13)//sortie du jeu et retour à la page de garde
                   {
                       /*for(x=0;x<5;x++)
                         for(y=0;y<5;y++)
                           tab[x][y]=233;

                       for(x=2;x<7;x++)
                         tab[x][9]=rand()%10;*/

                         Garde();

                       //Alea();

                       back=0;
                       FTmat=fopen("FTmat.ra","w+");

                       if(FTmat==NULL)
                         printf("Problème d'ouverture");
                       else
                      {
                         fwrite(&tab,sizeof(tab),1,FTmat);
                      }
                       fclose(FTmat);
                   }
                   if(tab[i][j]==911)//affichage de l'aide image après image avec un intervalle de 3 secondes
                   {
                       int cnt=0;

                       while(cnt<6)
                       {

                         i=events.button.y/60;
                         j=events.button.x/60;
                         if(cnt==0)
                         {cnt++;
                         SDL_Rect dsta1 = { 3*60, 1*60, 6*60, 4*60 };
                         SDL_RenderCopy(pRenderer, pTextureAide1, &srca1, &dsta1);
                         SDL_RenderPresent(pRenderer);
                         }
                         SDL_Delay(3000);
                         if(cnt==1)
                         {
                             cnt++;
                         SDL_Rect dsta2 = { 3*60, 1*60, 6*60, 4*60 };
                         SDL_RenderCopy(pRenderer, pTextureAide2, &srca2, &dsta2);
                         SDL_RenderPresent(pRenderer);
                         }
                         SDL_Delay(3000);
                         if(cnt==2)
                         {
                             cnt++;
                         SDL_Rect dsta2 = { 3*60, 1*60, 6*60, 4*60 };
                         SDL_RenderCopy(pRenderer, pTextureAide2, &srca2, &dsta2);
                         SDL_RenderPresent(pRenderer);
                         }
                         SDL_Delay(3000);
                         if(cnt==3)
                         {
                             cnt++;
                         SDL_Rect dsta3 = { 3*60, 1*60, 6*60, 4*60 };
                         SDL_RenderCopy(pRenderer, pTextureAide3, &srca3, &dsta3);
                         SDL_RenderPresent(pRenderer);
                         }
                         SDL_Delay(3000);
                         if(cnt==4)
                         {
                             cnt++;
                         SDL_Rect dsta4 = { 3*60, 1*60, 6*60, 4*60 };
                         SDL_RenderCopy(pRenderer, pTextureAide4, &srca4, &dsta4);
                         SDL_RenderPresent(pRenderer);
                         }
                         SDL_Delay(3000);
                         if(cnt==5)
                         {
                             cnt++;
                         SDL_Rect dsta5 = { 3*60, 1*60, 6*60, 4*60 };
                         SDL_RenderCopy(pRenderer, pTextureAide5, &srca5, &dsta5);
                         SDL_RenderPresent(pRenderer);
                         }
                         SDL_Delay(3000);
                       }
                   }
                   if(tab[i][j]==-1 && back!=0)//retour au coup précédent (sur cette partie nous avons rencontrés des diffivultés que nous n'avons pas pu surmonter dans le temps imparti)
                   {
                       int b0=back;
                       back--;

                       FTmat=fopen("FTmat.ra","a+");
                     if(FTmat==NULL)
                       printf("Problème d'ouverture");
                     else
                     {
                         //printf("\nok1\n");
                        fseek(FTmat,-2*sizeof(T),SEEK_CUR);
                        fread(&T,sizeof(T),1,FTmat);
                        fclose(FTmat);

                        for(x=0;x<7;x++)
                            for(y=0;y<13;y++)
                               tab[x][y]=T[x][y];
                     }
                        FILE* FSmat;
                        FSmat=fopen("FSmat.ra","w+");
                        FTmat=fopen("FTmat.ra","r+");
                        if(FSmat==NULL || FTmat==NULL)
                          printf("Problème d'ouverture");
                        else
                        {
                            printf("ok2\n");
                          while(b0!=0)
                          {
                              printf("ok3\n");
                              fread(&T,sizeof(T),1,FTmat);
                              fwrite(&T,sizeof(T),1,FSmat);
                              b0--;
                          }
                        }
                        fclose(FTmat);
                        fclose(FSmat);
                        FTmat=fopen("FTmat.ra","w+");
                        FSmat=fopen("FSmat.ra","r+");
                        while(!feof(FSmat))
                        {
                            printf("ok4\n");
                              fread(&T,sizeof(T),1,FSmat);
                              fwrite(&T,sizeof(T),1,FTmat);
                        }
                        fclose(FTmat);
                        fclose(FSmat);
                   }
                   if(tab[i][j]==12)//sauvegarde de la partie
                   {
                       printf("ok");
                       //save_me++;
                       Savior=fopen("Savior.ra","a+");
                       if(Savior==NULL)
                         printf("Problème d'ouverture");
                       else
                      {
                         fwrite(&tab,sizeof(tab),1,Savior);
                      }
                       fclose(Savior);
                   }
                }

                 Affich();

                 if(R==tab[i][j])//vérification d'un coup réussi
                 {
                     Destruct(i,j);
                     Affich();
                 }
                }
                 if(Winn()==233)//vérification de victoire
                 {
                     SDL_Rect dstw = { 3*60, 0*60, 7*60, 5*60 };
                     SDL_RenderCopy(pRenderer, pTextureWin, &srcw, &dstw);
                     SDL_Rect dstrep = { 3*60, 4*60, 7*60, 3*60 };
                     SDL_RenderCopy(pRenderer, pTextureReplay, &srcrep, &dstrep);
                     SDL_Rect dstynoc = { 4*60, 6*60, 2*60, 1*60 };
                     SDL_RenderCopy(pRenderer, pTextureYesnoclic, &srcynoc, &dstynoc);
                     SDL_Rect dstnnoc = { 7*60, 6*60, 2*60, 1*60 };
                     SDL_RenderCopy(pRenderer, pTextureNonoclic, &srcnnoc, &dstnnoc);
                     SDL_RenderPresent(pRenderer);
                     i=events.button.y/60;
                     j=events.button.x/60;
                     if(i==6 && (j==4 || j==5))//le joueur clique sur "Yes" et recommence une nouvelle partie
                     {
                       SDL_Rect dstyc = { 4*60, 6*60, 2*60, 1*60 };
                       SDL_RenderCopy(pRenderer, pTextureYesclic, &srcyc, &dstyc);
                       SDL_RenderPresent(pRenderer);
                       for(x=2;x<7;x++)
                         tab[x][9]=rand()%10;

                       Alea();
                     }
                     if(i==6 && (j==7 || j==8))//le joueur clique sur "No" et retourne à la page de garde
                     {
                       SDL_Rect dstnc = { 7*60, 6*60, 2*60, 1*60 };
                       SDL_RenderCopy(pRenderer, pTextureNoclic, &srcnc, &dstnc);
                       SDL_RenderPresent(pRenderer);
                       SDL_Delay(1000);
                       Garde();
                     }
                 }
                 else

                 {
                     if(Luz()==-1)//vérification de défaite
                     {
                         SDL_Rect dstl = { 3*60, 0, 7*60, 7*60 };
                         SDL_RenderCopy(pRenderer, pTextureLosses, &srcl, &dstl);
                         SDL_Rect dstrev = { 3*60, 4*60, 7*60, 3*60 };
                         SDL_RenderCopy(pRenderer, pTextureRevench, &srcrev, &dstrev);
                         SDL_Rect dstynoc = { 4*60, 6*60, 2*60, 1*60 };
                         SDL_RenderCopy(pRenderer, pTextureYesnoclic, &srcynoc, &dstynoc);
                         SDL_Rect dstnnoc = { 7*60, 6*60, 2*60, 1*60 };
                         SDL_RenderCopy(pRenderer, pTextureNonoclic, &srcnnoc, &dstnnoc);
                         SDL_RenderPresent(pRenderer);
                         i=events.button.y/60;
                         j=events.button.x/60;
                     if(i==6 && (j==4 || j==5))//le joueur clique sur "Yes" et recommence une nouvelle partie
                     {
                       SDL_Rect dstyc = { 4*60, 6*60, 2*60, 1*60 };
                       SDL_RenderCopy(pRenderer, pTextureYesclic, &srcyc, &dstyc);
                       SDL_RenderPresent(pRenderer);

                       for(x=0;x<5;x++)
                         for(y=0;y<5;y++)
                           tab[x][y]=233;

                       for(x=2;x<7;x++)
                         tab[x][9]=rand()%10;

                       Alea();
                     }
                     if(i==6 && (j==7 || j==8))//le joueur clique sur "No" et retourne à la page de garde
                     {
                       SDL_Rect dstnc = { 7*60, 6*60, 2*60, 1*60 };
                       SDL_RenderCopy(pRenderer, pTextureNoclic, &srcnc, &dstnc);
                       SDL_RenderPresent(pRenderer);
                       SDL_Delay(1000);
                       Garde();
                     }
                 }
            }
                break;
            }
        }
   }
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return EXIT_SUCCESS;
}
//Nous savons que notre projet contient encore de nombreux manquement et qu'il n'est sans doute pas optimal, alors, nous restons dans l'attente de critique pour nous perfectionner
