#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void accept(int adj[10][10], int n){
    int i,j;
    printf("enter adjacency matrix\n");
    for (i=0;i<n;i++){
        printf("connection bt %d and %d (1/0) : ",i,j);
        scanf("%d",&adj[i][j]);
        if(i==j && adj[i][j]==i){
            printf("\nself loop isnt allowed");
        }
    }
}

void display(int adj[10][10], int n){
    printf("adjacency matrix is: \n");
    for (int i =0;i<n;i++){
        for (int j=0; j<n; j++){
            printf ("%d",adj[i][j]);
        }
        printf("\n");
    }
}

int checksymm(int adj[10][10], int n){
    int flag=1;
    for(int i =0;i<n;i++){
        for (int j=0;j<n;j++){
            if (adj[i][j]!=adj[j][i]){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

void indegree(int adj[10][10], int n){
    int degree[10] = {0},i,j;
    for (int i =0; i<n;i++){
        for (int j=0;j<n;j++){
            degree[i] += adj[j][i];
        }
    }
    printf ("\nindegree\n");
    for (int i=0;i<n;i++){
        printf("%d\n",degree[i]);
    }
}

int main()
{
    int adj[10][101];
    int n, flag, ch;
    do
    {
        printf("\n\n1. read array \n2. print arrray \n3. check matrix is symmetrical or not \n4. calculate indegree \n5. exit\n");
        printf("enter your choice\n");
        scanf("%d\n", &ch);
        switch (ch)
        {
        case 1:
            printf("enter no of vertices");
            scanf("%d", &n);
            accept(adj, n);
            break;
        case 2:
            display(adj, n);
            break;
        case 3:
            flag = checksymm(adj, n);
            if (flag == 1)
            {
                printf("matrix is symmetrical");
            }
            else
            {
                printf("matrix is not symmetrical");
            }
            break;
        case 4:
            indegree(adj,n);
            break;
        }
    } while (ch != 5);
    return 0;
}