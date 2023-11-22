    /*
    
    If we see nums.length it is between 1 <= nums.length <= 10^5 and 1 <= nums[i].length <= 10^5 so if only see this then to traverse each elemnt in array will take O(n^2) time which will give tle but but 

    It is given that 1 <= sum(nums[i].length) <= 10^5 so total time to traverse each element in thew nums will takje at most 10^5 time
    
    INTUITION - Any diagonal element in array (top to bottom ) generally have i and j value same so why not hink something in terms of i and j  

    So we can observe that all the element on the diagonal have same i+j value that is if for any i+j=7 , then all such i+j which have value 7 will lie on same diagonaland this sum will be least for first diagonal and will increase further as we go from upper diagonal to lower diagonal

    so we can store  a tuple of {i+j,j,nums[i][j]} for every element and then sort it to get all element in correct order

    */

    static bool comp(vector<int>& a,vector<int>& b){

        //to find correct order of element on the diagonal
        if(a[0]==b[0]){

            return a[1]<b[1];
        }

        return a[0]<b[0];
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        vector<int> ans;
        vector<vector<int>> temp;

        for(int i=0;i<nums.size();i++){

            for(int j=0;j<nums[i].size();j++){

                temp.push_back({i+j,j,nums[i][j]});
            }
        }

        sort(temp.begin(),temp.end(),comp);
        for(auto it:temp){

            ans.push_back(it[2]);
        }

        return ans;
    }
