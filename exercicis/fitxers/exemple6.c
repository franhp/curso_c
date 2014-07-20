#include <stdio.h>
#define N 10

void llegir(float *, FILE *);

void main(){
    FILE *pf;
    float v[N];
    int i;
    
    llegir(v,pf);
    for(i=0;i<N;i++) printf("\nv[%d] = %f", i , v[i]);
    
}

void llegir(float *pv, FILE *pf){
    if ((pf=fopen("dades.bin", "rb"))==NULL) printf("\n Error");
    else {
        fread(pv,sizeof(float),1,pf);
    }
    fclose(pf);
}
