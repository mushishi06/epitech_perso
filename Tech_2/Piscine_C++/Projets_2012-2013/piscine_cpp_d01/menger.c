/* pour compiler taper en ligne de commande :
   gcc tapis.c -o tapis `allegro-config --libs`
   pour exécuter taper tapis suivi du nombre d'itérations :
   tapis 7 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <allegro.h>

#define MAXX 1100
#define MAXY 1100
#define OX 0
#define OY 0
#define TX 1000
#define TY 1000

BITMAP *bmp;

/* fonction récursive, qui a pour paramètres
   les coordonnées (x, y) d'un des sommets d'un rectangle,
   a la longueur et b la largeur de ce rectangle  et,
   n le nombre d'itérations */

void tapis_Sierpinski(double x, double y, double a, double b, int n)
{
  if (n>0)
    {
      /* on supprime le petit rectangle central */
      rectfill(bmp, (int) (x+a/3), (int) (y+b/3), (int) (x+2*a/3), (int)(y+2*b/3), 8);
      printf ("[%.3d] [%.3d] [%.3d]\n",(int) (x+2*a/3) - (int) (x+a/3), (int) (y+b/3), (int) (x+a/3));

      /* appels récursifs pour les huit rectangles restants */
      tapis_Sierpinski(x, y, a/3, b/3, n-1);
      tapis_Sierpinski(x+a/3, y, a/3, b/3, n-1);
      tapis_Sierpinski(x+2*a/3, y, a/3, b/3, n-1);
      tapis_Sierpinski(x, y+b/3, a/3, b/3, n-1);
      tapis_Sierpinski(x+2*a/3, y+b/3, a/3, b/3, n-1);
      tapis_Sierpinski(x, y+2*b/3, a/3, b/3, n-1);
      tapis_Sierpinski(x+a/3, y+2*b/3, a/3, b/3, n-1);
      tapis_Sierpinski(x+2*a/3, y+2*b/3, a/3, b/3, n-1);
    } else
    /* on dessine un rectangle plein */
    {
      rectfill(bmp, (int) x, (int) y, (int) (x+a), (int)(y+b), 1);
    }
}

int main(int argc, char *argv[])
{
  unsigned long n=1;
  if (argc>1) n = strtoul(argv[1], NULL, 10);

  /* initialisation de allegro */
  allegro_init();

  set_color_depth(8);

  bmp = create_bitmap(MAXX, MAXY);
  if(!bmp)
    {
      allegro_message("Ne peut pas créer l'image\n");
      return 1;
    }

  tapis_Sierpinski(OX, OY, strtoul(argv[2], NULL, 10), strtoul(argv[3], NULL, 10), (int)n);

  save_bitmap("Tapis_de_Sierpinski.pcx", bmp, desktop_palette);
  destroy_bitmap(bmp);

  return 0;
}

END_OF_MAIN();
