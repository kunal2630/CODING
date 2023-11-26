  /*
    
    Straightforward question of prefix sum 

    Since we have to return answer where answer[i] is equal to the product of all the elements of nums except nums[i] it means for a 
    index i we need product of element of nums from 0 to i-1 and from i+1 to n-1 and we have to do this for every element of nums , so we 
    can store it in prefix and suffix array then for any ith index answer[i] =pref[i-1]*suf[i+1]

    */
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suf(n,0);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){

            pre[i]=pre[i-1]*nums[i];

        }
        for(int i=n-2;i>=0;i--){

            suf[i]=suf[i+1]*nums[i];
        }

        vector<int> ans(n);
        ans[0]=suf[1];
        ans[n-1]=pre[n-2];
        for(int i=1;i<n-1;i++){

            ans[i]=pre[i-1]*suf[i+1];
        }

        return ans;

        
    }
