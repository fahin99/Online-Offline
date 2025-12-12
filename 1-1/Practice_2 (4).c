#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], f[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j] && i != j)
            {
                f[i]++;
            }
        }
    }
    int max;
    for (int i = 0; i < n - 1; i++)
    {
        max = f[i];
        int temp, temp1;
        for (int j = i + 1; j < n; j++)
        {
            if (max < f[j])
            {
                temp = max;
                max = f[j];
                f[j] = temp;
                temp1 = a[i];
                a[i] = a[j];
                a[j] = temp1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}