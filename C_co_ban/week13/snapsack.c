#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX(a, b) ((a > b) ? a : b)

int maxProfit;
int n, W;
int weight[100];
int profit[100];

int bound(int u, int n, int wt[], int val[], int W)
{
    int profit_bound = 0;
    int j = 0;
    int totweight = u;
    while ((j < n) && (totweight + wt[j] <= W))
    {
        totweight = totweight + wt[j];
        profit_bound = profit_bound + val[j];
        j++;
    }
    if (j < n)
        profit_bound = profit_bound + (W - totweight) * val[j] / wt[j];
    return profit_bound;
}

void knapsack(int n, int W, int wt[], int val[], int u, int v)
{
    if (u == n)
    {
        if (v > maxProfit)
            maxProfit = v;
        return;
    }
    if (wt[u] > W)
        knapsack(u + 1, W, wt, val, u + 1, v);
    else
    {
        knapsack(u + 1, W, wt, val, u + 1, v);
        knapsack(u + 1, W - wt[u], wt, val, u + 1, v + val[u]);
    }
}

int main(void)
{
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    printf("Enter the weight and profit of each item:\n");
    int i; 
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &weight[i], &profit[i]);
    }

    knapsack(0, W, weight, profit, 0, 0);

    printf("The maximum profit is: %d\n", maxProfit);

    return 0;
}

