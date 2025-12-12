#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int lar, sec_l, nf = 1;
    if (a[0] > a[1])
    {
        lar = a[0];
        sec_l = a[1];
    }
    else
    {
        lar = a[1];
        sec_l = a[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i] > lar)
        {
            sec_l = lar;
            lar = a[i];
        }
        else if (a[i] > sec_l)
        {
            a[i] = sec_l;
        }
    }
    if (sec_l == lar)
        printf("Not Found\n");
    else
        printf("%d\n", sec_l);
    return 0;
}