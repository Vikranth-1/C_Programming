#include <stdio.h>
#define INF 9999
#define V 5

int minDist(int d[], int vis[]) {
    int min = INF, idx = -1;
    for (int i = 0; i < V; i++)
        if (!vis[i] && d[i] <= min)
            min = d[i], idx = i;
    return idx;
}

void dijkstra(int g[V][V], int s) {
    int d[V], vis[V] = {0};
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;

    for (int c = 0; c < V - 1; c++) {
        int u = minDist(d, vis);
        vis[u] = 1;
        for (int v = 0; v < V; v++)
            if (!vis[v] && g[u][v] && d[u] + g[u][v] < d[v])
                d[v] = d[u] + g[u][v];
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, d[i]);
}

int main() {
    int g[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };
    dijkstra(g, 0);
    return 0;
}
