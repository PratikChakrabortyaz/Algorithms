#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree rooted with node i which is an index in arr[].
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a heap
void buildHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    buildHeap(arr, n);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to find and delete an element of a given value in the heap
void deleteElement(int arr[], int *n, int value) {
    int i;
    // Find the index of the element to be deleted
    for (i = 0; i < *n; i++) {
        if (arr[i] == value)
            break;
    }
    // If the element is not found
    if (i == *n) {
        printf("Element not found in the heap.\n");
        return;
    }
    // Replace the element with the last element in the heap
    arr[i] = arr[*n - 1];
    // Decrease the heap size
    (*n)--;
    // Heapify again to maintain heap property
    heapify(arr, *n, i);
}

// Function to find and delete the smallest element in the max heap
// Function to find and delete the smallest element in the max heap
void deleteSmallestElement(int arr[], int *n) {
    // The smallest element in a max heap will be either the root or one of its children
    int smallest = 0; // Initialize the index of the smallest element as the root

    // Find the index of the smallest element among the root and its children
    int left = 2 * smallest + 1;
    int right = 2 * smallest + 2;

    if (left < *n && arr[left] < arr[smallest])
        smallest = left;

    if (right < *n && arr[right] < arr[smallest])
        smallest = right;

    // If the smallest element is not the root, swap it with the root
    if (smallest != 0) {
        swap(&arr[0], &arr[smallest]);
        // Heapify from the new root to fix any violations
        heapify(arr, *n, smallest);
    }

    // Delete the smallest element from its new position
    deleteElement(arr, n, arr[0]);
}


int main() {
    int n, arr[MAX_SIZE];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Array size exceeds maximum size.\n");
        return 1;
    }
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 1) Create a heap using top-down heap construction algorithm (max heap)
    buildHeap(arr, n);

    // Print the heap
    printf("Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 2) Sort the list of integers using heap sort
    heapSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 3) Find and delete an element of a given value in the heap
    int value;
    printf("Enter the value to delete from the heap: ");
    scanf("%d", &value);
    deleteElement(arr, &n, value);
    printf("Heap after deleting %d: ", value);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 4) Find and delete the smallest element in the max heap
    deleteSmallestElement(arr, &n);
    printf("Heap after deleting smallest element: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

