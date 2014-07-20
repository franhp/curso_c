#include<stdio.h>

char * esborrar(char *, int, int);

void main(){
	char cad1[]="Les cases grans i blaves";
	int longitud=8, pos=9;

	printf("%s\n",esborrar(cad1,pos,longitud));
}

char * esborrar(char *cad1, int pos, int longitud){
	int i,j;
	for(i=0; i<pos; i++);
	j=i;
	for(;*(cad1+i)!='\0';i++,longitud++){
		*(cad1+i)=*(cad1+j+longitud);
	}
	return(cad1);
}
