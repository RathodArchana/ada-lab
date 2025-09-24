#include <stdio.h>
#include <stdlib.h>

int indeg[50], source[50], f, r, cycle, bcount;

void indegree(int n, int G[n][n]) {
    for (int i = 0; i < n; i++) indeg[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bcount++;
            if (G[j][i] == 1) {
                indeg[i]++;
            }
        }
    }

    f = 0;
    r = -1;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            source[++r] = i;
    }
}

void sourcerem(int n, int G[n][n]) {
    cycle = 0;
    while (f <= r) {
        int src = source[f++];
        cycle++;
        for (int i = 0; i < n; i++) {
            bcount++;
            if (G[src][i]) {
                indeg[i]--;
                if (indeg[i] == 0)
                    source[++r] = i;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int G[n][n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    bcount = 0;
    indegree(n, G);
    sourcerem(n, G);

    printf("\nTopological Sort (Source Removal Method):\n");
    if (cycle != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        for (int i = 0; i < n; i++)
            printf("%d ", source[i]);
        printf("\n");
    }
    printf("Number of edge checks (bcount): %d\n", bcount);

    return 0;
}
