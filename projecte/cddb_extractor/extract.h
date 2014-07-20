#define N 1024

//Troba paraules dins cadenes
int troba(char *pcad1, char *pcad2){
        int i,j;
        for(i=0;(*(pcad1+i)!='\0');i++){
                if(*(pcad1+i)==*(pcad2+0)) {
                        for(j=0;(*(pcad2+j)!='\0')&&(*(pcad1+i+j)==(*(pcad2+j)));j++);
                        if (*(pcad2+j)=='\0') return i;
                }
        }
 return -1;
}

void reiniciaCadena(char *vector){
	int i;
	for(i=0;((vector[i+1])!='\0');i++) vector[i]='\0';
}

// Treu el XXXXX=
void clean(char *vector){
        int i,j,count=0;
        char cadena[N]={0};

        for(j=0;vector[j]!='=';j++);
        j++;
        for(i=j;vector[i]!='\n';i++){
                cadena[count]=vector[i];
                count++;
        }
	reiniciaCadena(vector);
	strcpy(vector, cadena);
}

//Separa l'artista de la cadena
void show_artist(char *string){
        char artist[N]={'\0'};
        int i,j;

        for(j=0;string[j]!='=';j++);
        j++;
        for(i=0;string[j]!='/';i++){
                artist[i]=string[j];
                j++;
        }
        strcpy(string, artist);
}

//Separa el titol de la cadena
void show_title(char *string){
        char title[N]={'\0'};
                int i,j;

                for(j=0;string[j]!='/';j++);
                j=j+2;
                for(i=0;string[j]!='\n';i++){
                        title[i]=string[j];
                        j++;
                }
	strcpy(string, title);
}

int changeHour(char *string){
        char seconds[N]={'\0'};
        int time;
        int i,j;

        for(j=0;string[j]!=':';j++);
        j=j+2;
        for(i=0;string[j]!=' ';i++){
                seconds[i]=string[j];
                j++;
        }

        time=atoi(seconds);
        return time;
}