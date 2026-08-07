#include<stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int item)
{
	if(top == MAX - 1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		top++;
		stack[top] = item;
	}
}
void pop()
{
	if(top == -1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("Deleted Number is  %d\n",stack[top]);
		top --;
	}
}
void peek()
{
	if(top == -1)
	{
		printf("Stack is Empty");
	}
	else
	{
		printf("the top element is %d\n", stack[top]);
	}
}
void display()
{
	int i;
	if(top == -1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Stack Elements:\n");
		for(i = top; i >= 0; i--)
		{
			printf("%d\n", stack[i]);
		}		
	}
}
int main()
{
	int choice, item;
	
	while(1)
	{
		printf("--------Stack Menu-------\n");
		printf(" 1. Push\n");
		printf(" 2. Pop\n");
		printf(" 3. peek\n");
		printf(" 4. display\n");
		printf(" 5. Exit\n");
		
		printf("Enter the choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter element: ");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				return 0;
			default:
				printf("Invalid Choice");
		}
	}
}


