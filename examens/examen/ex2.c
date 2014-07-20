#include <stdio.h>
#define N 50

int index (char *, char *);

void main(){
    char cad1[N], cad2[N];
    
    printf("\nIntrodueix la frase\t");
        gets(cad1);
    printf("\nInsereix el terme repetit\t");
        gets(cad2);
    
    printf("\nLa paraula \"%s\" s'ha repetit %d vegada(es)\n", cad2, index(cad1,cad2));
}

int index (char *cad1, char *cad2){
    int i,j,repeticions=0;
    for(i=0;*(cad1+i)!='\0';i++){
        if(*(cad1+i)==*(cad2)){
            for(j=0;(*(cad2+j)!='\0')&&(*(cad1+i+j)==(*(cad2+j)));j++);
	    if (*(cad2+j)=='\0') repeticions++;
        }
    }
    
    return repeticions;
    
}
