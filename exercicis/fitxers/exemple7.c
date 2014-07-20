#include <stdio.h>
#define N 3

void ini(float [][N]);

void main(){
    FILE *pf;
    float mat[N][N];
    int i,j;
    
    ini(mat);
    if((pf=fopen("matriu.bin","wb"))==NULL) puts("error");
        else{
            fwrite(mat,sizeof(mat),1,pf);
            printf("\n el punter fitxer esta a a %ld", ftell(pf));
        }
}

void ini (float m[][N]){
    int i,j;
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("\n m[%d][%d]", i, j);
            scanf("%f", &m[i][j]);
        }
    }
    
}
