# include <stdio.h>
int a[10],b[10],n,i,j,k,p,q,r,x,temp;

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

int partition(int p, int r)
{
    x=a[r];
    i=p-1;
    for (int j=p;j<r;j++)
    {
        if (a[j]<x)
        {
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

void quick_sort(int p, int r)
{
    if (p<r)
    {
        q=partition(p,r);
        quick_sort(p,q-1);
        quick_sort(q+1,r);
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
    p=0,r=n-1;
    quick_sort(p,r);
    display_array();

    return 0;
}

