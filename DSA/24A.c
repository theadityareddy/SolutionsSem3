#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include "24A.h"
void evaluate(char[]);

int main()
{
    char str[50];

    printf("Enter string: ");
    scanf("%s", str);

    evaluate(str);
    
    return 0;
}

void evaluate(char str[])
{
    int i, op1, op2, result;

    init();
    for(i = 0; str[i]!='\0'; i++)
        {
            if(isdigit(str[i]))
                push(str[i]);
            else
                {
                    op2 = pop()-'0';
                    op1 = pop()-'0';
                    switch(str[i])
                        {
                            case '+': result = op1+op2;
                                      break; 

                            case '-': result = op1-op2;
                                      break; 

                            case '*': result = op1*op2;
                                      break; 

                            case '/': result = op1/op2;
                                      break; 

                            case '^':
                            case '$':result = pow(op1, op2);
                                     break;
                        }
                    push(result+'0');
                }
        }
    result = pop()-'0';
    printf("Result is %d", result);
}