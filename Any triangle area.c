#include <stdio.h>
#include <math.h>

int main()


{
    float s,a,b,c;
    printf("Input 3 arms value of triangle:\n");

    scanf("%f%f%f",&a,&b,&c);

    float area;
    if(a+b>c && b+c>a && c+a>b)
    {
    
    s=0.5*(a+b+c);

    area= pow(s*(s-a)*(s-b)*(s-c),.5);
    printf("Triangle area is %f",area);
    }

    else
    {
        printf("invalid input");
    }
    return 0;
}