class Solution {
public:
    
    int mod=1e9+7;
    int dp[51][51][51];
    int dlrow[4]={0,1,0,-1};
    int dlcol[4]={-1,0,1,0};



    int f(int row,int col,int m,int n,int maxMove){

        //any time we move out of the boundary means a valid path exits so we have to return 1,doesnt matter we have moves left or not
        if(row<0 || row>=m || col<0 || col>=n){

            return 1;
        }

        //if our moves gets exhausted in between then we cant move further
        if(maxMove==0) return 0;

        if(dp[row][col][maxMove]!=-1){

            return dp[row][col][maxMove];
        }

        int ans=0;

        for(int i=0;i<4;i++){

            int newrow=row+dlrow[i];
            int newcol=col+dlcol[i];

            ans=(ans+f(newrow,newcol,m,n,maxMove-1))%mod;

        }

   

        return dp[row][col][maxMove]=ans;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
         memset(dp,-1,sizeof(dp));
         return f(startRow,startColumn,m,n,maxMove);
    }
};
