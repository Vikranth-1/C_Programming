#include <stdio.h>
#define INF 999

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;

    vis[0] = 1;
    int edges = 0, min, u, v, total = 0;

    printf("Edges in MST:\n");
    while (edges < n - 1) {
        min = INF;
        for (int i = 0; i < n; i++)
            if (vis[i])
                for (int j = 0; j < n; j++)
                    if (!vis[j] && cost[i][j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
        printf("%d - %d : %d\n", u + 1, v + 1, min);
        vis[v] = 1;
        total += min;
        edges++;
    }

    printf("Minimum cost = %d\n", total);
    return 0;
}
