#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if(n%10==0) printf("No");
    else{
        if(n%2==0 || n%5==0){
            printf("Yes");
        }
        else printf("No");
    }
    main();
}
