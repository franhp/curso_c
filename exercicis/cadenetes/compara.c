#include <stdio.h>

int comparar (char *, char *);
void main(){
     char cad1[]="casa", cad2[]="cosa";

     if (comparar(cad1, cad2)==2) printf("\nCad1 es mes petita\n\n");
     else if (comparar(cad1, cad2)==1) printf("\nCad1 es mes gran\n\n");
     else printf("\nCad1 es igual a Cad2\n\n");
}

int comparar (char *pcad1, char *pcad2){
     int i,j,s1=0,s2=0;
     for (i=0;(*(pcad1+i)!='\0' || *(pcad2+i)!='\0');i++){
         s1=s1+*(pcad1+i);
         s2=s2+*(pcad2+i);
     }
     if(s1>s2) return 1;
     else if (s1<s2) return 2;
     else if (s1==s2) return 0;
}
