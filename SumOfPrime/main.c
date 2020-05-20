#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m,n,length;
    int * prime = NULL;

    int * primeFilter(int floor, int ceiling, int* lengthFeedBack);
    int sum(int* values, int length);

    scanf("%d %d", &m, &n);

    prime = primeFilter(m, n, &length);

    m = sum(prime, length);
    printf("%d\n", m);
}

int * primeFilter(int floor, int ceiling, int* lengthFeedBack)
{
    int primeMap[ceiling+1];
    int primeNum = 0;
    int * prime = NULL;

    void arraySet(int* array, int value, int length);

    if (ceiling < 2 || floor > ceiling) 
    {
        return NULL;
    }
    
    ceiling += 1;
    arraySet(primeMap, 1, ceiling);
    for (int i = 2; i < ceiling; i++)
    {
        if (primeMap[i])
        {
            primeNum++;
            for (int j = 2; i*j < ceiling; j++)
            {
                primeMap[i*j] = 0;
            }
            
        }
        
    }

    prime = (int*)calloc(primeNum, sizeof(int));
    *lengthFeedBack = primeNum;

    primeNum -= 1;
    for (int i = floor; i < ceiling; i++)
    {
        if (primeMap[i])
        {
            prime[primeNum--] = i;
        }
        
    }
    
    return prime;
}

void arraySet(int* array, int value, int length)
{
    //int max = sizeof(array) / sizeof(int);
    for (int i = 0; i < length; i++)
    {
        array[i] = value;
    }
}

int sum(int* values, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += values[i];
    }
    return sum;
}