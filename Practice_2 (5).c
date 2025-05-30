#include <stdio.h>

int main()
{
    int n, x;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    int l = 0, h = n - 1, mid = l + (h - l) / 2;
    if (x > a[n - 1])
        printf("%d", 0);
    else if (x < a[0])
        printf("%d", n);
    else
    {
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (a[mid] == x)
            {
                printf("%d", n - mid - 1);
                break;
            }
            else if (a[mid] > x)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return 0;
}
