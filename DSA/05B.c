/*Write a 'C' program to create linked list with given number in which data part of each node contains individual digit of the number.
(Ex. Suppose the number is 368 then the nodes of linked list should contain 3, 6, 8)*/



#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;                   
    struct node *next;       
}*start, *temp;
void main()
{
	int a[10],j,i,num;
	start=NULL;
	temp=NULL;
	printf("Enter number:");
	scanf("%d",&num);
	i=0;
	while(num>0)
	{
		a[i]=num%10;
		i++;
		num=num/10;
	}
	i--;
	printf("Linked list:");
	for(j=i;j>=0;j--)
	{
		if(start==NULL)
	{
	start = (struct node *)malloc(sizeof(struct node));
	start->data=a[j];
	printf("%d",start->data);
	start->next=NULL;
	temp=start;
    }   
    else
	{
    temp->next = (struct node *)malloc(sizeof(struct node));
	temp->next->data=a[j];
	printf("--->%d",temp->next->data);
	temp->next->next=NULL;
	temp=temp->next;
	}
}
}
