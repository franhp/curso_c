/*L’horari escolar d’un grup de batxillerat és de 6 hores diàries de dilluns a divendres. Volem crear una aplicació que ens permeti introduir les dades d’aquest horari.

Per cada hora s’haurà de definir:

- nom de l’assignatura.

- nom del professor.

- número d’aula.

L’horari s’emmagatzema en una estructura de dades anomenada horari. Tria l’estructura de dades més adient per emmagatzemar aquesta informació i que tingui les següents funcionalitats:

a) OmplenarHorari. Ha de permetre introduir totes les hores.

b) OmplenarHora. Permet introduir les dades d’una determinada hora d’un dia.

c) LlistarHorari. Treu per pantalla l’horari.

d) ModificarHora. Permet canviar les dades d’una determinada hora d’un dia.
*/
#include <stdio.h>
#define hores 6

struct horari {
        int  dia; // del 1 al 5 - dilluns a divendres
        int  hora; // del 1 al 6 - hores del dia
        char nom_assignatura[20];
        char nom_professor[20];
        char aula[10];
}assignatures[hores*5];

void omplenarhorari(struct horari assignatures[]);
void omplenarhora(struct horari assignatures[], int, int);
void llistarhorari(struct horari assignatures[]);
void modificarhora(struct horari assignatures[], int, int);

void main(){
        int tria,n=1,x,y;
        while(n==1){
                printf("\nQuina opcio vols?\n1.OmplenarHorari. Ha de permetre introduir totes les hores.\n2.OmplenarHora. Permet introduir les dades d’una determinada hora d’un dia.\n3.LlistarHorari. Treu per pantalla l’horari.\n4. ModificarHora. Permet canviar les dades d’una determinada hora d’un dia.\n5. Sortir\n");
                scanf("%d", &tria);
                switch(tria){
                        case 1: omplenarhorari(assignatures);
                                break;
                                
                        case 2: printf("\nQuina hora?");
                                scanf("%d", &x);
                                printf("\nQuina dia?");
                                scanf("%d", &y);
                                omplenarhora(assignatures,x,y);
                                break;
                                
                        case 3: llistarhorari(assignatures);
                                break;
                                
                        case 4: printf("\nQuina hora?");
                                scanf("%d", &x);
                                printf("\nQuina dia?");
                                scanf("%d", &y);
                                modificarhora(assignatures, x, y);
                                break;
                                
                        case 5: n=0;
                                break;
                                
                        default: break;
                }
                
        }
}

void omplenarhorari(struct horari assignatures[]){
        int i,dia=1,hora=1,cont=1;
        for(i=0;i<hores*5;i++){
                printf("\nDia %d Hora %d", dia, hora );
                printf("\tNom assignatura\t");
                        scanf("%s", assignatures[i].nom_assignatura);
                printf("\tNom professor\t");
                        scanf("%s", assignatures[i].nom_professor);
                printf("\tAula\t");
                        scanf("%s", assignatures[i].aula);
                assignatures[i].dia=dia;
                assignatures[i].hora=hora;
                hora++;
                if(hora==7) {
                        hora=1;
                        dia++;
                }
                printf("-----");
        }
}
void omplenarhora(struct horari assignatures[], int hora, int dia){
        printf("\nNova Assignatura:");
        scanf("%s", assignatures[hora*dia].nom_assignatura);
        printf("\nNou Professor:");
        scanf("%s", assignatures[hora*dia].nom_professor);
        printf("\nAula");
        scanf("%s", assignatures[hora*dia].aula);
        assignatures[hora*dia].dia=dia;
        assignatures[hora*dia].hora=hora;
}
void llistarhorari(struct horari assignatures[]){
        int i;
        for(i=0;i<hores*5;i++){
                printf("\nDia-Hora: %d - %d\tAssignatura: %s\tProfessor: %s\tAula: %s\n----", assignatures[i].dia,assignatures[i].hora,assignatures[i].nom_assignatura,assignatures[i].nom_professor,assignatures[i].aula);
                if(assignatures[i].hora==6){
                        printf("///////////////////////////////////");
                }
        }
        
}
void modificarhora(struct horari assignatures[], int hora, int dia){
        printf("\nAbans hi havia %s, i ara?", assignatures[hora*dia].nom_assignatura);
        scanf("%s", assignatures[hora*dia].nom_assignatura);
        printf("\nAbans hi havia %s, i ara?", assignatures[hora*dia].nom_professor);
        scanf("%s", assignatures[hora*dia].nom_professor);
        printf("\nAbans hi havia %s, i ara?", assignatures[hora*dia].aula);
        scanf("%s", assignatures[hora*dia].aula); 
}

