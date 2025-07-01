#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void new_string(char *input, char **output, int *size){
   *size=0;
    for(int i=1;i<strlen(input);i++){
        if(*(input+i)>='1' &&*(input+i)<='9'){
            *size+=(*(input+i)-'0');
        }

    }
    *output=(char*)malloc((*size+1)*sizeof(char));
    if(*output==NULL){
        printf("wrong!");
        exit(1);
    }
    int pos=0;
    for(int i=1;i<strlen(input);i++){
        if(*(input+i)>='1'  && *(input+i)<='9'){
            for(int j=0;j<(*(input+i)-'0');j++){
                *(*output+pos)=*(input+i-1);
                pos++;
            }
        }
    }
    *(output+*size)='\0';
}
int main(void) {
    char *input=(char*)malloc(100*sizeof(char));
    scanf("%s",input);
    char *output;
    int size;
    new_string(input, &output, &size);
    printf("%s", output);
    free(input);
    free(output);
    return 0;
}