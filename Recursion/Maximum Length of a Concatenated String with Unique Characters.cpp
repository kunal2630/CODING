class Solution {
public:

    /*

    Just a simple pick not pick variation only catch is to check whether a subsequence contains any duplicate character or not for that we use can use set or 26 size array to check character frequency
    */
    int ans=INT_MIN;
    void f(int idx,vector<string>& arr,string temp){

        if(idx>=arr.size()){

            int fre[26];
            memset(fre,0,sizeof(fre));
            for(int i=0;i<temp.size();i++){

                fre[temp[i]-'a']++;
            }
            for(int i=0;i<26;i++){

                if(fre[i]>1) return;
            }
            int size=temp.size();

            ans=max(ans,size);
            return;
        }

        string oldString=temp;
        temp+=arr[idx];
        f(idx+1,arr,temp);
        temp=oldString;
        f(idx+1,arr,temp);
    }
    int maxLength(vector<string>& arr) {
        
        string temp="";
        f(0,arr,temp);
        return ans;
    }
};
