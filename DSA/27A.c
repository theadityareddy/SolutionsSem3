#include <stdio.h>
#include "27A.h"
int main()
{
    Queue q;
    int x, choice;

    init(&q);
    do
    {
        printf("\n\n1: Insert");
        printf("\n2: Delete");
        printf("\n3: Isempty");
        printf("\n4: Display");
        printf("\n5: Isfull");
        printf("\n6: Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &x);
            insert(&q, x);
            break;

        case 2:
            x = delet(&q);
            if (x != -1)
                printf("The deleted element is %d", x);
            break;

        case 3:
            if (isempty(&q))
                printf("Queue is empty");
            else
                printf("Queue is not empty");
            break;

        case 4:
            display(&q);
            break;

        case 5:
            if (isfull(&q))
                printf("Queue is full");
            else
                printf("Queue is not full");
            break;
        }
    } while (choice != 6);

    return 0;
}
