#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX 10 // Maximum number of cities

// Structure to represent a city
typedef struct {
    char name[20];
} City;

int n;                    // Number of cities
int min_cost = INT_MAX;   // Initialize the minimum cost to maximum integer value
int min_path[MAX];        // Array to store the minimum path
City cities[MAX];         // Array to store the city names
int graph[MAX][MAX];      // Adjacency matrix representing the graph
int visited[MAX];         // Array to keep track of visited cities

void tsp(int current_city, int visited_count, int cost, int path[]) {
    if (visited_count == n) { // If all cities are visited
        if (graph[current_city][0] != 0) { // If there is a path back to the starting city
            int total_cost = cost + graph[current_city][0]; // Calculate total cost
            if (total_cost < min_cost) { // Update minimum cost if needed
                min_cost = total_cost;
                memcpy(min_path, path, sizeof(int) * n);
            }
        }
        return;
    }

    // Explore all unvisited cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current_city][i] != 0) {
            visited[i] = 1; // Mark city as visited
            path[visited_count] = i;
            tsp(i, visited_count + 1, cost + graph[current_city][i], path); // Recur for next city
            visited[i] = 0; // Backtrack: Mark city as unvisited
        }
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the names of cities:\n");
    for (int i = 0; i < n; i++) {
        printf("City %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    printf("Enter the distances between cities (use 0 for same city or no path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Distance from %s to %s: ", cities[i].name, cities[j].name);
            scanf("%d", &graph[i][j]);
        }
    }

    visited[0] = 1; // Mark the starting city as visited
    int path[MAX];  // Array to store the current path
    path[0] = 0;    // Starting city is the first element of the path
    tsp(0, 1, 0, path);   // Start with the first city

    printf("Minimum cost for TSP: %d\n", min_cost);
    printf("Minimum path: %s", cities[0].name); // Starting city

    for (int i = 1; i < n; i++) {
        printf(" -> %s", cities[min_path[i]].name); // Print the cities in the minimum path
    }
    printf(" -> %s\n", cities[0].name); // Return to starting city

    return 0;
}
