#include<stdio.h>

int main(){
    int n,a,b;
    scanf("%d %d %d",&n, &a, &b);
    if(a+b>n && a+n>b && b+n>a && a!=0 && b!=0 && n!=0){
        if(a==b && b==n) printf("equilateral");
        else if(a==b || b==n || a==n) printf("Isosecles");
        else printf("Scalene");
    }
    else printf("No possible triangle");
    main();
}
