#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 50 // Maximum size of the hash table

// Structure for a node in the linked list
struct Node {
    int key;
    struct Node* next;
};

// Structure for a hash table entry
struct Entry {
    struct Node* head; // Head of the linked list
};

// Initialize hash table
void initHashTable(struct Entry hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i].head = NULL;
    }
}

// Hash function (simple modulo hash)
int hash(int key, int size) {
    return key % size;
}

// Insert key into the hash table
void insert(struct Entry hashTable[], int key, int size) {
    int index = hash(key, size);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    // Insert at the beginning of the linked list
    newNode->next = hashTable[index].head;
    hashTable[index].head = newNode;
}

// Search for a key in the hash table
// Returns the number of key comparisons made during the search
int search(struct Entry hashTable[], int key, int size) {
    int index = hash(key, size);
    int comparisons = 1;
    struct Node* current = hashTable[index].head;
    while (current != NULL) {
        if (current->key == key) {
            return comparisons; // Key found
        }
        current = current->next;
        comparisons++;
    }
    return comparisons; // Key not found
}

int main() {
    int m_values[] = {5, 20, 50}; // Hash table sizes
    int n_values[] = {10, 15, 20}; // Number of keys
    int num_m_values = sizeof(m_values) / sizeof(m_values[0]);
    int num_n_values = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < num_m_values; i++) {
        int m = m_values[i];
        for (int j = 0; j < num_n_values; j++) {
            int n = n_values[j];
            int load_factor = n * 100 / m;
            printf("Hash Table Size: %d, Number of Keys: %d, Load Factor: %d%%\n", m, n, load_factor);

            struct Entry hashTable[TABLE_SIZE];
            initHashTable(hashTable, TABLE_SIZE);

            // Insert keys into hash table
            for (int k = 0; k < n; k++) {
                int key = rand() % 100; // Random keys
                insert(hashTable, key, m);
            }

            // Successful search
            int total_success_comparisons = 0;
            for (int k = 0; k < n; k++) {
                int key = rand() % 100; // Random keys
                total_success_comparisons += search(hashTable, key, m);
            }
            printf("Average number of comparisons in successful search: %.2f\n", (float)total_success_comparisons / n);

            // Unsuccessful search
            int total_failure_comparisons = 0;
            for (int k = 0; k < n; k++) {
                int key = rand() % 200 + 100; // Random keys not in the hash table
                total_failure_comparisons += search(hashTable, key, m);
            }
            printf("Average number of comparisons in unsuccessful search: %.2f\n\n", (float)total_failure_comparisons / n);
        }
    }

    return 0;
}

