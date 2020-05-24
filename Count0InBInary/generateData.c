#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{
    void printBinary(int n, FILE * fp);
    int isPowOf2(int n);
    void intToString(int n, char* desc);

    char fileName[20];
    char str[3];
    long num;
    FILE * fp;

    while (scanf("%ld", &num) != EOF)
    {
        intToString(num, str);
        strcpy(fileName, "data/data_");
        strcat(fileName, str);
        strcat(fileName, ".txt");
        fp = fopen(fileName, "w");

        num = pow(2, num);
        for (int i = 1; i <= num; i++)
        {
            printBinary(i, fp);
            if (isPowOf2(i))
            {
                fputc('\n', fp);
            }
        }
      
        fclose(fp);
    }
}

void printBinary(int num, FILE * fp)
{
    int temp,
        i;
    char b[64];

    for (i = 0; num > 1; i++)
    {
        temp = num >> 1;
        temp <<= 1;
        b[i] = (temp == num ? '0' : '1');

        num >>= 1;
    }

    if (num > 0)
    {
        b[i] = '1';
    }
    
    while (i >= 0)
    {
        if (fputc(b[i--], fp) == EOF)
        {
            printf("%s", "写入操作出错！");
            break;
        }
    }
    fputc(',', fp);
}

int isPowOf2(int num)
{
	if (num & (num - 1))   //去掉一个1，判断是否为0
		return 0;
	return 1;
}

void intToString(int num, char* desc)
{
    int i,len;
    char temp;

    for (i = 0; num > 0; i++)
    {
        desc[i] = '0' + num % 10;
        num /= 10;
    }
    desc[i] = '\0';

    len = strlen(desc);
    for (i = 0; i < len/2; i++)
    {
        temp = desc[i];
        desc[i] = desc[len-1-i];
        desc[len-1-i] = temp;
    }
}