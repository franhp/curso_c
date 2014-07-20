/*Escriu un programa que obri el fitxer que has creat abans i mostri per pantalla el valor 
d’aquests nombres. */

#include <stdio.h>

void main(){
    FILE *pf;
    char car;
    
    
    if((pf=fopen("paraules.txt","rt"))==NULL) printf("No s'ha pogut obrir");
    else {
        car=getc(pf); 
         
        while(car!=EOF){ 
            putchar(car); 
            car=getc(pf); 
        } 
        fclose(pf); 
    }
}


