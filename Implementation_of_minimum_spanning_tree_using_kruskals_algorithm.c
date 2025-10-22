#include <stdio.h>

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int u, int v) {
    parent[v] = u;
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    int u[e], v[e], w[e];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (w[j] > w[j + 1]) {
                int temp = w[j]; w[j] = w[j + 1]; w[j + 1] = temp;
                temp = u[j]; u[j] = u[j + 1]; u[j + 1] = temp;
                temp = v[j]; v[j] = v[j + 1]; v[j + 1] = temp;
            }

    int parent[n + 1];
    for (int i = 1; i <= n; i++) parent[i] = i;

    int count = 0, total = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(parent, u[i]);
        int b = find(parent, v[i]);
        if (a != b) {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            total += w[i];
            unionSet(parent, a, b);
            count++;
        }
    }

    printf("Minimum cost = %d\n", total);
    return 0;
}
