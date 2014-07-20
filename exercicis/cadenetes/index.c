#include <stdio.h>

int index(char *, char *);

void main(){
   char cad1[80]="la casa es gran",cad2[80]="gran";
   	if (index(cad1,cad2)==-1){
		printf("\nNo s'ha trobat la cadena\n");
   	}
	else	printf("%d\n",index(cad1,cad2));
}
int index(char *pcad1, char *pcad2){
	int i,j;
	for(i=0;(*(pcad1+i)!='\0');i++){
	      if(*(pcad1+i)==*(pcad2+0))               {
        	for(j=0;(*(pcad2+j)!='\0')&&(*(pcad1+i+j)==(*(pcad2+j)));j++);
		if (*(pcad2+j)=='\0') return i;
	      }
	}
	return -1;
}
