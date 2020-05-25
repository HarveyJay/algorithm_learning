#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    void quickSort(int* arr, int low, int high);
    short strCompare(char* strA, char* strB);

    int num;
    char** stack;  //存储每一个部门的手机数量
    int* sortedIndex;  //存储排序后的索引

    while (scanf("%d", &num) != EOF)
    {
        stack = (char**)malloc(num * sizeof(char*));
        sortedIndex = (int*)malloc(num * sizeof(int));

        for(int i = 0;i < num; i++) {
            stack[i] = (char*)malloc(12);  
            scanf("%s", stack[i]);
        }

        //quickSort(stack, 0, num-1);
        for (int i = 0; i < num-1; i++)
        {
            printf("%d\n", strCompare(stack[i], stack[i+1]));
        }
        
        free(stack);
    }
    
}

void quickSort(int* arr, int low, int high) {
    int getIndex(int* arr, int low, int high);

    if (low < high) {
        // 找寻基准数据的正确索引
        int index = getIndex(arr, low, high);

        // 进行迭代对index之前和之后的数组进行相同的操作使整个数组变成有序
        quickSort(arr, 0, index - 1);
        quickSort(arr, index + 1, high);
    }

}

int getIndex(int* arr, int low, int high) {
    int base = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= base) {
            high--;
        }
        
        arr[low] = arr[high];
        while (low < high && arr[low] <= base) {
            low++;
        }
        
        arr[high] = arr[low];

    }
    
    arr[low] = base;
    return low; // 返回基准数据的正确索引
}

short strCompare(char* strA, char* strB)
{
    short lengthOfA = strlen(strA);
    short lengthOfB = strlen(strB);
    if (lengthOfA != lengthOfB)
    {
        return lengthOfA - lengthOfB;
    }
    
    for (int i = 0; i < lengthOfA; i++)
    {
        if (strA[i] != strB[i])
        {
            return strA[i] - strB[i];
        }
    }
    
}