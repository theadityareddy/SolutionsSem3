// A) Write a C program that accepts the graph as an adjacency matrix and checks if the graph is undirected. The matrix for undirected graph is symmetric. Also calculate in degree of all vertices
// -	Read a graph as adjacency Matrix
// -	Check the matrix is symmetric or not
// -	Calculate indegree of all vertices
#include <stdio.h>
#include <stdlib.h>
void accept(int size, int mat[100][100])
{
    printf("\nInput Matrix Element:");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("\nConnection Between %d and %d  ", i, j);
            scanf("%d", &mat[i][j]);
            if (i == j && mat[i][j] == 1)
            {
                printf("\nLoop Vertex in Not Allowed");
                exit(0);
            }
        }
    }
}

void display(int size, int mat[100][100])
{
    printf("\nPrinting Matrix:");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int symmetric(int size, int mat[100][100])
{
    int flag = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

void indegree(int size, int mat[100][100])
{
    int degree[100] = {0};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            degree[i] = degree[i] + mat[j][i];
        }
    }

    printf("\nPriting Indegree");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", degree[i]);
        printf("\n");
    }
}

void main()
{
    int size, mat[100][100];
    int choice;
    printf("\nInput Matrix size==>");
    scanf("%d", &size);
    do
    {
        printf("\n1.Read Graph\n2.Check Symmetrix\n3.Indegree\n4.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            accept(size, mat);
            break;
        case 2:
            printf("\nIndegree of Graph==>%d", symmetric(size, mat));
            break;
        case 3:
            indegree(size, mat);
            break;
        case 4:
            display(size, mat);
        case 5:
            exit(1);
        default:
            printf("\nInput Appropriate Choice");
            break;
        }
    } while (choice != 5);
}
