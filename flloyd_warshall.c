# include <stdio.h>
# define INF 999;
int g[10][10],p[10][10],d[10][10],i,j,k,v;

void read_graph()
{
    printf("Enter number of vertices of the graph\n");
    scanf("%d",&v);
    printf("Enter weights of graph\n");
    for (int i=0;i<v;i++)
    {
        for (int j=0;j<v;j++)
        {
            printf("Enter weights between edges %d and %d ",(i+1),(j+1));
            scanf("%d",&g[i][j]);
        }
    }
}

void display_graph(int a[10][10])
{
    for(int i=0;i<v;i++)
    {
        for (int j=0;j<v;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void initialise ()
{
    for(int i=0;i<v;i++)
    {
        for (int j=0; j<v; j++)
        {
            if(i==j)
            {
                d[i][j]=0;
                p[i][j]=-1;
            }
            else if (g[i][j]==0)
            {
                d[i][j]=INF;
                p[i][j]=-1;
            }
            else
            {
                d[i][j]=g[i][j];
                p[i][j]=i;
            }
        }
    }
}

void flloyd ()
{
    for (int k=0;k<v;k++)
    {
        for (int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(d[i][j]<=d[i][k]+d[k][j])
                    continue;
                else
                    {
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                    }
            }
        }
    }
}

void print (int s, int l)
{
    if (s==l)
        printf("%d",s);
    else if (p[s][l]==-1)
        printf("No path exists");
    else
    {
        print(s,p[s][l]);
        printf(" ---> ");
        printf("%d",l);
    }
}

int main ()
{
    read_graph();
    display_graph(g);
    initialise();
    printf("\n Distance graph \n");
    display_graph(d);
    printf("\n Predecessor graph \n");
    display_graph(p);
    flloyd();
    printf("\n Distance graph after flloyd warshall \n");
    display_graph(d);
    printf("\n Predecessor graph after flloyd warshall \n");
    display_graph(p);
    printf("\n printing paths \n");
    for(int i=0;i<v;i++)
    {
        for (int j=0;j<v;j++)
        {
            if(i!=j)
            {
            print(i,j);
            printf("\n");
            }

        }
    }
    return 0;
}
