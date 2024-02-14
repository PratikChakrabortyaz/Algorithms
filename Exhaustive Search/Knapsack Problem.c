#include <stdio.h>

#define MAX_ITEMS 10 // Maximum number of items
#define MAX_WEIGHT 10 // Maximum weight capacity of knapsack

// Structure to represent an item
typedef struct {
    int weight;
    int value;
} Item;

Item items[MAX_ITEMS]; // Array to store the items
int knapsack[MAX_ITEMS]; // Array to store the selected items
int n; // Number of items
int max_value = 0; // Maximum value obtained

// Function to calculate the total value and weight of selected items
void calculate(int selected[]) {
    int total_value = 0;
    int total_weight = 0;
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            total_value += items[i].value;
            total_weight += items[i].weight;
        }
    }
    if (total_weight <= MAX_WEIGHT && total_value > max_value) {
        max_value = total_value;
        for (int i = 0; i < n; i++) {
            knapsack[i] = selected[i];
        }
    }
}

// Function to recursively generate all possible combinations of items
void knapsack_recursive(int selected[], int index) {
    if (index == n) {
        calculate(selected);
        return;
    }
    selected[index] = 0; // Exclude current item
    knapsack_recursive(selected, index + 1);
    selected[index] = 1; // Include current item
    knapsack_recursive(selected, index + 1);
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int selected[MAX_ITEMS] = {0}; // Array to store the selected items (0: not selected, 1: selected)
    knapsack_recursive(selected, 0);

    printf("Maximum value: %d\n", max_value);
    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (knapsack[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}
