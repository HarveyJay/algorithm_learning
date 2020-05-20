#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m,length,primeNum;
    int* primeList = NULL; 
    int* getPrimeList(int n, int* lengthFeedback);
    void printFactors(int m, int* primeList, int length);

    while (scanf("%d", &m) != EOF)
    {
       
        primeList = getPrimeList(m, &length);
        printFactors(m, primeList, length);
        free(primeList);
    }
}

void printFactors(int m, int* primeList, int length)
{
    int primeNum;

    for (int i = 0; i < length; i++)
    {
        primeNum = primeList[i];
        while (m % primeNum == 0)
        {
            m /= primeNum;

            if (m == 1)
            {
                printf("%d\n", primeNum);
            } 
            else 
            {
                printf("%d*", primeNum);
            } 
        }
        
    }
}

void arraySet(int* array, int value, int length)
{
    //short times = sizeof(int) / sizeof(char);
    //memset(array, value, length);
    for (int i = 0; i < length; i++)
    {
        array[i] = value;
    }
}

int* getPrimeList(int n, int* lengthFeedback)
{
    n += 1;

    int num = 0;
    int* prime = NULL;
    int primeList[n/2+1];
    int primeMap[n];
    arraySet(primeMap, 1, n);

    for (int i = 2; i < n; i++)
    {
        if (primeMap[i])
        {
            primeList[num++] = i;
            for (int j = i; (double)i*j < n; j++)
            {
                primeMap[i*j] = 0;
            }
        }
        
    }

    *lengthFeedback = num;

    prime = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        prime[i] = primeList[i];
    }
    
    return prime;
}