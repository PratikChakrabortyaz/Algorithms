#include<stdio.h>

void bubblesort(int a[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {

            if(a[j]>a[j+1])
            {
                int swap=a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
            }
        }
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
    bubblesort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
