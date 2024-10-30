#include <stdio.h>

int *stack = NULL;
int number_elements = 0;

int main()
{
	char response;
	while(1)
	{
		printf("please enter operation (p)-Push (o)-Pop (d)-Display (e)-Exit: ");
		scanf(" %c",&response);
		switch(response)
		{
			case 'p':
				printf("Enter an integer: ");
				int tmp;
		       	       	scanf("%d",&tmp);
		 		push(tmp);
				break;
			case 'o':
				printf("Poped: %d\n",pop());
				break;
			case 'd':
				display();
				break;
			case 'e':
				return 0;
			case '\n':
				break;
			default:
				printf("not recognized please enter (p)-Push (o)-Pop (d)-Display (e)-Exit");
						
		}
	}
	return 0;
}

void display()
{
	printf("Stack:\n");
	for(int i = 0 ; i < number_elements ; i++)
	{
		printf("%02d- %d\n",i,stack[i]);
	}
}
void push(int value)
{
	number_elements++;
	grow();
	printf("new size: %d\n",number_elements);
	stack[number_elements-1] = value;
}

int pop()
{
	if(number_elements == 0)
	{
		printf("stack is empty...");
		return -1;
	}
	int value = stack[--number_elements];	
	shrink();
	return value;
}

int grow()
{
	stack = realloc(stack, number_elements * sizeof(int));
	if(stack == NULL)
	{
		printf("failed to allocate more space\n");
		return -1;
	}
	return 0;
}

void shrink()
{
	stack = realloc(stack, number_elements * sizeof(int));
}
