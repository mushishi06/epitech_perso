#include	<stdlib.h>
#include	<stdio.h>
#include	<SDL/SDL.h>
#include	<math.h>
#include	"sdl_math.h"

int main(int argc, char *argv[])
{
  int continuer = 1,p,a,t;
  SDL_Event event;
  SDL_Surface *ecran = NULL, *rectangle = NULL, *imageDeFond1 = NULL,*imageDeFond2 = NULL,*imageDeFond3 = NULL,*imageDeFond4 = NULL,*imageDeFond5 = NULL,*imageDeFond6 = NULL,*imageDeFond7 = NULL;
  SDL_Rect   position,positionFond1,positionFond2,positionFond3,positionFond4,positionFond5,
    positionFond6,positionFond7;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);
  ecran = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, 32, SDL_HWSURFACE| SDL_DOUBLEBUF);// definit la taille de la fenetre (largeur x hauteur y)
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 1,2, 32, 0, 0, 0, 0); // Allocation de la surface (taille du point)
  SDL_WM_SetCaption("tracage de courbe ", NULL);// met le nom de la fenetre
  positionFond1.x = 385;
  positionFond1.y = 0;
  positionFond2.x = 399;
  positionFond2.y = 100;
  positionFond3.x = 399;
  positionFond3.y =200;

  positionFond4.x = 399;
  positionFond4.y = 300;
  positionFond5.x = 399;
  positionFond5.y = 400;
  positionFond6.x = 399;
  positionFond6.y = 500;
  positionFond7.x = 0;
  positionFond7.y = 0;
  imageDeFond7 = SDL_LoadBMP("aa.bmp");
  SDL_BlitSurface(imageDeFond7, NULL, ecran, &positionFond7);
  imageDeFond1 = SDL_LoadBMP("menu.bmp");
  SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
  imageDeFond2 = SDL_LoadBMP("sin.bmp");
  SDL_SetAlpha(imageDeFond2, SDL_SRCALPHA,220);
  SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond2);
  imageDeFond3 = SDL_LoadBMP("cos.bmp");
  SDL_SetAlpha(imageDeFond3, SDL_SRCALPHA, 220);
  SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond3);
  imageDeFond4 = SDL_LoadBMP("exp.bmp");
  SDL_SetAlpha(imageDeFond4, SDL_SRCALPHA, 220);
  SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond4);
  imageDeFond5 = SDL_LoadBMP("log.bmp");
  SDL_SetAlpha(imageDeFond5, SDL_SRCALPHA, 220);
  SDL_BlitSurface(imageDeFond5, NULL, ecran, &positionFond5);
  imageDeFond6 = SDL_LoadBMP("quitter.bmp");
  SDL_SetAlpha(imageDeFond6, SDL_SRCALPHA, 220);
  SDL_BlitSurface(imageDeFond6, NULL, ecran, &positionFond6);
  SDL_Flip(ecran); // Mise à jour de l'écran
  while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  continuer = 0;
	case SDL_MOUSEMOTION:
	  if(event.motion.x>399 &&event.motion.x<601 &&event.motion.y>110 && event.motion.y<188)
            {
              SDL_ShowCursor(SDL_ENABLE);
	      imageDeFond2 = SDL_LoadBMP("sin.bmp");
	      SDL_SetAlpha(imageDeFond2, SDL_SRCALPHA,228);
	      SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond2);
              SDL_Flip(ecran);
              SDL_WaitEvent(&event);
            }
	  else
	    if(event.motion.x>399 &&event.motion.x<601 &&event.motion.y>208 && event.motion.y<286)
	      {
                imageDeFond3 = SDL_LoadBMP("cos.bmp");
                SDL_SetAlpha(imageDeFond3, SDL_SRCALPHA,228);
                SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond3);
                SDL_Flip(ecran);
	      }
	    else
	      if(event.motion.x>399 &&event.motion.x<601 &&event.motion.y>306 && event.motion.y<382)
		{
		  imageDeFond4 = SDL_LoadBMP("exp.bmp");
		  SDL_SetAlpha(imageDeFond4, SDL_SRCALPHA,228);
		  SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond4);
		  SDL_Flip(ecran);
		}
	      else
                if(event.motion.x>399 &&event.motion.x<601 &&event.motion.y>402 && event.motion.y<480)
		  {
		    imageDeFond5 = SDL_LoadBMP("log.bmp");
		    SDL_SetAlpha(imageDeFond5, SDL_SRCALPHA,228);
		    SDL_BlitSurface(imageDeFond5, NULL, ecran, &positionFond5);
		    SDL_Flip(ecran);
		  }
                else
		  if(event.motion.x>399 &&event.motion.x<601 &&event.motion.y>500 && event.motion.y<578)
		    {
		      imageDeFond6 = SDL_LoadBMP("quitter.bmp");
		      SDL_SetAlpha(imageDeFond6, SDL_SRCALPHA,228);
		      SDL_BlitSurface(imageDeFond6, NULL, ecran, &positionFond6);
		      SDL_Flip(ecran);
		    }
		  else
		    {
		      imageDeFond7 = SDL_LoadBMP("aa.bmp");
		      SDL_BlitSurface(imageDeFond7, NULL, ecran, &positionFond7);
		      imageDeFond1 = SDL_LoadBMP("menu.bmp");
		      SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
		      imageDeFond2 = SDL_LoadBMP("sin.bmp");
		      SDL_SetAlpha(imageDeFond2, SDL_SRCALPHA,220);
		      SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond2);
		      imageDeFond3 = SDL_LoadBMP("cos.bmp");
		      SDL_SetAlpha(imageDeFond3, SDL_SRCALPHA, 220);
		      SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond3);
		      imageDeFond4 = SDL_LoadBMP("exp.bmp");
		      SDL_SetAlpha(imageDeFond4, SDL_SRCALPHA, 220);
		      SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond4);
		      imageDeFond5 = SDL_LoadBMP("log.bmp");
		      SDL_SetAlpha(imageDeFond5, SDL_SRCALPHA, 220);
		      SDL_BlitSurface(imageDeFond5, NULL, ecran, &positionFond5);
		      imageDeFond6 = SDL_LoadBMP("quitter.bmp");
		      SDL_SetAlpha(imageDeFond6, SDL_SRCALPHA, 220);
		      SDL_BlitSurface(imageDeFond6, NULL, ecran, &positionFond6);
		      SDL_Flip(ecran);
		    }
	  break;
	case SDL_MOUSEBUTTONUP:
	  if( event.button.x>399 && event.button.x<601 && event.button.y>110 &&  event.button.y<188)
	    {
	      // construction des axes*******************************************************************************

	      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 12,2,45));
	      draw_axe_x(ecran, rectangle, WIN_HEIGHT - 50);
	      draw_axe_y(ecran, rectangle, 50);

	      /*    for ( a=0;a<1000;a++)
		    {
		    position.x = a ;
		    position.y = 550 ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		    }
		    for ( a=0;a<600;a++)
		    {
		    position.x = 50 ;
		    position.y = a ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		    }*/
	      // construction des fleches*******************************************************************************
	      draw_fleche_x(ecran, rectangle, WIN_HEIGHT - 50);
	      draw_fleche_y(ecran, rectangle, 50);
	      /*  for ( a=490;a<500;a++)
		  {
		  position.x = a ;
		  position.y =500-a ;
		  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		  SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		  for ( a=500;a<510;a++)
		  {
		  position.x = a ;
		  position.y = a-500 ;
		  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		  SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		  for ( a=1000;a>990;a--)
		  {
		  position.x = a ;
		  position.y = 300+1000-a ;
		  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		  SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		  for ( a=990;a<1000;a++)
		  {
		  position.x = a ;
		  position.y =290+a-990 ;
		  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		  SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }*/

	      // TRACE DE LA FONCTION

	      draw_func_densite(ecran, rectangle, 1.18);

	      /*	      for (t =-500; t<500;t++)

			      {
			      position.x = 500+t; // abcisse du point
			      position.y =300-sin(t*0.01)*200 ;// ordonnee du point
			      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 100, 25));
			      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
			      SDL_Flip(ecran); // Mise à jour de l'écran
			      }*/
	      p=1;
	      while(p==1)
		{
		  SDL_WaitEvent(&event);
		  switch(event.type)
		    {
		    case SDL_QUIT:
		      p=0;
		      continuer = 0;
		      break;
		    case SDL_KEYDOWN:
		      switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE: /* Appui sur la touche Echap, pour retourner au menu */
			  p = 0;
			  imageDeFond7 = SDL_LoadBMP("aa.bmp");
			  SDL_BlitSurface(imageDeFond7, NULL, ecran, &positionFond7);
			  imageDeFond1 = SDL_LoadBMP("menu.bmp");
			  SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
			  imageDeFond2 = SDL_LoadBMP("sin.bmp");
			  SDL_SetAlpha(imageDeFond2, SDL_SRCALPHA,220);
			  SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond2);
			  imageDeFond3 = SDL_LoadBMP("cos.bmp");
			  SDL_SetAlpha(imageDeFond3, SDL_SRCALPHA, 220);
			  SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond3);
			  imageDeFond4 = SDL_LoadBMP("exp.bmp");
			  SDL_SetAlpha(imageDeFond4, SDL_SRCALPHA, 220);
			  SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond4);
			  imageDeFond5 = SDL_LoadBMP("log.bmp");
			  SDL_SetAlpha(imageDeFond5, SDL_SRCALPHA, 220);
			  SDL_BlitSurface(imageDeFond5, NULL, ecran, &positionFond5);
			  imageDeFond6 = SDL_LoadBMP("quitter.bmp");
			  SDL_SetAlpha(imageDeFond6, SDL_SRCALPHA, 220);
			  SDL_BlitSurface(imageDeFond6, NULL, ecran, &positionFond6);
			  SDL_Flip(ecran); // Mise à jour de l'écran
			  break;
			}
		      break;
		    }
		}
	    }
	  else
	    if( event.button.x>399 && event.button.x<601 && event.button.y>208 &&  event.button.y<286)
	      {
		// construction des axes*******************************************************************************
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,12,2,45));
		for ( a=0;a<1000;a++)
		  {
		    position.x = a ;
		    position.y = 300 ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		for ( a=0;a<600;a++)
		  {
		    position.x = 500 ;
		    position.y = a ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		// construction des fleches*****************************************************************************
		for ( a=490;a<500;a++)
		  {
		    position.x = a ;
		    position.y =500-a ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		for ( a=500;a<510;a++)
		  {
		    position.x = a ;
		    position.y = a-500 ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		for ( a=1000;a>990;a--)
		  {
		    position.x = a ;
		    position.y = 300+1000-a ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		for ( a=990;a<1000;a++)
		  {
		    position.x = a ;
		    position.y =290+a-990 ;
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		  }
		// TRACE DE LA FONCTION
		for (t =-500; t<500;t++)
		  {
		    position.x = 500+t; // abcisse du point
		    position.y =300-cos(t*0.01)*200 ;// ordonnee du point
		    SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 100, 25));
		    SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		    SDL_Flip(ecran); // Mise à jour de l'écran
		  }
		p=1;
		while(p==1)
		  {
		    SDL_WaitEvent(&event);
		    switch(event.type)
		      {
		      case SDL_QUIT:
			p=0;
			continuer = 0;
			break;
		      case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			  {
			  case SDLK_ESCAPE:
			    p = 0;
			    imageDeFond7 = SDL_LoadBMP("aa.bmp");
			    SDL_BlitSurface(imageDeFond7, NULL, ecran, &positionFond7);
			    imageDeFond1 = SDL_LoadBMP("menu.bmp");
			    SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
			    imageDeFond2 = SDL_LoadBMP("sin.bmp");
			    SDL_SetAlpha(imageDeFond2, SDL_SRCALPHA,220);
			    SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond2);
			    imageDeFond3 = SDL_LoadBMP("cos.bmp");
			    SDL_SetAlpha(imageDeFond3, SDL_SRCALPHA, 220);
			    SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond3);
			    imageDeFond4 = SDL_LoadBMP("exp.bmp");
			    SDL_SetAlpha(imageDeFond4, SDL_SRCALPHA, 220);
			    SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond4);
			    imageDeFond5 = SDL_LoadBMP("log.bmp");
			    SDL_SetAlpha(imageDeFond5, SDL_SRCALPHA, 220);
			    SDL_BlitSurface(imageDeFond5, NULL, ecran, &positionFond5);
			    imageDeFond6 = SDL_LoadBMP("quitter.bmp");
			    SDL_SetAlpha(imageDeFond6, SDL_SRCALPHA, 220);
			    SDL_BlitSurface(imageDeFond6, NULL, ecran, &positionFond6);
			    SDL_Flip(ecran); // Mise à jour de l'écran
			    break;
			  }
			break;
		      }

		  }
	      }
	    else
	      if( event.button.x>399 && event.button.x<601 && event.button.y>306 &&  event.button.y<382)
		{
		  // construction des axes*******************************************************************************
		  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,12,2,45));
		  for ( a=0;a<1000;a++)
		    {
		      position.x = a ;
		      position.y = 300 ;
		      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran

		    }
		  for ( a=0;a<600;a++)
		    {
		      position.x = 500 ;
		      position.y = a ;
		      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran

		    }
		  // construction des fleches*******************************************************************************
		  for ( a=490;a<500;a++)
		    {
		      position.x = a ;
		      position.y =500-a ;
		      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		    }
		  for ( a=500;a<510;a++)
		    {
		      position.x = a ;
		      position.y = a-500 ;
		      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		    }
		  for ( a=1000;a>990;a--)
		    {
		      position.x = a ;
		      position.y = 300+1000-a ;
		      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		    }
		  for ( a=990;a<1000;a++)
		    {
		      position.x = a ;
		      position.y =290+a-990 ;
		      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		    }

		  // TRACE DE LA FONCTION

		  for (t =-500; t<500;t++)

		    {
		      position.x = 500+t; // abcisse du point
		      position.y =300-exp(t*0.01)*100 ;// ordonnee du point
		      SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 100, 25));
		      SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		      SDL_Flip(ecran); // Mise à jour de l'écran
		    }
		  p=1;
		  while(p==1)
                    {
                      SDL_WaitEvent(&event);
		      switch(event.type)
			{
			case SDL_QUIT:
			  p=0;
			  continuer = 0;
			  break;
			case SDL_KEYDOWN:
                          switch (event.key.keysym.sym)
			    {
                            case SDLK_ESCAPE:
                              p = 0;
			      imageDeFond7 = SDL_LoadBMP("aa.bmp");
			      SDL_BlitSurface(imageDeFond7, NULL, ecran, &positionFond7);
			      imageDeFond1 = SDL_LoadBMP("menu.bmp");
			      SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond1);
			      imageDeFond2 = SDL_LoadBMP("sin.bmp");
			      SDL_SetAlpha(imageDeFond2, SDL_SRCALPHA,220);
			      SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond2);
			      imageDeFond3 = SDL_LoadBMP("cos.bmp");
			      SDL_SetAlpha(imageDeFond3, SDL_SRCALPHA, 220);
			      SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond3);
			      imageDeFond4 = SDL_LoadBMP("exp.bmp");
			      SDL_SetAlpha(imageDeFond4, SDL_SRCALPHA, 220);
			      SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond4);
			      imageDeFond5 = SDL_LoadBMP("log.bmp");
			      SDL_SetAlpha(imageDeFond5, SDL_SRCALPHA, 220);
			      SDL_BlitSurface(imageDeFond5, NULL, ecran, &positionFond5);
			      imageDeFond6 = SDL_LoadBMP("quitter.bmp");
			      SDL_SetAlpha(imageDeFond6, SDL_SRCALPHA, 220);
			      SDL_BlitSurface(imageDeFond6, NULL, ecran, &positionFond6);
			      SDL_Flip(ecran); // Mise à jour de l'écran
                              break;
                            }
			  break;
			}

		    }
		}
	      else
		if( event.button.x>399 && event.button.x<601 && event.button.y>402 &&  event.button.y<480)
		  {
                    // construction des axes*******************************************************************************
		    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,12,2,45));
		    for ( a=0;a<1000;a++)
		      {
			position.x = a ;
			position.y = 300 ;
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		      }
		    for ( a=0;a<600;a++)
		      {
			position.x = 500 ;
			position.y = a ;
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran

		      }
		    // construction des fleches*******************************************************************************
		    for ( a=490;a<500;a++)
		      {
			position.x = a ;
			position.y =500-a ;
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		      }
		    for ( a=500;a<510;a++)
		      {
			position.x = a ;
			position.y = a-500 ;
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		      }
		    for ( a=1000;a>990;a--)
		      {
			position.x = a ;
			position.y = 300+1000-a ;
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		      }
		    for ( a=990;a<1000;a++)
		      {
			position.x = a ;
			position.y =290+a-990 ;
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
		      }
		    // TRACE DE LA FONCTION
		    for (t =0; t<500;t++)
		      {
			position.x = 500+t; // abcisse du point
			position.y =300-log(t*0.01)*100;// ordonnee du point
			SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 100, 25));
			SDL_BlitSurface(rectangle, NULL, ecran, &position); // Collage du point sur l'écran
			SDL_Flip(ecran); // Mise à jour de l'écran
		      }
                    p=1;
                    while(p==1)
		      {

                      }
		  }
		else
		  if( event.button.x>399 && event.button.x<601 && event.button.y>500 &&
		      event.button.y<578)
                    {
		      p=0;
		      continuer=0;
                    }
	  break;
	}
    }
  SDL_FreeSurface(rectangle); // Libération de la surface
  SDL_Quit();
  return EXIT_SUCCESS;
}
