 int mod=1e9+7;
    int dp[1001][1001];
    int f(int n,int k){

        if(n==0) return 0;

        //0 inversion is possible only when array is sorted means there can be exactly 1 array with 0 inversion 
        if(k==0) return 1;

        if(dp[n][k]!=-1) return dp[n][k];
        int ans=0;

         //In an array of length n, We can't create inversions more than (n-1) -> min(n-1, k)
        for(int inv=0;inv<=min(k,n-1);inv++){

            ans =(ans+f(n-1,k-inv))%mod;
        }

        return dp[n][k]=ans;
    }
    int kInversePairs(int n, int k) {

        memset(dp,-1,sizeof(dp));
        return f(n,k);
        
    }
