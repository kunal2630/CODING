//Logic similar to Word break problem  - trying to find every substring if current substring is valid then only we made further recursion calls

    int f(int idx,string& s,vector<int>& dp){

    
        if(idx==s.size()){

            return 1;
        }

        if(dp[idx]!=-1){

            return dp[idx];
        }

        int ans=0;

        for(int i=idx;i<s.size();i++){

            string subs=s.substr(idx,i-idx+1);

            if(subs.size()<3){

                int num=stoi(subs);

                if(num>=1 && num<=26 && subs[0] !='0'){

                   ans += f(i+1,s,dp);

                }
            }
        }

        return dp[idx]=ans;
    }
    int numDecodings(string s) {
        
        vector<int> dp(s.size(),-1);
        return f(0,s,dp);
    }
