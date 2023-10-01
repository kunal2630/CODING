

/*

    This question can be solved using bfs on matrix type, but since this is taking about minimum distance from a fixed starting point , 
    we can use djkistra to solved it  From a cell or node we can go in 8 direction (can be treated this as adjacency) ,
    distance taken from one node to another (in this case distance between two adjacent cell) is 1 and we can go from
    one node to another only if its value is 0  and it is range so we also have to check that

*/

//T.C - O(E log(V)) => O(n*n log(8*n*n)) => O(n^2 log(n^2))
//S.C - O(n^2)


    bool isSafeToGo(int row,int col,int n,vector<vector<int>>& grid){

        return row>=0 && row<n && col>=0 && col<n && grid[row][col]==0;

    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        vector<vector<int>> dis(n,vector<int>(n,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,1});
        dis[0][0]=1;
        int dlrow[8]={0,1,1,1,0,-1,-1,-1};
        int dlcol[8]={-1,-1,0,1,1,1,0,-1};

        while(!pq.empty()){

            int row=pq.top()[0];
            int col=pq.top()[1];
            int old_dis=pq.top()[2];
            pq.pop();

            for(int i=0;i<8;i++){

                int newrow=row+dlrow[i];
                int newcol=col+dlcol[i];

                if(isSafeToGo(newrow,newcol,n,grid) && dis[newrow][newcol]>old_dis+1){

                    dis[newrow][newcol]=old_dis+1;
                    pq.push({newrow,newcol,dis[newrow][newcol]});
                }
            }

        }

        return dis[n-1][n-1]==1e9?-1:dis[n-1][n-1];
    }
