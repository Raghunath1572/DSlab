#include<stdio.h>
#include<stdlib.h>
#define size 2
int st[size];
int top=-1;
void push(int item)
{
	top++;
	st[top] = item;
}
    int peek()
{
	return st[top];
	}    
int pop()
{
	int item;
	item = st[top];
    top--;
	return (item);
}
void display()
{
	int i;
	for (i = top; i >= 0; i--)
	printf("\n%d", st[i]);
}
int main()
{
	int item, choice;
	char ans;
	printf("\n\tImplementation of Stack");
	do {
		printf("\nMain Menu");
		printf("\n1.push \n2.Pop \n3.Peek \n4.Display \n4.exit");
		printf("\nEnter Your Choice");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			if(top<size-1)
			{
				printf("\nEnter The item to be pushed");
				scanf("%d", &item);
				push(item);
			}
			else
			   printf("overflow");
			break;
		case 2:
		  if(top==-1)
		       printf("underflow");
		  else
		  {
		  	item = pop();
		  	printf("\nThe popped element is %d", item);
		  }
		  break;
		   case 3:
		   if(top==-1)
		      printf("underflow");
		   else
			{
			  item=peek(); 
			  printf(" the top most element is %d",item);
			}
			break;
			case 4:
			   display();
			   break;
			case 5:
			    exit(0);
			}
			printf("\nDo You want TO Continue?");
			scanf("%c",&ans);
		} while (ans == 'Y' || ans == 'Y');
return 0;		
	}	
