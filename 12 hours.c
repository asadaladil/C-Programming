#include <stdio.h>

int main()

{
    int a,b,i;
    printf("Enter your starting: ");
    scanf("%d",&a);
    printf("Enter your finishing: ");
    scanf("%d",&b);
    
    if(a>12||b>12)
    {
        printf("\nInvalid input for 12 hours format\n");
    }

    else if(a<b)
    {
        for(i=a;i<=b;i++)
        {
            printf("%dam or %dpm\n",i,i);
        }
    }
    else if(a>b)
    {
        for(i=a;i<=12;i++)
        {
            printf("%dam or %dpm\n",i,i);
        }
        for(i=1;i<=b;i++)
        {
            printf("%dam or %dpm\n",i,i);
        }
    }
    return 0;
}