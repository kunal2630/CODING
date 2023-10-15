
typedef pair<int,int> P;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

       /*

        We have to find shortest path length so whenever we  need shortest path or length we think of bfs 
        We dont have to worry about whether the path is minimum or not because bfs find the minimum path only so the moments we first found 
        our exit we straightaway return steps as it will be minimum

       */
       
       //Queue
        queue<P> q;

        int m=maze.size();
        int n=maze[0].size();

        //Directions
        int dlrow[4]={0,1,0,-1};
        int dlcol[4]={-1,0,1,0};
      
        q.push({entrance[0],entrance[1]});

        //Mark entrance cell as visited
        maze[entrance[0]][entrance[1]]='+';

          
            int steps=1;

            while(!q.empty()){

                int size=q.size();
                while(size--){

                    auto [row,col]=q.front();
                    q.pop();

                        for(int i=0;i<4;i++){

                            int newrow=row+dlrow[i];
                            int newcol=col+dlcol[i];

                            if(newrow>=0 && newrow<m && newcol>=0 &&  newcol<n && maze[newrow][newcol]=='.'  ){

                                
                                //If cell is a exit return steps
                                if(newrow==0 || newrow==m-1 || newcol==0 || newcol==n-1) return steps;

                                q.push({newrow,newcol});
                                 maze[newrow][newcol]='+';
                            }
                        }
                    

                }

                steps++;

            }
        

        return -1;
        
    }
