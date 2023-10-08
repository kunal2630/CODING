vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        vector<int> dis(V,1e8);
        dis[S]=0;
        
        //V-1 times relaxation
        
        for(int i=0;i<V-1;i++){
            
            for(auto it:edges){
                
                int u=it[0];
                int v=it[1];
                int w=it[2];
                
                //Do relaxation
                
                if(dis[u]+w<dis[v]){
                    
                    dis[v]=dis[u]+w;
                }
            }
        }
        
        //Check for -ve cycle - do relaxation one more time
        
        for(auto it:edges){
                
                int u=it[0];
                int v=it[1];
                int w=it[2];
                
                //Do relaxation
                
                if(dis[u]+w<dis[v]){
                    
                   //-ve Cycle
                    return {-1};
                }
        }
        
        return dis;
        
        
    }
