#include <stdio.h>

int main()
{
	char *sentence = malloc(25 * sizeof(char));
	printf("Enter a sentence(max 25): ");
	fgets(sentence, 25, stdin);
	int strLength = 0;
	while(sentence[strLength])
	{
		strLength++;
	}
	strLength--; //for the new line
	sentence[strLength] = '\0';
	sentence = realloc(sentence, strLength);
	printf("sentence : %s\n",sentence);
	printf("strLength: %d\n",strLength-1);
	char* reversedStr = malloc(1 * sizeof(char));
	int count = 0;
	for(int i = strLength-1 ; i >= 0 ; i--)
	{
		reversedStr[count++] = sentence[i];
		reversedStr = realloc(reversedStr, count+1);
		sentence = realloc(sentence, strLength - count);
	}
	reversedStr[count] = '\0';
	printf("the reversed sentence is: %s\n",reversedStr);
	free(sentence);
	free(reversedStr);
	return 0;
}
