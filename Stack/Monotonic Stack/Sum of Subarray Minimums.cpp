 /*

    So basically we need to find sum of all minimum in every subarrays,but due to constraint we can't actually find all subarrays so we have to somehow find all such minimum optimally

    So for each element(nums[i]) of arr we try to find all such subarray where  which contain nums[i] as its minimum , so that we can just do a nums[i]*totalSubarray

    So in a subarray if you want current element to be minimum it means all element to the left must be greater than it and all element to right must be greater than it

    That means for each element if we can find the index of element
which is smaller than the current element then from that index+1 to currentindex we can take one subarray which has current element as its minimum 
    */
    
    int mod=1e9+7;

    vector<int> getNSL(vector<int>& arr){

        int n=arr.size();
        vector<int> NSL(n);
        stack<int> st;
        for(int i=0;i<n;i++){

            int currEl=arr[i];
            if(st.empty()){
                NSL[i]=-1;
            }
            else {

                while(!st.empty() && arr[st.top()]>currEl){

                    st.pop();
                }
                if(st.empty()){

                    NSL[i]=-1;
                }
                else{

                    NSL[i]=st.top();
                }


            }
         
            st.push(i);

        }
        return NSL;
    }

    vector<int> getNSR(vector<int>& arr){

        int n=arr.size();
        vector<int> NSR(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){

            int currEl=arr[i];
            if(st.empty()){
                NSR[i]=n;
            }
            else {

                while(!st.empty() && arr[st.top()]>=currEl){

                    st.pop();
                }
                if(st.empty()){

                    NSR[i]=n;
                }
                else{

                    NSR[i]=st.top();
                }
            }
            st.push(i);

        }
        return NSR;
    }

    int sumSubarrayMins(vector<int>& arr) {
        
        int ans=0;
        int n=arr.size();

        //generate next smaller element in the left
        vector<int> NSL=getNSL(arr);

        //generate next smaller element in the right
        vector<int> NSR=getNSR(arr);

        for(int i=0;i<n;i++){

            //Number of el in left which is greater than curr element till we didnt get a smaller el in left so that all the subarray containing current element has current el as minimum
            int numL=i-NSL[i];

            //Number of el in right which is greater than curr element till we didnt get a smaller el in left 
            int numR=NSR[i]-i;

            //total number of subarray having current element as minimum
            long long totalSubArrayCount=numL*numR;
            long long  totalSum=(arr[i]*totalSubArrayCount)%mod;

            ans =(ans+totalSum)%mod;
        }

        return ans;
    }
