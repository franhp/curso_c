#include <stdio.h>
#include <stdlib.h>

void main(){
    
    int n,i,*p;
    printf("\n n= ");
    scanf("%d", &n);

    
    if((p=(int*)calloc(n,sizeof(int)))==NULL) printf("\nError");
    else {
        printf("\ndir = %p", p);
        for(i=0;i<n;i++){
            printf("\np[%d] = ", i);
            scanf("%d", p+i);
        }
        
        for(i=0;i<n;i++) printf("\np[%d] -> %d",i,*(p+i));
    }
    
    free(p);
}

