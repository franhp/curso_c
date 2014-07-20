#include <stdio.h>

void main(int argc, char *argv[]){
    FILE *origen, *desti;
    char c;
    
    if(argc!=3){
        printf("\nnombre de parametres incorrectes");
        return;
    }
    
    else {
        origen=fopen(argv[1],"rb");
        desti=fopen(argv[2],"wb");
        
        if(origen==NULL||desti==NULL) printf("\n Error");
        else {
            c=getc(origen);
            while(!feof(origen)){
                putc(c,desti);
                c=getc(origen);
            }
        fclose(origen);
        fclose(desti);
        }
    }
}
