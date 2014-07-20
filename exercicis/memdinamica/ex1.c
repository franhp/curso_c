/*5. Escriure un programa en què l’usari entri una seqüència de nombres, i en calculi la mitjana, 
reservant memòria per desar-los a mesura que es van inicialitzant. */

#include <stdio.h>
#include <stdlib.h>

void main(){

    float *p,mitjana,suma=0;
    int nums=1,i=0,espai=2,resposta=0;
    
    if ((p=(float*)malloc(sizeof(float)))==NULL) printf("\nError");
    else {
        printf("\nInsereix Num\t");
        scanf("%f", p+i);
        printf("\n Numero inserit %f", *(p+i));
        suma=*(p+i);

        
        for(i=1;resposta==0;i++){
        if ((p=(float*)realloc(p,sizeof(float)*espai))==NULL) printf("\nError");
        else {
            printf("\nInsereix Num\t");
            scanf("%f", p+i);
            printf("\n Numero inserit %f", *(p+i));
        }
        espai++;
        
        //Mitjana
        suma=suma+*(p+i);
        printf("\nSuma es = %f", suma);
        nums++;
        printf("\nNums es = %d", nums);
        
        printf("\nVols continuar? 1 per NO/0 per SI\t");
        scanf("%d", &resposta);       
        }
        
        free(p);
        printf("\nMitjana\t%f\n", suma/nums);
    }
    
}
