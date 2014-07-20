#include <stdio.h>
#include <stdlib.h>

struct node { 
 int num; 
 struct node *seguent; 
}; 
 
struct node *pPrimer=NULL; 
struct node *pActual=NULL;

void crearNode(int);
int cercar(int);
void modificar(int, int);
void saltarPrimerElement();
void obtenirSeguentElement();
int finalLlista();
int obtenirElementActual();

void main(){
    
    int opt,n,u,i;
    do{
        printf("\n0. Crear Node");          
        printf("\n1. Cercar i modificar");
        printf("\n2. Mostrar totes");
        printf("\n3. Sortir");
        printf("\nTria\t ");        
        scanf("%d",&opt);
        printf("\n===============\n");
        
        switch(opt){
             case 0: printf("\nEscriu el valor a crear: \t");
                     scanf("%d",&n);
                     crearNode(n);
                     break;
             case 1: printf("\nEscriu el valor a cercar: \t");
                     scanf("%d",&n);
                     if (cercar(n)!=-1){
                        printf("\nExisteix!");
                        printf("\nPer quin valor el vols modificar?: \t");
                        scanf("%d",&u);
                        modificar(cercar(n),u);
                     }
                     else printf("\nNO existeix!\n");
                     break;
             case 2: //recorrer llista
                        i=0;
                        saltarPrimerElement();
                        while(!finalLlista()){ 
                         printf("Element %d: %d\n", i, obtenirElementActual());
                         obtenirSeguentElement();
                         i++;
                        } 
                        printf("Element %d: %d\n", i, obtenirElementActual());
                        i=0;
                        break;
             case 3: break;  
           default : printf("Wrong answer!\n");
                     break;
        }
    
    
    }while(opt!=3);
    
    printf("\nBye!\n");
}

void crearNode(int n){ 
    struct node *p; 
    p = (struct node *) malloc(sizeof(struct node)); 
    p->num=n; 
    
    if(pPrimer == NULL){ 
        p->seguent=NULL; 
        pActual = p; 
    } 
    else{ 
        p->seguent=pPrimer; 
    } 
    
    pPrimer = p; 
}


int cercar(int element){
    
    int i=0;
    struct node *paux;
    
    paux=pPrimer;
    
    while(paux!=NULL){
        if(paux->num == element) return i;
        paux=paux->seguent;
        i++;
    }
    return -1;
}

void modificar(int posicio, int n){
    
    struct node *p;
    int i;
    p = (struct node *) malloc(sizeof(struct node)); 
    p->num=n;
    
    saltarPrimerElement();
    if(posicio==0){
        pActual->num=n;
    }
    else{
        for(i=0;i<=posicio+1;i++){
            obtenirSeguentElement();
        }
        p->seguent=pActual;
        saltarPrimerElement();
        for(i=0;i<=posicio;i++){
            pActual->seguent=p;
        }
    }
    
}

void saltarPrimerElement(){ 
     pActual = pPrimer; 
} 
 
void obtenirSeguentElement(){ 
     if(!finalLlista()) pActual = pActual->seguent;  
} 
 
int finalLlista(){ 
     return (pActual->seguent == NULL); 
} 
 
int obtenirElementActual(){ 
     return pActual->num; 
} 
