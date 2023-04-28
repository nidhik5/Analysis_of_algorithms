# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int a[10],b[10],n,i,j,k,low, high, mid;

void read_array()
{
    printf("enter size of array ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter %d element",(i+1));
        scanf("%d",&a[i]);
    }
}

void merge(int low, int mid, int high)
{
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if (a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if (i>mid)
    {
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for (k=low;k<=high;k++)
    {
        a[k]=b[k];
    }
}

void merge_sort(int low, int high)
{
    if (low<high)
    {
        int mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}

void display_array()
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);

    }
}
int main ()
{
    read_array();
    low=0,high=n-1;
    merge_sort(low,high);
    display_array();

    return 0;
}

