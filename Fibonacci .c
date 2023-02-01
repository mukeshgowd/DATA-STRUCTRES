#include <stdio.h>

int main()
{
    int num, i, a = 0, b = 1, c;
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("Fibonacci series: %d %d", a, b);
    for (i = 2; i < num; i++) {
        c = a + b;
        printf(" %d", c);
        a = b;
        b = c;
    }
    printf("\n");

    return 0;
}
