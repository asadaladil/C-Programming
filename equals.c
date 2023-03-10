#include <stdio.h>

int main()

{
    int a,b,c;

    printf("Input your 3 values: \n");
    scanf("%d%d%d",&a,&b,&c);

    if(b*b==a*c)
    {
        printf("Multiplication series");
    }
    else
    {
        printf("it is not that series");
    }
return 0;

}