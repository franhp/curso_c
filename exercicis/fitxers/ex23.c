/* Fer un programa que obri el fitxer generat per l’exercici 21, actualitzi el valor dels 
camps especificats per l’usuari, i fet això, ho torni a desar en disc. */
#include <stdio.h>
#define N 100


struct info{
    char nom[50];
    char carrer[50];
    char numero[4];
    char ciutat[20];
    char codi_postal[5];
}contactes[N];


void main(){
    FILE *pf;
    int i;
    char c;
    
    if((pf=fopen("contactes.txt","rt"))==NULL) printf("\nError");
    else {
        while( (c=getc(pf)) != EOF){
            putchar(c);
        }
    }
    
    fclose(pf);
}
