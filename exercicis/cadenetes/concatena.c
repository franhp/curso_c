#include <stdio.h>

char * concatenar(char *, char *);
void main(){
     char cad1[100]="Hola ", cad2[100]="que tal";
     printf("\n%s\n",concatenar(cad1,cad2));
}

char * concatenar(char *pcad1, char *pcad2){
     int i,j,z=0;
     for (i=0;*(pcad1+i)!='\0';i++);
     for (j=0;*(pcad2+j)!='\0';j++){
        *(pcad1+i)=*(pcad2+j);
	i++;
     }
*(pcad1+i)='\0';
return(pcad1);
}
