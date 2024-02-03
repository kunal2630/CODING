class Solution {
public:

    //dp partioning straight forward template
    bool checkPalindrome(string& s,int l,int r){

       
        while(l<r){

            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }


    int minCut(string s) {

        int dp[2001];
        memset(dp,-1,sizeof(dp));
        int n=s.size();

        for(int idx=n-1;idx>=0;idx--){

            int ans=INT_MAX;
            for(int i=idx;i<n;i++){

                //substr takes O(n) complexity hence we can avoid that by sending just index (start and end)
               
                // string temp=s.substr(idx,i-idx+1);
                    if(checkPalindrome(s,idx,i)){

                        ans=min(ans,1+dp[i+1]);
                    }
            }

             dp[idx]=ans;

        }


        return dp[0];
    }
};
