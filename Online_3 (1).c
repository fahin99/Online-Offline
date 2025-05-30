#include <stdio.h>
#include <math.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n, m;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    int b[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    // int z=max(n,m)+1,c[z];
    // for(int i=0;i<z;i++){
    //     if(a[i]+b[i]>=10 && i<min(n,m)){
    //         b[i+1]++;
    //         b[i]=
    //     }
    //     c[i]=a[i]+b[i];
    // }
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += a[i] * (int)pow(10, i);
    }
    for (int i = 0; i < m; i++)
    {
        s2 += b[i] * (int)pow(10, i);
    }
    int s3 = s1 + s2;
    int x = s3, c = 0;
    while (x)
    {
        x = x / 10;
        c++;
    }
    int d[c];
    for (int i = 0; i < c; i++)
    {
        d[i] = s3 % 10;
        s3 = s3 / 10;
    }
    for (int i = 0; i < c; i++)
        printf("%d ", d[i]);
}