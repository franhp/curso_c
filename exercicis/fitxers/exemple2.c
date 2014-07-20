#include <stdio.h>
// ESCRIURE FITXER
void main(){
    FILE *pf;
    char c;
    
    if ((pf=fopen("exemple1.txt", "rt"))==NULL){
        printf("\nError, no s'ha pogut obrir el fitxer\n");
    }
    else {
        while( (c=getc(pf)) != EOF) putchar(c);
    }
    
    fclose(pf);
}
