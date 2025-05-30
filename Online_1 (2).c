#include <stdio.h>
int main()
{
    float x1,y1,r1, x2, y2, r2,c;
    scanf("%f %f %f", &x1, &y1, &r1);
    scanf("%f %f %f", &x2 ,&y2, &r2);
    if(r1<r2){
        c=r2;
        r2=r1;
        r1=c;
    }
    if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))==(r1+r2)*(r1+r2) || ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))==(r1-r2)*(r1-r2) ){
        printf("Touching");
    }
    else if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<(r1+r2)*(r1+r2) && ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>(r1-r2)*(r1-r2)){
        printf("Intersecting");
    }
    else if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<(r1-r2)*(r1-r2)){
        printf("Inside");
    }
    else{
        printf("Not intersecting");
    }
    return 0;
}
