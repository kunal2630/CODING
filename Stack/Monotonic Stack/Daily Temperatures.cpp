
   /*

   Simple Monotonic stack question where for each element we have to find its next greater element 

   NGR- next greater element

   */
    
    vector<int> getNGR(vector<int>& temperatures,int n){

        vector<int> temp(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){

            int currTemp=temperatures[i];
            if(st.empty()){

                temp[i]=-1;
            }
            else{

                while(!st.empty() && temperatures[st.top()]<=currTemp){

                    st.pop();
                }

                st.empty()?temp[i]=-1:temp[i]=st.top();
            }
            st.push(i);
        }
        return temp;

    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {

       int n=temperatures.size();
       vector<int> ans(n); 
       vector<int> NGR=getNGR(temperatures,n);
       for(int i=0;i<n;i++){

           NGR[i]==-1?ans[i]=0:ans[i]=(NGR[i]-i);
       }
       return ans;
    }
