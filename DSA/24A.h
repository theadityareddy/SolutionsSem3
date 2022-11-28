#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    char data;
    struct stack* next;
}stack;
stack* top;

stack* init()
{
    top = NULL;
}

int isempty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

void push(char x)
{
    stack* temp;

    temp = (stack*)malloc(sizeof(stack));
    temp->data = x;
    temp->next = NULL;
    if(top == NULL)
        top = temp;
    else
        {
            temp->next = top;
            top = temp;
        }
}

char pop()
{
    stack* q;
    char x = '\0';

    if(!isempty(top))
        {
            q = top;
            top = top->next;
            x = q->data;
            q->next = NULL;
            free(q);
            return x;
        }
    else
        printf("The stack is empty");
}

void display()
{   
    stack* p;

    if(!isempty(top))
        {
            p = top;
            while(p != NULL)
                {
                    printf("%d\n", p->data);
                    p = p->next;
                }
        }
    else
        printf("Stack is empty");
}
