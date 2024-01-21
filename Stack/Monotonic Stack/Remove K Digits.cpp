string removeKdigits(string num, int k) {
        
        /*

        We have to choose digits from num such that when they form a number their value is as less as possible, so in thid type of 
        question where monotonicity is requried licking picking number in certain order we can use monotonic stack

        Here with monotonicty we have also take care of k that we can only leave element if k>0 

        */
        stack<char> st;
        
        for(int i=0;i<num.size();i++){

            char ch=num[i];

            //if curr element is less than stack top means we can remove stack element to take a smaller element so that we can form a smaller number
            while(!st.empty() && ch<st.top() && k>0){

                st.pop();
                k--;
            }
            //take curr element 
            st.push(num[i]);
        }

        //it may be case that we have got number in monotonic order so we could have taken all the element of num but we can only take n-k element so removing those extra element from top as top would have larger digits
        while(k>0 && !st.empty()){

            st.pop();
            k--;
        }

        string ans="";

        while(!st.empty()){

            ans +=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        int i=0;
        //check for front 0 , if present cnt it
        while(i<ans.size() && ans[i]=='0'){

            i++;
        }

        if(i==ans.size()) return "0";

        //removing 0 which is present in front only take non zero element
        return ans.substr(i,ans.size()-i+1);
    }
