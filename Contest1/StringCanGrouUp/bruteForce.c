#include <stdio.h>

#define MAX_GEN 80

char* generateKmString()
{
    const MAX_STRING_LENGTH = 0;
    char* currentGenString = (char*)malloc(MAX_STRING_LENGTH);
    char* lastGenString = (char*)malloc(MAX_STRING_LENGTH);
    char* tempString = (char*)malloc(MAX_STRING_LENGTH);

    if (currentGenString == NULL) {
        printf("1.无法分配内存空间\n");
        exit(1);
    }
    else if (lastGenString == NULL) {
        printf("2.无法分配内存空间\n");
        exit(2);
    }
    else if (tempString == NULL) {
        printf("3.无法分配内存空间\n");
        exit(3);
    }
    
    strcpy(lastGenString ,"me");
    strcpy(currentGenString, "ktv");
   
    for (short i = 2; i <= MAX_GEN; i++)
    {
        //保存i-1代
        strcpy(tempString, currentGenString);
        //在i-1代后追加i-2代的字符串
        strcat(currentGenString, lastGenString);
        //更新i-2代
        strcpy(lastGenString, tempString);
    }

    free(tempString);
    free(lastGenString);

    return currentGenString;
}