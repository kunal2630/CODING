    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        //To store edge weight such that minimum edge weight remains at top
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> inMst(V,0);

        pq.push({0,0});
        
        int sum=0;
        
        while(!pq.empty()){
            
            int wt=pq.top()[0];
            int v=pq.top()[1];   
            pq.pop();
 
           //If Already in mst graph then no need to operate as if we will operate that we wll get extra weight 
            if(inMst[v]) continue;
             
             sum +=wt;
             inMst[v]=1;
          
      
            
            for(auto &it:adj[v]){
                
                if(!inMst[it[0]]){
                    
                    pq.push({it[1],it[0]});
                }
            }
            
        }
        
        return sum;
        
    }
