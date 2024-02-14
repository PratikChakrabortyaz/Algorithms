#include<stdio.h>

void selectionsort(int a[],int size)
{
    int min;
    for(int i=0;i<size-1;i++)
    {
        min=i;
        for(int j=i+1;j<size;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        int swap=a[min];
        a[min]=a[i];
        a[i]=swap;
    }
}

void main()
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
