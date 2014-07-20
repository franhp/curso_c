#include <stdio.h>
#include <string.h>

struct llibre{
	char titol[20];
	char autor[20];
	int pag;
	float preu;
}biblio[30];

void ini(struct llibre [], int );

int buscar(struct llibre[], int , char[]);

void main(){

int i, n, res;
char cerca[20];

do{
	printf("\nQuants llibres? ");
	scanf("%d",&n);
	fflush(stdin);
}while((n<0)&&(n>30));

ini(biblio, n);

printf("\nQue vols buscar?");
scanf("%s", cerca);
fflush(stdin);

res<-buscar(biblio, n, cerca);

}

void ini(struct llibre biblio[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("\nTitol... ");
		scanf(" %s", biblio[i].titol);
		fflush(stdin);
		printf("\nAutor... ");
		scanf(" %s", biblio[i].autor);
		fflush(stdin);
		printf("\nPagines... ");
		scanf("%d", &biblio[i].pag);
		fflush(stdin);
		printf("\nPreu... ");
		scanf("%f", &biblio[i].preu);
		fflush(stdin);
	}
}

int buscar(struct llibre biblio[], int n, char cerca[]){
	int i, trobat, trobat2;
	for(i=0;i<n;i++){
		trobat=strcmp(cerca, biblio[i].titol);
		trobat2=strcmp(cerca, biblio[i].autor);
		if(trobat==0){
			printf("\nS'ha trobat per titol");
			printf("\n %s", biblio[i].titol);
			printf("\n %s", biblio[i].autor);	
			printf("\n%d", biblio[i].pag);
			printf("\n%f", biblio[i].preu);
			return trobat;
		}

		if(trobat2==0){
			printf("\nS'ha trobat per autor");
			printf("\n %s", biblio[i].titol);
			printf("\n %s", biblio[i].autor);	
			printf("\n%d", biblio[i].pag);
			printf("\n%f", biblio[i].preu);
			return trobat2;
		}	
		
	printf("\nNo s'ha trobat");
	}
}