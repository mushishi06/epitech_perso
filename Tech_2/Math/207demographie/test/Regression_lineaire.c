/************************************************************************/
/*Régression linéaire méthode des moindres carrés version 1.1c avec menu*/
/************************************************************************/

#include	<stdio.h>
#include	<math.h>
#include <stdlib.h>
#include <string.h>

#include	"sdl_math.h"

#define MAX 52 /*définition de la taille maximum des tableaux donc du nombre d'element Xi et Yi*/

/***************************/
/*Déclaration des fonctions*/
/***************************/

void entete();
int nbrelement();
void ligne(int nbr);
void ligne2(int deb,int nbr,int fin);
void titre(char titre[]);
float somme(float tab[],int N);
float moyenne(float somme,int N);
void produittab(float tab1[],float tab2[],float tab_produit[],int N);
float pente(float SommeProduitXiYi,float MoyenneXi,float MoyenneYi,float SommeCarreXiMoinMoyenneXi,int N);
float ordonee(float MoyenneXi,float MoyenneYi,float a);
void ecart_a_moyenne(float tab[],float tab_ecart_a_moyenne[],float Moyenne,int N);
void affich_tab(float tab[],float tab1[],float tab2[],float tab3[],float tab4[],float tab5[],int N);
double corr(float SommeCarreXiMoinMoyenneXi,float SommeCarreYiMoinMoyenneYi,float a);
void affichage(float tab[]);
void aff_equation(float tab[]);
void regression(float Xi[],float Yi[],int N,float result[],float ProduitXiYi[],float carre_ecart_a_moyenne_Xi[],float carre_ecart_a_moyenne_Yi[]);
void fichier(float tab[],float tab1[],float tab2[],float tab3[],float tab4[],float tab5[],int N);


/***************************/
/* Fonction principal MAIN */
/***************************/

void main ()

{
  int position,choix=-1,choix1=-1,choix1_2=-1,N,i=1;		/*Déclaration des variables*/
  float Xi[MAX],Yi[MAX],result[10];
  float ProduitXiYi[MAX];
  float carre_ecart_a_moyenne_Xi[MAX];
  float carre_ecart_a_moyenne_Yi[MAX];
  int j = 0;

  while (j < 53)
    {
      Xi[j] = data[0].country_nb[j];
      Yi[j] = data[8].country_nb[j];
      j++;
    }

  /*Appel de la fonction d'affichage d'en-tête*/

  entete();

  /********/
  /* MENU */
  /********/


  while(choix!=0)
    {
      titre("Menu Principale:");

      printf("\nEntrez le num%cro de l\'op%cration d%csir%ce:\n",130,130,130,130);
      printf("\n(1) Entrer o%c modifier les donn%ces (Xi et Yi).",151,130);
      printf("\n(2) D%cterminer l\'%cquation de la droite",130,130);
      printf("\n(3) Afficher le tableau des valeurs interm%cdiaires.",130);
      printf("\n(4) Afficher les r%csultats.",130);
      printf("\n(5) Sauvegadrer les donn%ces dans un fichier.",130);
      printf("\n(0) Quitter le programme.");
      printf("\n\n Quel est votre choix? :");
      scanf("%d",&choix);

      switch (choix)
	{
	case 1:
	  {	choix1=-1;choix1_2=-1;

	    while(choix1!=0)
	      {
		titre("Menu Donnees:");
		printf("\nEntrez le num%cro de l\'op%cration d%csir%ce:\n",130,130,130,130);
		printf("\n(1) Entrer des nouvelles valeurs.");
		printf("\n(2) Modiffier les valeurs existantes.");
		printf("\n(3) Revenir au menu principale.");
		printf("\n(0) Quitter le programme.");
		printf("\n\n Quel est votre choix? :");
		scanf("%d",&choix1);

		switch (choix1)
		  {
		  case 1:
		    {

		      titre("Donnees:");/*Fonction d'affichage de titre*/

		      /*Appel de la fonction d'entrée du nombre d'élement*/

		      N=nbrelement();

		      i=1;

		      /*Entree des élements Xi*/

		      titre("Entree des valeurs de Xi:");/*Fonction d'affichage de titre*/

		      while (i<(N+1))
			{
			  printf("Entrez la valeur de X%d: ",i);
			  scanf("%f",&Xi[i]);i++;
			};

		      i=1;

		      /*Entree des élements Yi*/

		      titre("Entree des valeurs de Yi:");/*Fonction d'affichage de titre*/

		      while (i<(N+1))
			{
			  printf("Entrez la valeur de Y%d: ",i);
			  scanf("%f",&Yi[i]);i++;
			}
		      printf("\nTappez une touche pour revenir au menu pr%cc%cdant:",130,130);
		      getchar();
		      getchar();
		      printf("\n\n");


		    };break;

		  case 2:
		    {
		      choix1_2=-1;

		      while(choix1_2!=0)
			{
			  titre("Menu Modiffication Donnees");
			  printf("\nEntrez le num%cro de l\'op%cration d%csir%ce:\n",130,130,130,130);
			  printf("\n(1) Modifier un %cl%cment des Xi.",130,130);
			  printf("\n(2) Modifier un %cl%cment des Yi.",130,130);
			  printf("\n(3) Revenir au menu pr%cc%cdant.",130,130);
			  printf("\n(4) Revenir au menu principale.");
			  printf("\n(0) Quitter le programme.");
			  printf("\n\n Quel est votre choix? :");
			  scanf("%d",&choix1_2);

			  switch (choix1_2)
			    {
			    case 1:
			      {
				titre("Modiffication d'un element des Xi:");
				printf("Entrez la position de l\'%cl%cment dans le tableau:",130,130);
				scanf("%d",&position);
				printf("\nEntrez la nouvelle valeur de X%d:",position);
				scanf("%lf",&Xi[position]);
				printf("\n Modification %cffectu%ce...\n",130,130);

			      };break;
			    case 2:
			      {
				printf("\n\nEntrez la position de l\'%cl%cment dans le tableau:",130,130);
				scanf("%d",&position);
				printf("\nEntrez la nouvelle valeur de Y%d:",position);
				scanf("%lf",&Yi[position]);
				printf("\n Modification %cffectu%ce...\n",130,130);

			      };break;
			    case 3:choix1=-1;choix1_2=0;break;
			    case 4:choix1_2=0;choix1=0;choix=-1;break;
			    case 0:choix1=0;choix1_2=0;break;
			    default:;break;
			    }
			}

		    };break;

		  case 3:choix=-1;choix1=0;break;
		  case 0:choix=0;choix1=0;break;
		  default:printf("\n Entr%ce non valide!");break;
		  }
	      }




	  };break;

	case 2:
	  {
	    /*Appel de la fonction de regression linéaire*/

	    regression(Xi,Yi,N,result,ProduitXiYi,carre_ecart_a_moyenne_Xi,carre_ecart_a_moyenne_Yi);

	    printf("\nOp%Cration termin%ce...\n",130,130);

	    /*Affichage de l'éqation et de la corrélation "r"*/

	    aff_equation(result);

	    printf("\nCoefficient de corr%clation:=> r = %lf\n\n",130,result[9]);
	    printf("Tappez une touche pour revenir au menu pr%cc%cdant:",130,130);
	    getchar();
	    getchar();
	    printf("\n\n");

	  };break;

	case 3:
	  {
	    /*Affichage du tableau des resultats*/

	    affich_tab(result,Xi,Yi,ProduitXiYi,carre_ecart_a_moyenne_Xi,carre_ecart_a_moyenne_Yi,N);
	    printf("\nTappez une touche pour revenir au menu pr%cc%cdant:",130,130);
	    getchar();
	    getchar();
	    printf("\n\n");


	  };break;

	case 4:
	  {
	    /*Affichage des résultats*/

	    affichage(result);
	    printf("\nTappez une touche pour revenir au menu pr%cc%cdant:",130,130);
	    getchar();

	  };break;

	case 5:
	  {
	    fichier(result,Xi,Yi,ProduitXiYi,carre_ecart_a_moyenne_Xi,carre_ecart_a_moyenne_Yi,N);
	    printf("\nTappez une touche pour revenir au menu pr%cc%cdant:",130,130);
	    getchar();
	  }

	case 0:;break;

	default:printf("\nEntree non valide!\n");break;
	};


    }

  getchar();
}


/*********************************/
/*         Les Fonctions         */
/*********************************/


/*Fonction d'affichage de l'en-tête avec nom et version du programme etc...*/

void entete()

{

  printf("************************************************************************\n");
  printf("* R%cgression lin%caire par la m%cthodes des moindres carr%cs Version 1.1c *\n",130,130,130,130);
  printf("*                    R%calisation: LEMAGICIEN.                          *\n",130);
  printf("************************************************************************\n");
  printf("* Nouveaut%cs par rapport %c la version 1.1b:                            *\n",130,133);
  printf("*    ==> Un menu                                                       *\n",130,130);
  printf("************************************************************************\n\n");

}


/*Fonction d'entrée du nombre d'elements*/

int nbrelement()

{
  float n;
  int N;

  printf("Entrez le nombre de mesures N (entre 2 et %d):",MAX);
  scanf("%f",&n);

  N=n;

  while ((N<2)||(N>(MAX+1))||(n!=N))  /*verification que "n" est bien entier*/

    {if (n!=N)

	{while (n!=N)
	    {printf("\nLa valeur de N doit %ctre enti%cre",136,138);
	      printf("\nEntrez une nouvelle valeur:");
	      scanf("%f",&n);N=n;
	    };
	};
      if ((N<2)||(N>(MAX+1)))

	{printf("\nLa valeur doit %ctre comprise entre 2 et %d:",136,MAX);
	  printf("\nEntrez une nouvelle valeur:");
	  scanf("%f",&n);N=n;
	};
    };
  return(N);
}


/*Fonction de calcul de somme d'element d'un tableau*/

float somme(float tab[],int N)
{
  float somme=0;
  int i=1;


  while (i<(N+1))
    {
      somme=((tab[i])+(somme));i++;
    };

  return(somme);
}

/*Fonction de calcul de moyenne d'element d'un tableau*/

float moyenne(float somme,int N)

{
  float moyenne;

  moyenne=((somme)/(float)N);

  return (moyenne);
}

/*Fonction de calcul du produit d'element de deux tableau ligne par ligne*/

void produittab(float tab1[],float tab2[],float tab_produit[],int N)

{
  int i=1;

  while (i<(N+1))
    {
      tab_produit[i]=(tab1[i]*tab2[i]);i++;
    };

}


/*Fonction de calcul de la pente "a" de la droite*/

float pente(float SommeProduitXiYi,float MoyenneXi,float MoyenneYi,float SommeCarreXiMoinMoyenneXi,int N)
{
  float a;

  a=((SommeProduitXiYi)-(N*MoyenneXi*MoyenneYi))/(SommeCarreXiMoinMoyenneXi);

  return (a);
}

/*Fonction de calcul de l'ordonee a l'orrigine "b"*/

float ordonee(float MoyenneXi,float MoyenneYi,float a)

{
  float b;

  b=(MoyenneYi-(a*MoyenneXi));
  return (b);
}

/*Fonction de calcul des écarts à la moyenne*/

void ecart_a_moyenne(float tab[],float tab_ecart_a_moyenne[],float Moyenne,int N)

{
  int i=1;

  while (i<(N+1))
    {
      tab_ecart_a_moyenne[i]=(tab[i]-Moyenne);i++;
    };

}

/*Calcul du coefficient de corrélation "r"*/

double corr(float SommeCarreXiMoinMoyenneXi,float SommeCarreYiMoinMoyenneYi,float a)

{

  double r, q, rCarre;



  /*Calcul de r*/

  rCarre=(((a*a)*(SommeCarreXiMoinMoyenneXi))/SommeCarreYiMoinMoyenneYi);

  /*Le signe de r est le meme que a*/

  if (a>=0.0)
    {q = 1;
    }
  else
    {q = -1;
    };

  r = (sqrt(rCarre)) * q;
  return (r);

}

/*************************************/
/*    Fonction d'affichage divers    */
/*************************************/


/*Fonction d'affichage des résultats*/

void affichage(float tab[])

{
  printf("\n%c",201);
  ligne(12);/*boucle d'affichage double ligne*/
  printf("%c\n",187);

  printf("%c R%csultats: %c\n",186,130,186);

  printf("%c",200);
  ligne(12);/*boucle d'affichage double ligne*/
  printf("%c",188);

  printf("\n\nSomme Xi = %f",tab[0]);
  printf("\nSomme Yi = %f\n",tab[1]);


  printf("\nMoyenne des Xi = %f",tab[2]);
  printf("\nMoyenne des Yi = %f\n",tab[3]);

  printf("\nSomme des (Xi * Yi) = %f",tab[4]);

  printf("\n\nPente de la droite:=========> a = %f",tab[7]);

  printf("\nOrdonn%ce %c l'origine:=======> b = %f",130,133,tab[8]);

  printf("\nCoefficient de corr%clation:=> r = %lf",130,tab[9]);

  /*Fonction d'affichage de l'equation*/

  aff_equation(tab);

  printf("\n");

  getchar();
}

/*Fonction d'affichage simple de l'équation*/

void aff_equation(float tab[])
{
  printf("\n\nL'%cquation de la droite est:\n\n",130);
  printf("     ");
  ligne2(201,27,187);
  printf("\n     %c Y = %f X + %f %c\n",186,tab[7],tab[8],186);
  printf("     ");
  ligne2(200,27,188);
  printf("\n");
}

/*Fonction d'affichage des doubles lignes*/

void ligne(int nbr)
{
  int j=0;

  while(j<nbr)
    {printf("%c",205);j++;};
}

/*Fonction d'affichage des doubles lignes2*/

void ligne2(int deb,int nbr,int fin)
{
  int j=0;

  printf("%c",deb);

  while(j<nbr)
    {printf("%c",205);j++;
    }

  printf("%c",fin);
}

/*Fonction d'affichage des titres*/

void titre(char titre[])
{
  int nbr,j=0;

  nbr = strlen(titre)+2;

  printf("\n");
  ligne2(201,nbr,187);
  printf("\n%c %s %c",186,titre,186);
  printf("\n");
  ligne2(200,nbr,188);
  printf("\n\n");
}

/*Fonction d'affichage des donnée sous forme de tableau*/

void affich_tab(float tab[],float tab1[],float tab2[],float tab3[],float tab4[],float tab5[],int N)
{
  int i=1,j=0;

  printf("\n\n%c",201);


  ligne(22);/*boucle d affichage double ligne*/

  printf("%c",187);
  printf("\n%c Tableau des donn%ces: %c",186,130,186);
  printf("\n%c",200);


  ligne(22);/*boucle d affichage double ligne*/


  printf("%c",188);

  printf("\n\n%c",201);

  ligne(7);/*boucle d affichage double ligne*/

  printf("%c",203);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",203);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",203);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",203);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",203);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",187);

  printf("\n%c   N   %c      Xi     %c      Yi     %c     XiYi    %c  (Xi-<X>)%c  %c  (Yi-<Y>)%c  %c",186,186,186,186,186,253,186,253,186);
  printf("\n%c",204);
  ligne(7);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",185);

  /*Boucle d affichage des données proprement dites*/

  while(i<N+1)
    {
      printf("\n%c %3.d   %c%12.4e %c%12.4e %c%12.4e %c%12.4e %c%12.4e %c",186,i,186,tab1[i],186,tab2[i],186,tab3[i],186,tab4[i],186,tab5[i],186);i++;
    }

  printf("\n%c",204);
  ligne(7);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",185);


  printf("\n%c Somme %c%12.4e %c%12.4e %c%12.4e %c%12.4e %c%12.4e %c",186,186,tab[0],186,tab[1],186,tab[4],186,tab[5],186,tab[6],186);

  printf("\n%c",204);
  ligne(7);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",206);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",202);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",202);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",188);

  printf("\n%cMoyenne%c%12.4e %c%12.4e %c",186,186,tab[2],186,tab[3],186);

  printf("\n%c",200);
  ligne(7);/*boucle d affichage double ligne*/
  printf("%c",202);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",202);
  ligne(13);/*boucle d affichage double ligne*/
  printf("%c",188);

  printf("\n");
}

/*Fonction de Saufgarde dans un fichier text*/

void fichier(float tab[],float tab1[],float tab2[],float tab3[],float tab4[],float tab5[],int N)
{
  FILE   *sortie1;
  char car,filename[20];
  int i=1;

  printf("\nVoulez-vous enregistrer les resultats dans un fichier (o/n)?");
  scanf("%s",&car);


  if(car =='o')
    {
      /* Entree du nom du fichier*/
      /* il est cree si il n'existe pas */

      printf("\n\nTapez un nom de fichier:");
      scanf("%s",filename);

      printf ("\nOuverture du fichier: %s",filename);

      /*Ouvreture du fichier */

      sortie1  = fopen (filename, "a");

      /* Test d ouvreture */
      if (sortie1 == NULL)
	{
	  /* fopen a echoue */
	  printf ("\nErreur a l'ouverture du fichier: %s.",filename);
	  printf ("\nFin anormale!!!");
	  exit(4);
	}

      /* Si tout va bien, ecriture dans le fichier */


      fprintf(sortie1,"\n\n************************");
      fprintf(sortie1,"\n* Tableau des données: *");
      fprintf(sortie1,"\n************************\n\n");
      fprintf(sortie1,"\n************************************************************************************");
      fprintf(sortie1,"\n*   N   *       Xi     *       Yi     *      XiYi    *   (Xi-<X>)²  *   (Yi-<Y>)²  *");
      fprintf(sortie1,"\n************************************************************************************");

      while(i<N+1)
	{
	  fprintf(sortie1,"\n* %3.d   * %12.4e * %12.4e * %12.4e * %12.4e * %12.4e *",i,tab1[i],tab2[i],tab3[i],tab4[i],tab5[i]);i++;
	}

      fprintf(sortie1,"\n************************************************************************************");
      fprintf(sortie1,"\n* Somme * %12.4e * %12.4e * %12.4e * %12.4e * %12.4e *",tab[0],tab[1],tab[2],tab[3],tab[4]);
      fprintf(sortie1,"\n************************************************************************************");
      fprintf(sortie1,"\n*Moyenne* %12.4e * %12.4e *",tab[2],tab[3]);
      fprintf(sortie1,"\n***************************************");


      fprintf(sortie1,"\n\n");
      fprintf(sortie1,"*************\n");
      fprintf(sortie1,"* Résultats:*\n");
      fprintf(sortie1,"*************\n\n");


      fprintf(sortie1,"\nSomme Xi = %f",tab[0]);
      fprintf(sortie1,"\nSomme Yi = %f\n",tab[1]);


      fprintf(sortie1,"\nMoyenne des Xi = %f",tab[2]);
      fprintf(sortie1,"\nMoyenne des Yi = %f\n",tab[3]);

      fprintf(sortie1,"\nSomme des (Xi * Yi) = %f",tab[4]);

      fprintf(sortie1,"\n\nPente de la droite:=========> a = %f",tab[7]);

      fprintf(sortie1,"\nOrdonnée %c l'origine:=======> b = %f",133,tab[8]);

      fprintf(sortie1,"\nCoefficient de corrélation:=> r = %lf",tab[9]);

      fprintf(sortie1,"\n\nL'équation de la droite est:");
      fprintf(sortie1,"\n\n   *****************************");
      fprintf(sortie1,"\n   * Y = %f X + %f *",tab[7],tab[8]);
      fprintf(sortie1,"\n   *****************************");
      fprintf(sortie1,"\n\n");

      /* fermeture des fichiers */

      fclose (sortie1);

      printf ("\nEcriture termin%ce...\n\n",130);

    }
  ;getchar();

}

/*Fonction de calcul de la DMC*/

void regression(float Xi[],float Yi[],int N,float result[],float ProduitXiYi[],float carre_ecart_a_moyenne_Xi[],float carre_ecart_a_moyenne_Yi[])

{

  float SommeXi;
  float SommeYi;
  float MoyenneXi;
  float MoyenneYi;
  float SommeProduitXiYi;
  float SommeCarreXiMoinMoyenneXi;
  float SommeCarreYiMoinMoyenneYi;
  float a;
  float b;
  double r;
  float tab_ecart_a_moyenne[MAX];
  float ecart_a_moyenne_Xi[MAX];
  float ecart_a_moyenne_Yi[MAX];
  int i=1;

  /*Calcul de la somme des Xi et Yi*/

  SommeXi= somme(Xi,N);
  SommeYi= somme(Yi,N);

  /*Calcul des moyennes des Xi et Yi*/

  MoyenneXi = moyenne(SommeXi,N);
  MoyenneYi = moyenne(SommeYi,N);

  /*Calcul de de la pente "a"de la droite et de l'ordonee à l'origine "b" */



  /*Somme des Xi*Yi*/

  produittab(Xi,Yi,ProduitXiYi,N);
  SommeProduitXiYi = somme(ProduitXiYi,N);



  /*calcul des (Xi- MoyenneXi)² et (Yi- MoyenneYi)² */

  ecart_a_moyenne(Xi,tab_ecart_a_moyenne,MoyenneXi,N);

  i=1;
  while (i<(N+1))
    {
      ecart_a_moyenne_Xi[i] = tab_ecart_a_moyenne[i];
      carre_ecart_a_moyenne_Xi[i] = ((ecart_a_moyenne_Xi[i])*(ecart_a_moyenne_Xi[i]));i++;
    };

  ecart_a_moyenne(Yi,tab_ecart_a_moyenne,MoyenneYi,N);

  i=1;
  while (i<(N+1))
    {
      ecart_a_moyenne_Yi[i] = tab_ecart_a_moyenne[i];
      carre_ecart_a_moyenne_Yi[i] = ((ecart_a_moyenne_Yi[i])*(ecart_a_moyenne_Yi[i]));i++;
    };


  /*Somme des (Xi- MoyenneXi)²*/


  SommeCarreXiMoinMoyenneXi = somme(carre_ecart_a_moyenne_Xi,N);
  SommeCarreYiMoinMoyenneYi = somme(carre_ecart_a_moyenne_Yi,N);


  /*Appel de la fonction de calcul de la pente "a" de la droite*/


  a=pente(SommeProduitXiYi,MoyenneXi,MoyenneYi,SommeCarreXiMoinMoyenneXi,N);


  /*Appel de la fonction de calcul de l'ordonee a l'orrigine "b"*/


  b=ordonee(MoyenneXi,MoyenneYi,a);


  /*Calcul du coefficient de corrélation "r"*/

  r=corr(SommeCarreXiMoinMoyenneXi,SommeCarreYiMoinMoyenneYi,a);

  /*Stockage des résultats dans une tableau de varialbes*/

  result[0]=SommeXi;
  result[1]=SommeYi;
  result[2]=MoyenneXi;
  result[3]=MoyenneYi;
  result[4]=SommeProduitXiYi;
  result[5]=SommeCarreXiMoinMoyenneXi;
  result[6]=SommeCarreYiMoinMoyenneYi;
  result[7]=a;
  result[8]=b;
  result[9]=r;

}
