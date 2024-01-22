static bool comp(vector<int>& a,vector<int>& b){

        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        /*

        We need tallest people in the queue as early as possible a/c to it ki value , so sorted the array according to height and if height same then place that people in front whose ki values is less

        */
        sort(people.begin(),people.end(),comp);
        int n=people.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){

            int pos=people[i][1];
            ans.insert(ans.begin()+pos,people[i]);
        }

        return ans;
    }
