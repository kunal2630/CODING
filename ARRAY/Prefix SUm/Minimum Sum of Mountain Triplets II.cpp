/*

    Intuition -

    Bruteforce - O(n^3) , find all triplets and check every triplets for condition

    Optimal - For every number of array to satisfy mountain property we need a number which is less than current number to its left and a number which is less than current number to its right and both these number should be minimum as we need minimum possible sum  that is minimum on left, minimum on right for every element and return min leftmin+peak+rightmin

    */
    int minimumSum(vector<int>& nums) {
        
          int ans=INT_MAX;
        int n=nums.size();
        
        vector<int> left_min(n);
         vector<int> right_min(n);
        left_min[0]=nums[0];
         right_min[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++){
            
            left_min[i]=min(left_min[i-1],nums[i]);
        }
         for(int i=n-2;i>=0;i--){
            
            right_min[i]=min(right_min[i+1],nums[i]);
        }
         for(int i=1;i<n-1;i++){
             
             if(nums[i]>left_min[i-1] && nums[i]>right_min[i+1]){
                 
                 ans=min(ans,nums[i]+left_min[i-1]+right_min[i+1]);
             }
         }
        
        
        return ans==INT_MAX?-1:ans;
        
    }
