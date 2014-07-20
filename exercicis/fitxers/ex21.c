/*Crea un programa en què l’usuari escrigui les direccions del nombre de persones 
desitjat usant una estructura que contingui els camps: nom, carrer, número, ciutat, codi 
postal. Després el programa haurà de desar en disc en un fitxer tantes estructures com 
persones hagi escrit. 
*/
#include <stdio.h>
#define N 100
struct info{
    char nom[50];
    char carrer[50];
    char numero[4];
    char ciutat[20];
    char codi_postal[5];
}contactes[N];


void main(){
    FILE *pf;
    int limit,i;
    

    printf("\nQuants contactes vols inserir\t");
    scanf("%d", &limit);
    
    for(i=0;i<limit;i++){
        printf("\n________________");
        printf("\nContacte %d\n", i);
        
        printf("\nNom\t");
        scanf("%s", contactes[i].nom);
        printf("\nCarrer\t");
        scanf("%s", contactes[i].carrer);
        printf("\nNumero\t");
        scanf("%s", contactes[i].numero);
        printf("\nCiutat\t");
        scanf("%s", contactes[i].ciutat);
        printf("\nCodi Postal\t");
        scanf("%s", contactes[i].codi_postal);
    }

    if((pf=fopen("contactes.txt","at"))==NULL) printf("\nError");
    else {
        for(i=0;i<limit;i++){
            fputs(contactes[i].nom,pf);
            fputs("\t",pf);
            fputs(contactes[i].carrer,pf);
            fputs("\t",pf);
            fputs(contactes[i].numero,pf);
            fputs("\t",pf);
            fputs(contactes[i].ciutat,pf);
            fputs("\t",pf);
            fputs(contactes[i].codi_postal,pf);
            fputs("\n",pf);
        }
        fclose(pf);  
    }
}
