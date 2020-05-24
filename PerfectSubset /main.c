#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m,
        n,
        maxLength; //好子集的最大元素个数
    int* arr;  //定义一个数组，用于存放对应子集元素个数为n时的好子集个数
    int sum(int* arr, int length);

    while (scanf("%d", &m) != EOF)
    {
        maxLength = (m + 1) / 2;

        arr = malloc(maxLength*sizeof(int)/sizeof(char));
        arr[0] = m;
        for (int i = 1; i < maxLength; i++)
        {
            n = m - i * 2;
            arr[i] = n * (n + 1) / 2;
        }

        printf("%d\n", sum(arr, maxLength));
        free(arr);
    }
}

int sum(int* arr, int length)
{
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result += arr[i];
    }
    return result;
}

/* 
long fact(int num){
	long result=num;
    if (num <= 0)
    {
        return 1;
    }
    

	for(int i = num-1; i > 0 ; i--){
		result *= i;
	}
	return result;
}

long combinatorialNumber (int m, int n) 
{
    long result;
    result = fact(m) / (fact(n) * fact(m-n));
    return result;
} */