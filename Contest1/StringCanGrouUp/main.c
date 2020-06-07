#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GEN  80
//#define MAX_LENGTH 256
unsigned long long int fbSeries[MAX_GEN];  //斐波那契数列

void main()
{
    void fibonacci();

    int gen;
    unsigned long long int pos;
    char kmString[] = "ktvme";

    fibonacci();
    while (scanf("%d %llu", &gen, &pos) != EOF)
    {

        while (gen > 2)
        {   
            if (pos <= fbSeries[gen - 1])
            {
                gen--;
            }
            else 
            {
                pos -= fbSeries[gen - 1];
                gen -= 2;
            }
        } 
        printf("%c\n", kmString[pos - 1]);  
    }
}

void fibonacci()
{
    //void* sum(char* a, char* b, char* dest);

    fbSeries[0] = 2;
    fbSeries[1] = 3;
    
  
    for (int i = 2; i <= MAX_GEN; i++)
    {
        fbSeries[i] = fbSeries[i-1] + fbSeries[i-2];
    }
}
