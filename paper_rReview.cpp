#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_PAPERS 100
#define MAX_REVIEWERS 100

std::vector<std::vector<int>> papers(MAX_PAPERS, std::vector<int>(MAX_REVIEWERS));
std::vector<int> reviewers(MAX_REVIEWERS);
std::vector<int> load(MAX_REVIEWERS);

int main() {
    int N, M, b;
    std::cin >> N >> M >> b;

    // Read the list of reviewers for each paper
    for (int i = 0; i < N; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> papers[i][j];
        }
    }

    // Sort the list of reviewers for each paper in ascending order
    for (int i = 0; i < N; i++) {
        std::sort(papers[i].begin(), papers[i].end());
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
        std::cout << "-1\n";
    } else {
        std::cout << max_load << "\n";
    }

    return 0;
}