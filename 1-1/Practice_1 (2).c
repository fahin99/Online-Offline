#include<stdio.h>
int main(){
    double n;
    scanf("%lf",&n);
    if(n<=300000){
            printf("%.2lf",n);
    }
    else if(n<=400000){
            printf("%.2lf",n-((n-300000)*5)/100);
    }
    else if(n<=700000){
            printf("%.2lf", n-(((n-400000)*10)/100)-5000);
    }
    else if(n<=1100000){
            printf("%.2lf", n-(((n-700000)*15)/100)-5000-30000);
    }
     else if(n<=1600000){
            printf("%.2lf", n-(((n-1100000)*20)/100)-60000-35000);
     }
     else{
        printf("%.2lf", n-(((n-1600000)*25)/100)-60000-35000-100000);
     }
     main();
}
