  /*

    Simple bfs traversal wont work here as edge weight(diff between heigts of adjacent cells) is variable
    Now since fixed starting point is there and in question minimum of something is asking think about djkistra
    Slight variation from djkistra - here we dont have to track distance taken to reach current cell in account ,
    we only have to take in account the height difference but since at last we have to return min(of each path max) 
    so while visitng each cell we ahve to main max(dis[parent_cell],abs(height[curr_cel] - height[adj_cell]))
 
    */

    bool isSafe(int row,int col,int n,int m){

        return row>=0 && row<n && col>=0 && col<m;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
       
        
        int dlrow[4]={0,1,0,-1};
        int dlcol[4]={-1,0,1,0};

        while(!pq.empty()){

            
            int row=pq.top()[1];
            int col=pq.top()[2];
            int old_effort=pq.top()[0];
           
            pq.pop();
            for(int i=0;i<4;i++){

                int newrow=row+dlrow[i];
                int newcol=col+dlcol[i];
               
                

                if(isSafe(newrow,newcol,n,m)  ){

                    int adj_dis=heights[newrow][newcol];
                    int curr_effort=max(old_effort,abs(heights[row][col]-heights[newrow][newcol]));
                    if(dis[newrow][newcol]>curr_effort){

                        
                         dis[newrow][newcol]=curr_effort;
                          pq.push({curr_effort,newrow,newcol});


                    }
                  
                   
                }
            }
            
        


        }

        return dis[n-1][m-1];





        
    }
