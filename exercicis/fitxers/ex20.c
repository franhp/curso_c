/*Fes un programa en qu� l�usuari escrigui una l�nia de text, i mitjan�ant la l�nia de 
comandes indiqui amb quin nom vol desar el fitxer de text corresponent. 
*/
#include <stdio.h>

void main(){
    char frase[100],nomarxiu[20];
    FILE *pf;
    
    printf("\nEscriu una frase\t");
        gets(frase);

    printf("\nOn la vols desar?\t");
        scanf("%s", nomarxiu);
        
    if((pf=fopen(nomarxiu,"wt"))==NULL) printf("\nERROR");
    else {
        fputs(frase,pf);
        fclose(pf);
    }
    
}
