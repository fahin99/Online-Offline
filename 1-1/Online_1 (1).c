#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    if(b*b>4*a*c){
        printf("Distinct Solutions\n");
        float s1=(-b+sqrt(b*b-4*a*c))/(2*a);
        float s2=(-b-sqrt(b*b-4*a*c))/(2*a);
        printf("%.2f %.2f",s1,s2);
    }
    else if(b*b==4*a*c){
        printf("Equal solutions\n");
        printf("%.2f",-b/(2*a));
    }
    else{
        printf("Imaginary solutions");
        float a1=-b/(2*a),a2=sqrt(b*b-4*a*c)/(2*a),a3=-sqrt(b*b-4*a*c)/(2*a);
        printf("(%.2f %.2f) (%.2f %.2f)", a1,a2,a1,a3);
    }
    

}

