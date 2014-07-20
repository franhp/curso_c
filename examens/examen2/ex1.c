#include <stdio.h>
#define N 50

int compara(char *, char *);

void main(){
    char cad1[N],cad2[N];
    
    printf("\nInsereix cad1 (posa la cadena llarga aqui)\t");
        gets(cad1);
    printf("\nInsereic cad2\t");
        gets(cad2);
        
    if(compara(cad1,cad2)==-1){
        printf("\nSon iguals\n");
    }
    else{
        printf("\nDifereixen a partir de la lletra %d\n", compara(cad1,cad2));
    }
}

int compara (char *cad1, char *cad2){
    int suma1=0, suma2=0,i=0;
    
    for(i=0;(*(cad1+i)!='\0');i++){
        suma1=*(cad1+i)+suma1;
        suma2=*(cad2+i)+suma2;
        if((suma1>suma2)||(suma1<suma2)) return i;
    }
    
    return(-1);
    
}
