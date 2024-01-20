/*

Using monotonic stack concept to find the next greater element of each number to the right 

*/

void findNGR(vector<int>& nums2, vector<int>& NGR){
        stack<int> st;
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                NGR[i] = -1;
            } else if(st.top() < nums2[i]){
                while(!st.empty() && nums2[i] > st.top()){
                    st.pop();
                }
                if(st.empty()) NGR[i] = -1;
                else NGR[i] = st.top();
            } else{
                NGR[i] = st.top();
            }
            st.push(nums2[i]);
        }
    }
