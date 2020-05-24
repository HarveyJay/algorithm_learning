#include <stdio.h>

void main()
{
    int m;
    int countBit0(int n);

    while (scanf("%d", &m) != EOF)
    {
        printf("%d\n", countBit0(m));
    }
}

//计算0的总次数（mod 2020）
int countBit0(int n)
{
    int powOf2(int n);
    
    int times = 0,
        an[3];
    an[2] = 1;   //a(n-2)项
    an[1] = 3;   //a(n-1)项
    an[0] = 0;   //a（n）项

    if (n < 1)
    {
        return 0;
    }
    else if (n < 3)
    {
        return an[3-n];
    }
    
    //a(0) = 0;
    //a(1) = 1;
    //a(2) = 3;
    //a(n) = 3 * a(n-1) - 2 * a(n-2) + 2^(n-2) - 1;
    for (int i = 3; i <= n; i++)
    {
        an[0] = 3 * an[1] - 2 * an[2] + powOf2(i-2) - 1;
        if (an[0] >= 2020 && an[1] >= 2020)
        {
            an[1] %= 2020; 
            times = an[0] / 2020;
            an[0] -= (times - 1) * 2020;  //保证a(n)项大于a(n-1)项
        }
        an[2] = an[1]; 
        an[1] = an[0]; 
    }
    
    if (an[0] >= 2020)
    {
        an[0] %= 2020;
    } else if (an[0] < 0) {
        an[0] += 2020;
    }
    
    return an[0];
}

//求2的阶乘（mod 2020）
int powOf2(int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result <<= 1;
        if (result >= 2020)
        {
            result %= 2020;
        }   
    }
    
    return result;
}