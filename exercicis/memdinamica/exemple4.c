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
 
void main() { 
    crearNode(11); 
    crearNode(6); 
    crearNode(4); 
    crearNode(5); 
    
    saltarPrimerElement(); 
    
    //recorrer llista 
    while(!finalLlista()){ 
     printf("Element : %d\n", obtenirElementActual()); 
     obtenirSeguentElement(); 
    } 
    printf("Element : %d\n", obtenirElementActual());
} 


void crearNode(int n){ 
    struct node *p; 
    p = (node *) malloc(sizeof(node)); 
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
    p = (node *) malloc(sizeof(node)); 
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

