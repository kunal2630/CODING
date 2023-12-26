 /* 

    We have n dice
    For each dice we have option to pick a number from 1 to k 
    If number picked sum ==target means we have 1 ways
    So wrote a recursion with 2 changing factor n and target , and when our n becomes 0 means we have used all our dice , so checked did our taget becomes 0 if yes returned 1 means 1 way else return 0

    Generally we just have to change k values (in coins problem or subarray sum problem) but here we also have to change n 


    */


    int dp[31][1001];
    int mod=1e9+7;
    int f(int n, int k, int target){

        if(n==0){

            if(target==0) return 1;
            return 0;
        }
        
        if(target<0) return 0;

        if(dp[n][target]!=-1){

            return dp[n][target];
        }

        int ans=0;

        for(int i=1;i<=k;i++){

            ans =(ans+f(n-1,k,target-i))%mod;
        }

        return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        memset(dp,-1,sizeof(dp));
        return f(n,k,target);
    }


   
