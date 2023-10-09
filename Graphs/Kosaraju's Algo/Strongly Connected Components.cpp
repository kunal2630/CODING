 void topoSort(int node,stack<int>& st,vector<vector<int>>& adj,vector<int> &vis){
        
        vis[node]=1;
        
        for(auto &it:adj[node]){
            
            if(!vis[it]){
                
                topoSort(it,st,adj,vis);
            }
        }
        
        st.push(node);
        
    }
    
    void dfs(int node,vector<int>& vis,vector<vector<int>>& rev_adj){
        
        vis[node]=1;
        
        for(auto it:rev_adj[node]){
            
            if(!vis[it]){
                
                dfs(it,vis,rev_adj);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        //3 Steps - 
        // (1) Find topoSort 
        // (2) Reverse Edges
        // (3) Call dfs on node taken out from stack , the number of times we can make the dfs call is equal to the number of component present
        
        stack<int> st;
        vector<int> vis(V,0);
        
        //It is important to call topoSort for every node as there may be case that some node are not connected 
        //directly as they may belong to different connected component
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                
                 topoSort(i,st,adj,vis);
                
            }
        }
       
        int scc=0;
        vector<vector<int>> rev_adj(V);
        for(int i=0;i<V;i++){
            
           for(auto &it:adj[i]){
               
               rev_adj[it].push_back(i);
           }
        }
        
        for(int i=0;i<V;i++){
            
            vis[i]=0;
        }
        while(!st.empty()){
            
            int node=st.top();
            st.pop();
            
            if(!vis[node]){
                
               
                dfs(node,vis,rev_adj);
                 scc++;
            }
            
        }
        
        return scc;
        
    }
