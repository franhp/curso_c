#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char cad[80],*pcad;
    int lon;
    
    puts("\nEscriu una frase ...\n");
    gets(cad);
    
    lon=strlen(cad);
    
    if((pcad=(char*)malloc((lon+1)*sizeof(char)))==NULL) puts("\nError");
    else {
        strcpy(pcad,cad);
        puts(pcad);
        free(pcad);
    }
}
