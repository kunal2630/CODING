  /*

    So for any ith index of nums[i] its result[i] is the total sum of =>
    abs(nums[i] - nums[0]) + abs(nums[i] - nums[1]) + ... + abs(nums[i] - nums[i-1]) +abs (nums[i] - nums[i])+ abs(nums[i+1] - nums[i]) + abs(nums[i+2] - nums[i]) + ... + abs(nums[n-1] - nums[i]).

    but now since array is sorted for all index less than i ,nums[i]-nums[j] where j<i is positive so we can remove abs for all index less than i

    (nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i-1]) + abs (nums[i] - nums[i]) + abs(nums[i] - nums[i+1]) + abs(nums[i] - nums[i+2]) + ... + abs (nums[i] - nums[n-1]).

    for all index greater than i -> abs(nums[i] - nums[i+1]) can be written as nums[i+1] - nums[i] (abs can be removed since it will be positive as array is sorted)

    So final result ith index can be calculated by -> 

    nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i-1]) + (nums[i+1] - nums[i]) + (nums[i+2] - nums[i]) + ... + (nums[n-1] - nums[i]  =>  nums[i] * i - (nums[0] + nums[1] + ... + nums[i-1])) + ((nums[i+1] + nums[i+2] + ... + nums[n-1]) - (nums[i] * (n-i-1))
)

And we can maintain a prefix array to hold sum

    */
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> pref_sum(n);
        pref_sum[0]=nums[0];
        for(int i=1;i<n;i++){

            pref_sum[i]=pref_sum[i-1]+nums[i];
        }

         vector<int> result(n);

         result[0]=(pref_sum[n-1]-nums[0])-nums[0]*(n-1);

         for(int i=1;i<n;i++){

             int leftSum=pref_sum[i-1];
             int rightSum=pref_sum[n-1]-pref_sum[i];

             result[i]= nums[i]*i - leftSum+rightSum - nums[i]*(n-i-1);
         }

         return result;
    }
