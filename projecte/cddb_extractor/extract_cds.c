#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extract.h"
#define N 1024

struct disc{
    char discid[10];
    char artist[100];
    char title[100];
    char genre[20];
    char year[4];
    int duration; //En segons
};

int main(int argc, char *argv[]){
	struct disc discTmp;
        FILE *pf;
        FILE *pd;
        int lon=0,i,*posicions,count=0,suma=0;
        char c,**vector;
        char buffer[N]={'\0'};
        //Markers
        char seconds[]="Disc length",discid[]="DISCID",titlemark[]="DTITLE",year[]="DYEAR",genre[]="DGENRE";
        posicions = (int *)malloc(1*sizeof(int));
	if((pf=fopen(argv[1],"rt"))==NULL) printf("\nError");
        else {
		while( (c=getc(pf)) != EOF){
			if(c=='\n'){
				//Detecto de quantes posicions consta cada linia
				posicions=(int *)realloc(posicions,(count+1)*sizeof(int));
				posicions[count]=(ftell(pf))-suma;
				suma=posicions[count]+suma;
				count++;
			}
		}
		
		//Per prevenir l'error dels fitxers buits
		if(posicions[0]==0) return 1;
		
		if((pd=fopen("cds.txt", "at"))==NULL) printf("\nError");
		else{
			//Torno al principi
			fseek(pf,0,SEEK_SET);

			//Fico cada contacte en una posici� del vector
			if((vector=(char**)malloc(count*sizeof(char*)))==NULL) printf("\nError");
			else{
				for(i=0;i<count;i++){
					lon = (posicions[i]+1);
					if((*(vector+i)=(char*)malloc(lon*sizeof(char)))==NULL) printf("\nError");
					else {
						if(vector[i]!=0){
							fgets(vector[i], lon, pf);
							if((posicions[i])!=0){
								//Comparem aviam si hi ha algun dels nostres texts especials
								if(troba(vector[i],discid)!=-1){
									strcpy(buffer, vector[i]);
									clean(buffer);
									strcpy(discTmp.discid, buffer);
									reiniciaCadena(buffer);
								}
								if(troba(vector[i],titlemark)!=-1){
									strcpy(buffer, vector[i]);
									show_artist(buffer);
									strcpy(discTmp.artist, buffer);
									reiniciaCadena(buffer);
									strcpy(buffer, vector[i]);
									show_title(buffer);
									strcpy(discTmp.title, buffer);
									reiniciaCadena(buffer);
								}
								if(troba(vector[i],year)!=-1){
									strcpy(buffer, vector[i]);
									clean(buffer);
									strcpy(discTmp.year, buffer);
									reiniciaCadena(buffer);
								}
								if(troba(vector[i],genre)!=-1){
									strcpy(buffer, vector[i]);
									clean(buffer);
									strcpy(discTmp.genre, buffer);
									reiniciaCadena(buffer);
								}
								if(troba(vector[i],seconds)!=-1){
									discTmp.duration = changeHour(vector[i]);
								}
							}
						}
					}
				}
			}
		}
		//Ho escric
		fprintf(pd,"%s\t%s\t%s\t%s\t%s\t%d\n", discTmp.discid, discTmp.artist, discTmp.title, discTmp.genre, discTmp.year, discTmp.duration);
	}

	fclose(pf);
	fclose(pd);
	return 0;
}

