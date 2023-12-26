 /*

    Standard Pick not pick type , just while picking we have to ensure that if it gets pick at ith position and 
    ith position is even then we have to add it in our answer else subtract it

    */

    //tabulation +memoisation
    long long  dp[100001][2];
    long long f(int idx,int even,vector<int>& nums){

        if(idx==nums.size()) return 0;

        if(dp[idx][even]!=-1){

            return dp[idx][even];
        }

        long long ans=0;

        if(even==1){

            ans =max(ans,nums[idx]+f(idx+1,0,nums));
        }
        if(even==0){

            ans =max(ans,-nums[idx]+f(idx+1,1,nums));

        }

        ans=max(ans,f(idx+1,even,nums));

        return dp[idx][even]=ans;


    }
    long long maxAlternatingSum(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return f(0,1,nums);
    }


 //Tabulation 

 
    long long maxAlternatingSum(vector<int>& nums) {
        
        long long  dp[100001][2];
        memset(dp,0,sizeof(dp));

        for(int i=nums.size()-1;i>=0;i--){

            long long ans=0;
    
            for(int even=0;even<=1;even++){

                if(even==1){

                    ans =max(ans,nums[i]+dp[i+1][0]);
                }
                if(even==0){

                    ans =max(ans,-nums[i]+dp[i+1][1]);

                }
                ans=max(ans,dp[i+1][even]);
                dp[i][even]=ans;


            }


        }


        return dp[0][1];
    }
