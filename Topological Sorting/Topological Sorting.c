#include <stdio.h>

#define MAX 100

int main()
{
    int n, adj[MAX][MAX], indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], count = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    while(front < rear)
    {
        int u = queue[front++];
        topo[count++] = u;

        for(int v = 0; v < n; v++)
        {
            if(adj[u][v] == 1)
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    if(count != n)
    {
        printf("Topological sorting is not possible.\n");
    }
    else
    {
        printf("Topological ordering is: ");
        for(int i = 0; i < n; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }

    return 0;
}
