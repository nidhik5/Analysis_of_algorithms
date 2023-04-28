# include <stdio.h>
# include <stdlib.h>
int x[10],n,row,k,l,c=0,y[10][10]={0};
int place(int k,int i)
{
for (row=1; row<=k-1; row++)
	{
		if ( (y[row][x[row]]==i) || (abs(y[row][x[row]]-i)==abs(row-k)))
		{
		return 0;
		}
	}
return 1;
}
void write()
{
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=n;j++)
    {
        if (y[i][j]!=0)
            printf("%d",y[i][j]);
        else
            printf("--");
    }
    printf("\n");
}
}
void nqueen(int k,int n)
{
	for (int i=1;i<=n;i++)
	{
		if (place(k,i)==1)
		{

			y[k][x[k]]=i;
			//printf("%d\t",y[k][x[k]]);
			if(k==n)
			{
				c++;
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
    printf("Enter number of queens");
	scanf("%d",&n);
    //for (int i=1;i<=n;i++)
    {
        //for (int j=1;j<=n;j++)
        {
            //y[i][j]=0;
        }
    }
	nqueen(1,n);
	printf("%d",c);
	return 0;
}
