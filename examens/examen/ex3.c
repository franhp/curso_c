#include <stdio.h>
#include <string.h>
#define N 2
struct pelis{
    char titol[20];
    char director[20];
    char duracio[4];
}collection[N];

void ini(struct pelis collection[]);
void cerca(struct pelis collection[], char []);

void main(){
    char troba[20];
    ini(collection);
    
    printf("\nQuin terme vols cercar?\t");
        scanf("%s", troba);
        
    cerca(collection,troba);
    
}

void ini(struct pelis collection[]){
    int i;
    for(i=0;i<N;i++){
        printf("\nInsereix Titol\t");
            scanf("%s", collection[i].titol);
        printf("\nInsereix director\t");
            scanf("%s", collection[i].director);
        printf("\nInsereix duracio\t");
            scanf("%s",  collection[i].duracio);
        printf("\n//////////////////////////");
    }
}

void cerca(struct pelis collection[], char troba[]){
    int opcio,i,s;
    while((opcio<=0)||(opcio>=4)){
        printf("\nPremeu 1 per cercar per titol\nPremeu 2 per cercar per director\nPremeu 3 per cercar per duracio\n");
        scanf("%d", &opcio);   
    }
    
    switch(opcio){
        case 1:
            for(i=0;i<N;i++){
                s=strcmp(collection[i].titol,troba);
                if(s==0){
                    printf("\n%s - %s - %s\n", collection[i].titol, collection[i].director, collection[i].duracio);
                }
            }
            break;
            
        case 2:
            for(i=0;i<N;i++){
                s=strcmp(collection[i].director,troba);
                if(s==0){
                    printf("\n%s - %s - %s\n", collection[i].titol, collection[i].director, collection[i].duracio);
                }
            }
            break;
        case 3:
             for(i=0;i<N;i++){
                s=strcmp(collection[i].duracio,troba);
                if(s==0){
                    printf("\n%s - %s - %s\n", collection[i].titol, collection[i].director, collection[i].duracio);
                }
            }
            break;
        default:
            break;
    }
}
