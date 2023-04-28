# include <stdio.h>
int a[10][4],m,n,rem_capacity,temp,k,l,i,j,idx = 0;
float x[10];

void read_knapsack()
{
 printf("Enter knapsack capacity ");
    scanf("%d",&m);
    printf("Enter number of items ");
    scanf("%d",&n);

    printf("Enter knapsack element weights\n");
    for (int i=0;i<n;i++)
    {
        printf("Enter weight of %d th object\n",(i+1));
        scanf("%d",&a[i][1]);
        a[i][0]=i+1;
    }

    printf("Enter knapsack elements profits\n");
    for (int i=0;i<n;i++)
    {
        printf("Enter profit of %d th object\n",(i+1));
        scanf("%d",&a[i][2]);
    }
    printf("Enter knapsack elements profits\n");


     for (int i=0;i<n;i++)
    {
        a[i][3]=(a[i][2]/a[i][1]);
    }
}

void sort()
{
    for (int k=0;k<n-1;k++)
    {
        for(int l=0;l<n-k-1;l++)
        {
            if(a[l][3]<a[l+1][3])
            {
                temp=a[l][3];
                a[l][3]=a[l+1][3];
                a[l+1][3]=temp;

                temp=a[l][2];
                a[l][2]=a[l+1][2];
                a[l+1][2]=temp;

                temp=a[l][1];
                a[l][1]=a[l+1][1];
                a[l+1][1]=temp;

                temp=a[l][0];
                a[l][0]=a[l+1][0];
                a[l+1][0]=temp;
            }
        }
    }
}

void knapsack()
{ // Declare a new variable for loop index
    rem_capacity=m;
    for(int i=0;i<n;i++)
    {
        x[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if (rem_capacity<a[i][1]) // Change a[i][1] to a[i][0]
        {idx = i;
            break;}

        rem_capacity-=a[i][1]; // Change a[i][1] to a[i][0]
        x[i]=1;
         // Store the current loop index in a separate variable
    }
    if(idx<=n) // Change i to idx
    {
        x[idx]=(float)rem_capacity/a[idx][1]; // Change i to idx
    }
}

void display_knapsack()
{
    printf("Object\t weight\t profit\t ratio\n");
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void display_array()
{
    for (int i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
}
int main ()
{
    read_knapsack();
    display_knapsack();
    sort();
    display_knapsack();
    knapsack();
    printf("\n");
    display_array();
    return 0;
}
