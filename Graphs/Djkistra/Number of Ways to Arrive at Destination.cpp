
    int mod = 1e9 + 7;
    typedef long long ll;
    typedef pair<ll,ll> P;
    

    //STRAIGHT FORWARD DJKISTRA BUT CATCH HERE IS THAT WE HAVE TO FIND NUMBER OF WAYS TO REACH THE LAST NODE(DESTINATION) 
    //STRAIGHTAWAY LOGIC WILL BE TO COUNT THE NUMBER OF TIMES WE ARE REACHING DESTINATION NODE AND INCREASING COUNT BY 1 BUT BUT 
    //MIND THAT SUPPOSE YOU REACHED END NODE VIA SOME MIDDLE NODE X , BUT YOU COULD HAVE REACHED X IN N NUMBER OF WAYS THROUGH DIFFERENT PATH ,
    //THEREFORE YOU WOULD HAVE REACHED END NODE IN N WAYS NOT 1 , SO WE HAVE TO MANTAIN WAYS ARRAY ALSO WHICH WILL HOLD DIFFERENT NUMBER OF WAYS 
    //TO REACH Ith NODE

    int countPaths(int n, vector<vector<int>>& roads) {


        vector<vector<P>> adj(n);

        for(auto it:roads){

            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long> dis(n,LONG_MAX);
        vector<long long> ways(n,0);

        dis[0]=0;
        ways[0]=1;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            
            // int wt=pq.top().first;
            // int u=pq.top().second;
            auto [wt,u]=pq.top();
            
            pq.pop();

            for(auto [v,cur_wt]:adj[u]){

                if(wt+cur_wt<dis[v]){

                    dis[v]=wt+cur_wt;
                    pq.push({dis[v],v});
                    ways[v]=ways[u];

                }

                //IT MEANS YOU HAVE REACHED V EARLIER , NOW YOU HAVE REACHED AGAIN WITH SAME MINIMUM DISTANCE SO UPDATE NUMBER OF WAYS
                else if(wt+cur_wt==dis[v]){

                    ways[v]=(ways[v]+ways[u])%mod;
                }
            
        }
    }

    return ways[n-1];
     
  
    }
   
