#include <stdio.h>

char * extreure(char *, int , int, char *);
void main(){

char cad1[]="Les cases grans", cad2[50];
int longitud=10,pos=1;

     printf("\n%s\n",extreure(cad1,pos,longitud,cad2));
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