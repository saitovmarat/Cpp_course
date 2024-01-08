#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 0; i < 500000; ++i)
    {
        int x = 0;
        scanf("%i", &x);
        sum += x;
    }
    printf("%i\n", sum);
    return 0;
}