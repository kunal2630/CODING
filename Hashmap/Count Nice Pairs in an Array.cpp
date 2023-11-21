/*

    Whenever we  see a question containing {...[i] + ...[j]==...[j]+...[i]} - always try to regroup i and j on either side it will simplify the question  

    nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    
    So for the ith(nums[i] - rev(nums[i])) number  we have to find such jth index which have same values nums[j] - rev(nums[j]) and count such pairs

    */

    int mod=1e9+7;

    //revser time complexity - O(n)
    int reverse(int num){

        int reverse_num=0;
        while(num>0){

            reverse_num =reverse_num*10+num%10;
            num=num/10;
        }

        return reverse_num;
    }
    int countNicePairs(vector<int>& nums) {
        
         
         //replacing each number with nums[i] - rev(nums[i])
         for(int i=0;i<nums.size();i++){

             nums[i]=nums[i]-reverse(nums[i]);
         }

         unordered_map<int,int> mp;
         int ans=0;

         for(auto it:nums){

            
                 //if current number is present in map then its mp[it]>0 hence we make 1 pair with each of the number present before this number
                 ans =(ans+mp[it])%mod;

                 //increase the frequency of current number so that if we get same number in the future then we cam make a pair with it
                 
                 mp[it]++;
             
         }

         return ans;

    }
