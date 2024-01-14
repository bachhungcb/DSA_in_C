#include <stdio.h>
#include <stdlib.h>

#define MAX_PAPERS 100
#define MAX_REVIEWERS 100

int papers[MAX_PAPERS][MAX_REVIEWERS];
int reviewers[MAX_REVIEWERS];
int load[MAX_REVIEWERS];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, M, b;
    scanf("%d %d %d", &N, &M, &b);

    // Read the list of reviewers for each paper
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &papers[i][j]);
        }
    }

    // Sort the list of reviewers for each paper in ascending order
    for (int i = 0; i < N; i++) {
        qsort(papers[i], sizeof(papers[i]) / sizeof(papers[i][0]), sizeof(papers[i][0]), compare);
    }

    // Initialize the load of each reviewer to 0
    for (int i = 0; i < M; i++) {
        load[i] = 0;
    }

    // Assign reviewers to papers
    for (int i = 0; i < N; i++) {
        int assigned = 0;
        for (int j = 0; j < b; j++) {
            int min_load = load[0];
            int min_load_index = 0;
            for (int k = 1; k < M; k++) {
                if (load[k] < min_load) {
                    min_load = load[k];
                    min_load_index = k;
                }
            }
            int reviewer = papers[i][assigned];
            reviewers[reviewer]++;
            load[min_load_index]++;
            assigned++;
        }
    }

    // Find the maximum load among all reviewers
    int max_load = load[0];
    for (int i = 1; i < M; i++) {
        if (load[i] > max_load) {
            max_load = load[i];
        }
    }

    // Check if a solution is found
    if (max_load > b) {
        printf("-1\n");
    } else {
        printf("%d\n", max_load);
    }

    return 0;
}
