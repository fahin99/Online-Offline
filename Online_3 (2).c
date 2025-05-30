#include <stdio.h>
#include <math.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &height[i]);
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int d = min(height[i], height[j]);
            int e = j - i;
            c = max(c, e * d);
        }
    }
    printf("%d\n", c);
    return 0;
}
