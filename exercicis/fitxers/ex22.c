/*Realitzar un programa que primer calculi la longitud del fitxer desat en el programa 
anterior, l’obri i en mostri el contingut de l’estructura. 
*/
#include <stdio.h>
#define N 100
void main(){
    FILE *pf;
    int i,numcontactes=0;
    char c;
    
    if((pf=fopen("contactes.txt","rt"))==NULL) printf("\nError");
    else {
        while( (c=getc(pf)) != EOF){
            putchar(c);
            if(c=='\n') numcontactes++;
        }
    }
    
    printf("\nNum de contactes: %d\n", numcontactes);
    fclose(pf);
}
