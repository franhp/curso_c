#include <stdio.h>
void main(){
    FILE *pf;
    float element;
    int i,j,pos;
    
    if((pf=fopen("matriu.bin","rb"))==NULL) puts ("error");
    else{
        printf("\n el punter fitxer esta a %d", ftell(pf)); // should be 0
        printf("\n pos = ");
        scanf("%d", &pos);
        fseek(pf,pos*sizeof(float),SEEK_SET); // Em despla�o una posici� desde pos
        printf("\n posicio punter = %d", ftell(pf)); // Num de bytes despla�at
        fread(&element,sizeof(float),1,pf); // LLegeix els bytes de float  
        printf("\n n = %f\n", element);
        fclose(pf);
    }
    
}
