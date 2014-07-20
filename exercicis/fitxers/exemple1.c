#include <stdio.h>

void main(){
    FILE *pf;
    char c;
    
    if ((pf=fopen("exemple1.txt", "wt"))==NULL){
        printf("\nError, no s'ha pogut obrir el fitxer\n");
    }
    else {
        while( (c=getchar()) != EOF) fputc(c,pf);
    }
    
    fclose(pf);
}
