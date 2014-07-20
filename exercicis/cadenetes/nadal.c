/*Joc de la moneda. Fet per Hector Costa Guzman.
Programat amb l'entorn Quanta i compilat amb exit amb gcc a Ubuntu 8.10 i a Windows XP amb DevC++ 
La norma de que es pot guanyar si un dels jugadors guanya 3 apostes mes que l'altre ho he fet com
a partides seguides, ja que no s'acababa d'entendre l'enunciat */
#include <stdio.h>
#include <string.h>
/*Constants per entendre millor el programa*/
#define PM 0             //dades[PM] = posicio moneda
#define PJ1 1            //dades[PJ1] = punts jugador 1
#define PJ2 2            //dades[PJ2] = punts jugador 2
#define RGJ1 3           //dades[RGJ1] = rondes guanyades jugador 1
#define RGJ2 4           //dades[RGJ2] = rondes guanyades jugador 2
#define RPJ1 5           //dades[RPJ1] = rondes perdudes jugador 1
#define RPJ2 6           //dades[RPJ2] = rondes perdudes jugador 2
#define NR 7             //dades[NR] = numero de ronda
#define RSGJ1 8          //dades[RSGJ1] = rondes seguides guanyades del jugador 1
#define RSGJ2 9          //dades[RSGJ2] = rondes seguides guanyades del jugador 2	
/*Funcions*/
void apostes(int [],int [],int [],char [],char []);
void tauler(int [], char [],char []);
int acabar(int [],char [],char []);
/*Funcio principal*/
int main(){
/*
  	 aj1 = apostes jugador 1
  	 aj2 = apostes jugador 2
  	 nj1 = nom jugador 1
  	 nj2 = nom jugador 2
*/
int dades[10]={0,50,50,0,0,0,0,1,0,0}, aj1[100], aj2[100], final=0;
char nj1[50], nj2[50];/*Per seguretat amb gets() hi poso un espai llarg*/
	printf("\n\t********************************************************************\n\t********************************************************************\n\t************* BENVINGUTS AL JOC DE LA MONEDA VERSIO 1.00 ***********\n\t********************************************************************\n\t********************** QUE TINGUEU UN BON JOC! *********************\n\t********************************************************************\n\t********************************************************************\n");
	/*Jugador 1*/
	printf("\n\tNom del jugador 1?: ");
	gets(nj1);
	/*Jugador 2*/
	printf("\n\tNom del jugador 2?: ");
	gets(nj2);
	printf("\n\t********************************************************************\n\t*********************** COMENCA EL JOC!!!! *************************\n\t********************************************************************\n");
	tauler(dades, nj1, nj2);
	/*Bucle del programa, condicio d'acabada: final=1*/
	while(final==0){	
		apostes(dades, aj1, aj2, nj1, nj2);
		tauler(dades, nj1, nj2);
		printf("\n\t>> Apreta Enter per continuar");
		getchar();
		getchar();
		final=acabar(dades, nj1, nj2);
	}
	    printf("\n\t>> Apreta Enter per Sortir");
		getchar();
}
/*Funcio de les apostes*/
void apostes(int dades[], int aj1[], int aj2[], char nj1[], char nj2[]){
	printf("\n\t********************************************************************\n\t********************************************************************\n\tJugada %d\n",dades[NR]);
	/*Aposta Jugador 1*/
	printf("\n\t\tTorn de: %s",nj1);
	printf("\n\t\tPunts: %d\n",dades[PJ1]);
	do{	printf("\t\tQuants punts vols apostar?\n\t\tMaxim %d: ",dades[PJ1]);
		scanf("%d",&aj1[dades[NR]]);
	}while(aj1[dades[NR]]>dades[PJ1]);
	/*Aposta Jugador 2*/
	printf("\n\t\t************************************************************\n\t\t************************************************************\n\n\t\tTorn de: %s",nj2);
	printf("\n\t\tPunts: %d\n",dades[PJ2]);
	do{	printf("\t\tQuants punts vols apostar?\n\t\tMaxim %d: ",dades[PJ2]);
		scanf("%d",&aj2[dades[NR]]);
	}while(aj2[dades[NR]]>dades[PJ2]);
	/*Comparem les apostes, avaluem la posicio de la moneda, incrementem les rondes guanyades o perdudes de cada jugador i ho escrivim per pantalla*/
	if (aj1[dades[NR]]>aj2[dades[NR]]){
		dades[PM]--;                   //Posicio de la moneda a l'esquerra 
		dades[RGJ1]++;                 //Rondes guanyades jugador 1 aumenta
		dades[RPJ2]++;                 //Rondes perdudes jugador 2 aumenta
		dades[RSGJ1]++;                //Rondes guanyades seguides jugador 1 aumenta
		dades[RSGJ2]=0;                //Rondes guanyades seguides jugador 2 es torna zero
		printf("\n\t********************************************************************\n\t********************************************************************\n\n\tEl guanyador es: %s\n",nj1);
		printf("\n\tEstat del joc:\n");
		printf("\n\t\tJugador 1: %s\n",nj1);	
		printf("\n\t\t\tJugades guanyades: %d\n\t\t\tJugades perdudes: %d\n\t\t\tJugades seguides guanyades: %d\n",dades[RGJ1],dades[RPJ1],dades[RSGJ1]);
		printf("\n\t\tJugador 2: %s\n",nj2);	
		printf("\n\t\t\tJugades guanyades: %d\n\t\t\tJugades perdudes: %d\n\t\t\tJugades seguides guanyades: %d\n",dades[RGJ2],dades[RPJ2],dades[RSGJ2]);
	}
	else if(aj2[dades[NR]]>aj1[dades[NR]]){
		dades[PM]++;                       //Posicio de la moneda a la dreta
		dades[RGJ2]++;                     //Rondes guanyades jugador 2 aumenta
		dades[RPJ1]++;                     //Rondes perdudes jugador 1 aumenta
		dades[RSGJ2]++;                    //Rondes guanyades seguides jugador 2 aumenta
		dades[RSGJ1]=0;                    //Rondes guanyades seguides jugador 1 es torna zero
		printf("\n\t********************************************************************\n\t*******************************************************************\n\n\tEl guanyador es: %s\n",nj2);
		printf("\n\tEstat del joc:\n");
		printf("\n\t\tJugador 1: %s\n",nj1);	
		printf("\n\t\t\tJugades guanyades: %d\n\t\t\tJugades perdudes: %d\n\t\t\tJugades seguides guanyades: %d\n",dades[RGJ1],dades[RPJ1],dades[RSGJ1]);
		printf("\n\t\tJugador 2: %s\n",nj2);	
		printf("\n\t\t\tJugades guanyades: %d\n\t\t\tJugades perdudes: %d\n\t\t\tJugades seguides guanyades: %d\n",dades[RGJ2],dades[RPJ2],dades[RSGJ2]);;
	}
	else {
		printf("\n\t********************************************************************\n\t********************************************************************\n\n\tHi ha un empat en aquesta ronda!\n");
		printf("\n\tEstat del joc:\n");
		printf("\n\t\tJugador 1: %s\n",nj1);	
		printf("\n\t\t\tJugades guanyades: %d\n\t\t\tJugades perdudes: %d\n\t\t\tJugades seguides guanyades: %d\n",dades[RGJ1],dades[RPJ1],dades[RSGJ1]);
		printf("\n\t\tJugador 2: %s\n",nj2);	
		printf("\n\t\t\tJugades guanyades: %d\n\t\t\tJugades perdudes: %d\n\t\t\tJugades seguides guanyades: %d\n",dades[RGJ2],dades[RPJ2],dades[RSGJ2]);
	}
	/*Restem les apostes als punts de cada jugador*/
	dades[PJ1]=dades[PJ1]-aj1[dades[NR]];
	dades[PJ2]=dades[PJ2]-aj2[dades[NR]];
	/*Incrementem la ronda*/
	dades[NR]++;	
}
/*Funcio de dibuixar la taula*/
void tauler(int dades[], char nj1[], char nj2[]){
switch(dades[PM]){
	case -3 :
	printf("\n\t********************************************************************\n\t************************ ESTAT DEL TAULER **************************\n\t********************************************************************\n\n\n");
	printf("\t%s\n\n",nj1);
      printf("\t\t    |     |     |     |     |     |     |     |\n");
	printf("\t\t    |  O  |     |     |     |     |     |     |\n");
	printf("\t\t    |_____|_____|_____|_____|_____|_____|_____|\n\n\n");
	printf("\t\t\t\t\t\t\t\t\%s",nj2);
	printf("\n\n");
	break;
	case -2 :
	printf("\n\t********************************************************************\n\t************************ ESTAT DEL TAULER **************************\n\t********************************************************************\n\n\n");
	printf("\t%s\n\n",nj1);
      printf("\t\t    |     |     |     |     |     |     |     |\n");
	printf("\t\t    |     |  O  |     |     |     |     |     |\n");
	printf("\t\t    |_____|_____|_____|_____|_____|_____|_____|\n\n\n");
	printf("\t\t\t\t\t\t\t\t\%s",nj2);
	printf("\n\n");
	break;
	case -1 :
	printf("\n\t********************************************************************\n\t************************ ESTAT DEL TAULER **************************\n\t********************************************************************\n\n\n");
	printf("\t%s\n\n",nj1);
      printf("\t\t    |     |     |     |     |     |     |     |\n");
	printf("\t\t    |     |     |  O  |     |     |     |     |\n");
	printf("\t\t    |_____|_____|_____|_____|_____|_____|_____|\n\n\n");
	printf("\t\t\t\t\t\t\t\t\%s",nj2);
	printf("\n\n");
	break;
	case 0 :
	printf("\n\t********************************************************************\n\t************************ ESTAT DEL TAULER **************************\n\t********************************************************************\n\n\n");
	printf("\t%s\n\n",nj1);
      printf("\t\t    |     |     |     |     |     |     |     |\n");
	printf("\t\t    |     |     |     |  O  |     |     |     |\n");
	printf("\t\t    |_____|_____|_____|_____|_____|_____|_____|\n\n\n");
	printf("\t\t\t\t\t\t\t\t\%s",nj2);
	printf("\n\n");
	break;
	case 1 :
	printf("\n\t********************************************************************\n\t************************ ESTAT DEL TAULER **************************\n\t********************************************************************\n\n\n");
	printf("\t%s\n\n",nj1);
      printf("\t\t    |     |     |     |     |     |     |     |\n");
	printf("\t\t    |     |     |     |     |  O  |     |     |\n");
	printf("\t\t    |_____|_____|_____|_____|_____|_____|_____|\n\n\n");
	printf("\t\t\t\t\t\t\t\t\%s",nj2);
	printf("\n\n");
	break;
	case 2 :
	printf("\n\t********************************************************************\n\t************************ ESTAT DEL TAULER **************************\n\t********************************************************************\n\n\n");
	printf("\t%s\n\n",nj1);
      printf("\t\t    |     |     |     |     |     |     |     |\n");
	printf("\t\t    |     |     |     |     |     |  O  |     |\n");
	printf("\t\t    |_____|_____|_____|_____|_____|_____|_____|\n\n\n");
	printf("\t\t\t\t\t\t\t\t\%s",nj2);
	printf("\n\n");
	break;
	case 3 :
	printf("\n\t********************************************************************\n\t************************ ESTAT DEL TAULER **************************\n\t********************************************************************\n\n\n");
	printf("\t%s\n\n",nj1);
      printf("\t\t    |     |     |     |     |     |     |     |\n");
	printf("\t\t    |     |     |     |     |     |     |  O  |\n");
	printf("\t\t    |_____|_____|_____|_____|_____|_____|_____|\n\n\n");
	printf("\t\t\t\t\t\t\t\t\%s",nj2);
	printf("\n\n");
	break;
}
}
/*Funcio d'acabada del joc*/
int acabar(int dades[], char nj1[], char nj2[]){
	/*Analisi de possibilitats*/
	/*Possibilitat 1: si la posicio de la moneda es -3*/
	if (dades[PM]==-3){
		printf("\n\n\t********************************************************************\n\t********************************************************************\n\t EL JUGADOR 1: =>\t %s\t\t <= GUANYA PER LA MONEDA! \n\t********************************************************************\n\t********************************************************************\n\n",nj1);
		return 1;
	}
	/*Possibilitat 2: si la posicio de la moneda es 3*/
	if (dades[PM]==3){
		printf("\n\n\t********************************************************************\n\t********************************************************************\n\t EL JUGADOR 2: =>\t %s\t\t <= GUANYA PER LA MONEDA! \n\t********************************************************************\n\t********************************************************************\n\n",nj2);
		return 1;
	}
	/*Possibilitat 3: si el jugador 1 ha guanyat 3 jugades seguides*/
	if (dades[RSGJ1]==3){
		printf("\n\n\t********************************************************************\n\t********************************************************************\n\t EL JUGADOR 1: =>\t %s\t\t <= GUANYA PER RONDES! \n\t********************************************************************\n\t********************************************************************\n\n",nj1);
		return 1;
	}
	/*Possibilitat 4: si el jugador 2 ha guanyat 3 jugades seguides*/
	if (dades[RSGJ2]==3){
		printf("\n\n\t********************************************************************\n\t********************************************************************\n\t EL JUGADOR 2: =>\t %s\t\t <= GUANYA PER RONDES! \n\t********************************************************************\n\t********************************************************************\n\n",nj2);
		return 1;
	}
	else return 0;
}
