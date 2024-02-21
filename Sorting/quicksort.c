#include <stdio.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int l,int r)
{

    int j=l-1;
    int pivot=arr[r];
    for(int i=l;i<r;i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[j+1],&arr[r]);
    return j+1;
}
void quicksort(int arr[],int l,int r)
{
    if(r>l)
    {
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array using quick sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
