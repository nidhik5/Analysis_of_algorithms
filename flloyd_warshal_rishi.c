#include <stdio.h>
int v,e;
int G[10][10];
int d[10][10],p[10][10];
void readgraph()
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
}

void printgraph(int temp[10][10])
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("%d\t",temp[i][j]);
		}
		printf("\n");
	}
}

void initialize()
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i==j)
			{
				d[i][j]=0;
				p[i][j]=-1;
			}
			else if(G[i][j]==0)
			{
				d[i][j]=9999;
				p[i][j]=-1;
			}
			else
			{
				d[i][j]=G[i][j];
				p[i][j]=i;
			}
		}
	}
}

void Floydwarshall()
{
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(d[i][j]> (d[i][k]+d[k][j]))
				{
					d[i][j]=(d[i][k]+d[k][j]);
					p[i][j]=p[k][j];
				}
				else
					continue;
			}
		}
	}
}

void printpath(int s,int v)
{
	if(s==v)
		printf("%d\n",s);
	else if(p[s][v]==-1)
		printf("No path exist\n");
	else
	{
		printpath(s,p[s][v]);
		printf("-->");
		printf("%d",v);
	}
}

int main()
{
	printf("Enter number of vertices:");
	scanf("%d",&v);
	printf("Enter adjacency matrix\n");
	readgraph();
	printf("The adjacency matrix is\n");
	printgraph(G);
	initialize();
	printf("After initializing\nD Matrix\n");
	printgraph(d);
	printf("P Matrix\n");
	printgraph(p);
	Floydwarshall();
	printf("After Algorithm\nD Matrix\n");
	printgraph(d);
	printf("P Matrix\n");
	printgraph(p);
	printf("Path between pair of vertices\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i!=j)
			{
				printpath(i,j);
				printf("\n");
			}
		}
	}
	return 0;
}
