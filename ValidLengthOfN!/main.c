#include <stdio.h>
#include <math.h>

void main()
{
    int m;
    int lengthOfFactorial (int n);

    while (scanf("%d", &m) != EOF)
    {
        printf("%d\n", lengthOfFactorial(m));
    }  
}

int lengthOfFactorial(int n)
{
    double result = 1,
        temp;
    for (int i = 1; i <= n; i++)
    {
        temp = log10(i);
        result += temp;
    }
    
    return (int)result;
}
