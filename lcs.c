# include <stdio.h>
int m,n,i,j,c[10][10];
char b[10][10],x[10],y[10];

void read_array()
{
    printf("Enter size of X string ");
    scanf("%d",&m);
    printf("Enter elements of string x\n");
    for (int i=0;i<m;i++)
    {
        scanf("%s",&x[i]);
    }

    printf("Enter size of Y string ");
    scanf("%d",&n);
    printf("Enter elements of string y\n");
    for (int i=0;i<n;i++)
    {
        scanf("%s",&y[i]);
    }
}

void lcs ()
{
    for (int i=0;i<n;i++)
    {
        c[0][i]=0;
    }

    for (int i=0;i<m;i++)
    {
        c[i][0]=0;
    }

    for (int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
               c[i][j]=c[i-1][j-1]+1;
               b[i][j]='/' ;
            }
            else
            {
                if (c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='|';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='-';
            }
            }
        }
    }
}

void print()
{
    for (int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
     for (int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c\t",b[i][j]);
        }
        printf("\n");
    }
}

int main ()
{
    read_array();
    lcs();
    print();
    return 0;
}
