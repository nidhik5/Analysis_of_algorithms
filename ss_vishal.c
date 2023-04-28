#include <stdio.h>
int i,j,k,a[50],n,temp;
void readarray()
{
    printf("Enter size of an array");
    scanf("%d",&n);
    printf("Enter elements of an array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void displayarray()
{
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
void selectionsort()
{
    for(i=0;i<n;i++)
    {
        j=i;
        for(k=i+1;k<n;k++)
        {
            if(a[j]>a[k])
            {
                j=k;
            }
        }
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
int main()
{
    readarray();
    selectionsort();
    displayarray();
    return 0;
}
