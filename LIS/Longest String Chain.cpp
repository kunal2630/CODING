

class Solution {
public:

    /*

    Straightaway question of LIS ,only difference is that in LIS while taking new element we have to check whether my curr elemeent is greater than previous
    element or not , however in this question we have to check whether my last taken word is predecessor of my curr  word  or not

    */
    int dp[1001][1001];
    int n;
    static bool comp(string & a,string & b){

        return a.length()<b.length();
    }
    bool possible(string& last,string& curr){

        if(last.length()!=curr.length()-1) return false;
        int diff=0,i=0,j=0;
        while(i<last.length() && j<curr.length()){

            if(last[i]!=curr[j]){

                diff++;
                j++;

            }
            else{

                i++;
                j++;
            }
        }

        if(diff>1) return false;
        return true;
    }
    int f(int curr,int last,vector<string>& words){

        if(curr==n){

            return 0;
        }

        if(last!=-1 && dp[curr][last]!=-1) return dp[curr][last];

        int op1=0,op2=0;

        //op1 - take

        if(last==-1 ||  possible(words[last],words[curr])){

            op1=1+f(curr+1,curr,words);
        }

        //op2- not take

        op2=0+f(curr+1,last,words);

        if(last!=-1) dp[curr][last]=max(op1,op2);
        return max(op1,op2) ;
    }
    int longestStrChain(vector<string>& words) {
        
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),comp);
        n=words.size();
        return f(0,-1,words);
        
    }
};
