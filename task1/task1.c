#include <stdio.h>

int main()
{
	int Vsize;
	int scalarA;
	int scalarB;
	printf("This program will compute z = ax + by\n");
	printf("Enter the size of the vectors : ");
	scanf("%d",&Vsize);
	printf("Enter the scalar a: ");
	scanf("%d",&scalarA);
	printf("Enter the scalar b: ");
	scanf("%d",&scalarB);
	int *vectorX = (int*)malloc(Vsize * sizeof(int));
	int *vectorY = (int*)malloc(Vsize * sizeof(int));
	int *vectorZ = (int*)malloc(Vsize * sizeof(int));

	if(vectorX == NULL || vectorY == NULL || vectorZ == NULL)
	{
		printf("failed to allocate memory for vectors\n");
		return -1;
	}

	printf("you will be asked to enter each value of vector x and y\n");
	for(int i = 0 ; i < Vsize ; i++)
	{
		printf("Enter the value of X(%d): ",i);
		scanf("%d",&vectorX[i]);
	}
	for(int i = 0 ; i < Vsize ; i++)
	{
		printf("Enter the value of Y(%d): ",i);
		scanf("%d",&vectorY[i]);
	}

	arrayTimesScalar(vectorX, Vsize, scalarA);
	printf("ax:\n");
	for(int i = 0 ; i < Vsize ; i++)
	{
		printf("%2d\n",vectorX[i]);
	}
	printf("\n");
	arrayTimesScalar(vectorY, Vsize, scalarB);
	printf("by:\n");
	for(int i = 0 ; i < Vsize ; i++)
	{
		printf("%2d\n",vectorY[i]);
	}
	printf("\n");
	addTwoArrays(vectorZ, vectorX, vectorY, Vsize);
	printf("resulting array z = ax + by:\n");
	for(int i = 0 ; i < Vsize ; i++)
	{
		printf("%2d ",vectorZ[i]);
	}
	printf("\n");
	return 0;
}

void arrayTimesScalar(int *arr, int size, int scalar)
{
	for(int i = 0 ; i < size ; i++)
		arr[i] *= scalar;
}

void addTwoArrays(int *destArr, int *arr1, int *arr2, int size)
{	
	for(int i = 0 ; i < size ; i++)
		destArr[i] = arr1[i] + arr2[i];
}
