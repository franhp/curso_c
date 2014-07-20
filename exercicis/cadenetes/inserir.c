#include<stdio.h>

char * inserir(char *, int, char *);
int longitud(char *);

void main(){
	char cad1[50]="El es feo", cad2[]="niño ";
	int pos=3;
		printf("%s\n",inserir(cad1,pos,cad2));
}

int longitud(char *cad1){
	int i;
	for(i=0; *(cad1+i)!='\0'; i++);
	return(i);
}

char * inserir(char *cad1, int pos, char *cad2){
	int i,j,k=0;
	k=longitud(cad1)+longitud(cad2);
	for(i=longitud(cad1)+1; i>=pos; i--, k--){
		*(cad1+k+1)=*(cad1+i);
	}
	for(i=pos, j=0; *(cad2+j)!='\0'; i++, j++) *(cad1+i)=*(cad2+j);
	return(cad1);
}
