#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter the cost adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    struct Edge edges[100];
    int e = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(cost[i][j] != 0)
            {
                edges[e].u = i;
                edges[e].v = j;
                edges[e].w = cost[i][j];
                e++;
            }
        }
    }

    for(int i = 0; i < e - 1; i++)
    {
        for(int j = 0; j < e - i - 1; j++)
        {
            if(edges[j].w > edges[j + 1].w)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int minCost = 0, count = 0;

    printf("Edges in the Minimum Spanning Tree:\n");

    for(int i = 0; i < e && count < n - 1; i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b)
        {
            printf("%d -> %d : %d\n", edges[i].u, edges[i].v, edges[i].w);

            minCost += edges[i].w;
            unionSet(a, b);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", minCost);

    return 0;
}
