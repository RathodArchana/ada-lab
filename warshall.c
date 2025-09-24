#include <stdio.h>

#define MAX_NODES 100

int count;
int paths[MAX_NODES][MAX_NODES];

void warshall(int adjMat[MAX_NODES][MAX_NODES], int n) {
    count = 0;

    // Initialize paths matrix with adjMat
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            paths[i][j] = adjMat[i][j];
    
    // Compute transitive closure
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (paths[i][k])
                for (int j = 0; j < n; j++) {
                    count++;
                    paths[i][j] = paths[i][j] || (paths[i][k] && paths[k][j]);
                }
}

void plotter() {
    FILE *fb = fopen("best-warshall1.txt", "w");
    FILE *fw = fopen("worst-warshall1.txt", "w");

    if (!fb || !fw) {
        printf("Error opening files for writing.\n");
        if (fb) fclose(fb);
        if (fw) fclose(fw);
        return;
    }

    for (int n = 1; n <= 10; n++) {
        int adjMat[MAX_NODES][MAX_NODES];

        // Best case: Complete graph
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = (i == j) ? 0 : 1;

        warshall(adjMat, n);
        fprintf(fw, "%d\t%d\n", n, count);

        // Worst case: Linear chain with a cycle
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adjMat[i][j] = 0;

        for (int i = 0; i < n - 1; i++)
            adjMat[i][i + 1] = 1;
        adjMat[n - 1][0] = 1;

        warshall(adjMat, n);
        fprintf(fb, "%d\t%d\n", n, count);
    }

    fclose(fb);
    fclose(fw);
}


void tester() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int adjMat[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);
    
    warshall(adjMat, n);
    
    printf("Transitive closure matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", paths[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Enter:\n1. Tester\n2. Plotter\nYour choice: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) tester();
    else if (choice == 2) plotter();
    else printf("Invalid choice!\n");
    
    return 0;
}