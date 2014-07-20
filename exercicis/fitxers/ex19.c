/*Crea el programa per recuperar i mostrar els nombres desats en el fitxer anterior 
*/

#include <stdio.h>
#define N 2
struct complex{
    float x,y;
}nombres[N];

void main(){

    FILE *pf;
    int i;
    
    if((pf=fopen("complex.bin", "rb"))==NULL) printf("\nMerda!");
    else {
        fread(&nombres,sizeof(struct complex)*N,1,pf);
        fclose(pf);
        for(i=0;i<N;i++){
            printf("\n%f %f", nombres[i].x,nombres[i].y);
        }
    }
    
}
