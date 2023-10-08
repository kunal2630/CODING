 typedef pair<int,int> P;
    int minCostConnectPoints(vector<vector<int>>& mat) {

        int n=mat.size();
        vector<vector<pair<int,int>>> adj(n);
       
       //We need to form adjacency matrix from each node we can go to all other node 
       for(int i=0;i<mat.size();i++){

           for(int j=i+1;j<n;j++){

               adj[i].push_back({j,(abs(mat[i][0]-mat[j][0]) + abs(mat[i][1]-mat[j][1]))});
               adj[j].push_back({i,(abs(mat[i][0]-mat[j][0]) + abs(mat[i][1]-mat[j][1]))});
           }
       }

       // SAME AS PRIMS ALGORITHM
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<int> inMst(n,0);
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){

            int wt=pq.top().first;
            int v=pq.top().second;
            pq.pop();
            if(inMst[v]) continue;

            ans +=wt;
            inMst[v]=1;

            for(auto &it:adj[v]){

                if(!inMst[it.first]){

                    pq.push({it.second,it.first});

                }

            }


        }

        return ans;
        
    }
