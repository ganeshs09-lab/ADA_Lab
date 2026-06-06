#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};

int main()
{
    int n;
    float capacity, totalProfit = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(item[j].ratio < item[j + 1].ratio)
            {
                struct Item temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }

    printf("Selected items:\n");

    for(int i = 0; i < n; i++)
    {
        if(capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
            printf("Item %d -> 100%% selected\n", i + 1);
        }
        else
        {
            float fraction = capacity / item[i].weight;
            totalProfit += item[i].profit * fraction;
            printf("Item %d -> %.2f%% selected\n", i + 1, fraction * 100);
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
