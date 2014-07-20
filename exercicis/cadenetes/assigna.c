#include <stdio.h>

char * copiar (char *, char *);
void main(){
     char cad1[50], cad2[]="Hola";
     printf("cad_origen = %s\n",cad2); 
     printf("cad_destí = %s\n", copiar(cad1, cad2));
}

char * copiar (char *pcad1, char *pcad2){
     int i;
     for (i=0;*(pcad2+i)!='\0';i++){
         *(pcad1+i)=*(pcad2+i);
     }
     *(pcad1+i)='\0';
     return pcad1;
}
