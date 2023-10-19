

/*

Two islands are considered to be the same if  and only if one island is equal to another (not rotated or reflected) i.e if we
can translate one island on another without rotating or reflecting then it would beconsidered as the same islands.

That is two island are same if there travelsal path is same ,  so we have to track travelsal path

For every 1 in the matrix, do DFS and mark all the 1’s as visited which are connected to this 1 and store the path of the island 
in a string.
  

     Followings are the abbreviated path :

     ‘S’ - starting vertex

     ‘D’ - down

     ‘U’ - up

     ‘L’ - left

     ‘R’ - right

     ‘B’ - backtrack

*/

int dlrow[4]={0,1,0,-1};
int dlcol[4]={-1,0,1,0};

void dfs(int row,int col,int n,int m, string& path,int** arr, vector<vector<int>>& vis){

    vis[row][col]=1;

    for(int i=0;i<4;i++){

        int newrow=row+dlrow[i];
        int newcol=col+dlcol[i];

        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !vis[newrow][newcol] && arr[newrow][newcol]==1){

            if(i==0) path +='L';
            else if(i==1) path +='D';
            else if(i==2) path +='R';
            else path +='T';

            dfs(newrow,newcol,n,m,path,arr,vis);
            path +='B';
        }
         
        
        
    }
   
   
}


int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    set<string> s;
    vector<vector<int>> vis(n,vector<int>(m,0));

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(!vis[i][j] && arr[i][j]==1){

                string path;
                 path +='S';
                dfs(i,j,n,m,path,arr,vis);
                s.insert(path);
               
            }
        }
    }

    return s.size();

}
