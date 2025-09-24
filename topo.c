#include <stdio.h>
#include <stdlib.h>

int vis[50], path[50];
int stack[50], top = -1;
int cycle = 0, bcount = 0;

void dfs(int n, int g[n][n], int v) {
    vis[v] = 1;
    path[v] = 1;

    for (int i = 0; i < n; i++) {
        bcount++;
        if (g[v][i] == 1) {
            if (path[i] == 1) {
                cycle = 1;  // back edge → cycle
            }
            if (vis[i] == 0) {
                dfs(n, g, i);
            }
        }
    }

    path[v] = 0;
    stack[++top] = v;  // push after finishing children
}

void runTester() {
    int n, g[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
        vis[i] = 0;
        path[i] = 0;
    }

    cycle = 0;
    top = -1;
    bcount = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(n, g, i);
        }
    }

    printf("\nTopological Sort (using DFS):\n");
    if (cycle) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    printf("Number of edge checks (bcount): %d\n", bcount);
}

void runPlotter() {
    FILE *fp1, *fp2;
    fp1 = fopen("topo_best.txt", "w");
    fp2 = fopen("topo_worst.txt", "w");

    for (int n = 4; n <= 10; n++) {
        int g[n][n];

        // --- Worst case: complete DAG (upper triangular matrix) ---
        bcount = 0;
        cycle = 0;
        top = -1;
        for (int i = 0; i < n; i++) {
            vis[i] = path[i] = 0;
            for (int j = 0; j < n; j++) {
                g[i][j] = (i < j) ? 1 : 0;  // edges from i → j if i < j
            }
        }
        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs(n, g, i);
        fprintf(fp2, "%d\t%d\n", n, bcount);

        // --- Best case: simple chain ---
        bcount = 0;
        cycle = 0;
        top = -1;
        for (int i = 0; i < n; i++) {
            vis[i] = path[i] = 0;
            for (int j = 0; j < n; j++) g[i][j] = 0;
        }
        for (int i = 0; i < n - 1; i++) g[i][i + 1] = 1;

        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs(n, g, i);
        fprintf(fp1, "%d\t%d\n", n, bcount);
    }

    fclose(fp1);
    fclose(fp2);
    printf("Plotter output written to topo_best.txt and topo_worst.txt\n");
}

int main() {
    int choice;
    printf("1. Tester Mode\n2. Plotter Mode\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        runTester();
    } else if (choice == 2) {
        runPlotter();
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
