#include <stdio.h>
#include <stdlib.h>

int count = 0, bcount = 0, cycle = 0;
int connected_comp[100], cycles[100][100];

void BFS(int n, int G[n][n], int v, int *visited) {
    int queue[100], parent[100];
    int front = -1, rear = -1;

    count = 0; // reset for each BFS
    connected_comp[count++] = v;
    visited[v] = 1;
    queue[++rear] = v;
    parent[rear] = -1;

    while (rear > front) {
        int cur = queue[++front];
        int par = parent[front];

        for (int w = 0; w < n; w++) {
            bcount++;

            if (G[cur][w] == 1 && visited[w] == 0) {
                visited[w] = 1;
                connected_comp[count++] = w;
                queue[++rear] = w;
                parent[rear] = cur;
            }
            // Cycle detection (undirected graph)
            else if (G[cur][w] == 1 && visited[w] == 1 && w != par) {
                if (cur < w && cycles[cur][w] == 0) {
                    cycles[cur][w] = 1;
                    cycle++;
                }
            }
        }
    }
}

void BFSComponent(int n, int G[n][n], int *visited) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cycles[i][j] = 0;

    int n_connected = 0;
    for (int v = 0; v < n; v++) {
        if (visited[v] == 0) {
            n_connected++;
            BFS(n, G, v, visited);
            printf("Connected component %d: ", n_connected);
            for (int j = 0; j < count; j++)
                printf("%d ", connected_comp[j]);
            printf("\n");
        }
    }
    printf("Total connected components: %d\n", n_connected);
    printf("Number of cycles detected: %d\n\n", cycle);
}

void tester() {
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int G[n][n];
    int *visited = (int *)malloc(n * sizeof(int));

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    cycle = bcount = 0;
    BFSComponent(n, G, visited);

    free(visited);
}

void plotter() {
    FILE *fp1, *fp2;
    fp1 = fopen("bfs_best.txt", "w");
    fp2 = fopen("bfs_worst.txt", "w");

    for (int n = 4; n <= 10; n++) {
        int G[n][n];
        int *visited = (int *)malloc(n * sizeof(int));

        // ---------- Worst case: complete graph ----------
        bcount = cycle = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = (i == j) ? 0 : 1;
        BFSComponent(n, G, visited);
        fprintf(fp2, "%d\t%d\n", n, bcount);

        // ---------- Best case: line graph ----------
        bcount = cycle = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = 0;

        for (int i = 0; i < n - 1; i++) {
            G[i][i + 1] = G[i + 1][i] = 1;
        }

        BFSComponent(n, G, visited);
        fprintf(fp1, "%d\t%d\n", n, bcount);

        free(visited);
    }

    fclose(fp1);
    fclose(fp2);
    printf("BFS results written to bfs_best.txt and bfs_worst.txt\n");
}

int main() {
    int choice;
    printf("Choose mode:\n1. Tester\n2. Plotter\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        tester();
    else if (choice == 2)
        plotter();
    else
        printf("Invalid choice!\n");

    return 0;
}
