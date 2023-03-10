#include<stdio.h>
int x;
void Cell(int A[4][4])
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(A[i][j]==1)
            {
                printf("X");
            }
            else if(A[i][j]==2)
            {
                printf("O");
            }
            if(j<3)
            {
                printf("\t|\t");
            }
        }
        printf("\n");
        if(i<3)
        {
            printf("___________________________________");
        }
        printf("\n");
    }
}
int Match_Draw_Check(int A[4][4])
{
    int u=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(A[i][j]!=0)
            {
                u++;
            }
        }
    }
    if(u==9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Cell_Check(int A[4][4])
{
    int cnt=0,tnc=0,t;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(A[i][j]==1)
            {
                cnt++;
                t=1;
            }
            else if(A[i][j]==2)
            {
                tnc++;
                t=2;
            }
        }
        if(cnt==3&&tnc==0||tnc==3&&cnt==0)
        {
            break;
        }
        else
        {
            cnt=0;tnc=0;
        }
    }
    if(cnt==3&&t==1)
    {
        x=1;
        return 1;
    }
    else if(tnc==3&&t==2)
    {
        x=1;
        return 2;
    }
    cnt=0;
    t=0;
    tnc=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(A[j][i]==1)
            {
                cnt++;
                t=1;
            }
            else if(A[j][i]==2)
            {
                tnc++;
                t=2;
            }
        }
        if(cnt==3&&tnc==0||tnc==3&&cnt==0)
        {
            break; 
        }
        else
        {
            cnt=0;tnc=0;
        }
    }
    if(cnt==3&&t==1)
    {
        x=2;
        return 1;
    }
    else if(tnc==3&&t==2)
    {
        x=2;
        return 2;
    }
    cnt=0;
    t=0;
    tnc=0;
    for(int i=1;i<=3;i++)
    {
        if(A[i][i]==1)
        {
            cnt++;
            t=1;
        }
        else if(A[i][i]==2)
        {
            tnc++;
            t=2;
        }
    }
    if(cnt==3&&t==1)
    {
        x=3;
        return 1;
    }
    else if(tnc==3&&t==2)
    {
        x=3;
        return 2;
    }
    if(A[1][3]==A[2][2] && A[2][2]==A[3][1] && A[1][3]==1)
    {
        x=4;
        return 1;
    }
    else if(A[1][3]==A[2][2] && A[2][2]==A[3][1] && A[1][3]==2)
    {
        x=4;
        return 2;
    }
    return 0;
}
int main()
{
    printf("Welcome to TIC TAC TUC Game\n\n");
    int R[50],S[50];
    printf("Name of the player 1 is: ");
    scanf("%s",R);
    printf("\n");
    printf("Name of the player 2 is: ");
    scanf("%s",S);
    printf("\n");
    int A[4][4];
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            A[i][j]=0;
        }
    }
    Cell(A);
    int p1,p2;
    p1=1;
    p2=0;
    while(1)
    {
        if(p1==1)
        {
            printf("%s (X) please enter your row & column: ",R);
            int r,c;
            scanf("%d%d",&r,&c);
            if(r>3 || c>3 || A[r][c]!=0)
            {
                printf("row %d and column %d is not available, %s\n, %s",r,c,R);
                continue;
            }
            A[r][c]=1;
            p1=0;
            p2=1;
        }
        else
        {
            printf("%s (O) please enter your row & column: ",S);
            int r,c;
            scanf("%d%d",&r,&c);
            if(r>3 || c>3 || A[r][c]!=0)
            {
                printf("row %d and column %d is not available, %s\n",r,c,S);
                continue;
            }
            A[r][c]=2;
            p1=1;
            p2=0;
        }
        if(Cell_Check(A)==1)
        {
            Cell(A);
            printf("%s wins this game....\n",R);
            break;
        }
        else if(Cell_Check(A)==2)
        {
            Cell(A);
            printf("%s wins this game....\n",S);
            break;
        }
        Cell(A);
        if(Match_Draw_Check(A)==1)
        {
            printf("....%s & %s your Game is tied....\n",R,S);
            break;
        }
    }
    return 0;
}