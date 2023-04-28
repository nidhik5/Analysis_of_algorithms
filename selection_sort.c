# include <stdio.h>
int a[10],n,temp,j;

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

void selection_sort()
{
    for (int i=0;i<n;i++)
    {
        j=i;
        for (int k=i+1;k<n;k++)
        {
            if (a[k]<a[j])
            {
                j=k;
            }
        }
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
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
    selection_sort();
    display_array();
    return 0;
}
