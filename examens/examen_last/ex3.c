#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    char frase[100];
    FILE *pf;
    int i;
    
    printf("\nEscriu una frase: \t");
    gets(frase);
    
    if((pf=fopen("vertical.txt","wt"))==NULL) printf("No s'ha pogut obrir");
    
    else {
        for(i=0;*(frase+i)!='\0';i++){
            fputc(*(frase+i),pf);
            fputs("\n", pf);
        }
        fclose(pf);
    }
    
    
}