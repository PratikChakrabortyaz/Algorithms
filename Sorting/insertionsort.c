#include<stdio.h>

void insertionsort(int arr[],int n)
{
    int j;int key;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void main()
{
    int n;
    printf("Enter no. of elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);
    printf("Sorted array using insertion sort:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
