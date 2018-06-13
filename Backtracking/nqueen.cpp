#include <bits/stdc++.h>
using namespace std;
int n;

void solution(int board[32][32])
{
    int p,q;
    for(p=0;p<n;p++)
    {
        for(q=0;q<n;q++)
        {
            printf("%d ",board[p][q]);
        }
        cout<<endl;
    }
}

bool safe(int board[32][32], int row,int col)
{
     int i,j;
     for(i=0;i<col;i++)
     {
         if(board[row][i])
         {
             return false;
         }
     }

     for(i=row, j=col; i>=0 && j>=0; i--,j--)
     {
         if(board[i][j])
         {
             return false;
         }
     }

     for(i=row,j=col; j>=0 && i<n; i++,j--)
     {
         if(board[i][j])
         {
             return false;
         }
     }

     return true;
}


bool solve(int board[32][32], int col)
{
    int k;

    if(col>=n)
    {
        return true;
    }

    for(k=0;k<n;k++)
    {
        if(safe(board,k,col))
        {
            board[k][col]=1;
            if(solve(board,col+1))
            {
                return true;
            }
            board[k][col]=0;
        }



    }

    return false;
}


bool nqueen()
{
    int board[32][32];
    cin>>n;
    memset(board,0,sizeof board);
    if(solve(board,0)==false)
    {
        cout<<"Solution does not exist"<<endl;
    }

    solution(board);

    return true;

}

int main()
{
    nqueen();
    return 0;
}
