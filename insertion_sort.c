# include <stdio.h>
int a[10],n,temp,i,j,key;

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

void insertion_sort()
{
    for (j=0;j<n;j++)
    {
        key=a[j];
        i=j-1;
        while (i>=0 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
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
    insertion_sort();
    display_array();

    return 0;
}
