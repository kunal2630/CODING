  /*

    As in the question least number was given src,target was given hence thought of bfs

    Think of question as a Metro use case , here  you have to start your journey from your nearest metro station that is 
    in this case is the source Once you have seated in the metro , you can go to n metro station and if in this n station 
    one is your destination(target) station   then well and good you reached your target, but if target is not on this route 
    then you have to switch metro , so from a particular station check which metro is available and sit on that metro which 
    you have not taken before and repeat the same process


    */
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        //No need to take metro
        if(source==target){

            return 0;
        }

        int n=routes.size();

        //to store from each metro station which metro trains are available
        unordered_map<int,vector<int>> adj;

        for(int metro=0;metro<n;metro++){

            for(auto& station:routes[metro]){

                //ex from staion 1st metro train 0 available
                adj[station].push_back(metro);
            }
        }

        int ans=1;

        //Once you have tsken a metro you will probably not take the same metro again
        vector<int> vis(n,0);

        //to store metro as have to find least number of metro train we will take
        queue<int> q;

        for(auto& metro:adj[source]){

            q.push(metro);
            vis[metro]=1;

        }

        while(!q.empty()){

           
           int size=q.size();
           
           while(size--){

            int metro_no=q.front();
            q.pop();
           
           
            //From a particular metro which station can you go
            for(auto& station:routes[metro_no]){

                if(station==target){

                    return ans;
                }

                 //From a particular station  which metro can you take
                for(auto& metro:adj[station]){

                    if(!vis[metro]){

                        q.push(metro);
                        vis[metro]=1;
                    }
                }

            }

            }

             ans++;
        }


        return -1;
    }
