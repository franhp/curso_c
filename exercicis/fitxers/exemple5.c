#include <stdio.h>
#define N 10

void ini(float *);
void desa(float *, FILE *);

void main(){
    FILE *pf;
    float v[N];
    
    ini(v);
    desa(v,pf);
    
}

void ini(float *pv){
    int i;
    for(i=0;i<N;i++){
        printf("\nv[%d] =", i);
        scanf("%f", pv+i);
    }
}

void desa(float *pv, FILE *pf){
    if ((pf=fopen("dades.bin", "wb"))==NULL) printf("\n Error");
    else {
        fwrite(pv,N*sizeof(float),1,pf);
    }
       
    fclose(pf);
}
