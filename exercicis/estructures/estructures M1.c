#include <stdio.h>
#include <stdlib.h>
#define Z 1000
#define N 20

struct dades{
	char nom[N], servei;
	int dia, mes, any, h, m, s;
}magatzem[Z];

void afegir(struct dades [], int i);
void llistat(struct dades [], char[]);

void main(){
	int o,i=0;
	char nom[N];
	printf("\n\tPROGRAMA DE MIERDA 1:");
	while(o!=3){
		printf("\n\tOpcio 1: Afegir estructures alumnes");
		printf("\n\tOpcio 2: Llistat d'una maquina");
		printf("\n\tOpcio 3: Sortir\n");
		printf("\n\tOpcio desitjada: ");
		do{
			scanf("%d",&o);
			if (o<1||o>3) printf("\n\tOpcio incorrecta!");
		}while(o<1||o>3);
		if(o==1){
			afegir(magatzem, i);
			i++;
		}
		else if(o==2){
			printf("\n\tSobre quina màquina vols fer el llistat (20 caracters max, no espais)? ");
			scanf("%s", nom);
			llistat(magatzem, nom);
		}
	}
	printf("\n\tAdeu, vagi be\n\n");
}

void afegir(struct dades maquina[], int i){
	printf("\n\tNova estructura de dades:");
	printf("\n\tNom de la maquina (20 caracters max, no espais): ");
	scanf("%s", maquina[i].nom);
	do {
	printf("\n\tHores de servei: ");
	scanf("%d", &maquina[i].h);
	}while(maquina[i].h<0);
	do {
	printf("\n\tMinuts: ");
	scanf("%d", &maquina[i].m);
	}while(maquina[i].m>60 || maquina[i].m <0);
	do {
	printf("\n\tSegons: ");
	scanf("%d", &maquina[i].s);
	}while(maquina[i].s>60 || maquina[i].s <0);
	do {		
	printf("\n\tDia: ");
	scanf("%d", &maquina[i].dia);
	}while(maquina[i].dia>31 || maquina[i].dia<1);
	do {		
	printf("\n\tMes: ");
	scanf("%d", &maquina[i].mes);
	}while(maquina[i].mes>12 || maquina[i].mes<1);
	do {		
	printf("\n\tAny: ");
	scanf("%d", &maquina[i].any);
	}while(maquina[i].any>3000 || maquina[i].any<2000);
	printf("\n\tServei facturat? s/n: ");
	fflush(stdin);
	scanf(" %c", &maquina[i].servei);
}

void llistat(struct dades maquina[], char nom[]){
	int i,r;
	float preu,suma=0;
	printf("\n\t\thores\tminuts\tsegons\tdia\tmes\tany\tfacturat\tpreu");
	for (i=0;i<Z;i++){
		r=strcmp(nom, maquina[i].nom);
		if (r==0 && maquina[i].servei=='n'){
			printf("\n\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%c\t",maquina[i].nom,maquina[i].h,maquina[i].m,maquina[i].s,maquina[i].dia,maquina[i].mes,maquina[i].any,maquina[i].servei);
			preu=((maquina[i].h*60.00+maquina[i].m)*0.01);
			printf("\t%f",preu);
			suma=suma+preu;
		}
	}
	printf("\n\t\t\t\t\t\t\t\t\tTotal:\t%f",suma);
	printf("\n\n");
}

