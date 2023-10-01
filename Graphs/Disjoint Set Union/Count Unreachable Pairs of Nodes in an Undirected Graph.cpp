
class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){

        if(x==parent[x]) return x;

        return parent[x]=find(parent[x]);
    }
    void combine(int x,int y){

        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]){

            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){

            parent[x_parent]=y_parent;
        }
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        rank.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){

            parent[i]=i;
        }

       for(auto it:edges){

            combine(it[0],it[1]);

       }
       
        long long cnt=0;

        /*
         //n^2 complexity
        for(int i=0;i<n;i++){

              int x_parent=find(i);

            for(int j=i+1;j<n;j++){

              
                int y_parent=find(j);
                if(x_parent!=y_parent) {

                   cout<<i<<" "<<j<<endl; 
                    cnt++;
                }
            }
        }

        */
        
        //To store number of nodes in a component
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){

            //Find who is parent of the current node,so total number of node  in the current component can be found by mp[parent]
            mp[find(i)]++;



        }
        long long int total_el=n;
        for(auto it:mp){

            long long size=it.second;
            cnt +=((total_el-size)*size);
            total_el -=it.second;


        }


        return cnt;
        
    }
};
