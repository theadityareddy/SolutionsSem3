#include <stdio.h>
#include <stdlib.h>
#define NEWNODE (node *)malloc(sizeof(node));
typedef struct node
{
    int data;
    struct node *next;
} node;

void print(node *);
node *append(node *, int);

int main()
{
    node *head1 = NULL, *head2 = NULL;
    int i, n, x;

    printf("Enter how many nos ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data to be inserted: ");
        scanf("%d", &x);
        if (x % 2 == 0)
            head2 = append(head2, x);
        else
            head1 = append(head1, x);
    }

    printf("\nEven nodes: ");
    print(head2);

    printf("\nOdd nodes: ");
    print(head1);

    return 0;
}

void print(node *head)
{
    node *p;

    p = head;
    printf("\n");
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
    printf("\n");
}
node *append(node *head, int x)
{
    node *temp, *p;

    temp = NEWNODE;
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else if (head->next == NULL)
        head->next = temp;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }

    return head;
}