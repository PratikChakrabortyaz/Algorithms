#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10 // Maximum number of agents or tasks

int costs[MAX][MAX]; // Cost matrix
int assignments[MAX]; // Array to store assignments
int best_assignment[MAX]; // Array to store best assignments
int n; // Number of agents or tasks
int min_cost = INT_MAX; // Minimum total cost

// Function to calculate the total cost of assignments
void calculate_cost(int assignments[]) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += costs[i][assignments[i]];
    }
    if (total_cost < min_cost) {
        min_cost = total_cost;
        for (int i = 0; i < n; i++) {
            best_assignment[i] = assignments[i];
        }
    }
}

// Function to recursively generate all possible assignments
void assign_recursive(int index, bool used[]) {
    if (index == n) {
        calculate_cost(assignments);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            assignments[index] = i;
            assign_recursive(index + 1, used);
            used[i] = false;
        }
    }
}

int main() {
    printf("Enter the number of agents or tasks: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &costs[i][j]);
        }
    }

    bool used[MAX] = {false};
    assign_recursive(0, used);

    printf("Minimum total cost: %d\n", min_cost);
    printf("Assignments:\n");
    for (int i = 0; i < n; i++) {
        printf("Person %d -> Job %d\n", i + 1, best_assignment[i] + 1);
    }

    return 0;
}
