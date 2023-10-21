//Straight forward question of djkstra or Bellman ford Algorithm

   typedef pair<int,int> Pi;

    void djkistra(int start, vector<int>& dis, vector<vector<Pi>>& adj,int distanceThreshold){

        priority_queue<Pi,vector<Pi>,greater<Pi>> pq;

        pq.push({0,start});
        dis[start]=0;


        while(!pq.empty()){

            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){

                int adj_node=it.first;
                int adj_weight=it.second;

                if(dis[node]+adj_weight<dis[adj_node] && dis[node]+adj_weight<=distanceThreshold){

                   dis[adj_node]= dis[node]+adj_weight;
                   pq.push({dis[adj_node],adj_node});

                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<Pi>> adj(n);
        for(auto it:edges){

            adj[it[0]].push_back({it[1],it[2]});
             adj[it[1]].push_back({it[0],it[2]});
        }

        int max_no_of_city=INT_MAX;
        int ans=0;

        for(int i=0;i<n;i++){

            vector<int> dis(n,1e9);
            djkistra(i,dis,adj,distanceThreshold);
            
            //To store cnt of city which is reachable by i with distance less than threshold distance
            int cnt=0;

            for(int j=0;j<n;j++){

                if(i!=j && dis[j]<=distanceThreshold){

                    cnt++;

                }
            }

           
           //We need minum no city which is reachable in threshold distance

            if(cnt<=max_no_of_city){

                ans=i;
                max_no_of_city=cnt;
            }

        }

        return ans;
        
    }
