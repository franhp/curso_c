#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

//estructures

struct node_disc{
    char discid[10];
    char artist[100];
    char title[100];
    char genre[20];
    int year;
    int duration; //En segons
    struct node *seguent;
};

struct node_songs{
    char discid[10];
    char song_title[100];
    struct node *seguent;
};

struct node_disc *pPrimerDiscs=NULL; 
struct node_songs *pPrimerSongs=NULL; 
struct node_disc *pActualDiscs=NULL;
struct node_songs *pActualSongs=NULL;

//funcions

int troba(char *, char *);
void eliminaDiscs();
void eliminaSongs();
void omple_llista_cds();
void estructurifica_cds();
void omple_llista_songs();
void estructurifica_songs();
void reiniciaCadena(char *);
void cercaDiscs(char *);
void cercaSongs(char *);
void mostrarTotsSongs();
void mostrarTotsDiscs();
void writeSongs();
void writeDiscs();
void modificaSongs(int);
void modificaDiscs(int);

//variables globals

int trobat;

//main
void main(){
    int element;
    char opt, buscar, buffer[N];
    system("clear");
    do{
        printf("\n==============================");
        printf("\n| Indica una opci\u00F3:          |");
        printf("\n| 0.Processa la carpeta CDDB |");
        printf("\n| 1.Insereix Disc            |");
        printf("\n| 2.Insereix Can\u00E7ons         |");
        printf("\n| 3.Modificar Disc           |");
        printf("\n| 4.Modificar Can\u00E7\u00F3          |");
        printf("\n| 5.Eliminar Disc            |");
        printf("\n| 6.Eliminar Can\u00E7\u00F3           |");
	printf("\n| 7.Mostrar Discs            |");
	printf("\n| 8.Mostrar Songs            |");
        printf("\n| 9.Sortir                   |");
        printf("\n==============================\n");
        printf("Opci\u00F3?\t");        
        scanf(" %c", &opt);
        
        switch(opt){
		case '0': system("clear");
		    printf("Processant Can\u00E7ons....\n");
		    system("for i in CDDB/*/*; do if [ $(dirname $i) != CDDB/Status ]; then ./extract_songs $i; fi; done");
		    printf("Processant Discs....\n");
		    system("for i in CDDB/*/*; do if [ $(dirname $i) != CDDB/Status ]; then ./extract_cds $i; fi; done");
		    printf("Fet!\n");
		    break;
		case '1': system("clear");
		    writeDiscs();
		    break;     
             case '2': system("clear");
		    writeSongs();
		    break;
		case '3': system("clear");
			reiniciaCadena(buffer);
			omple_llista_cds();
			if(pPrimerDiscs==NULL) {
			    printf("\nNo hi ha cap");
			    break;
			}
		    do{
				printf("\n========================================");
				printf("\n| 1: Modificar cercant un t\u00EDtol o autor|");
				printf("\n| 2: Modificar cercant a tota la BBDD  |");
				printf("\n| 3: Sortir d'aqu\u00ED                     |");
				printf("\n========================================");
				printf("\nOpci\u00F3?\t");
				__fpurge(stdin);  
				scanf(" %c",&buscar);
				if(buscar=='1'){printf("\nEscriu t\u00EDtol o autor del disc a editar: ");
					__fpurge(stdin);
					gets(buffer);
					cercaDiscs(buffer);
					if(trobat==1){
						printf("\nEscriu el n\u00FAmero del CD:\t");
						scanf("%d", &element);
						modificaDiscs(element);
						pPrimerDiscs=NULL;
						break;
					}else printf("\nSembla que no s'ha trobat res...\n");
				} 
				else if(buscar=='2'){
					mostrarTotsDiscs();
					printf("\nEscriu el n\u00FAmero del CD:\t");
					scanf("%d", &element);
					modificaDiscs(element);
					pPrimerDiscs=NULL;
					break;
				}
			}while(buscar!='3');
		    break;
		case '4': system("clear");
			reiniciaCadena(buffer);
			omple_llista_songs();
			if(pPrimerSongs==NULL) {
			    printf("\nNo hi ha cap");
			    break;
			}
			do{
				printf("\n========================================");
				printf("\n| 1: Modificar cercant un t\u00EDtol de Song|");
				printf("\n| 2: Modificar cercant a tota la BBDD  |");
				printf("\n| 3: Sortir d'aqu\u00ED                     |");
				printf("\n========================================");
				printf("\nOpci\u00F3?\t");  
				__fpurge(stdin);  
				scanf(" %c",&buscar);
				if(buscar=='1'){
					printf("\nEscriu t\u00EDtol de la Song:\t");
					__fpurge(stdin);
					gets(buffer);
					cercaSongs(buffer);
					if(trobat==1){
						printf("Escriu el n\u00FAmero de Song:\t");
						scanf("%d", &element);
						modificaSongs(element);
						pPrimerSongs=NULL;
						break;
					}else printf("Sembla que no s'ha trobat res...\n");
				} 
				else if(buscar=='2'){
					mostrarTotsSongs();
					printf("\nEscriu el n\u00FAmero de Song:\t");
					scanf("%d", &element);
					modificaSongs(element);
					pPrimerSongs=NULL;
					break;
				}
			}while(buscar!='3');
			break;
		case '5': system("clear");
			reiniciaCadena(buffer);
			omple_llista_cds();
			if(pPrimerDiscs==NULL) {
			    printf("\nNo hi ha cap");
			    break;
			}
		    do{
				printf("\n========================================");
				printf("\n| 1: Eliminar cercant un t\u00EDtol o autor |");
				printf("\n| 2: Eliminar cercant a tota la BD     |");
				printf("\n| 3: Sortir d'aqu\u00ED                     |");
				printf("\n========================================");
				printf("\nOpci\u00F3?\t");  
				__fpurge(stdin);  
				scanf(" %c",&buscar);
				if(buscar=='1'){printf("\nEscriu t\u00EDtol o autor del disc a editar: ");
					__fpurge(stdin);
					gets(buffer);
					cercaDiscs(buffer);
					if(trobat==1){
						printf("\nEscriu el n\u00FAmero del CD:\t");
						scanf("%d", &element);
						eliminaDiscs(element);
						pPrimerDiscs=NULL;
						break;
					}else printf("\nSembla que no s'ha trobat res...\n");
				} 
				else if(buscar=='2'){
					mostrarTotsDiscs();
					printf("\nEscriu el n\u00FAmero del CD:\t");
					scanf("%d", &element);
					eliminaDiscs(element);
					pPrimerDiscs=NULL;
					break;
				}
			}while(buscar!='3');
		    break;
		case '6': system("clear");
			reiniciaCadena(buffer);
			omple_llista_songs();
			if(pPrimerSongs==NULL) {
			    printf("\nNo hi ha cap");
			    break;
			}
			do{
				printf("\n========================================");
				printf("\n| 1: Eliminar  cercant un t\u00EDtol de song|");
				printf("\n| 2: Eliminar  cercant a tota la BD    |");
				printf("\n| 3: Sortir d'aqu\u00ED                     |");
				printf("\n========================================");
				printf("\nOpci\u00F3?\t");  
				__fpurge(stdin);  
				scanf(" %c",&buscar);
				if(buscar=='1'){
					printf("\nEscriu t\u00EDtol de la song:\t");
					__fpurge(stdin);
					gets(buffer);
					cercaSongs(buffer);
					if(trobat==1){
						printf("Escriu el n\u00FAmero de Song:\t");
						scanf("%d", &element);
						eliminaSongs(element);
						pPrimerSongs=NULL;
						break;
					}else printf("Sembla que no s'ha trobat res...\n");
				} 
				else if(buscar=='2'){
					mostrarTotsSongs();
					printf("\nEscriu el n\u00FAmero de Song:\t");
					scanf("%d", &element);
					eliminaSongs(element);
					pPrimerSongs=NULL;
					break;
				}
			}while(buscar!='3');
			break;
		case '7':system("clear");
			omple_llista_cds();
			mostrarTotsDiscs();
			pPrimerDiscs=NULL;
			break;
	    case '8':   system("clear");
			omple_llista_songs();
			mostrarTotsSongs();
			pPrimerSongs=NULL;
			break;
	     case '9': break;
		default :  system("clear");
			printf("Wrong!\n");
			break;
           
        }
    }while(opt!='9'); 
    
    printf("\nEnjoy your music!\n\n");
}

int troba(char *pcad1, char *pcad2){
        int i,j;
        for(i=0;(*(pcad1+i)!='\0');i++){
                if(*(pcad1+i)==*(pcad2+0)) {
                        for(j=0;(*(pcad2+j)!='\0')&&(*(pcad1+i+j)==(*(pcad2+j)));j++);
                        if (*(pcad2+j)=='\0') return 1;
                }
        }
 return 0;
}

void cercaDiscs(char *cadena){
    int i=0;
    trobat=0;
    pActualDiscs = pPrimerDiscs;
    if(pActualDiscs->seguent==NULL){
    	if((troba(pActualDiscs->artist, cadena)==1) || (troba(pActualDiscs->title, cadena)==1)){
			printf("Numero: %d. Title: %s Artist: %s\n", i, pActualDiscs->title, pActualDiscs->artist);
			trobat=1;
		}
    }else{
		for(i=0;pActualDiscs->seguent!=NULL;i++){
			if((troba(pActualDiscs->artist, cadena)==1) || (troba(pActualDiscs->title, cadena)==1)){
				printf("Numero: %d. Title: %s Artist: %s\n", i, pActualDiscs->title, pActualDiscs->artist);
				trobat=1;
			}
			pActualDiscs = pActualDiscs->seguent;
		}
	}
}

void cercaSongs(char *cadena){
    int i=0;
    trobat=0;
    pActualSongs = pPrimerSongs;
    
	if(pActualSongs->seguent==NULL){
		if(troba(pActualSongs->song_title, cadena)==1){
			printf("Numero: %d. Song: %s\n", i, pActualSongs->song_title);
			trobat=1;
		}
	}else{
		for(i=0;pActualSongs->seguent!=NULL;i++){
			if(troba(pActualSongs->song_title, cadena)==1){
				printf("Numero: %d. Song: %s\n", i, pActualSongs->song_title);
				trobat=1;
			}
			pActualSongs = pActualSongs->seguent;
		}
	}
}

void eliminaSongs(int element){
	int i, j,contador;
    FILE *pf;
    struct node_songs *paux;
    pActualSongs=pPrimerSongs;
    for(contador=0;pActualSongs->seguent!=NULL;contador++) pActualSongs = pActualSongs->seguent;
    if(element > contador || element < 0) printf("\nEstas intentat esborrar una Song que no existeix\n");
    else{
    	//primer borrarem el node dessitjat
    	pActualSongs=pPrimerSongs;
		if(element!=0){
			for(i=0;i<(element-1);i++){ 
				pActualSongs = pActualSongs->seguent;
			}
			paux = pActualSongs->seguent;
			pActualSongs->seguent=paux->seguent;
			free(paux);
			
		}else if(element==0){
			paux=pPrimerSongs;
			pPrimerSongs=pPrimerSongs->seguent;
			free(paux);
		}
		//un cop alliberat de la memoria, passem al procés d'escriptura de la llista
		if((pf=fopen("songs.txt","wt"))==NULL) printf("\nError!");
		else {
			pActualSongs = pPrimerSongs;
			for(i=0;pActualSongs->seguent!=NULL;i++){
			    pActualSongs = pActualSongs->seguent;
			}
			while(i!=0){
			    pActualSongs = pPrimerSongs;
			    for(j=0;j<i;j++){
				pActualSongs = pActualSongs->seguent;
			    }
			    fprintf(pf,"%s\t%s\n",pActualSongs->discid,pActualSongs->song_title);
			    i--;
			}
 		    fprintf(pf,"%s\t%s\n",pPrimerSongs->discid,pPrimerSongs->song_title);
			fclose(pf);
		}
		printf("\nEliminat!");
	}
}
void eliminaDiscs(int element){
    int i, j,contador;
    FILE *pf;
    struct node_disc *paux;
    pActualDiscs=pPrimerDiscs;
    for(contador=0;pActualDiscs->seguent!=NULL;contador++) pActualDiscs = pActualDiscs->seguent;
    if(element > contador || element < 0) printf("\nEstas intentat esborrar un CD que no existeix\n");
    else{
    	//primer borrarem el node dessitjat
    	pActualDiscs=pPrimerDiscs;
		if(element!=0){
			for(i=0;i<(element-1);i++){ 
				pActualDiscs = pActualDiscs->seguent;
			}
			paux = pActualDiscs->seguent;
			pActualDiscs->seguent=paux->seguent;
			free(paux);
			
		}else if(element==0){
			paux=pPrimerDiscs;
			pPrimerDiscs=pPrimerDiscs->seguent;
			free(paux);
		}
		//un cop alliberat de la memoria, passem al procés d'escriptura de la llista
		if((pf=fopen("cds.txt","wt"))==NULL) printf("\nError!");
		else {
			pActualDiscs = pPrimerDiscs;
			for(i=0;pActualDiscs->seguent!=NULL;i++){
			    pActualDiscs = pActualDiscs->seguent;
			}
			while(i!=0){
			    pActualDiscs = pPrimerDiscs;
			    for(j=0;j<i;j++){
				pActualDiscs = pActualDiscs->seguent;
			    }
			    fprintf(pf,"%s\t%s\t%s\t%s\t%d\t%d\n",pActualDiscs->discid,pActualDiscs->artist,pActualDiscs->title,pActualDiscs->genre,pActualDiscs->year,pActualDiscs->duration);
			    i--;
			}
			fprintf(pf,"%s\t%s\t%s\t%s\t%d\t%d\n",pPrimerDiscs->discid,pPrimerDiscs->artist,pPrimerDiscs->title,pPrimerDiscs->genre,pPrimerDiscs->year,pPrimerDiscs->duration);
			fclose(pf);
		}
		printf("\nEliminat!");
	}
}

void modificaSongs(int element){
    int i,j, contador;
    FILE *pf;
    pActualSongs = pPrimerSongs;
    for(contador=0;pActualSongs->seguent!=NULL;contador++) pActualSongs = pActualSongs->seguent;
    if(element > contador || element < 0) printf("\nEstas intentat modificar una Song que no existeix\n");
    else{
    	pActualSongs = pPrimerSongs;
			if(element!=0){
			for(i=0;i<element;i++){
				pActualSongs = pActualSongs->seguent;
			}
		}
		printf("\nEditant l'element %d",element);
		printf("\nInsereix el nou discid:");
		__fpurge(stdin);
		gets(pActualSongs->discid);
		printf("\nInsereix el nou song_title [%s]:",pActualSongs->song_title);
		gets(pActualSongs->song_title);
		if((pf=fopen("songs.txt","wt"))==NULL) printf("\nError!");
		else {
		    pActualSongs = pPrimerSongs;
			for(i=0;pActualSongs->seguent!=NULL;i++){
			    pActualSongs = pActualSongs->seguent;
			}
			while(i!=0){
			    pActualSongs = pPrimerSongs;
			    for(j=0;j<i;j++){
				pActualSongs = pActualSongs->seguent;
			    }
			    fprintf(pf,"%s\t%s\n",pActualSongs->discid,pActualSongs->song_title);
			    i--;
			}
 		        fprintf(pf,"%s\t%s\n",pPrimerSongs->discid,pPrimerSongs->song_title);
		    fclose(pf);
		}
		mostrarTotsSongs();
	}
}
void modificaDiscs(int element){
    int i,j, contador;
    FILE *pf;
    pActualDiscs=pPrimerDiscs;
    for(contador=0;pActualDiscs->seguent!=NULL;contador++) pActualDiscs = pActualDiscs->seguent;
    if(element > contador || element < 0) printf("\nEstas intentat modificar un CD que no existeix\n");
	else{
		pActualDiscs=pPrimerDiscs;
		if(element!=0){
			for(i=0;i<element;i++){
				pActualDiscs = pActualDiscs->seguent;
			}
		}
		printf("\nEditant l'element %d", element);
		printf("\nInsereix el nou discid: ");
		__fpurge(stdin);
		gets(pActualDiscs->discid);
		printf("\nInsereix el nou artist [%s]:", pActualDiscs->artist);
		gets(pActualDiscs->artist);
		printf("\nInsereix el nou title [%s]:", pActualDiscs->title);
		gets(pActualDiscs->title);
		printf("\nInsereix el nou genre [%s]:", pActualDiscs->genre);
		gets(pActualDiscs->genre);
		printf("\nInsereix el nou year [%d]:", pActualDiscs->year);
		scanf("%d", &pActualDiscs->year);
		printf("\nInsereix el nou duration [%d]:", pActualDiscs->duration);
		scanf("%d", &pActualDiscs->duration);
		
		if((pf=fopen("cds.txt","wt"))==NULL) printf("\nError!");
		else {
		pActualDiscs = pPrimerDiscs;
			for(i=0;pActualDiscs->seguent!=NULL;i++){
			    pActualDiscs = pActualDiscs->seguent;
			}
			while(i!=0){
			    pActualDiscs = pPrimerDiscs;
			    for(j=0;j<i;j++){
				pActualDiscs = pActualDiscs->seguent;
			    }
			    fprintf(pf,"%s\t%s\t%s\t%s\t%d\t%d\n",pActualDiscs->discid,pActualDiscs->artist,pActualDiscs->title,pActualDiscs->genre,pActualDiscs->year,pActualDiscs->duration);
			    i--;
			}
			fprintf(pf,"%s\t%s\t%s\t%s\t%d\t%d\n",pPrimerDiscs->discid,pPrimerDiscs->artist,pPrimerDiscs->title,pPrimerDiscs->genre,pPrimerDiscs->year,pPrimerDiscs->duration);
		fclose(pf);
		}
		
		mostrarTotsDiscs();
	}
}
void omple_llista_songs(){
    FILE *pf;
    int i,linia=0,suma=0,lon=0,espai=2;
    char c;
    char **p;
    int *posicions;

    if((pf=fopen("songs.txt","rt"))==NULL) printf("\nError");
    else {
		posicions=(int*)malloc(sizeof(int));
    	        while( (c=getc(pf)) != EOF){
    	        	if(c=='\n'){
    	        		//Detecto de quantes posicions consta cada linia
    	        		posicions[linia]=(ftell(pf))-suma;
    	        		suma=posicions[linia]+suma;
    	        		linia++;
				posicions=(int*)realloc(posicions,sizeof(int)*espai);
				espai++;
    	        	}
    	        }

		printf("Estructures creades: %d\n", linia);
		
                // Ho torno a posar al principi
    	        fseek(pf,0,SEEK_SET);

    	        //Fico cada contacte en una posici— del vector
    	        if((p=(char**)malloc(linia*sizeof(char*)))==NULL) printf("\nError");
                else{
                for(i=0;i<linia;i++){
                    	if(posicions[i]!=0){
                                    lon = posicions[i]+1;
                                    if((*(p+i)=(char*)malloc(lon*sizeof(char)))==NULL) printf("\nError");
                        		else fread(*(p+i),posicions[i],1,pf);
                    	}
                    }
                    fclose(pf);
                }
                //// Trobar els \t i anar ficant lo anterior a la seva respectiva estructura
                for(i=0;i<linia;i++){
                    estructurifica_songs(p[i]);
                }
		
		free(posicions);
		free(p);
    }
    
    
}


void estructurifica_songs(char *cad){
    int i,j=0;
    char buffer[N]={'\0'};
    struct node_songs *p; 
    
    if((p=(struct node_songs *)malloc(sizeof(struct node_songs)))==NULL) printf("\nError");
    else {
	for(i=0;*(cad+i)!='\t';i++){
	    *(buffer+i)=*(cad+i);
	}
	i++;
	*(buffer+i)='\0';
	
	strcpy(p->discid,buffer);
	
	reiniciaCadena(buffer);

	//// Song title
	while(*(cad+i)!='\n'){
	    *(buffer+j)=*(cad+i);
	    i++;
	    j++;
	}
	j++;
	*(buffer+j)='\0';
	
	strcpy(p->song_title,buffer);
	
	reiniciaCadena(buffer);

        if(pPrimerSongs == NULL){ 
            p->seguent=NULL; 
            pActualSongs = p; 
        } 
        else{ 
            p->seguent=pPrimerSongs; 
        } 

        pPrimerSongs = p;
    }
  
}

void omple_llista_cds(){
    FILE *pf;
    int i,linia=0,suma=0,lon=0,espai=2;
    char c;
    char **p;
    int *posicions;

    if((pf=fopen("cds.txt","rt"))==NULL) printf("\nError");
    else {
		posicions=(int*)malloc(sizeof(int));
    	        while( (c=getc(pf)) != EOF){
    	        	if(c=='\n'){
    	        		//Detecto de quantes posicions consta cada linia
    	        		posicions[linia]=(ftell(pf))-suma;
    	        		suma=posicions[linia]+suma;
    	        		linia++;
				posicions=(int*)realloc(posicions,sizeof(int)*espai);
				espai++;
    	        	}
    	        }

		printf("Estructures creades: %d\n", linia);
		
                // Ho torno a posar al principi
    	        fseek(pf,0,SEEK_SET);

    	        //Fico cada contacte en una posici— del vector
    	        if((p=(char**)malloc(linia*sizeof(char*)))==NULL) printf("\nError");
                else{
                for(i=0;i<linia;i++){
                    	if(posicions[i]!=0){
                                    lon = posicions[i]+1;
                                    if((*(p+i)=(char*)malloc(lon*sizeof(char)))==NULL) printf("\nError");
                        	    else fread(*(p+i),posicions[i],1,pf);
                    	}
                    }
                    fclose(pf);
				}
                //// Trobar els \t i anar ficant lo anterior a la seva respectiva estructura
                for(i=0;i<linia;i++){
		    
                    estructurifica_cds(p[i]);
                }
		
		free(posicions);
		free(p);
    }
    
    
}


void estructurifica_cds(char *cad){
    int i,j=0;
    char buffer[N]={'\0'};
    struct node_disc *p; 
    
    if((p =(struct node_disc *)malloc(sizeof(struct node_disc)))==NULL) printf("\nError");
    else {
	for(i=0;*(cad+i)!='\t';i++){
	    *(buffer+i)=*(cad+i);
	}
	i++;
	*(buffer+i)='\0';
	
	strcpy(p->discid,buffer);
	
	reiniciaCadena(buffer);

	//// Artist
	while(*(cad+i)!='\t'){
	    *(buffer+j)=*(cad+i);
	    i++;
	    j++;
	}
	j++;
	*(buffer+j)='\0';
	
	strcpy(p->artist,buffer);
	
	reiniciaCadena(buffer);
	j=0;
	i++;
	
	//// Title
	while(*(cad+i)!='\t'){
	    *(buffer+j)=*(cad+i);
	    i++;
	    j++;
	}
	j++;
	*(buffer+j)='\0';
	
	strcpy(p->title,buffer);
	
	reiniciaCadena(buffer);
	j=0;
	i++;
	
	//// Genre
	while(*(cad+i)!='\t'){
	    *(buffer+j)=*(cad+i);
	    i++;
	    j++;
	}
	j++;
	*(buffer+j)='\0';
	
	strcpy(p->genre,buffer);
	
	reiniciaCadena(buffer);
	j=0;
	i++;
	
	//// Year
	while(*(cad+i)!='\t'){
	    *(buffer+j)=*(cad+i);
	    i++;
	    j++;
	}
	j++;
	*(buffer+j)='\0';
	
	p->year=atoi(buffer);
	
	reiniciaCadena(buffer);
	j=0;
	i++;
	
	//// Duration
	while(*(cad+i)!='\0'){
	    *(buffer+j)=*(cad+i);
	    i++;
	    j++;
	}
	j++;
	*(buffer+j)='\0';
	
	p->duration=atoi(buffer);
	
	reiniciaCadena(buffer);
	j=0;
	i++;
        
        if(pPrimerDiscs == NULL){ 
            p->seguent=NULL; 
            pActualDiscs = p; 
        } 
        else{ 
            p->seguent=pPrimerDiscs; 
        } 

        pPrimerDiscs = p;
    }
  
}

void reiniciaCadena(char *vector){
	int i;
	for(i=0;((vector[i+1])!='\0');i++) vector[i]='\0';
} 

void mostrarTotsDiscs(){
    int i=0;
    pActualDiscs = pPrimerDiscs;
    if(pActualDiscs==NULL) printf("\nNo hi ha cds.txt o esta buit");
    else {
	while (pActualDiscs->seguent !=NULL){
	    	printf("\n======= %d =======\nDiscid : %s\nArtist: %s Title: %s\nGenre: %s Year: %d\nDuration: %d minutes", i,pActualDiscs->discid, pActualDiscs->artist, pActualDiscs->title, pActualDiscs->genre, pActualDiscs->year, pActualDiscs->duration/60);
    	if(pActualDiscs->seguent != NULL) pActualDiscs = pActualDiscs->seguent;
	i++;
    }
    printf("\n======= %d =======\nDiscid : %s\nArtist: %s Title: %s\nGenre: %s Year: %d\nDuration: %d minutes", i,pActualDiscs->discid, pActualDiscs->artist, pActualDiscs->title, pActualDiscs->genre, pActualDiscs->year, (pActualDiscs->duration/60));
    }
 }

void mostrarTotsSongs(){
    int i=0;
    if(pActualSongs==NULL) printf("\nNo hi ha songs.txt o esta buit");
    else {
    pActualSongs = pPrimerSongs;
    while (pActualSongs->seguent !=NULL){
    	printf("\n======= %d =======\nDiscID: %s \tSongTitle: %s",i,pActualSongs->discid, pActualSongs->song_title);
    	if(pActualSongs->seguent != NULL) pActualSongs = pActualSongs->seguent;
	i++;
    }
    printf("\n======= %d =======\nDiscID: %s \tSongTitle: %s",i,pActualSongs->discid, pActualSongs->song_title);
    }

}

void writeSongs(){
    FILE *pf;
    struct node_songs *p;
    p = (struct node_songs *) malloc(sizeof(struct node_songs));
 
    printf("Discid:\n\t-> ");
    __fpurge(stdin);
    gets(p->discid);
    printf("Song Title:\n\t-> ");
    gets(p->song_title);

    
    if((pf=fopen("songs.txt","at"))==NULL) printf("\nError");
    else {
            fputs(p->discid,pf);
            fputs("\t",pf);
            fputs(p->song_title,pf);
            fputs("\n",pf);
        fclose(pf);  
    }
    
    printf("\n ============== \n");
}
 
void writeDiscs(){
    FILE *pf;
    struct node_disc *p; 
    p = (struct node_disc *) malloc(sizeof(struct node_disc));
 
    ///Comprobar los strlen para el malloc
    printf("Discid:\n\t-> ");
    __fpurge(stdin);
    gets(p->discid);
    printf("Artist\n\t-> ");
    gets(p->artist);
    printf("Title:\n\t-> ");
    gets(p->title);
    printf("Genre:\n\t-> ");
    gets(p->genre);
    printf("Year:\n\t-> ");
    scanf("%d", &p->year);
    printf("Duration in seconds:\n\t-> ");
    scanf("%d", &p->duration);
    
    if((pf=fopen("cds.txt","at"))==NULL) printf("\nError");
    else {
            fputs(p->discid,pf);
            fputs("\t",pf);
            fputs(p->title,pf);
            fputs("\t",pf);
            fputs(p->artist,pf);
            fputs("\t",pf);
            fputs(p->genre,pf);
            fputs("\t",pf);
	    fprintf(pf,"%d",p->year);
	    fputs("\t",pf);
            fprintf(pf,"%d",p->duration);
            fputs("\n",pf);
        fclose(pf);  
    }
    
    printf("\n ============== \n");
}
