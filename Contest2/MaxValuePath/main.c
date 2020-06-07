#include <stdio.h>
#include <stdlib.h>

struct Customer 
{
    int cValue;      //用户调研价值
    int *relationList;      //用户关系数组指针
    int rMaxIdx;   //用户关系长度
    unsigned int rLength;      //用户关系数组长度
};

int main()
{
    int getMaxValuePath(struct Customer *customer, int cLength, int index, int (*dp)[2]);
    int pushRelationship(struct Customer *customer, int rValue);
    
    int customerNum,
        relationNum,
        current,
        next,
        i;
    struct Customer *customerList = NULL;

    while (scanf("%d", &customerNum) != EOF)
    {
        customerList = (struct Customer *)malloc(sizeof(struct Customer) * customerNum);
        int dp[customerNum][2];  //[0]保存从该用户开始可取到的最大价值的总和，[1]保存当前用户下一个可调研的用户
        if (customerList == NULL)
        {
            printf("无法分配指定空间！\n");
            return 1;
        }
        
        for (i = 0; i < customerNum; i++)
        {
            scanf("%d", &customerList[i].cValue);
            customerList[i].rMaxIdx = -1;
            customerList[i].rLength = 0;
        }

        scanf("%d", &relationNum);
        for (i = 0; i < relationNum; i++)
        {
            scanf("%d %d", &current, &next);
            current--;
            next--;
            if (current < customerNum && next < customerNum)
            {
                if (pushRelationship(&customerList[current], next) < 0) 
                {
                    printf("无法保存用户调研关系！\n");
                    return 2;
                }
            }
            
        }
        
        for (i = customerNum-1; i >= 0; i--)
        {
            //直接用current存储最大价值路径的起始下标
            current = getMaxValuePath(customerList, customerNum, i, dp);
            free(customerList[i].relationList);
        }

        printf("%d\n", dp[current][0]);
        printf("%d", current + 1);
        next = dp[current][1];
        while (next >= 0)
        {
            printf("->%d", next + 1); 
            next = dp[next][1];
        }

        printf("\n");
        free(customerList);
    }

    return 0;    
}

int pushRelationship(struct Customer *customer, int rValue)
{
    int *newRelationList = NULL;
    //关系数超过关系数组长度，需要重新分配更大的数组
    if (customer->rMaxIdx >= (customer->rLength - 1))
    {
        newRelationList = (int *)malloc(sizeof(int) * (customer->rLength + 2));
        if (newRelationList == NULL)
        {
            return -1;
        }
        

        //复制原来的关系数组
        if (customer->rLength > 0)
        {
            for (int i = 0; i < customer->rLength; i++)
            {
                newRelationList[i] = customer->relationList[i];
            }
            free(customer->relationList);
        }
        customer->relationList = newRelationList;

        customer->rLength += 2;
    }

    //push
    customer->relationList[++customer->rMaxIdx] = rValue;
    return customer->rMaxIdx;
}

int getMaxValuePath(struct Customer *customer, int cLength, int index, int (*dp)[2])
{
    static int max = 0;
    static int indexOfMax = 0;
    int maxNextValue,
        maxNextIdx = -1,
        next,
        i;

    if (customer[index].rMaxIdx < 0)    //没有下一个可调研用户
    {
        maxNextValue = 0;
        maxNextIdx = -1;  
    } 
    else
    {
        //寻找后续路径中具有最大价值的路径
        next = customer[index].relationList[0];
        maxNextIdx = next;
        maxNextValue = dp[next][0];
        for (i = 1; i <= customer[index].rMaxIdx; i++)
        {
            next = customer[index].relationList[i];
            if (maxNextValue < dp[next][0]) 
            {
                maxNextIdx = next;
                maxNextValue = dp[next][0];
            }
        }
    }

    dp[index][0] = customer[index].cValue + maxNextValue;
    dp[index][1] = maxNextIdx;
    
    if (index >= cLength - 1)
    {
        index = cLength - 1;
        max = dp[index][0];
        indexOfMax = index;
    }
    else if (dp[index][0] >= max) 
    {
        max = dp[index][0];
        indexOfMax = index;
    }
    
    return indexOfMax;
}