#include <stdio.h>


int main() {

        int n,v=0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            int s_odd=0, s_even=0, s_eve=0,v1=0, k, c=0;
            scanf("%d", &k);
            if(k==0) printf("ROW %d: INACTIVE- ENERGY LEVEL 0\n", i+1);
            else{
                for(int j=1;j<=k;j++){
                int a1;
                scanf("%d", &a1);
                if(j%2==0){
                    s_even+=a1;
                    s_eve=s_eve-a1;
                 }   
                else{
                    s_odd+=a1;
                 }                
            }
            if(s_even==s_odd){
                v1+=2;
                c++;
            }
            if((s_odd+s_eve)%7==0){
                v1+=4;
                c++;
            }
            int l;
            for(l=2;l*l<(s_odd+s_even);l++){
                if((s_odd+s_even)%l==0){
                    break;
                }
            }
            if(l*l>(s_odd+s_even) && ((s_odd+s_even)>1 || (s_odd+s_even)<-1)){
                v1+=5;
                c++;
            }
            int r=s_odd+s_even,s=0;
            while(r){
                s=s*10+r%10;
                r=r/10;
            }
            if(s==(s_even+s_odd)){
                v1+=3;
                c++;
            }
            v+=v1;
            printf("ROW %d: ", i+1);
            switch(c){
                case 0: printf("INACTIVE");
                    break;
                case 1: printf("LOW");
                    break;
                case 2: printf("MEDIUM");
                    break;
                case 3: printf("HIGH");
                    break;
                default: printf("ULTRA");
               }
            printf("- ENERGY LEVEL %d\n", v1);
        }
    }
        printf(".\nTOTAL ENERGY: %d", v);

    return 0;
}

