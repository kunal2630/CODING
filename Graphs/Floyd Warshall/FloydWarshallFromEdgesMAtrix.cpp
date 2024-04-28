
 vector<int> GenerateDisMatrix(int n, vector<vector<int>>& edges) {

        int size=edges.size();
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dis[i][j]=0;
                }
            }
        }
         for(int i=0;i<size;i++){
                //assuming each edges has 1 unit distance between them
                dis[edges[i][0]][edges[i][1]]=1;
                  dis[edges[i][1]][edges[i][0]]=1;
         }
         for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][via]+dis[via][j]);
                }
            }
         }
 }
