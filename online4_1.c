#include <stdio.h>
#include <stdlib.h>
void rotate(int *n, int **a){
    for(int i=0;i<*n/2;i++){
        for(int j=i;j<*n-i-1;j++){
            int temp= *(*(a+i)+j);
            *(*(a+i)+j)=*(*(a+*n-j-1)+i);
            *(*(a+*n-j-1)+i)=*(*(a+*n-i-1)+(*n-j-1));
            *(*(a+*n-i-1)+(*n-j-1))=*(*(a+j)+*n-i-1);
            *(*(a+j)+*n-i-1)=temp;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int **a=(int**)malloc(n*sizeof(int*));
    if(a==NULL){
        printf("allocation fail");
        return 0;
    }
    for(int i=0;i<n;i++){
        *(a+i)=(int*)malloc(n*sizeof(int));
        if(*(a+i)==NULL){
            printf("allocation fail");
            for(int j=0;j<i;j++) free(*(a+j));
            free(a);
            return 0;
        }
        for(int j=0;j<n;j++) scanf("%d", (*(a+i)+j));
    }
    rotate(&n, a);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", *(*(a+i)+j));
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        free(*(a+i));
    }
    free(a);
    return 0;
}