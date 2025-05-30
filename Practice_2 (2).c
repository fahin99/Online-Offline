#include <stdio.h>

int main()
{
    int n, s, c = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &s);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i] + a[j] == s)
            {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    if (c == 0)
        printf("No pair");
    return 0;
}
