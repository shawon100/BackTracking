#include <bits/stdc++.h>
using namespace std;
int n,a,b,h;

void solution(int board[32][32])
{
    int p,q;
    printf("%2d     ",h++);

    for(q=0;q<n;q++)
    {
      for(p=0;p<n;p++)
      {
        if(board[p][q]==1)
        {
            printf(" %d",p+1);
        }
      }

    }

    cout<<endl;
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

    if(col==n && board[a-1][b-1]==1)
    {
        solution(board);
        return true;
    }
    bool res=false;
    for(k=0;k<n;k++)
    {
        if(safe(board,k,col))
        {
            board[k][col]=1;
            res=solve(board,col+1)||res;

            board[k][col]=0;
        }



    }

    return res;
}


bool nqueen()
{
    int board[32][32],t,x;
    //freopen("750in.txt","r",stdin);
    //reopen("750out.txt","w",stdout);
    cin>>t;
    for(x=1;x<=t;x++)
    {
        memset(board,0,sizeof board);
        cin>>a>>b;
        h=1;
        n=8;
        if(x>1)
        {
           cout<<endl;
        }

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        if(solve(board,0)==false)
        {
            cout<<"Solution does not exist"<<endl;
        }
    }



    return true;

}

int main()
{
    nqueen();
    return 0;
}


