#include<stdio.h>
#include <string.h>
int main()
{
    char S[1000];
    scanf("%s",&S);
    int len =strlen(S),v=0;

    for(int i=0;i<len;i++)
    {
        if(S[i]=='0'||S[i]=='1')
        {
            v++;
        }
        else
        {
            printf("NO");
            break;
        }
    }
    if(v==len)
    {
        printf("YES");
    }
    return 0;


}