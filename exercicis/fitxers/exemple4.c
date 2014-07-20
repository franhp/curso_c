#include <stdio.h>
// LLEGIR FITXER
void main(){
    FILE *pf;
    char cad[80];
    
    if ((pf=fopen("exemple1.txt", "rt"))==NULL){
        printf("\nError, no s'ha pogut obrir el fitxer\n");
    }
    else {
        fgets(cad,80,pf); // caracter, limit de caracters (N) i fitxer
        puts(cad);
    }
    
    fclose(pf);
}
