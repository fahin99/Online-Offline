#include <stdio.h>
#include <stdlib.h>

void removeNegatives(int *input, int n, int **output, int *newSize){
    *output = (int*)malloc(n * sizeof(int));

    if (*output==NULL){
        printf("Memory allocation failed\n");
        *newSize=0;
        return;
    }

    int count=0;
    for (int i=0; i<n; i++){
        if (input[i]>=0){
            *(*output+count)=*(input+i);
            count++;
        }
    }

    *output=(int*)realloc(*output, count*sizeof(int));
    *newSize=count;
}

int main(){
    int n;
    scanf("%d", &n);

    int *input=(int*)malloc(n * sizeof(int));
    for (int i=0; i<n; i++){
        scanf("%d",input+i);
    }
    int *output=NULL, newSize=0;

    removeNegatives(input, n, &output, &newSize);

    printf("%d\n", newSize);
    for (int i=0; i<newSize; i++){
        printf("%d ",*(output+i));
    }
    printf("\n");

    free(output);
    return 0;
}
