#include <stdio.h>

int main()
{
	int count = 0;
	int *integers = NULL;
	char response = 'y';
	while(response == 'y' || response == '1')
	{
		count++;
		integers = realloc(integers, count * sizeof(int));
		printf("Enter The integer #%2d: ",count);
		scanf("%d",&integers[count-1]);
		printf("do you want to enter another number (y/n): ");
		scanf("%c");//kill new line char
		scanf("%c",&response);
	}
	printf("integers:\n");
	printIntArray(integers, count);
	int average = computeAverageOfIntArray(integers, count);
	printf("Average of array: %d:\n",average);
	subtractFromArray(integers, count, average);
	printf("integers after DC shift:\n");
	printIntArray(integers, count);
	return 0;
}

void printIntArray(int *arr,int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int computeAverageOfIntArray(int *arr, int size)
{
	int sum = 0;
	for(int i = 0 ; i < size ; i++)
	{
		sum += arr[i];
	}
	return sum/size;
}

void subtractFromArray(int *arr, int size, int value)
{
	for(int i = 0 ; i < size ; i++)
	{
		arr[i] -= value;
	}
}
