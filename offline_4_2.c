#include <stdio.h>
#include <stdlib.h>
int maxim(char *a, char *b){
    int i=0;
    while(*(a+i)!='.' && *(b+i)!='.'){
        if(*(a+i)>*(b+i)){
            return -1;
        }
        else if(*(a+i)<*(b+i)){
            return 1;
        }
        i++;
    }
    if(*(a+i)=='.' && *(b+i)=='.'){
        return 0;
    }
    else if(*(a+i)=='.'){
        return 1;
    }
    else{
        return -1;
    }
} 
int main(){
    int n;
    scanf("%d", &n);
    char **list=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        *(list+i) =(char*)malloc(26*sizeof(char));
        scanf("%s", *(list+i)); 
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(maxim(*(list+j), *(list+j+1))<0){
                char *temp=*(list+j);
                *(list+j)=*(list+j+1);
                *(list+j+1)=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s\n", *(list+i));
    }
    for(int i=0;i<n;i++){
        free(*(list+i));
    }
    free(list);
    
    return 0;
}