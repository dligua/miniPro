/// DLIGUA HELMI - LA II A1-2 Le 18/5/2019
/// Mini Projet - Gestion d'une Banque
///================les include================
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 50
///===============les declaration=============
 typedef struct
{
	int jour;

	int mois ;
	int annee;
}date;
struct client
{ int id_client;
char nom [30];
char prenom [30];
char num_tel [8];
date date_ouv;

};
struct compte
{	int id_compte;
	int id_client ;
	float solde_b;
	char op;
};
struct client client [max];
struct compte compte [max];
int n=0,m=0;
void suppresion()
{int i,k,v,d,j;
char ch1[5];
	system("color 1A");
do{
           printf("\n        *******     Suppresion    ****** \n\n");
           printf("          ============================================= \n\n");
           printf("      <1.  Un Par Un ---------------------------------- \n");
           printf("      <2.  Tout --------------------------------------- \n");
           printf("          ============================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%d",&k);
           printf("\n\n");
           switch(k){
case 1: system("cls");
printf ("voules_vous supprimez un  compte (taper : oui ou non)\n");
scanf ("%s",&ch1);
if (strcmp(ch1,"OUI")==0)

{
printf ("entre le id-compte : ");
scanf ("%d",&d);

for(i=1;i<=n;i++){

                       if(compte[i].id_compte==d){
                                             v=i;
                                              n=n-1;

                         for(j=v;j<=n;j++){
                            compte[j].id_client=compte[j+1].id_client;
                            compte[j].id_compte=compte[j+1].id_compte;
                            compte[j].op=compte[j+1].op;
                            compte[j].solde_b=compte[j+1].solde_b;
                                      }

                           printf("ce compte est supprime");                    }

                         else
						 {
                         	printf("Ce compte n'existe pas\n");
						 }
					   }
}
else
printf ("*****ok*****\n *****Merci*****\n");
;break;
case 2: system("cls");
printf ("voules_vous supprimes tout les compte(taper:oui ou non) \n");
scanf ("%s",&ch1);
if (strcmp(ch1,"oui")==0)
{
printf ("tout les comptes seraont supprimes \n ");
exit(0);
}
else
printf ("tout les comptes  ne seraont pas  supprimes \n ");
;break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        }while(k>2);


  system("PAUSE>null");
  system("cls");
}
int exist(int v)
{	int i;
	for (i=0;i<=n;i++)
	{
		if(client[i].id_client==v)
		return(1);
		else
		return(0);
	}
}
void ajoutclient()
{
int f,c;

printf("Identife client : ");
 scanf ("%d",&c);
              if(exist(c)==0)
                                        {
										  client[n].id_client=c;


                                        printf("Nom : ");
                                       scanf("%s",&client[n].nom);
                                       printf("Prenom : ");
                                       scanf("%s",&client[n].prenom);
                                       do
                                       {

                                       printf("numero de telephone : ");
                                       scanf("%s",&client[n].num_tel);


									   }while (strlen(client[n].num_tel)!=8);
									   do

									   {

									      printf ("donner la date \n ");
									      printf ("la jour :\n");

									      scanf ("%d",&client[n].date_ouv.jour);

									      do
									      {


										  printf ("le mois :\n ");
									      scanf ("%d",&client[n].date_ouv.mois);


										  }while (client[n].date_ouv.mois>12);
									      do
									      {


										  printf ("la annee :\n ");
									      scanf ("%d",&client[n].date_ouv.annee);

										   }
										   while (client[n].date_ouv.annee<2010);
										  f=0;
									      switch (client[n].date_ouv.mois)
									      {
									      case 1:case 3:case 5:case 7:case 8:case 10:case 12:
										  if(client[n].date_ouv.jour>31)
										  printf (" se mois contient 31comme maximum de nombre de jour  \n");
										   else
										  f=1;
										  break ;
										  case 4: case 6 :case 9 :case 11 :
										  	if(client[n].date_ouv.jour>30)

										  printf ("se mois contient 30 comme de nombre de jour  \n");
										  else
										  f=1;
									      	break;
									      	case 2:if((client[n].date_ouv.jour>29)&&(client[n].date_ouv.annee%4==0))
									      	printf ("valide le jour \n");
									      	 else
										  f=1;
									      	break ;
									      	default: printf ("verifer svp \n ");

										  }
										  }
										  while(f!=1);
									      printf ("donner le identifie de compte \n");
									      scanf ("%d",&compte[n].id_compte);
									      printf ("donner les solde de base \n");
									      scanf ("%d",&compte[n].solde_b);
									       compte[n].id_client=c;
                                       n=n+1;
	                                  printf("L'ajout de cliient est termine'");

									  }
                              else
                              {
							  printf ("se client deja existe entre un autre id_client pour n autre client  svp \n");
                              ajoutclient();


							  }
							   printf("Cliquer sur <Enter> pour continuer");
							   system("PAUSE>null");
							   system("cls");

}
///===========gestion des clients=================
int  gestiondeclient()
{int m ,i,r,a,c,t,k,z,p,f,x ;
char ch [30];
char ch4[20];
char ch3[20];
system("color 1A");
lab1:
do{
           printf("\n        *******      Gestion des clients   ****** \n\n");
           printf("          ============================================= \n\n");
           printf("       1.  Ajout Client-------------------------------- \n");
           printf("       2.  Modification ------------------------------- \n");
           printf("       3.  Suppresion---------------------------------- \n");
           printf("       4.  Rechercher---------------------------------- \n");
           printf("       5.  Menu General  ------------------------------ \n");
           printf("          ============================================== \n\n");
           printf("Entrer votre choix : ");
           scanf("%d",&m);
           printf("\n\n");
           switch(m){
case 1:
system("cls");
ajoutclient();
system("cls");

break;
case 2: system("cls");
printf ("donner le identifier de client \n ");
scanf ("%d",&z);
if (exist(z)==1)

{
printf ("voules_vous modifier tout les coordonnees de ce client \n");
scanf ("%s",&ch3);
if (strcmp(ch3,"NON")==0)
{
	system("color 1A");
	do
	{
		printf("     1. NOM-------------------------------- \n");
           printf("  2.  PRENOM  --------------------------- \n");
           printf("  3.  NUMERO DE TELPHONE ----------------- \n");
           printf("  4.  DATE DE OUVERTURE ------------------ \n");
           printf ("entre votre choix\n");
           scanf ("%d",&p);
		switch (p)
		{case 1:
				for (i=0;i<=n;i++)
		{
		if(client[i].id_client==z)
		{
			 printf ("entrer le nouveau nom \n");
			 	scanf ("%s",&client[i].nom);
			}
			}
			break;

			case 2 :

				for (i=0;i<=n;i++)
		{
		if(client[i].id_client==z)
		{
			  printf ("enter le nouveau prenom \n");
			scanf ("%s",&client[i].prenom);
			}
			}
			break;
			case 3:

				for (i=0;i<=n;i++)
		{
		if(client[i].id_client==z)
		{
			 printf ("entrer le nouveau numero  \n");
			scanf ("%s",&client[i].num_tel);
        }
			}
			break;
			case 4:
				printf ("entrer la nouvelle date \n");
			scanf ("%s",&ch4);
			default : system("cls");printf("votre choix n'est pas valide !!!\n");
		}

		}while (p>5);

		}
	else
	{
		for (i=0;i<=n;i++)
		{
		if(client[i].id_client==z)
		{

		  printf("Nom : ");
                                       scanf("%s",&client[i].nom);
                                       printf("Prenom : ");
                                       scanf("%s",&client[i].prenom);
                                       do
                                       {

                                       printf("numero de telephone : ");
                                       scanf("%s",&client[i].num_tel);


									   }while (strlen(client[i].num_tel)!=8);
									   do

									   {

									      printf ("donner la date \n ");
									      printf ("la jour :\n");

									      scanf ("%d",&client[i].date_ouv.jour);

									      do
									      {


										  printf ("le mois :\n ");
									      scanf ("%d",&client[i].date_ouv.mois);


										  }while (client[i].date_ouv.mois>12);
									      do
									      {


										  printf ("la annee :\n ");
									      scanf ("%d",&client[i].date_ouv.annee);

										   }
										   while (client[i].date_ouv.annee<2010);
										  f=0;
									      switch (client[i].date_ouv.mois)
									      {
									      case 1:case 3:case 5:case 7:case 8:case 10:case 12:
										  if(client[i].date_ouv.jour>31)
										  printf (" se mois contient 31comme maximum de nombre de jour  \n");
										   else
										  f=1;
										  break ;
										  case 4: case 6 :case 9 :case 11 :
										  	if(client[i].date_ouv.jour>30)

										  printf ("se mois contient 30 comme de nombre de jour  \n");
										  else
										  f=1;
									      	break;
									      	case 2:if((client[i].date_ouv.jour>29)&&(client[i].date_ouv.annee%4==0))
									      	printf ("valide le jour \n");
									      	 else
										  f=1;
									      	break ;
									      	default: printf ("verifier svp \n ");

										  }
										  }
										  while(f!=1);
									      printf ("donner l'identifiant de compte \n");
									      scanf ("%d",&compte[i].id_compte);
									      printf ("donner les solde de base \n");
									      scanf ("%d",&compte[i].solde_b);
                }
		}
		}
	}

else
{
  printf ("se client n existe pas \n");
}
printf("Cliquer sur <Entrer> pour continuer");
system("PAUSE>null");
system("cls");

break;
case 3: system("cls");
suppresion();
printf("Cliquer sur <Entrer> pour continuer");
system("PAUSE>null");
system("cls");
break;
case 4: system("cls");
	system("color 1A");
do{
           printf("\n        *******     Rechercher    ****** \n\n");
           printf("          ============================================= \n\n");
           printf("      <1.  Par Id_CLient ------------------------------ \n");
           printf("      <2.  Par Nom ------------------------------------ \n");
           printf("          ============================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%d",&r);
           printf("\n\n");
           switch(r){
case 1: system("cls");
printf ("donner le numero d'identite \n");
scanf ("%d",&a);
	t=0;

for (i=0;i<=n;i++)
{
	if(client[i].id_client==a)
	{
	t=1;
	   }
}
if (t==1)
{
printf ("client existant \n ");
}
else
{
printf ("client n' existe pas \n");
}
printf("Cliquer <Entrer> pour continuer ....");
system("PAUSE>null");
break;
case 2:
system("cls");
printf ("donner  le nom***********");
printf ("**********\n");
scanf ("%s",&ch);
k=0;
for (i=0;i<n;i++)
{
if (strcmp (client[i].nom,ch)==0)
{
	k=1;
}
}
if (k==1)
{
	printf ("client existant \n ");
}
else
{
	printf ("client n'existe pas \n");
}
printf("Cliquer <Entrer> pour continuer ....");
system("PAUSE>null");
break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        }while(r>2);

break;
  case 5: system("cls");
  fflush(stdin);
system("clear");
break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        }while(m>5);
  }
void  fermture()
{ int d,k,i;
printf ("**********fermture compte**********\n\n");
printf ("entre le id-compte\n ");
scanf ("%d",&d);
k=0;
for (i=0;i<=n;i++)
{
	if (compte[i].id_compte==d)
         {
         	k=i;
          	}
  }
 for (i=k+1;i<=n;i++)
{
	compte[k]=compte[i];
  k++;
}
printf("le compte est fermé avec succés\n");
printf("Clicquer <Enter> pour contunier\n");
system("PAUSE>null");
system("cls");
}
void consultation()
{ int i;
printf ("**********consulatation**********\n\n ");
printf ("Id_client :\n ");
printf (" Id_compte| Nom & Prénom| Solde de base| Opérations effectuées/date  | \n");
for (i=0;i<=n;i++)
{
	printf ("%d\n",&compte[i].id_client);
	printf ("%d | %s %s |  %f| %c| %d %d  %d \n",compte[i].id_compte, client[i].nom,client[i].prenom,compte[i].solde_b,client[i].date_ouv.jour,client[i].date_ouv.mois,client[i].date_ouv.annee);
}
printf ("indication :\n");
printf ("R: retairt \n v: vairenemt \n");
printf("Cliquer sur <Entrer> pour retourner au menu ...");
system("PAUSE>null");
system("cls");
}
void gestiondecompte()
{int  i,f ,h,k,d;
char ch1[10];
system("color 1A");
do{
           printf("\n        *******      Gestion des comptes  ****** \n\n");
           printf("          ============================================= \n\n");
           printf("      <1.  Nouveau Compte------------------------------ \n");
           printf("      <2.  Consultation  ------------------------------ \n");
           printf("      <3.  Fermature De Compte ------------------------ \n");
           printf("      <4.  Menu General  ------------------------------ \n");
           printf("          ============================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%d",&f);
           printf("\n\n");
           switch(f){
case 1: system("cls");
printf ("**********ajoute un niveau compte********** \n\n");
printf ("donner le identife de niveau  clinet \n");
scanf ("%d",&h);
for(i=0;i<=n;i++)
{
	if (compte[i].id_client==h)
             {
	   printf ("deja exist voulez_vous ajoute un autre compte pour se client \n");
                   scanf ("%s",ch1);
                  if (strcmp (ch1,"oui")==0)
               {     compte[n+1].id_client=h;
                     printf ("donner le identifie de compte \n");
									      scanf ("%d",&compte[n+1].id_compte);
									      printf ("donner les solde de base \n");
									      scanf ("%d",&compte[n+1].solde_b);
			   }
		     }
	else
	ajoutclient();
	break;

}
;break;
case 2: system("cls");
consultation();
;break;
case 3: system("cls");
fermture();
;break;
case 4: system("cls");
fflush(stdin);
system("clear");
;break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        }while(f>4);
}///===========gestion de operation=================
int  gestiondeoperation()
{
	int p ,a,e,i ;
system("color 1A");
do{
           printf("\n        *******      Gestion des Operations   ****** \n\n");
           printf("          ============================================= \n\n");
           printf("      <1.  .Retrait------------------------------------ \n");
           printf("      <2.  Virement   --------------------------------- \n");
           printf("      <3.  Menu General  ------------------------------ \n");
           printf("          ============================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%d",&p);
           printf("\n\n");
           switch(p){
case 1: system("cls");
printf ("donner le identife de compte \n");
scanf ("%d",&e);

do
{
	printf ("donner le nomtant retairt \n  ");
	scanf ("%d",&a);


}
while(a<700);
	for(i=0;i<n&&(compte[i].id_compte==e);i++)
	{
    if (compte[i].solde_b<a)
      printf ("ne peut pas retairt se prix \n");
else


	{
	compte[i].op='R';
	compte[i].solde_b=compte[i].solde_b-a;
     printf ("retairt avec succes \n");


	}
}
printf("Cliquer sur <Entrer> pour retourner au menu .");
system("PAUSE>Null");
system("cls");
break;
case 2: system("cls");
printf ("donner le identife de compte \n");
scanf ("%d",&e);
printf ("donner le nomtont verse \n");
scanf ("%d",&a);
	for(i=0;i<n &&(compte[i].id_compte==e);i++)
	{
	compte[i].solde_b=compte[i].solde_b-a;
	compte[i].op ='v';
		printf ("vairement avec succes \n");
	}
printf("Cliquer sur <Entrer> pour retourner au menu .");
system("PAUSE>Null");
system("cls");

break;
case 3: system("cls");
fflush(stdin);
system("clear");
break;
default : system("cls");printf("votre choix n'est pas valide !!!\n");
        }

        }while(p>4);

  return 0;





}
///===========quitter=================
void quitter(){
     system("cls");
 printf("\n\n        \t------------FIN-----------\n\n\n");
 printf("\n\n        \t------------MERCI-----------\n\n\n");
exit(0);
getchar();
 }
///===============menu prancipal=============
int main ()
{
	int  b,c,d ,i,choix;
	char e;
	system("color 5b");
lab1:
	while(1){


do{
	lab:   printf("=======       Le 3/4/2019    ||     mise a jour le 18/5/2019    =======");
           printf("\n        *******      Gestion d'une Banque    ****** \n\n");
           printf("          ============================================= \n\n");

           printf("      <A.  Gestion Des Clients ------------------------------ \n");
           printf("      <B.  Gestion Des Comptes------------------------------- \n");
           printf("      <C.  Gestion Des Operations---------------------------- \n");
           printf("      <D.  Quitter---------------------------------------- \n");
           printf("          ============================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%c",&e);
           printf("\n\n");
           if (e=='A')
           choix= 1;
           else  if (e=='B')
           choix=2;
           else if (e=='C')
           choix=3;
           else if (e=='D')
           choix=4;
           switch(choix){
case 1: system("cls");
gestiondeclient();
goto lab;
break;
case 2: system("cls");
gestiondecompte();
goto lab;
break;
case 3: system("cls");
gestiondeoperation();
goto lab;
break;
case 4: system("cls");
quitter();
break;
default : system("cls");
printf("votre choix n'est pas valide !!!\n");
        }
    }while(choix>4);
goto lab;
  }
}
