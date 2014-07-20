/*7. Escriu un programa que permeti gestionar dinàmicament una seqüència de nombres enters. 
El programa ha de permetre afegir un element, treure’l, mostrar una posició concreta i eliminar- 
los tots. */

#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
 int num; 
 struct node *seguent; 
}; 
 
struct node *pPrimer=NULL; 
struct node *pActual=NULL;
struct node *pPassat=NULL;
 
void crearNode(int n);
void treureNode(int n);
void insertarNode(int n); 
void saltarPrimerElement(); 
void obtenirSeguentElement(); 
int finalLlista(); 
int obtenirElementActual();
int eliminarElementActual();
 
void main() 
{
        
    int resposta, posicio, element,i=0;
    
    for(resposta=0;resposta<7;printf("\n")){
        printf("\n1.Insereix elements\n2.Treu elements\n3.Mostrar posicio\n4.Eliminar tot\n5.Mostrar totes\n6.Sortir\n");
        scanf("%d", &resposta);
        switch(resposta){
            case 1:
                printf("\nInsereix element\t");
                scanf("%d", &element);
                crearNode(element);
                break;
            case 2:
                printf("\nElement a treure\t");
                scanf("%d", &element);
                saltarPrimerElement(); 
                treureNode(element);
                break;
            case 3:
                printf("\nPosicio a mostrar\t");
                scanf("%d", &posicio);
                saltarPrimerElement();
                for(i=0;i<posicio;i++) obtenirSeguentElement();
                printf("\nA la posicio %d hi ha %d", posicio, pActual->num);
                break;
            case 4:
                printf("\nSalto al primer");
                saltarPrimerElement();
                printf("\nIntento arribar al final de la llista");
                while(!finalLlista()){
                    printf("\nPasso pel pActual que es igual a %d", pActual->num);
                    pPassat=pActual;
                    obtenirSeguentElement();
                    free(pPassat);
                }
                    printf("\nPasso pel pActual que es igual a %d", pActual->num);
                    pPassat=pActual;
                    obtenirSeguentElement();
                    free(pPassat);
                    pPrimer=NULL;
                printf("\nTot Eliminat");
                break;
            case 5:
                printf("\nMostrades totes\n");
                //recorrer llista
                saltarPrimerElement(); 
                while(!finalLlista()){ 
                    printf("Element %d -> %d\n", i, obtenirElementActual());
                    obtenirSeguentElement();
                    i++;
                } 
                printf("Element %d -> %d\n", i, obtenirElementActual());
                i=0;
                break;
            case 6:
                resposta=8;
                printf("\nBye!");
                break;
        }
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
 
void treureNode(int n){
    struct node *p;
    int element_extret,i,j;
    p = (struct node *)malloc(sizeof(struct node));
    
    //Fico el node en questió a l'auxiliar
    for(i=0;i<n;i++) obtenirSeguentElement();
    p=pActual;
    saltarPrimerElement(); 

    //Em situo a l'anterior
    for(i=0;i<(n-1);i++){
        printf("\nPasso pel pActual que es igual a %d", pActual->num);
        obtenirSeguentElement();
    }
    pActual->seguent=p->seguent;
    
    element_extret=p->num;
    free(p);

    printf("\n%d ha sigut eliminat", element_extret);
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



























/*


#include <stdio.h>
#include <stdlib.h>

struct node{
    int element;
    struct node *p_seg;
};

void main(){
    int element,posicio,resposta,i,j;
    struct node *p;
    struct node *aux;
    
    if ((p=(struct node*)malloc(sizeof(struct node)))==NULL) printf("\nError");
    else {
        for(resposta=0;resposta<7;printf("====================\n")){
            printf("\n1.Insereix elements\n2.Treu elements\n3.Mostrar posicio\n4.Eliminar tot\n5.Mostrar totes\n6.Sortir\n");
            scanf("%d", &resposta);
            switch(resposta){
                case 1:
                    printf("\nInsereix element\t");
                    scanf("%d", &element);
                case 2:
                    printf("\nElement a treure\t");
                    break;
                case 3:
                    printf("\nPosicio a mostrar\t");
                    break;
                case 4:
                    printf("\nEliminat");
                    break;
                case 5:
                    printf("\nMostrades totes");
                    
                    break;
                case 6:
                    resposta=8;
                    free(p);
                    break;
            }
        }
    }
    
    
    
}

























/*
void afegir_element(int ,int *);
void treure_element(int,int *);
int mostrar_posicio(int,int *);
void eliminar_tots(int *);
void mostrar_totes(int *);


void main(){
    int element,posicio,resposta;
    int *p;
    
    if ((p=(int*)malloc(sizeof(int)))==NULL) printf("\nError");
    else {
        while(resposta<7){
            printf("\n1.Insereix elements\n2.Treu elements\n3.Mostrar posicio\n4.Eliminar tot\n5.Mostrar totes\n6.Sortir\n");
            scanf("%d", &resposta);
            switch(resposta){
                case 1:
                    printf("\nInsereix element\t");
                    scanf("%d", &element);
                    afegir_element(element,p);
                    break;
                case 2:
                    printf("\nElement a treure\t");
                    scanf("%d", &element);
                    treure_element(element,p);
                    break;
                case 3:
                    printf("\nPosicio a mostrar\t");
                    scanf("%d", &posicio);
                    printf("\nA la posicio %d hi ha %d", posicio, mostrar_posicio(posicio,p);
                    break;
                case 4:
                    eliminar_tots(p);
                    printf("\nEliminat");
                    break;
                case 5:
                    mostrar_totes(p);
                    break;
                case 6:
                    resposta=8;
                    free(p);
                    break;
            }
        }
        
    }
}

void afegir_element(int element,int *p){
    int i;
    
    for(i=1;*(p+i)!=NULL;i++);
    
    printf("\n He contat fins %d", i);
    
    if ((p=(int*)realloc(p,sizeof(int)*i))==NULL) printf("\nError");
    else {
        *(p+i)=element;
        printf("\n Numero inserit %d a *(p+%d)\n",*(p+i),i);
    }

}
void treure_element(int element,int *p){
    int i;
    //encuentra al -1
    for(i=1;*(p+i)!=NULL;i++);
    
    *(p+element)=NULL;
}
int mostrar_posicio(int,int *);
void eliminar_tots(int *);
void mostrar_totes(int *p){
    int i;
    for(i=1;i<10;i++){
        printf("\n%d -> %d", i , *(p+i));
    }
}
*/