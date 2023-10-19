 bool dfs(int node,int n,int curColor,vector<int>& color,vector<vector<int>>& graph){

        color[node]=curColor;

        for(auto it:graph[node]){

            if(color[it]==-1){

                if(dfs(it,n,!curColor,color,graph)){

                    return true;
                }

            }

            //If node is visited , check whether current node and parent node have same color 
            else if(color[node]==color[it]){

                return true;
            }
        }

        return false;


    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int> color(n,-1);

        //Checking for all node as graph may be disconnected
      for(int i=0;i<n;i++){

           if(color[i]==-1)

          {
          
               if(dfs(i,n,0,color,graph)){

                  return false;
               }
          }

       }
        return true;
        
    }
