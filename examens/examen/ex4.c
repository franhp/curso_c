#include <stdio.h>

struct complex{ 
    float re; 
    float im; 
};

void ini(struct complex *);
struct complex quadrat(struct complex, struct complex);

void main(){
    struct complex a,b,resultat;
    ini(&a);
    ini(&b);
    
    resultat=quadrat(a,b);
    
    printf("\nEl seu quadrat es %f+%fi\n", resultat.re, resultat.im);
}

void ini(struct complex *a){ 
    printf("Introduiu els operadors (format x+yi):\t"); 
    scanf("%f+%fi", &a->re, &a->im);
}

struct complex quadrat (struct complex a, struct complex b){
    struct complex quadrat;
    quadrat.re=((a.re*a.re)-(b.re*b.re));
    quadrat.im=2*a.im*b.im;
    return(quadrat);
}
