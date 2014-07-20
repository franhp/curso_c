#include <stdio.h>
#include <string.h>

char * extreure(char *, int, int , char *);

void main(){
    char    cad1[20],cad2[20];
    int pos,longitud;
    
    printf("\nCad1\t");
    gets(cad1);
    
    printf("\nPosicio\t");
    scanf("%d", &pos);
    printf("\tLongitud\t");
    scanf("%d", &longitud);
    
    printf("\nEl resultat es %s\n", extreure(cad1,pos,longitud,cad2));
}

char * extreure(char *cad1, int pos, int longitud, char *cad2){
    int i, x=0;
    
    for(i=pos;i<=longitud;i++){
        *(cad2+x)=*(cad1+i);
        x++;
    }
    *(cad2+x)='\0';
    
    return(cad2);

}
