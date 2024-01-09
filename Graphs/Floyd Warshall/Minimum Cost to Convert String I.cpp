class Solution {
public:


 //Approach -1 
  
   Djkistra implementaion with memoisation since in the question it was given that {original[i],changed[i]} may be present more than once so we have memoised it so that we have to only calculate their cost once

  

 
    
    typedef pair<int,int> pi;
    int dp[26][26];
    void djkistra(int src,vector<vector<pair<int,int>>> & adj, vector<long long>& dis){

        dis[src]=0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,src});

        while(!pq.empty()){

            int sNode=pq.top().second;
            int sDist=pq.top().first;
            pq.pop();

            for(auto& it:adj[sNode]){

                int dNode=it.first;
                int dDist=it.second;

                if(sDist+dDist<dis[dNode]){

                    dis[dNode]=sDist+dDist;
                    pq.push({dis[dNode],dNode});

                }
            }
        }

    }
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {

      long long ans=0;
      int n=s.length();
      int m=o.size();
      memset(dp,-1,sizeof(dp));
      vector<vector<pair <int,int> >> adj(26);
      for(int i=0;i<m;i++){

          adj[o[i]-'a'].push_back({c[i]-'a',cost[i]});

      }
      for(int i=0;i<n;i++){

            int src=s[i]-'a';
            int target=t[i]-'a';
          if(s[i]!=t[i]) {

            if(dp[src][target]!=-1){

                ans +=dp[src][target];
            }
            else{
            vector<long long> dis(26,LONG_MAX);

            djkistra(src,adj,dis);
            if(dis[target]==LONG_MAX) return -1;
            ans +=dis[target];
            dp[src][target]=dis[target];
            }

          }
      }  

      return ans;


    }

   //Approach 2 - Floyd Warshall

    //Now since basically we have to find  minimum cost for to change each original[i] to changed[i] , so instead of apply djkistra on each character we can use Floyd Warshall algorithm to calculate pair distance once and then use it whenver necessary 
   

        long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        int n = source.size(), size = changed.size();
        vector<vector<int>> adjMat(26, vector<int>(26, 1e9));
        for(int i = 0 ; i < size ; i++){
            int x = original[i] - 'a', y = changed[i] - 'a';
            adjMat[x][y] = min(cost[i], adjMat[x][y]);
        }
        for(int via = 0 ; via < 26 ; via++){
            for(int j = 0 ; j < 26 ; j++){
                for(int k = 0 ; k < 26 ; k++)
                    adjMat[j][k] = min(adjMat[j][k], adjMat[j][via] + adjMat[via][k]);
            }
        }
        long minCost = 0;
        for(int i = 0 ; i < n ; i++){
            if(source[i] != target[i]){
                int x = source[i] - 'a', y = target[i] - 'a';
                if(adjMat[x][y] == 1e9)
                    return -1;
                minCost += adjMat[x][y];
            }
        }
        return minCost;
    }
};
