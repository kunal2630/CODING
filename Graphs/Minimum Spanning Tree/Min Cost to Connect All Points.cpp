
//APPROACH 1 - USING PRIM'S ALGORITHM
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

//APPROACH 2 - USING KRUSKAL ALGORITHM

//KRUSKAL ALGORITHM
    vector<int> rank;
    vector<int> parent;
    int findParent(int x){

        if(parent[x]==x){

            return x;
        }

        return  parent[x]=findParent(parent[x]);
    }

    void combine(int x,int y){

      

        int x_parent=findParent(x);
        int y_parent=findParent(y);

        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]){

            parent[y_parent]=x_parent;
        }

        else if(rank[x_parent]<rank[y_parent]){

                    parent[x_parent]=y_parent;
        }
        else{

             parent[y_parent]=x_parent;
             rank[x_parent]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

         int n=points.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){

            parent[i]=i;
        }
        vector<vector<int>> adj;

       

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=abs(x2-x1)+abs(y2-y1);
                adj.push_back({dist,i,j});
                adj.push_back({dist,j,i});

            }
        }
        
        sort(adj.begin(),adj.end());
       
        int ans=0;
        for(auto &it:adj){

            int wt=it[0];
            int u=it[1];
            int v=it[2];
       

            if(findParent(u)!=findParent(v)) {

                  ans +=wt;
                 combine(u,v);


            }

          


        }

        return ans;
        
    }
