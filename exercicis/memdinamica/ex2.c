/* 6. Escriure un programa en què l’usuari vagi introduint paraules, i quedin desades en una 
matriu creada dinàmicament. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char **p;
    char buffer[80]={'\0'};
    int lon=0,i,x,resp=0;
    
    if((p=(char**)malloc(5*sizeof(char*)))==NULL) printf("\nError");
    else{
        

        for(i=1;resp!=1;i++){
            
            printf("\nParaula %d\t",i);
            scanf(" %s", buffer);
            
            lon = strlen(buffer)+1;
            
            if((*(p+i)=(char*)malloc(lon*sizeof(char)))==NULL) printf("\nError");
            else {
                strcpy(*(p+i),buffer);
                printf("\nHe escrit %s a *(p+%d) i *(p+%d) es %s. Longitud actual: %d", *(p+i),i,i-1,*(p+(i-1)),lon);
            }
            
            printf("\n1 Para, 0 Continua\t");
            scanf("%d", &resp);
            
            //Clean Buffer
            char buffer[80]={'\0'};
        }

        for(x=1;x<i;x++){
            printf("cadena %d = %s\n", x, *(p+x));
        }
       
       free(p);
    }
    
    
}
/*
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
}*/