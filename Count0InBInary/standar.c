#include <stdio.h>
#include <math.h>

void main()
{
    int m;
    struct bit b;
    //long long countBitOf0(int n);

    while (scanf("%d", &m) != EOF)
    {
        b.val = m;
        printf("%d\n", b.val);
        //printf("%d\n", isPowOf2(m));
        //printf("%lld\n", countBitOf0(m));
    }
}

char* countBitOf0(int n)
{
    struct bit binary[5000];
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
       
}

/******   begin of bit  ******/
struct bit{
    unsigned int val: 1;
};

void increaseByOne(struct bit* binary) 
{

}
/*******   end of bit  *******/