int maximumTop(vector<int>& nums, int k) {
        
        
        /*

        Simple question but edge case are good , we have to return the maximum element so depending upon the value of k , our window where we have to find the maximum elemnt may differ , the value of k is greater than nums.size() then simply we have to find maximum vlaue in the nums and return it , if k value is less than or equal to nums.size() then maximum element window would be the element from 0th index to k-1th index and if nums.size()>k then maximum element window would be from 0th index to kth index 

        */
        if(k==0){

            return nums[0];
        }
        if(k%2==1 && nums.size()==1 ){

            return -1;
        }

        int maxii=-1;
        for(auto it:nums){

            maxii=max(maxii,it);
        }
        if(k>nums.size()){
            return maxii;
        }

        maxii=-1;
        
        
        for(int i=0;i<k-1;i++){

            maxii=max(maxii,nums[i]);
            
        }

        if(k<nums.size()){
             return max(maxii,nums[k]);
        }

        return maxii;


       

    }
