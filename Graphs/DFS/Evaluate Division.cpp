unordered_map<string,vector< pair<string,double> > > adj;
         vector<double> ans;

    void dfs(string src,string target,double prod,unordered_map<string,int>& vis,double& res ){

        if(src==target){
            res=prod;
            return;
        }

        vis[src]=1;
        for(auto& it:adj[src]){

            string adjNode=it.first;
            double value=it.second;

            if(!vis[adjNode]){

                double oldVal=prod;
                prod*=value;
                dfs(adjNode,target,prod,vis,res);

                //backtrack
                prod=oldVal;
                
            }
        }

        

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int cnt=0;
        for(auto& it:equations){

            adj[it[0]].push_back({it[1],values[cnt]});
            adj[it[1]].push_back({it[0],1.0/(values[cnt])});
            cnt++;
        }
        for(auto& it:queries){

            string src=it[0];
            string target=it[1];
            double res=-1;
           
            
            if(adj.find(src)!=adj.end()){

                 double prod=1.00000;
                unordered_map<string,int> vis;
                 dfs(src,target,prod,vis,res);
                 

            }
           
           ans.push_back(res);
           
        }
        return ans;
    }
