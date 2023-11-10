   /*

   In  adjacentPairs array every adjacent pair is given , so every number is this adjacentPairs will be present twice 
   except the first and last number since with starting or ending you can always make one pair ( ex -  2,3,4,5 pairs
   can be {(2,3),(3,4).(4,5)})

   In the question it is said that pairs may exist as [nums[i], nums[i+1]] or [nums[i+1], nums[i]] so either we start
   making original array from starting or ending it doesnt matter

   From adjacentPairs we can make our undirected graph so that we can get our numbers 

   Rest is simple dfs 
*/

// Bruteforce

    void dfs(int idx, unordered_map<int,vector<int>> &adj, unordered_map<int,int> &vis,vector<int>& ans){

        vis[idx]=1;
        ans.push_back(idx);

        for(auto it:adj[idx]){

            if(!vis[it]){

                dfs(it,adj,vis,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int n=adjacentPairs.size();
       unordered_map<int,vector<int>> adj;
        unordered_map<int,int> mp,vis;
        vector<int> ans;
        for(auto it:adjacentPairs){

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            mp[it[0]]++;
             mp[it[1]]++;

        }
        for(auto it:mp){

            if(it.second==1){

                dfs(it.first,adj,vis,ans);
                break;
            }
        }

        return ans;


    }

    

    //Optimised Space 

    /*

    1. I am using a map to store frequency of each element so that i can find starting or ending point but i can omit this because I can use adjacency list to find the starting or ending , in adjacency list the element (it) which has only 1 edge  will be starting or ending
    2. In palce of vis we can use last and curr to manage vis number , since in the adj every it can have max size of 2 one is prev and other is new so we will never go to prev 

    */

     void dfs(int idx, unordered_map<int,vector<int>> &adj,vector<int>& ans,int& last){

        //vis[idx]=1;
        ans.push_back(idx);

        for(auto it:adj[idx]){

            if(it!=last){

                dfs(it,adj,ans,idx);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
  
       unordered_map<int,vector<int>> adj;
       // unordered_map<int,int> mp,vis;
        vector<int> ans;

        for(auto& it:adjacentPairs){

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            //mp[it[0]]++;
            // mp[it[1]]++;

        }
        int last=INT_MIN;
        for(auto& it:adj){

            // if(it.second==1){

            //     dfs(it.first,adj,vis,ans);
            //     break;
            // }
            
            if(it.second.size()==1){

                dfs(it.first,adj,ans,last);
                break;
            }
        }

        return ans;


    }
