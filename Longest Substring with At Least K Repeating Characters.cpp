
//Nit a sling window approach , its bruteforce
int longestSubstring(string s, int k) {
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){

            int fre[26];
            memset(fre,0,sizeof(fre));
            for(int j=i;j<n;j++){

                fre[s[j]-'a']++;
                if(j-i+1>=k){

                    bool check=true;
                    for(int i=0;i<26;i++){

                        if(fre[i]>0 && fre[i]<k){

                            check=false;
                        } 
                    }
                    if(check) ans=max(ans,(j-i+1));
                }

            }
        }

        return ans;
    }
