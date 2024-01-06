class Solution {
public:
   
    /*

    Standard pick not pick dp

    Once a task is picked next task can only be picked if current task gets finished , so we can find next task (which start at current task endTime or after current task endTime) using linear search or binary search(lower_bound) since task is stored in a 2d vector , we cant directly use lower_bound (stl) so we implemented lower bound on our own(as 2d vector is sorted )

    */
    
    int dp[100000];
    int search(int s,int n,vector<vector<int>>& v,int endTime){

       
        int e=n-1;
        int result=n;
        while( s<=e){

            int mid=s+(e-s)/2;

            if(  v[mid][0]>=endTime){

                result=mid;
                e=mid-1;
            }
            else{

                s=mid+1;
            }
        }

        return result;
    }
    int f(int idx,int n,vector<vector<int>>& v){

        if(idx>=n) return 0;

        if(dp[idx] !=-1){
            return dp[idx];
        }
        int ans=0;

        //pick
        int nextIdx=search(idx+1,n,v,v[idx][1]);
        if(idx<n) ans=max(ans,v[idx][2]+f(nextIdx,n,v));

        //not pick current task
        ans=max(ans,0+f(idx+1,n,v));

        return dp[idx]=ans;
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {
        
        
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> v(n,vector<int>(3,0));

        for(int i=0;i<n;i++){
            

            v[i]={s[i],e[i],profit[i]};
        }

        sort(v.begin(),v.end());
        return f(0,n,v);
    }
};
