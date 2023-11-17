/*
     
     Intuition -

     We have to  group nums element in pair such that no element is repeated and we have to minimized maximum pair sum .
     So  any two number has maximum sum when they are individually the two largest number in the array and to get minimum 
     pair sum pair just group elements (1 smallest and 1 largest )
     
 */

    int minPairSum(vector<int>& nums) {
        
        //to get smallest and largest easily
        sort(nums.begin(),nums.end());

        int n=nums.size();

        // i for smallest , j for largest
        int i=0,j=n-1;
        int maxii=INT_MIN;
        
        while(i<j){

            maxii=max(maxii,nums[i]+nums[j]);
            i++;
            j--;
        }

        return maxii;
    }
