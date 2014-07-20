/*7. Fer un programa on es creï la mateixa estructura que en l’exercici 3 (d’un nombre 
complex). A partir d’aquí s’ha de demanar a l’usuari dues variables del tipus estructura 
complex, i que mitjançant funcions calculi el mòdul de cadascun dels nombres 
complexos, i el producte dels dos nombres complexos. 
*/

#include <stdio.h>
#include <math.h>
 
struct complex{ 
    float re; 
    float im; 
}; 
 
void impr(struct complex); 
void suma(struct complex , struct complex , struct complex * ); 
void resta(struct complex , struct complex , struct complex * );
void modul(struct complex , struct complex , struct complex * );
void producte(struct complex , struct complex , struct complex * );
 
void main(){ 
    struct complex z1,z2,zr; 
    printf("Introduiu els operadors. Per introduir un nombre complex\n"); 
    printf("amb part imaginaria negativa poseu a+-bi...\n");  
    printf("introduiu z1 (format x+yi):..."); 
    scanf("%f+%fi",&z1.re, &z1.im); 
 
    printf("introduiu z2 (format x+yi):..."); 
    scanf("%f+%fi",&z2.re, &z2.im); 
  
    suma(z1,z2,&zr); 
    impr(z1);printf("+ ");impr(z2);printf("= "); 
    impr(zr);printf("\n"); 
 
    resta(z1,z2,&zr); 
    impr(z1);printf("- ");impr(z2);printf("= "); 
    impr(zr);printf("\n");
    
    modul(z1,z2,&zr); 
    impr(z1);printf("- ");impr(z2);printf("= "); 
    impr(zr);printf("\n");
    
    producte(z1,z2,&zr); 
    impr(z1);printf("- ");impr(z2);printf("= "); 
    impr(zr);printf("\n");
} 
 
void impr(struct complex a){ 
    printf("%.2f+%.2fi ", a.re, a.im); 
} 
 
void suma(struct complex a, struct complex b, struct complex* c){ 
    c->re=a.re+b.re; 
    c->im=a.im+b.im; 
} 
 
void resta(struct complex a, struct complex b, struct complex* c){ 
    c->re=a.re-b.re; 
    c->im=a.im-b.im; 
}


void modul(struct complex a, struct complex b, struct complex* c){ 
    c->re=sqrt(a.re*a.re+a.im*a.im);
    c->im=sqrt(b.re*b.re+b.im*b.im);
}


void producte(struct complex a, struct complex b, struct complex* c){ 
    c->re=a.re*b.re-a.im*b.im;
    c->im=a.re*b.im+a.im*b.re;
}
