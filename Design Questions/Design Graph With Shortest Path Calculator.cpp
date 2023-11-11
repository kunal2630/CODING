    
    /*

    Intuition - Question is of direct djkistra implementation

    */
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        
        adj.resize(n);
        for(auto it:edges){

            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {

        adj[edge[0]].push_back({edge[1],edge[2]});
        
    }
    
    int shortestPath(int node1, int node2) {

        vector<int> dis(adj.size(),1e9);
        dis[node1]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,node1});
        while(!pq.empty()){

            auto it=pq.top();
            int old_dis=it[0];
            int old_node=it[1];
            pq.pop();

            

            for(auto it:adj[old_node]){

                if(old_dis+it.second<dis[it.first]){

                    dis[it.first]=old_dis+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }

        return dis[node2]==1e9?-1:dis[node2];
        
    }
