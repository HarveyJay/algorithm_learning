#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 256;
void main()
{
    char* fibValue;
    int m;
    char* fibonacci(int n);
    void* sum(char* a, char* b, char* dest);

    while (scanf("%d", &m) != EOF)
    {
        fibValue = fibonacci(m);
        printf("%s\n", fibValue);
        free(fibValue);
    }
}

char* fibonacci(int n)
{
    void* sum(char* a, char* b, char* dest);

    char series[n+1][MAX_LENGTH];
    char* result = malloc(MAX_LENGTH);

    series[0][0] = '0';
    series[0][1] = '\0';

    if (n >= 1)
    {
        series[1][0] = '1';
        series[1][1] = '\0';
    }
  
    for (int i = 2; i <= n; i++)
    {
        sum(series[i-1], series[i-2], series[i]);
    }
    strcpy(result, series[n]);
    
    return result;
}

void* sum(char* a, char* b, char* dest)
{
    char value = 0,
        valueA,
        valueB;
    short carry = 0;    
    int lengthOfA = strlen(a),
        lengthOfB = strlen(b),
        max = lengthOfA > lengthOfB ? lengthOfA : lengthOfB;
    char sum[max + 1];

    sum[max] = '\0';
    while (lengthOfA > 0 || lengthOfB > 0)
    {
        valueA = lengthOfA <=0 ? '0' : a[--lengthOfA];
        valueB = lengthOfB <=0 ? '0' : b[--lengthOfB];   
        value = valueA + valueB + carry - '0';

        if (value > '9')
        {
            value -= 10;
            carry = 1;
        } 
        else {
            carry = 0;
        }
        
        sum[--max] = value;
    }
    
    if (carry > 0)
    {
        dest[0] = '1';
        dest[1] = '\0';
        strcat(dest, sum);
    }
    else
    {
        strcpy(dest, sum); 
    }   
}