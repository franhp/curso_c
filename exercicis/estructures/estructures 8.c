#include <stdio.h>
#include <stdlib.h>

struct producte{
	char nom[30];
	float quantitat;
	float preu;
}cataleg[100];

void ini(struct producte [], int n);
void buscar(struct producte [], char [] , int );

void main (){
	
	int n,res;
	char cerca[30];

	printf("\nQuants productes vols inicialitzar? ");
	scanf("%d",&n);

	ini(cataleg, n);

	printf("\nNom del producte a cercar? ");
	fflush(stdin);
	scanf("%s", cerca);

	buscar(cataleg, cerca, n);
}

void ini(struct producte cataleg[], int n){
	int i;
	for(i=0;i<n;i++){
		
		fflush(stdin);

		printf("\nNom producte...");
		fflush(stdin);
		scanf("%s", cataleg[i].nom);

		printf("\nQuantitat producte...");
		fflush(stdin);
		scanf("%f", &cataleg[i].quantitat);

		printf("\nPreu producte...");
		fflush(stdin);
		scanf("%f", &cataleg[i].preu);

	}
}

void buscar(struct producte cataleg[], char cerca[], int n){
	int i,trobat;
	for(i=0;i<n;i++){
		trobat=strcmp(cerca, cataleg[i].nom);
		if (trobat==0){
			printf("\n%s", cataleg[i].nom);
			printf("\n%f", cataleg[i].quantitat);
			printf("\n%f\n", cataleg[i].preu);
		}
	}	
}
 
