/*8. Crear un programa en què es creï una estructura del tipus producte, que inclogui els 
següents camps : nom del producte, quantitat emmagatzemada, preu producte. En el 
programa s’haurà de declarar un array d’estructures d’aquest tipus. L’usuari 
determinarà les dades de quants productes vol escriure, i un cop els ha escrit tots, 
haurà d’escollir quin dels productes en vol veure la informació. 
*/


#include <stdio.h>
#include <string.h>
#define N 20
 
struct producte{ 
    char    nom_producte[N];
    int     quantitat;
    float   preu;
}cataleg[N];

void ini(struct producte [], int );
void cerca(struct producte [], char [], int );

void main(){

    int n;
    char troba[20];

    do{
        printf("\n quants llibres ?\t");
        scanf("%d", &n);
    }while((n<1)||(n>N));
    fflush(stdin);

ini(cataleg,n);

    printf("\nQuin nom de producte vols buscar?\t");
        scanf("%s", troba);
    cerca(cataleg,troba,n);

}

void ini(struct producte cataleg[], int n){
    int i;

    for(i=0;i<n;i++){
        printf("\nNom del producte...");
        fflush(stdin);
        scanf("%s", cataleg[i].nom_producte);
        printf("\n quantitat...");
        scanf("%d", &cataleg[i].quantitat);
        fflush(stdin);
        printf("\n preu...");
        scanf("%f", &cataleg[i].preu);
        fflush(stdin);
    }
}


void cerca(struct producte cataleg[], char troba[], int n){
    int i,v;
    
    for(i=0;i<n;i++){
        v=strcmp(cataleg[i].nom_producte,troba);
        if(v==0){
            printf("\n Nom del producte...%s",cataleg[i].nom_producte);
            printf("\n quantitat...%d",cataleg[i].quantitat);
            printf("\n preu...%f", cataleg[i].preu);
        }
    }
}

