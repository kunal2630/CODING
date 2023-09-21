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
        // Declare this inside main function and also initialized n
        rank.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){

            parent[i]=i;
        }
