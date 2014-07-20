#include<stdio.h>

char * substituir(char *, char *, char *);
char * esborrar(char *, int, int);
int index(char *, char *);
int longitud(char *);
char * inserir(char *, int, char *);

void main(){
	char cad1[100]="El nen es lleig", cad2[]="lleig", cad3[]="alt";

	printf("%s\n",cad1);
	printf("%s\n",substituir(cad1,cad2,cad3));
}

char * substituir(char *cad1, char *cad2, char *cad3){
	int pos;

	pos=index(cad1,cad2);
	esborrar(cad1,index(cad1,cad2),longitud(cad2));
	inserir(cad1,pos,cad3);
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

int index(char *pcad1, char *pcad2){
	int i,j;
	for(i=0;(*(pcad1+i)!='\0');i++){
	      if(*(pcad1+i)==*(pcad2+0))               {
        	for(j=0;(*(pcad2+j)!='\0')&&(*(pcad1+i+j)==(*(pcad2+j)));j++);
		if (*(pcad2+j)=='\0') return i;
	      }
	}
	return 0;
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