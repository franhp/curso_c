/*Escriu un programa en què l’usuari escrigui deu paraules diferents de 10 caràcters com a màxim i les desi en una matriu que posteriorment serà desada en disc. */
#include <stdio.h>
#include <string.h>
#define COLS 5
#define ROWS 2
#define MAXWIDTH 10
void main() {
    int x,y,contador=1;
    FILE *pf;
      
  /* Definimos una matriz de tres dimensiones */
    char m[COLS][ROWS][MAXWIDTH];

  /* La rellenamos con un texto a modo de ejemplo */
    for(x=0; x<COLS; x++) {
        for(y=0; y<ROWS; y++) {
      /* Tener en cuenta que no controlamos el tamaño
       * de la cadena. No deberíamos superar MAXWIDTH
       */
            do{
                printf("\nParula %d\t", contador);
                scanf("%s", m[x][y]);
            } while(strlen(m[x][y])>9);
            contador++;
        }
    }
  
    if ((pf=fopen("paraules.txt", "wt"))==NULL){
        printf("\nError, no s'ha pogut obrir el fitxer\n");
    }
    else {
        /* Mostramos el contenido de cada posición */
        for(x=0; x<COLS; x++) {
            for(y=0; y<ROWS; y++) {
                fputs(m[x][y],pf);
                fputs("\n", pf);
            }  
        }
    }
    
    fclose(pf);
  
}  

