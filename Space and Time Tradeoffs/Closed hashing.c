#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 50 // Maximum size of the hash table
#define EMPTY -1 // Empty cell marker

// Structure for a hash table entry
typedef struct {
    int key;
    bool occupied;
} Entry;

// Initialize hash table
void initHashTable(Entry hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i].key = EMPTY;
        hashTable[i].occupied = false;
    }
}

// Hash function (simple modulo hash)
int hash(int key, int size) {
    return key % size;
}

// Insert key into the hash table
// Returns 1 if successful, 0 if hash table is full
int insert(Entry hashTable[], int key, int size) {
    int index = hash(key, size);
    int originalIndex = index;
    do {
        if (!hashTable[index].occupied) {
            hashTable[index].key = key;
            hashTable[index].occupied = true;
            return 1; // Successful insertion
        }
        index = (index + 1) % size; // Linear probing
    } while (index != originalIndex); // Stop if we come back to the original index
    return 0; // Hash table is full
}

// Search for a key in the hash table
// Returns the number of key comparisons made during the search
int search(Entry hashTable[], int key, int size) {
    int index = hash(key, size);
    int comparisons = 1;
    int originalIndex = index;
    do {
        if (hashTable[index].occupied && hashTable[index].key == key) {
            return comparisons; // Key found
        }
        index = (index + 1) % size; // Linear probing
        comparisons++;
    } while (index != originalIndex); // Stop if we come back to the original index
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

            Entry hashTable[TABLE_SIZE];
            initHashTable(hashTable, TABLE_SIZE);

            // Insert keys into hash table
            int keys_inserted = 0;
            for (int k = 0; k < n; k++) {
                int key = rand() % 100; // Random keys
                if (insert(hashTable, key, m))
                    keys_inserted++;
                else
                    break; // Stop inserting if hash table is full
            }

            // Successful search
            int total_success_comparisons = 0;
            for (int k = 0; k < keys_inserted; k++) {
                int key = rand() % 100; // Random keys
                total_success_comparisons += search(hashTable, key, m);
            }
            printf("Average number of comparisons in successful search: %.2f\n", (float)total_success_comparisons / keys_inserted);

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
