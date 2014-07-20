#include <stdio.h>

void main(){
    FILE *pf;
    char cad[80];
    
    if ((pf=fopen("exemple1.txt", "at"))==NULL){
        printf("\nError, no s'ha pogut obrir el fitxer\n");
    }
    else {
        gets(cad);
        printf("\nEscrit cad a *pf\n");
        fputs(cad,pf);
        printf("\nHo printo\n");
        puts(cad);
    }
    
    fclose(pf);
}
