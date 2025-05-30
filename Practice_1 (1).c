#include<stdio.h>

int main(){
    int n,a,b,c,d,m1,m2;
    scanf("%d",&n);
    a=n%10;
    n=n/10;
    b=n%10;
    n=n/10;
    c=n%10;
    n=n/10;
    d=n%10;
    n=n/10;
    //(a>b)? ((b>c)? mx1=a : (c>a)? mx1=a
    if(a>b && b>c){
        m1=a;
    }
    else{
        if(b>c){
            m1=b;
        }
        else if(c>a){
            m1=c;
        }
        else m1=a;
    }
    if(d>b && d>c){
        m2=d;
    }
    else{
        if(b>c){
            m2=b;
        }
        else if(c>d){
            m2=c;
        }
        else m2=d;
    }
    if(m1>m2) printf("%d",m2);
    else printf("%d",m1);
}
