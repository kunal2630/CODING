 void dfs(int row,int col,int m,int n,vector<vector<char>>& board,int dlrow[],int dlcol[]){
        
  //Marking cell as visited     
   board[row][col]='Y';
       

        for(int i=0;i<4;i++){

            int newrow=row+dlrow[i];
            int newcol=col+dlcol[i];

            if(newrow>0 && newrow<m-1 && newcol>0 && newcol<n-1 && board[newrow][newcol]=='O'){

                dfs(newrow,newcol,m,n,board,dlrow,dlcol);
            }
        }

    }
    void solve(vector<vector<char>>& board) {

        int m=board.size();
        int n=board[0].size();
        int dlrow[4]={0,1,0,-1};
        int dlcol[4]={-1,0,1,0};
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){

                 
                    dfs(i,j,m,n,board,dlrow,dlcol);
                }

            }


        }
      

         for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(board[i][j]=='Y'){

                    board[i][j]='O';
                }
                else{

                     board[i][j]='X';

                }

            }


         }
        
    }
