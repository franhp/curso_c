#include <stdio.h>

// copiar (variable de dest’, variable de origen)
char * assigna (char *cad1, char *cad2){
    int i;
    for(i=0;*(cad2+i)='\0';i++){
        *(cad1+i)=*(cad2+i);
    }
    return(cad1);
}

// Retorna 1 si cad1 es mes gran, 0 si cad2 es mes gran, -1 si son iguals
int compara (char *cad1, char *cad2){
    int suma1=0, suma2=0,i;
    
    for(i=0;(*(cad1+i)!='\0')||(*(cad2+i)=='\0');i++){
        suma1=*(cad1+i)+suma1;
        suma2=*(cad2+i)+suma2;
    }
    if(suma1>suma2){
        return(1);
    }
    else if(suma2>suma1){
        return(0);
    }
    else {
        return(-1);
    }
    
}

// Afegeix cad2 a cad1
char * concatenar(char *cad1, char *cad2){
    int i,j;
    
    for(i=0;*(cad1+i)!='\0';i++){
    }
    for(j=0;*(cad2+j)!='\0';j++){
        *(cad1+i)=*(cad2+j);
        i++;
    }
    *(cad1+i)='\0';
    
    return(cad1);
}


//extreure (variable1, posici—, longitud, variable2)  
char * extreure(char *cad1, int pos, int longitud, char *cad2){
    int i, x=0;
    
    for(i=pos;i<=longitud;i++){
        *(cad2+x)=*(cad1+i);
        x++;
    }
    *(cad2+x)='\0';
    
    return(cad2);

}

//Longitud incloent espais
int longitud (char *cad1){
    int i;
    
    for(i=0;*(cad1+i)!='\0';i++);
    
    return i;
}

//Troba si la paraula esta dins la cadena 1 i retorna la seva posici—, sino retorna -1

int index (char *cad1, char *cad2){
    int i,j;
    for(i=0;*(cad1+i)!='\0';i++){
        if(*(cad1+i)==*(cad2)){
            for(j=0;(*(cad2+j)!='\0')&&(*(cad1+i+j)==(*(cad2+j)));j++);
	    if (*(cad2+j)=='\0') return i;
        }
    }
    
    return -1;
    
}

//Insereix el que hi ha a la cad2 en la posicio pos de la cad1

char * inserir(char *cad1, int pos, char *cad2){
    int i,j,x=0;
    x=longitud(cad1)+longitud(cad2);
    for(i=longitud(cad1)+1; i>=pos; i--, x--){
        *(cad1+x+1)=*(cad1+i);
    }
    for(i=pos, j=0; *(cad2+j)!='\0'; i++, j++){
        *(cad1+i)=*(cad2+j);
    }
    return(cad1);
}


//Esborra  desde pos tota la longitud de cad1
char * esborrar(char *cad1, int pos, int longitud){
    int i,j;
    for(i=0; i<pos; i++);
    j=i;
    for(;*(cad1+i)!='\0';i++,longitud++){
        *(cad1+i)=*(cad1+j+longitud);
    }
    return(cad1);
}

//Substitueix de cad1 , cad2 per cad3
char * substituir(char *cad1, char *cad2, char *cad3){
    int pos;

    pos=index(cad1,cad2);
    esborrar(cad1,index(cad1,cad2),longitud(cad2));
    inserir(cad1,pos,cad3);
}
