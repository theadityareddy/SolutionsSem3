#include<stdio.h>
#include<string.h>

typedef struct stack{
    char data[80];
    int top;
}stack;

int isempty(stack* p){
    if(p->top==-1){
        return 1;
    }
    return 0;
}

int isfull(stack* p){
    if(p->top > 80-1){
        return 1;
    }
    return 0;
}

void init (stack* p){
    p->top = -1;
}

void push (stack* p,char x){
    if (!isfull(p)){
        p->top = p->top + 1;
        p->data[p->top] = x;
    } else {
        printf ("\nstackoverflow\n");
    }
}

char pop(stack* p){
    char x = '\n';
    if (!isempty(p)){
        x = p->data[p->top];
        p->top = p->top-1;
    } else {
        printf("\nstackunderflow\n");
    }
    return x;
}

void revert (char str[], int m, int n){
    int i;
    stack s;
    init(&s);
    for (i=m; i<n;i++){
        push(&s, str[i]);
    }
    i=m;
    while(!isempty(&s)){
        str[i] = pop(&s);
        i++;
    }
}

int main(){
    stack s;
    int ch;
    char str[80], str1[80];
    printf("\nenter string\n");
    gets(str);
    revert(str, 0, strlen(str));
    printf("\nreversed string is %s", str);
    return 1;
}