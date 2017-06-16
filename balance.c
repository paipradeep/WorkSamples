#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
struct stack
{
	char a[SIZE];
	int top;
};
typedef struct stack STK;

void push(STK *s,char ele)
{
	if(s->top==SIZE-1)
		printf("Stack overflow");
	else
	s->a[++s->top]=ele;
}

void pop(STK *s)
{
	if(s->top == -1)
		printf("Stack underflow");
	s->top--;
}

void main()
{
	STK s;
	s.top=-1;
	int i=0;
	char exp[15],ch;
	printf("Enter expression:");
	scanf("%s",exp);
	while((ch=exp[i++])!='\0')
	{
		if(ch=='(')
			push(&s,ch);
		else if(ch==')')
			pop(&s);
	}
	if(s.top==-1)
		printf("Balanced exp");
	else 
		printf("Not balanced");
}
			
