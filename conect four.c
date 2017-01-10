#include<stdio.h>
void p_bacground (char (*a)[][7])
{
    int i,j;
    for(i=0;i<6;i++)
    {
        printf("|");
        for(j=0;j<7;j++)
        {
           if((*a)[i][j]==0)
            {
                printf("   ");
            }
            else
                {printf(" %c ",(*a)[i][j]);}
            printf("|");

        }
        printf("\n");
        printf("_____________________________\n");
    }
     printf("  1   2   3   4   5   6   7\n");
     printf("-------->connect four<--------\n");
}
int* reding(char (*a)[][7],int p)
{
    int x,i;
    if(p==1){
    printf("player1 Enter your colume: ");
    scanf("%d",&x);
    if(x>7||x<1)
    {
        printf("pleas again\n");
        reding(a,1);
    }
    for(i=5;i>=0;i--){
    if((*a)[i][x-1]==0){
    (*a)[i][x-1]='X';
    break ;
    }}
    }
    else
    {
    printf("player2 Enter your colume: ");
    scanf("%d",&x);
    if(x>7||x<1)
    {
        printf("pleas again\n");
        reding(a,2);
    }
    for(i=5;i>=0;i--){
    if((*a)[i][x-1]==0){
    (*a)[i][x-1]='O';
    break ;
    }}
    }
    return x-1;
}
int checkwin(char (*a)[][7],int r)
{
    int c,i;
    for(i=5;i>=0;i--)
    {
        if((*a)[i][r]==0)
            {c=i+1;
             break ;
            }
    }
    if((*a)[c][r]==(*a)[c][r-1]&&(*a)[c][r]==(*a)[c][r-2]&&(*a)[c][r]==(*a)[c][r-3])
        return 1;
    if((*a)[c][r]==(*a)[c][r-1]&&(*a)[c][r]==(*a)[c][r-2]&&(*a)[c][r]==(*a)[c][r+1])
        return 1;
    if((*a)[c][r]==(*a)[c][r-1]&&(*a)[c][r]==(*a)[c][r+1]&&(*a)[c][r]==(*a)[c][r+2])
        return 1;
    if((*a)[c][r]==(*a)[c][r+1]&&(*a)[c][r]==(*a)[c][r+2]&&(*a)[c][r]==(*a)[c][r+3])
        return 1;
    if((*a)[c][r]==(*a)[c-1][r]&&(*a)[c][r]==(*a)[c-2][r]&&(*a)[c][r]==(*a)[c-3][r])
        return 1;
    if((*a)[c][r]==(*a)[c-1][r]&&(*a)[c][r]==(*a)[c-2][r]&&(*a)[c][r]==(*a)[c+1][r])
        return 1;
    if((*a)[c][r]==(*a)[c-1][r]&&(*a)[c][r]==(*a)[c+1][r]&&(*a)[c][r]==(*a)[c+2][r])
        return 1;
    if((*a)[c][r]==(*a)[c+1][r]&&(*a)[c][r]==(*a)[c+2][r]&&(*a)[c][r]==(*a)[c+3][r])
        return 1;
    if((*a)[c][r]==(*a)[c+1][r-1]&&(*a)[c][r]==(*a)[c+2][r-2]&&(*a)[c][r]==(*a)[c+3][r-3])
        return 1;
    if((*a)[c][r]==(*a)[c+1][r-1]&&(*a)[c][r]==(*a)[c+2][r-2]&&(*a)[c][r]==(*a)[c-1][r+1])
        return 1;
    if((*a)[c][r]==(*a)[c+1][r-1]&&(*a)[c][r]==(*a)[c-1][r+2]&&(*a)[c][r]==(*a)[c-2][r+2])
        return 1;
    if((*a)[c][r]==(*a)[c-3][r+3]&&(*a)[c][r]==(*a)[c-1][r+2]&&(*a)[c][r]==(*a)[c-2][r+2])
        return 1;
    if((*a)[c][r]==(*a)[c+1][r+1]&&(*a)[c][r]==(*a)[c+2][r+2]&&(*a)[c][r]==(*a)[c+3][r+3])
        return 1;
    if((*a)[c][r]==(*a)[c+1][r+1]&&(*a)[c][r]==(*a)[c+2][r+2]&&(*a)[c][r]==(*a)[c-1][r-1])
        return 1;
    if((*a)[c][r]==(*a)[c+1][r+1]&&(*a)[c][r]==(*a)[c-1][r-1]&&(*a)[c][r]==(*a)[c-2][r-2])
        return 1;
    if((*a)[c][r]==(*a)[c-1][r-1]&&(*a)[c][r]==(*a)[c-2][r-2]&&(*a)[c][r]==(*a)[c-3][r-3])
        return 1;
}

int main ()
{
    int x=0,p,player1=1,player2=2;
    char a[6][7]={0};
    p_bacground(a);
    do
    {
    p=reding(a,player1);
    p_bacground(a);
    if(checkwin(a,p)==1){
        printf("\n>>>>>>>>>>>>>>  player 1 is win  <<<<<<<<<<<<<<<<<\n");
        break;
    }
    p=reding(a,player2);
    p_bacground(a);
    if(checkwin(a,p)==1){
        printf("\n>>>>>>>>>>>>>>  player 2 is win   <<<<<<<<<<<<<<<<<<\n");
        break;
    }
    }while(x==0);
    getch();
    return 0;
}