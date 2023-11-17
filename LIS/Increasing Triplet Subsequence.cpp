  /*
    
    INTUITION -

    Same question as LIS just in this we can return anytime our LIS length becomes 3
    */
    bool increasingTriplet(vector<int>& nums) {
        
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i=0;i<nums.size();i++){

            if(nums[i]>temp.back()){

                temp.push_back(nums[i]);
            }

            int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[idx]=nums[i];
            if(temp.size()>=3){

                return true;
            }
        }

        return false;
    }
