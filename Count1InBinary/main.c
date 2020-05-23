#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int m;
    char* countBit1(int n);

    while (scanf("%d", &m) != EOF)
    {
        printf("%s\n", countBit1(m));
    }
}


char* countBit1(int n)
{
    char* powOf2WithDecrease(int n);
    void* sum(char* a, char* b, char* dest);

    char* powDecrease1 = NULL;
    char* result = NULL;
    int length = 0;    
    char x2[2*n],
        arr[n+1][2*n];
    arr[0][0] = '1';
    arr[0][1] = '\0';

    for (int i = 1; i <= n; i++)
    {
        powDecrease1 = powOf2WithDecrease(i - 1);

        length = strlen(arr[i-1]);
        strcpy(x2, arr[i-1]);
        x2[length] = '0';
        x2[length + 1] = '\0';

        //arr[i] = 2 * arr[i-1] + pow(2, i-1) - 1;
        sum(x2, powDecrease1, arr[i]);
        free(powDecrease1);
    }

    result = malloc(strlen(arr[n]));
    strcpy(result, arr[n]);
    return result;
}

//计算2的n次方减一（二进制存储）
char* powOf2WithDecrease(int n)
{
    char* result = malloc(n + 1);

    for (int i = 0; i < n; i++)
    {
        result[i] = '1';
    }
    result[n] = '\0';

    return result;
}

//二进制加法
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

        if (value > '1')
        {
            value -= 2;
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