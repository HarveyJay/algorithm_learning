#include <stdio.h>

struct CharNode 
{
	CharNode *next[26];
};
int main()
{
	int patternNum,
		strNum
		i;
	
	while (scanf("%d %d", &patternNum, &strNum) != EOF)
	{
		char pattern[patternNum][7];
		char string[strNum][21];
		
		for (i = 0; i < patternNum; i++)
		{
			scanf("%s", pattern[i]);
		}
		for (i = 0; i < strNum; i++)
		{
			scanf("%s", string[i]);
		}
		
		//
		for (i = 0; i < strNum; i++)
		{
			
		}
	}
}