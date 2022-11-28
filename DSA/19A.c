// Write a ‘C’ program to accept a string from user and reverse it using
// Static implementation of Stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
} stack;

int empty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int full(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(stack *ptr, char value)
{
    if (full(ptr))
    {
        printf("\nStack Overflow..!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(stack *ptr)
{
    char value;
    if (empty(ptr))
    {
        printf("\nStack Underflow..!");
    }
    else
    {
        value = ptr->arr[ptr->top];
        ptr->top--;
    }
    return value;
}

void main()
{
    char str[100];
    stack *stackk = (stack *)malloc(sizeof(stack));
    stackk->size = 50;
    stackk->top = -1;
    stackk->arr = (char *)malloc(stackk->size * sizeof(char));
    printf("\nStack is Created..!");
    printf("\nInput String==>");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        push(stackk, str[i]);
    }
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = pop(stackk);
    }
    printf("\nReversed String==>%s\n", str);
}
