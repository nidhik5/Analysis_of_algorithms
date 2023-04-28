# include <stdio.h>
# include <stdlib.h>
int x[5],k,i,row,n,y[5][5];

int place(int k,int i)
{
    for (int row=1;row<=k;row++)
    {
        if(abs(x[row]-i)==abs(row-k))
            return 0;
    }
    return 1;
}
void write()
{
    for (int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if (x[i]==j)
                y[i][j]=1;
            else
                y[i][j]=0;
        }
    }
    for (int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if (y[i][j]==1)
                printf("Q\t");
            else
                printf("--");
        }
        printf("\n");
    }
}

void nqueen(int k, int i)
{
    for (int i=1;i<=n;i++)
    {
        if (place(k,i==1))
        {
           x[k]=i;
           if (k==n)
           {
               write();
               printf("\n");
           }
           else
           nqueen(k+1,n);

        }
    }
}
int main()
{
    printf("enter number of queens");
    scanf("%d",&n);
    nqueen(1,n);
    return 0;
}
