#include <stdio.h>
int main()
{
    int r[6][6],i,j,x,y;

    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            scanf("%d",&r[i][j]);
            if(r[i][j]==1)
            {
                x=i;
                y=j;
            }
        }
    }
    int a=x-3,b=y-3;
    if(a<0)
    {
        a=a*(-1);
    }
    if(b<0)
    {
        b=b*(-1);
    }
    int d;
    d=a+b;

    printf("%d",d);
    return 0;
}