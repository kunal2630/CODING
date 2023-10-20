 bool dfs(int node,vector<int>& vis, vector<int> &inRecursion,vector<vector<int>>& graph, vector<int> &ans){

        vis[node]=1;
        inRecursion[node]=1;

        for(auto it:graph[node]){

            if(!vis[it]){

                if(dfs(it,vis,inRecursion,graph,ans)) return true;
            }
            else if(inRecursion[it]){

                return true;
            }
        }

        //It means we didnt find cycle for this node ,so 

        ans.push_back(node);
        inRecursion[node]=0;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

      /*  
      
      If you have started from some node , eventually you will reach some node and if from that node you didn't go 
      anywhere it means you have reached terminal node but if you keep on travelling without stopping it means 
      you have entered in a cycle in that case you can never reach terminal node

        So for every node we have to check whether we can enter cycle or not if not it means we can reach 
      terminal node (Use Detect cycle in directed graph code for every node)

      */

        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> inRecursion(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){

            if(!vis[i]){

                dfs(i,vis,inRecursion,graph,ans);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

        
    }
