#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extract.h"
#define N 1024


int main(int argc, char *argv[]){
	FILE *pf;
	FILE *pd;
	char tmp_discid[N]={'\0'};
	int i,*posicions,count=0,suma=0,lon=0;
	char c,**vector;
	char buffer[N]={'\0'};
	//Markers
	char songtitle[]="TTITLE",discid[]="DISCID";
	
	if((pf=fopen(argv[1],"rt"))==NULL) printf("\nError");
	else {
		posicions = (int *)malloc(1*sizeof(int));
		while( (c=getc(pf)) != EOF){
                            if(c=='\n'){
                                    //Detecto de quantes posicions consta cada linia
				    posicions=(int *)realloc(posicions,(count+1)*sizeof(int));
                                    posicions[count]=(ftell(pf))-suma;
                                    suma=posicions[count]+suma;
                                    count++;
                            }
		}
		
		//Evitar l'error de fitxer buit
		if(posicions[0]==0) return 1;
		
		if((pd=fopen("songs.txt", "at"))==NULL) printf("\nError");
                else{
			//Torno al principi
			fseek(pf,0,SEEK_SET);
			
			//Fico cada contacte en una posici� del vector
			if((vector=(char**)malloc(count*sizeof(char*)))==NULL) printf("\nError");
			else{
				//primer trobarem la discID per tot el fitxer
				for(i=0;i<count;i++){
					lon = (posicions[i]+1);
					if((*(vector+i)=(char*)malloc(lon*sizeof(char)))==NULL) printf("\nError");
					else{
						if(vector[i]!=0){
							fgets(vector[i], lon, pf);
							if((posicions[i])!=0){
								if(troba(vector[i],discid)!=-1){
									strcpy(tmp_discid, vector[i]);
									clean(tmp_discid);
								}
							}
						}
					}
				}
				
				//I buscarem cada canço i l'escriurem al fitxer junt amb la discID
				for(i=0;i<count;i++){
					if(vector[i]!=0){
						if((posicions[i])!=0){
							if(troba(vector[i],songtitle)!=-1){
								strcpy(buffer, vector[i]);
								clean(buffer);
								fprintf(pd,"%s\t%s\n",tmp_discid,buffer);
								reiniciaCadena(buffer);
							}
						}
					}
				}
				
				fclose(pf);
				fclose(pd);
			}
		}
	}
	return 0;
}

