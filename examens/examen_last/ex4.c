#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
 int num; 
 struct node *seguent; 
}; 
 
struct node *pPrimer=NULL; 
struct node *pActual=NULL; 
 
void crearNode(int n); 
void insertarNode(int n); 
void saltarPrimerElement(); 
void obtenirSeguentElement(); 
int finalLlista(); 
int obtenirElementActual();
int cerca(int);
void inserirDarrere(int,int);
 
void main() {
    int n,valor,i=0;
    crearNode(11); 
    crearNode(6); 
    crearNode(4); 
    crearNode(5); 
    
    saltarPrimerElement(); 
    
    //recorrer llista 
    while(!finalLlista()){ 
     printf("Element %d: %d\n", i, obtenirElementActual());
     obtenirSeguentElement();
     i++;
    } 
    printf("Element %d: %d\n", i, obtenirElementActual());
    
    printf("\nValor a cercar?\t");
    scanf("%d", &n);
    printf("\nSha trobat a %d\n", cerca(n));
    if((cerca(n))!=-1){
        printf("\nValor a inserir despres?\t");
        scanf("%d", &valor);
        inserirDarrere(cerca(n),valor);
    }
     
     
    //recorrer llista
    i=0;
    saltarPrimerElement();
    while(!finalLlista()){ 
     printf("Element %d: %d\n", i, obtenirElementActual());
     obtenirSeguentElement();
     i++;
    } 
    printf("Element %d: %d\n", i, obtenirElementActual());
} 

int cerca(int n){
    int i=0;
    
    saltarPrimerElement();
    while(!finalLlista()){
        if(pActual->num==n) return i;
        obtenirSeguentElement();
        i++;
    }
    return -1;
}

void inserirDarrere(int posicio, int n){
    struct node *p;
    int i;
    p = (struct node *) malloc(sizeof(struct node)); 
    p->num=n;
    // No tinc cap jo ara per calcular ... pero la teoria Žs que m'he de posar al de davant, ficar-lo al vector del meu nou p, posar-me al que marca la posici— i ficar-hi p al seu  node seguent.
    saltarPrimerElement();
    for(i=0;i<=posicio+1;i++){
        obtenirSeguentElement();
        printf("\nAra estic a %d", pActual->num);
    }
    
    p->seguent=pActual;
    
    saltarPrimerElement();
    for(i=0;i<=posicio;i++){
        pActual->seguent=p;
        printf("\nAra estic a %d", pActual->num);
    }
    
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

void insertarNode(int n){ 
    struct node *p; 
    p = (struct node *) malloc(sizeof(struct node)); 
    p->num=n; 
    
    if(pPrimer == NULL){ 
     crearNode(n); 
    } 
    else if(finalLlista()){ 
     p->seguent=NULL; 
     pActual->seguent = p; 
    } 
   else{ 
     p->seguent = pActual->seguent; 
     pActual->seguent = p; 
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

