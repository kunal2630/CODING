 int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
 

        //Application of topological sorting
        //We have to find  time in which all course can be taken, so minimum time will be max of time taken by each course to complete 
        //Time requried to take a course - Time required to take its parent course + time requried to take current course
        //Steps - indegree array lo ,jiksa indegree 0 hai use queue mein daalo  , node se adjacent move kro , har node lene ka time 
        //store kro , indegree kam kro jaise indegree 0 ho use queue mein daal do(conditin to take node in topo sort)
        
        vector<int> indegree(n+1,0);
        vector<vector<int>> adj(n+1);
        queue<int> q;

        for(auto &it:relations){

            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        vector<int> maxtime(n+1,0);
        for(int i=1;i<=n;i++){

            if(indegree[i]==0){

                q.push(i);
                maxtime[i]=time[i-1];
            }
        }
        
        int ans=0;
        while(!q.empty()){

            int size=q.size();
         

            while(size--){

                int node=q.front();
                q.pop();
                

                for(auto it:adj[node]){

                    indegree[it]--;
                    maxtime[it]=max(maxtime[it],maxtime[node]+time[it-1]);

                    if(indegree[it]==0){

                        q.push(it);
                    }
                }

            }

           
        }

        for(int i=1;i<=n;i++){

            ans=max(ans,maxtime[i]);
        }

        return ans;
        
    }
