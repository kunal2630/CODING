
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

            //Straightaway application of Dijkistra algorithm(Single Source ) , in dijkstra we were going from a node to all nodes
            //covering minimum distance here we are sending singnal in minimum time
      
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){

            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dis(n+1,1e9);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});
        dis[k]=0;

        while(!pq.empty()){

            int node=pq.top().second;
            int adj_dis=pq.top().first;
            pq.pop();

            for(auto it:adj[node]){

                if(dis[it.first]>adj_dis+it.second){
                    dis[it.first]=adj_dis+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }

        int ans=INT_MIN;

        for(int i=1;i<=n;i++){

            cout<<dis[i]<<endl;
            if(dis[i]==1e9) return -1;
            ans=max(ans,dis[i]);
        }

        return ans;
        
    }
