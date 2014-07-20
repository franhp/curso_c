/*Fes un programa que generi els quadrats dels 10 primers nombres naturals, els posi en 
un vector i després els desi en disc en un fitxer. */
#include <stdio.h>
#include <math.h>
#define N 11

void main(){
    FILE *pf;
    int i;
    float v[N];
    
    for(i=1;i<N;i++){
        printf("\nEl quadrat de %d es %f", i, sqrt(i));
        v[i]=sqrt(i);
    }
    
    if((pf=fopen("arrels.bin","wb"))==NULL) puts("No hi ha hagut sort\n");
    else {
        for(i=1;i<N;i++){
            fwrite(&v[i],sizeof(float),1,pf);
        }
        fclose(pf);
    }
    
    
    
}
