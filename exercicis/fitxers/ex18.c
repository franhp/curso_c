/*Escriu un programa en què l’usuari entri 10 nombres complexes, i que aquests siguin 
desats en disc en una sola sentència. */
#include <stdio.h>
#define N 2
struct complex{
    float x,y;
}nombres[N];

void main(){

    FILE *pf;
    int i;
    
    for(i=0;i<N;i++){
        printf("\nInsereix X del nombre %d\t", i);
        scanf("%f", &nombres[i].x);
        printf("\nInsereix Y del nombre %d\t", i);
        scanf("%f", &nombres[i].y);
    }
    
    if((pf=fopen("complex.bin", "wb"))==NULL) printf("\nMerda!");
    else {
        fwrite(&nombres,sizeof(struct complex)*N,1,pf);
        fclose(pf);
    }
    
}
