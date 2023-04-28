# include <stdio.h>
int g[10][10],edge[10][3],e,v,i,j,k,parent[10],rank[10],temp,totalcost=0;

void read_graph()
{
    printf("Enter number of vertices\n");
    scanf("%d",&v);

    for (int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("Enter weight between edges %d and %d ",(i+1),(j+1));
            scanf("%d",&g[i][j]);
            if(g[i][j]!=0 && i<j)
                e++;
        }
    }

}

void display_graph()
{
    for (int i=0;i<v;i++)
    {
        for (int j=0;j<v;j++)
        {
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }
}

void print_1D_array(char *str,int x[])
{
    printf("\n%s[] ",str);
    for (int i=0;i<v;i++)
    {
        printf("%d",x[i]);
    }
}

void make_set(int x)
{
    parent[x]=x;
    rank[x]=0;
}

void create_table()
{
    k=0;
    for (int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(g[i][j]!=0 && i<j)
            {edge[k][0]=i;
            edge[k][1]=j;
            edge[k][2]=g[i][j];
            k++;
            }
        }
    }
}

void display_table()
{
    for(int i=0;i<e;i++)
    {
        printf("%d ---> %d : %d\n",edge[i][0],edge[i][1],edge[i][2]);
    }
}

void bubble_sort()
{
    for (int i=0;i<e-1;i++)
    {
        for (int j=0;j<e-i-1;j++)
        {
            if(edge[j][2]>edge[j+1][2])
            {
                temp=edge[j][2];
                edge[j][2]=edge[j+1][2];
                edge[j+1][2]=temp;

                temp=edge[j][1];
                edge[j][1]=edge[j+1][1];
                edge[j+1][1]=temp;

                temp=edge[j][0];
                edge[j][0]=edge[j+1][0];
                edge[j+1][0]=temp;

            }
        }
    }
}

int find_set(int x)
{   if(x!=parent[x])
        parent[x]=find_set(parent[x]);
    return parent[x];
}

void link (int x, int y)
{
    if(rank[x]<rank[y])
        parent[y]=x;
    else
    {
        parent[x]=y;
        if(rank[x]==rank[y])
        rank[y]+=1;

    }
}

void unionop(int x,int y)
{
    link(find_set(x),find_set(y));
}

int main()
{
    read_graph();
    display_graph();
    for(int i=0;i<v;i++)
    {
        make_set(i);
    }
    create_table();
    printf("\nEdges before sorting\n");
    display_table();
    bubble_sort();
    printf("\nEdges after sorting\n");
    display_table();
    for(int i=0;i<e;i++)
    {
        if(find_set(edge[i][0])!=find_set(edge[i][1]))
        {
            unionop(edge[i][0],edge[i][1]);
            totalcost+=edge[i][2];
            printf("\n\nEdges (%d,%d) : %d",edge[i][0],edge[i][1],edge[i][2]);

        }
    }
    print_1D_array("\nParent array :",parent);
    print_1D_array("\nRank array :",rank);
    printf("\n\nTotal Cost : %d",totalcost);

    return 0;
}
