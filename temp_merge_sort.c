# include <stdio.h>
# define d 10
#include<string.h>

int m,n,t=0,p=0,s,h=1,i,q=13;
char txt[30], pat[30];
int main ()
{
    printf("Enter text string:");
	scanf("%s",txt);
	printf("Enter Pattern string:");
	scanf("%s",pat);
	m=strlen(txt);
	n=strlen(pat);

	printf("%s",txt);

    for( i=0;i<n-1;i++)
    {
        h=(h*d)%q;
    }
    for ( i=0;i<n;i++)
    {
        t=(d*t+txt[i])%q;
        p=(d*p+pat[i])%q;
    }

    for(int s=0;s<=m-n;s++)
    {
        if(t==p)
        {
            for(i=0;i<n;i++)
            {
                if(txt[s+i]!=pat[i])
                    break;
            }
            if(i==n) {
    printf("Pattern found at index %d\n", s);
}
        }
        if(s<m-n)
        {
            t=(d*(t-txt[s]*h)+txt[s+n])%q;
              if (t<0)
            t+=q;

        }

    }
}

