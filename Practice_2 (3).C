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
    int c = n;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
                c--;
        }
    }
    int b[c], j = 1;
    b[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        int v = 0;
        for (int k = i - 1; k >= 0; k--)
        {
            if (a[i] == a[k])
            {
                v++;
                break;
            }
        }
        if (v == 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < c; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}
