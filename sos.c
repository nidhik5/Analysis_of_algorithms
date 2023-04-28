# include <stdio.h>
int w[10],n,s=0,r,k,x[10],m;
void read_array()
{
    printf("Enter sum you want ");
    scanf("%d",&m);
    printf("enter size of array ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter %d element",(i+1));
        scanf("%d",&w[i]);
        r+=w[i];
    }
}

void sos (int s,int k,int r)
{
    x[k]=1;
    if(s+w[k]==m)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d\t",x[i]);
        }
        printf("\n");
    }
    else if (s+w[k]+w[k+1]<=m)
    {
        sos(s+w[k],k+1,r-w[k]);
    }
    if ((s+r-w[k]>=m) && (s+w[k+1]<=m))
             {
                 x[k]=0;
                sos(s,k+1,r-w[k]);
             }
}

int main ()
{
    read_array();
    sos(0,0,r);
    return 0;
}
