#include <stdio.h>
#include <stdlib.h>
#define N 20

struct coordenada{
    float x,y;
}nombres[N],nombre;

void inicialitzar();
void modificar();

int main(){
    int opt;
    do{
        printf("\n0. Inicialitzar Coordenada");          
        printf("\n1. Llegir i Modificar");
        printf("\n2. Sortir");
        printf("\nOpcio?\t");        
        scanf("%d",&opt);
        
        switch(opt){
             case 0: inicialitzar();
                     break;
             case 1: modificar();
                     break;
             case 2: break;
           default : printf("What?\n");
                     break;
        }
    }while(opt!=2);
    
    printf("\nBye!\n");
    return 0;
}

void inicialitzar(){
    FILE *pf;
    printf("\nInsereix X:\t");
    scanf("%f", &nombre.x);
    printf("\nInsereix Y:\t");
    scanf("%f", &nombre.y);
    
    if((pf=fopen("coordenades.bin", "ab"))==NULL) printf("\nCachis!");
    else {
        printf("\nS'ha escrit %f i %f", nombre.x, nombre.y);
        fwrite(&nombre,sizeof(struct coordenada),1,pf);
        fclose(pf);
    }
}

void modificar(){
    FILE *pf;
    int i,coord, resposta;
    
    if((pf=fopen("coordenades.bin", "rb"))==NULL) printf("\nwtf!");
    else {
        for(i=0;i<N;i++){
            fread(&nombres[i],sizeof(struct coordenada),1,pf);
            if(nombres[i].x!=0 && nombres[i].y!=0) printf("\n%d : %f %f", i, nombres[i].x,nombres[i].y);
        }
        fclose(pf);
        printf("\nVols modificar?");
        scanf("%d", &resposta);
        if(resposta==0) return;
        if((pf=fopen("coordenades.bin", "wb"))==NULL) printf("\nOH NOES!1");
        printf("\nQuina vols modificar?\t");
        scanf("%d", &coord);
        
        printf("\nInsereix X del nombre %d: \t", coord);
        scanf("%f", &nombres[coord].x);
        printf("\nInsereix Y del nombre %d: \t", coord);
        scanf("%f", &nombres[coord].y);
        
        fwrite(&nombres,sizeof(struct coordenada),1,pf);
        fclose(pf);
    }    
}
