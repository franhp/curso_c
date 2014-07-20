#include<stdio.h>

int longitud(char *);

void main(){
	char cad1[]="Hola";
	printf("%d\n", longitud(cad1));
}
int longitud(char *cad1){
	int i;
	for(i=0; *(cad1+i)!='\0'; i++);
	return(i);
}
