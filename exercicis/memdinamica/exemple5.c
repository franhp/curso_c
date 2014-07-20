#include <stdio.h>
#include <stdlib.h>


void main() {
    int **p;
    int n,m,i,j;
    
    printf("\n n de files = ");
    scanf("%d", &n);
    
    if ((p=(int**)malloc(n*sizeof(int*)))==NULL) printf("\nError");
    else {
        for(i=0;i<n;i++){
            printf("\n columnes de la fila %d =", i);
            scanf("%d", &m);
            if((*(p+i)=(int*)malloc(m*sizeof(int)))==NULL) printf("\nError");
            else {
                for(j=0;j<m;j++){
                    printf("\nm[%d][%d] = ", i,j);
                    scanf("%d", &p[i][j]);
                }
            }
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("\n m[%d][%d] = %d", i, j, p[i][j]);
            }
        }
        free(p);
    }
}