class Solution {
public:
    int characterReplacement(string s, int k) {
        
        /*

        Reason for sliding window -

        1.Constraint hence O(n^2) solution not possible
        2.Asking about substring(continuos)

        A window could be longest if total no of character(either 
        they are same previously or if not same  we can replace
        to make same)

        Add elements in the window check how many elements we have to replace in that window , if no of replacement
         is less than k then that window is fine otherwise start contracting the window till window replacement is in range




        */
        int fre[26];
        int ans=0;
        memset(fre,0,sizeof(fre));
        int i=0,j=0,n=s.size();
        while(j<n){

            fre[s[j]-'A']++;
            int curWindowSize=j-i+1;
            
            int maxFrequentEl=0;
            for(auto& it:fre){

                maxFrequentEl=max(maxFrequentEl,it);
            }

            /*
            
             because we will try to replace all of the less frequent element with most frequent
             element so that we have to replace as less character as possible

            */
            
            int noOfReplacement=curWindowSize-maxFrequentEl;
            if(noOfReplacement<=k){
                ans=max(ans,curWindowSize);
            }
            while(i<n && noOfReplacement>k){

                //started removing element from front to manage noOfReplacement
                fre[s[i]-'A']--;
                i++;
                int curWindowSize=j-i+1;
                for(auto& it:fre){

                     maxFrequentEl=max(maxFrequentEl,it);
                 }
                 noOfReplacement=curWindowSize-maxFrequentEl;
            }
     
            j++;


        }

        return ans;
    }
};
