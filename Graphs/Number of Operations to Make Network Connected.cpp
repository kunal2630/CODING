class Solution {
public:

    vector<int> parent;
    vector<int> rank;
    int find(int x){

        if(parent[x]==x) return x;

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

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        rank.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){

            parent[i]=i;
        }
        
        /*

         We have to make connections such that we can form  components  because inside components they will be already  connected so at the end 
         we will just have to connect different componets and cables required to connect them will be our answer
         
         */
        
        //At starting suppose all are standalone hence we have n components
        int component=n;

        //We need atleast n-1 wires to coonect all  and no of wires is basically coonections.size()

        if(connections.size()<n-1) return -1;


        for(auto it:connections){

            int first_parent=find(it[0]);
            int second_parent=find(it[1]);

            if(first_parent!=second_parent){ 
                combine(it[0],it[1]);
                component--;
            }
        }

        return component-1;


    }
};
