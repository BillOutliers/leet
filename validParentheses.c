/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" 
and "([)]" are not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_TYPE char
typedef struct STACK_NODE {
	STACK_TYPE value;
	struct STACK_NODE *next;
} StackNode;
STACK_TYPE top(StackNode *stack_top);
int is_empty(StackNode *stack);
void push2(StackNode **stack_top,STACK_TYPE value);
void pop2(StackNode **stack_top);
int isValid(char* s) {
    StackNode *stack=NULL;
	char c;
	while(*s!='\0')
	{
		printf("%c\n",*s);
		switch(*s)
		{
			case '(':
			case '[':
			case '{': push2(&stack,*s);break;
			case ')': if(is_empty(stack) || top(stack)!='('){
						//	printf("top:%c\n",top(stack));
							return 0;
						}	
			          else pop2(&stack);break;
			case ']':  if(is_empty(stack) || top(stack)!='['){
						//	printf("top:%c\n",top(stack));
							return 0;
						}	
			          else pop2(&stack);break;
			case '}':  if(is_empty(stack) || top(stack)!='{'){
						//	printf("top:%c\n",top(stack));
							return 0;
						}	
			          else pop2(&stack);break;
			default:;
		}
		//printf("top:%c\n",top(stack));
		s++;
	}
	return is_empty(stack);
}
int main(int argc,char **argv)
{
	 char *s="([])[()";
	 printf("%d\n",isValid(s));
	return 0;
}
void push2(StackNode **stack_top,STACK_TYPE value)
{
	StackNode *new_node=(StackNode*)malloc(sizeof(StackNode));
	assert(new_node!=NULL);
	new_node->value=value;
	new_node->next=*stack_top;
	*stack_top=new_node;
}
void pop2(StackNode **stack_top)
{
	StackNode *first_node;
//	assert(!is_empty(*stack_top));
	first_node=*stack_top;
	*stack_top=first_node->next;
	free(first_node);
}
STACK_TYPE top(StackNode *stack_top)
{
	return (stack_top)->value;
}
int is_empty(StackNode *stack)
{
	return (stack)==NULL;
}