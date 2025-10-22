#include <stdio.h>
#define INF 9999
#define V 4

void floyd(int g[V][V]) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            d[i][j] = g[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (d[i][j] == INF) printf("INF ");
            else printf("%3d ", d[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int g[V][V] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floyd(g);
    return 0;
}
