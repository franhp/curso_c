/*Crea un programa amb la finalitat d’obrir el fitxer anterior i mostrar el valor dels 10 
nombres escrits en el fitxer. */
#include <stdio.h>
#define N 11

void main(){
    FILE *pf;
    int i;
    float v[N];
    
    if((pf=fopen("arrels.bin","rb"))==NULL) puts("No hi ha hagut sort\n");
    else {
        for(i=1;i<N;i++){
            fread(&v[i],sizeof(float),1,pf);
            printf("\nsqrt(%d) = %f", i , v[i]);
        }
        fclose(pf);
    }    
}
