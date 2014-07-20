#include <stdio.h>
#include <string.h>
#define N 20

struct llibre{
	char titol[N];
	char autor[N];
	int pag;
	float preu;
};

void ini(struct llibre [], int n);
void mostra(struct llibre[], int n);

void main(){
	struct llibre biblio[N];
	int n;
		
	do{
		printf("\nQuants llibres? ");
		scanf("%d",&n);
	}while((n<1)||(n>N));
	
	fflush(stdin);	

	ini(biblio,n);
	mostra(biblio,n);
}

void ini(struct llibre biblio[], int n){
	int i;
	
	for(i=0;i<n;i++){
		printf("\n Titol (sense espais)...");
		scanf(" %s",&biblio[i].titol);
		printf("\n Autor (sense espais)...");
		scanf(" %s",&biblio[i].autor);
		printf("\n Pagines...\t");
		scanf("%d", &biblio[i].pag);
		printf("\n Preu...\t");
		scanf("%f", &biblio[i].preu);
	}
}

void mostra(struct llibre biblio[], int n){
	int i;

	for(i=0;i<n;i++){
		printf("\n Titol... %s",biblio[i].titol);
		printf("\n Autor... %s",biblio[i].autor);
		printf("\n Pagines... %d",biblio[i].pag);
		printf("\n Preu... %f",biblio[i].preu);
	}
}